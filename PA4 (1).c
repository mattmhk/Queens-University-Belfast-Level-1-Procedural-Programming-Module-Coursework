/* NT01012 Procedural Programming */
/* Programming Assignment 4 */
/* */
/* Question Number: PA4*/
/* Name: Linn Myint Thet Khine*/
/* Date: 12/11/2025 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define SCALE 12000.0 // metres per degree (given in PA4)

typedef struct {
    double lon; // longitude
    double lat; // latitude
} Point;


int read_points_csv(const char *filename, Point **out_pts, size_t *out_n)
{
    FILE *fp = fopen(filename, "r");
    /* Debugging for not file found */
    if (!fp) {
        perror("Could not open CSV file");
        return 0;
    }

    char line[1024];


    if (!fgets(line, sizeof(line), fp)) {
        fclose(fp);
        return 0;
    }

    size_t cap = 1024;
    size_t n = 0;
    Point *pts = malloc(cap * sizeof *pts);
    if (!pts) {
        fclose(fp);
        fprintf(stderr, "Memory allocation failed\n");
        return 0;
    }

    while (fgets(line, sizeof line, fp)) {
        double x, y;
        if (sscanf(line, "%lf,%lf", &x, &y) == 2) {
            if (n == cap) {
                cap *= 2;
                Point *tmp = realloc(pts, cap * sizeof *pts);
                if (!tmp) {
                    fprintf(stderr, "Realloc failed\n");
                    free(pts);
                    fclose(fp);
                    return 0;
                }
                pts = tmp;
            }
            pts[n].lon = x;
            pts[n].lat = y;
            n++;
        }
    }

    fclose(fp);
    *out_pts = pts;
    *out_n = n;
    return 1;
}

/* writing TOTAL DISTANCE function */
double total_distance(const Point *pts, size_t n)
{
    if (!pts || n < 2) return 0.0;

    double sum = 0.0;
    for (size_t i = 1; i < n; ++i) {
        double dlon = pts[i].lon - pts[i - 1].lon;
        double dlat = pts[i].lat - pts[i - 1].lat;
        double dx = dlon * SCALE;
        double dy = dlat * SCALE;
        double d = sqrt(dx * dx + dy * dy);
        sum += d;
    }
    return sum;
}

/* FIXED write_route_svg function */
void write_route_svg(const Point *pts, size_t n,
                     const char *filename, int width, int height)
{
    if (!pts || n < 2) return;

    double minLon = DBL_MAX, maxLon = -DBL_MAX;
    double minLat = DBL_MAX, maxLat = -DBL_MAX;

    for (size_t i = 0; i < n; i++) {
        if (pts[i].lon < minLon) minLon = pts[i].lon;
        if (pts[i].lon > maxLon) maxLon = pts[i].lon;
        if (pts[i].lat < minLat) minLat = pts[i].lat;
        if (pts[i].lat > maxLat) maxLat = pts[i].lat;
    }

    int margin = 30;
    double spanLon = maxLon - minLon; if (spanLon == 0) spanLon = 1e-9;
    double spanLat = maxLat - minLat; if (spanLat == 0) spanLat = 1e-9;

    double scaleX = (width - 2.0 * margin) / spanLon;
    double scaleY = (height - 2.0 * margin) / spanLat;
    double scale = (scaleX < scaleY) ? scaleX : scaleY;

    double usedW = spanLon * scale;
    double usedH = spanLat * scale;

    double offX = margin + (width - 2.0 * margin - usedW) / 2.0;
    double offY = margin + (height - 2.0 * margin - usedH) / 2.0;

    FILE *svg = fopen(filename, "w");
    if (!svg) {
        printf("Could not create %s\n", filename);
        return;
    }

    fprintf(svg,
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<svg xmlns=\"http://www.w3.org/2000/svg\" "
        "width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n",
        width, height, width, height);

    fprintf(svg,
        " <rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" "
        "fill=\"#000000\" stroke=\"#cccccc\"/>\n",
        width, height);

    fprintf(svg,
        " <polyline fill=\"none\" stroke=\"#cccccc\" stroke-width=\"2\" points=\"");

    for (size_t i = 0; i < n; ++i) {
        double x = offX + (pts[i].lon - minLon) * scale;
        double y = offY + (maxLat - pts[i].lat) * scale;
        fprintf(svg, "%.2f,%.2f%s", x, y, (i + 1 < n ? " " : ""));
    }
    fprintf(svg, "\"/>\n");

    double sx = offX + (pts[0].lon - minLon) * scale;
    double sy = offY + (maxLat - pts[0].lat) * scale;
    double ex = offX + (pts[n-1].lon - minLon) * scale;
    double ey = offY + (maxLat - pts[n-1].lat) * scale;

    fprintf(svg,
        " <circle cx=\"%.2f\" cy=\"%.2f\" r=\"5\" fill=\"blue\"/>\n",
        sx, sy);
    fprintf(svg,
        " <circle cx=\"%.2f\" cy=\"%.2f\" r=\"5\" fill=\"green\"/>\n",
        ex, ey);

    fprintf(svg, "</svg>\n");
    fclose(svg);
}

/* main function */
int main()
{
    const char *inputFile = "C:\\Users\\40502392\\Desktop\\newpa4\\Data_for PA4_test.csv"; /* didnt work with normal file path. So i wrote absolute file path */
    const char *outputFile = "lmtk.svg"; /* giving figure file name */

    Point *points = NULL;
    size_t n = 0;
    /* debugging */
    if (!read_points_csv(inputFile, &points, &n)) {
        fprintf(stderr, "Error: cannot read %s\n", inputFile);
        return 1;
    }
    /* printing total distance(output) */
    double dist = total_distance(points, n);
    printf("Total distance travelled = %.2f metres (%.2f km)\n",
           dist, dist / 1000.0);

    write_route_svg(points, n, outputFile, 800, 600);
    printf("Route image saved as %s\n", outputFile);

    return 0;
}