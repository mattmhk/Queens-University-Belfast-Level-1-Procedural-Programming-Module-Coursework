#include <stdio.h>

typedef struct {
    double lon;
    double lat;
} Point;

void write_route_svg(Point pts[], int n, const char *filename, int width, int height) {
    int i;
    int margin = 30;

    double minLon = pts[0].lon;
    double maxLon = pts[0].lon;
    double minLat = pts[0].lat;
    double maxLat = pts[0].lat;

    for (i = 1; i < n; i++) {
        if (pts[i].lon < minLon) minLon = pts[i].lon;
        if (pts[i].lon > maxLon) maxLon = pts[i].lon;
        if (pts[i].lat < minLat) minLat = pts[i].lat;
        if (pts[i].lat > maxLat) maxLat = pts[i].lat;
    }

    double spanLon = maxLon - minLon;
    double spanLat = maxLat - minLat;

    if (spanLon == 0) spanLon = 1;
    if (spanLat == 0) spanLat = 1;

    double scaleX = (width - 2.0 * margin) / spanLon;
    double scaleY = (height - 2.0 * margin) / spanLat;
    double scale;

    if (scaleX < scaleY)
        scale = scaleX;
    else
        scale = scaleY;

    double usedW = spanLon * scale;
    double usedH = spanLat * scale;

    double offX = margin + (width - 2.0 * margin - usedW) / 2.0;
    double offY = margin + (height - 2.0 * margin - usedH) / 2.0;

    FILE *svg = fopen(filename, "w");
    if (svg == NULL) {
        printf("Could not create SVG file.\n");
        return;
    }

    fprintf(svg, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\">\n", width, height);
    fprintf(svg, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" fill=\"white\" stroke=\"gray\" />\n", width, height);

    fprintf(svg, "<polyline fill=\"none\" stroke=\"black\" stroke-width=\"2\" points=\"");

    for (i = 0; i < n; i++) {
        double x = offX + (pts[i].lon - minLon) * scale;
        double y = offY + (maxLat - pts[i].lat) * scale;
        fprintf(svg, "%.2f,%.2f ", x, y);
    }

    fprintf(svg, "\" />\n");

    double sx = offX + (pts[0].lon - minLon) * scale;
    double sy = offY + (maxLat - pts[0].lat) * scale;
    double ex = offX + (pts[n - 1].lon - minLon) * scale;
    double ey = offY + (maxLat - pts[n - 1].lat) * scale;

    fprintf(svg, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"5\" fill=\"green\" />\n", sx, sy);
    fprintf(svg, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"5\" fill=\"red\" />\n", ex, ey);

    fprintf(svg, "</svg>\n");
    fclose(svg);

    printf("SVG created successfully.\n");
}

int main() {
    FILE *fp = fopen("Data_for PA4_test.csv", "r");
    if (fp == NULL) {
        printf("Could not open CSV file.\n");
        return 1;
    }

    Point pts[16000];
    int n = 0;
    char line[256];

    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%lf,%lf", &pts[n].lon, &pts[n].lat) == 2) {
            n++;
        }
    }

    fclose(fp);

    printf("Read %d points.\n", n);

    if (n < 2) {
        printf("Not enough points to make SVG.\n");
        return 1;
    }

    write_route_svg(pts, n, "route.svg", 800, 600);

    return 0;
}