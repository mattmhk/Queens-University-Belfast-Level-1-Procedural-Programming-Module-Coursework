#include <stdio.h>

typedef struct {
    double lon;
    double lat;
} Point;

void write_route_svg(Point pts[], int n, const char *filename, int width, int height) {
    int i;
    int margin = 30;

    /* Start by assuming the first point is the smallest and biggest point.
       We will compare all the other points against it to find the full
       left, right, top, and bottom boundaries of the route. */
    double minLon = pts[0].lon;
    double maxLon = pts[0].lon;
    double minLat = pts[0].lat;
    double maxLat = pts[0].lat;

    /* Go through every point and update the boundaries whenever we find
       a point that is further left, right, lower, or higher. */
    for (i = 1; i < n; i++) {
        if (pts[i].lon < minLon) minLon = pts[i].lon;
        if (pts[i].lon > maxLon) maxLon = pts[i].lon;
        if (pts[i].lat < minLat) minLat = pts[i].lat;
        if (pts[i].lat > maxLat) maxLat = pts[i].lat;
    }

    /* These tell us how wide and how tall the route is based on the data.
       For example, if max longitude is only a little bigger than min longitude,
       then the route is not very wide. */
    double spanLon = maxLon - minLon;
    double spanLat = maxLat - minLat;

    /* If all longitudes or all latitudes were the same, the span would be 0.
       That would cause division problems later, so we replace 0 with 1 here. */
    if (spanLon == 0) spanLon = 1;
    if (spanLat == 0) spanLat = 1;

    /* Work out how much space is available for the drawing after leaving
       a margin around the outside of the SVG. Then calculate how much the
       route could be scaled horizontally and vertically. */
    double scaleX = (width - 2.0 * margin) / spanLon;
    double scaleY = (height - 2.0 * margin) / spanLat;

    /* Use the smaller scale so the whole route fits inside the SVG without
       going outside the edges. */
    double scale;

    if (scaleX < scaleY)
        scale = scaleX;
    else
        scale = scaleY;

    /* After scaling the route, this is how much width and height it will
       actually use on the screen. */
    double usedW = spanLon * scale;
    double usedH = spanLat * scale;

    /* These offsets move the route into the middle of the SVG instead of
       leaving it stuck in one corner. */
    double offX = margin + (width - 2.0 * margin - usedW) / 2.0;
    double offY = margin + (height - 2.0 * margin - usedH) / 2.0;

    /* Open the SVG file so we can write SVG code into it. */
    FILE *svg = fopen(filename, "w");

    /* Write the beginning of the SVG file. */
    fprintf(svg, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\">\n", width, height);

    /* Draw a white background rectangle so the SVG has a visible canvas area. */
    fprintf(svg, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" fill=\"white\" stroke=\"gray\" />\n", width, height);

    /* Start the polyline element. The points will be written inside this. */
    fprintf(svg, "<polyline fill=\"none\" stroke=\"black\" stroke-width=\"2\" points=\"");

    /* Convert every longitude and latitude point into an x and y position
       inside the SVG, then write it into the polyline. */
    for (i = 0; i < n; i++) {
        /* Move longitude so the smallest longitude starts at 0,
           then multiply by scale so it fits the SVG size,
           then add offX so it appears in the correct place. */
        double x = offX + (pts[i].lon - minLon) * scale;

        /* Do the same idea for latitude, but flip it vertically.
           In SVG, bigger y values go downward on the screen.
           For map data, bigger latitude should appear higher,
           so we use maxLat - currentLat to flip it. */
        double y = offY + (maxLat - pts[i].lat) * scale;

        /* Add this point to the polyline. */
        fprintf(svg, "%.2f,%.2f ", x, y);
    }

    /* Close the polyline element. */
    fprintf(svg, "\" />\n");

    /* Calculate the SVG position of the first point in the route. */
    double sx = offX + (pts[0].lon - minLon) * scale;
    double sy = offY + (maxLat - pts[0].lat) * scale;

    /* Calculate the SVG position of the last point in the route. */
    double ex = offX + (pts[n - 1].lon - minLon) * scale;
    double ey = offY + (maxLat - pts[n - 1].lat) * scale;

    /* Draw a green circle for the start point. */
    fprintf(svg, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"5\" fill=\"green\" />\n", sx, sy);

    /* Draw a red circle for the end point. */
    fprintf(svg, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"5\" fill=\"red\" />\n", ex, ey);

    /* Finish the SVG file. */
    fprintf(svg, "</svg>\n");

    /* Close the file after writing is finished. */
    fclose(svg);
}

int main() {
    /* Open the CSV file for reading. */
    FILE *fp = fopen("Data_for PA4_test.csv", "r");

    /* Create an array that can hold up to 16000 points from the CSV. */
    Point pts[16000];

    /* n keeps track of how many points have been read. */
    int n = 0;

    /* This stores one line of the CSV at a time while reading. */
    char line[256];

    /* Read and ignore the first line because it is the header row. */
    fgets(line, sizeof(line), fp);

    /* Read every remaining line in the file. */
    while (fgets(line, sizeof(line), fp)) {
        /* Read only the first two values from the line.
           Those are the X and Y values in the CSV.
           They are stored as longitude and latitude in the array. */
        sscanf(line, "%lf,%lf", &pts[n].lon, &pts[n].lat);

        /* Move to the next position in the array. */
        n++;
    }

    /* Close the CSV file because we are done reading it. */
    fclose(fp);

    /* Use all the points that were read to create the SVG file. */
    write_route_svg(pts, n, "route.svg", 800, 600);

    return 0;
}