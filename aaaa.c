#include <stdio.h>

/* 
   This creates a custom type called Point.

   Each Point stores one coordinate from the CSV.
   lon = longitude
   lat = latitude

   So if one row in the CSV begins with:
   -5.927808,54.55748

   then:
   lon = -5.927808
   lat = 54.55748
*/
typedef struct {
    double lon;
    double lat;
} Point;

/*
   write_route_svg

   This function takes:
   pts      = the array of all points read from the CSV
   n        = how many points are in that array
   filename = the name of the SVG file to create
   width    = width of the SVG canvas
   height   = height of the SVG canvas

   Its job is to:
   1. find the outer boundaries of the route
   2. scale the route so it fits inside the SVG
   3. draw the whole route as one polyline
   4. mark the first point in green
   5. mark the last point in red
*/
void write_route_svg(Point pts[], int n, const char *filename, int width, int height) {
    int i;

    /* 
       Leave a gap around the route so it is not touching
       the edges of the SVG canvas.
    */
    int margin = 30;

    /*
       Start by assuming the first point is both the minimum
       and maximum longitude and latitude.

       Then later, the loop checks all remaining points to
       find the true minimum and maximum values.
    */
    double minLon = pts[0].lon;
    double maxLon = pts[0].lon;
    double minLat = pts[0].lat;
    double maxLat = pts[0].lat;

    /*
       Go through all points and keep updating the boundary values.

       minLon = leftmost longitude
       maxLon = rightmost longitude
       minLat = lowest latitude
       maxLat = highest latitude

       After this loop finishes, we know the full bounding box
       of the route.
    */
    for (i = 1; i < n; i++) {
        if (pts[i].lon < minLon) minLon = pts[i].lon;
        if (pts[i].lon > maxLon) maxLon = pts[i].lon;
        if (pts[i].lat < minLat) minLat = pts[i].lat;
        if (pts[i].lat > maxLat) maxLat = pts[i].lat;
    }

    /*
       Work out how wide and how tall the route is in terms of
       coordinate values.

       spanLon = total width of the route
       spanLat = total height of the route
    */
    double spanLon = maxLon - minLon;
    double spanLat = maxLat - minLat;

    /*
       If all longitudes were the same, spanLon would be 0.
       If all latitudes were the same, spanLat would be 0.

       That would cause division by zero later when calculating scale,
       so replace 0 with 1 to avoid that problem.
    */
    if (spanLon == 0) spanLon = 1;
    if (spanLat == 0) spanLat = 1;

    /*
       Calculate how much the route could be stretched horizontally
       and vertically to fit inside the SVG canvas after leaving margins.

       scaleX = possible horizontal scale
       scaleY = possible vertical scale
    */
    double scaleX = (width - 2.0 * margin) / spanLon;
    double scaleY = (height - 2.0 * margin) / spanLat;

    /*
       This will hold the final scale used for drawing.
    */
    double scale;

    /*
       Use the smaller of scaleX and scaleY.

       Why?
       Because choosing the smaller one guarantees that the route
       will fit both horizontally and vertically inside the SVG.

       If we chose the bigger one, the route might fit in one direction
       but go outside the canvas in the other direction.
    */
    if (scaleX < scaleY)
        scale = scaleX;
    else
        scale = scaleY;

    /*
       After scaling, this is how much space the route will actually use
       on the SVG canvas.
    */
    double usedW = spanLon * scale;
    double usedH = spanLat * scale;

    /*
       offX and offY shift the route so that it is centered inside
       the drawing area instead of being stuck in a corner.
    */
    double offX = margin + (width - 2.0 * margin - usedW) / 2.0;
    double offY = margin + (height - 2.0 * margin - usedH) / 2.0;

    /*
       Open the output SVG file in write mode.
       This creates the file if it does not exist.
    */
    FILE *svg = fopen(filename, "w");

    /*
       If the file could not be created, stop the function.
    */
    if (svg == NULL) {
        printf("Could not create SVG file.\n");
        return;
    }

    /*
       Write the XML declaration at the top of the SVG file.
       This tells programs what type of file it is.
    */
    fprintf(svg, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");

    /*
       Start the SVG tag and set the size of the canvas.
    */
    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\">\n", width, height);

    /*
       Draw a background rectangle covering the whole canvas.
       fill   = white background
       stroke = gray border
    */
    fprintf(svg, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" fill=\"white\" stroke=\"gray\" />\n", width, height);

    /*
       Start the polyline element.

       A polyline draws one connected line through many points.
       The actual list of x,y coordinates will be written inside
       the points attribute in the loop below.
    */
    fprintf(svg, "<polyline fill=\"none\" stroke=\"black\" stroke-width=\"2\" points=\"");

    /*
       Convert every longitude and latitude into SVG x,y coordinates.

       x coordinate:
       1. subtract minLon so the leftmost point becomes 0
       2. multiply by scale so it fits the canvas
       3. add offX so it is shifted into the correct position

       y coordinate:
       1. use maxLat - current lat to flip the route vertically
       2. multiply by scale
       3. add offY

       The vertical flip is necessary because in SVG, bigger y values
       go downward on the screen, but for map data, larger latitude
       should appear higher.
    */
    for (i = 0; i < n; i++) {
        double x = offX + (pts[i].lon - minLon) * scale;
        double y = offY + (maxLat - pts[i].lat) * scale;

        /*
           Write one point into the polyline.
           The format is:
           x,y
           followed by a space before the next point.
        */
        fprintf(svg, "%.2f,%.2f ", x, y);
    }

    /*
       Finish the polyline tag.
    */
    fprintf(svg, "\" />\n");

    /*
       Calculate the SVG position of the first point in the route.
       This will be used for the green start marker.
    */
    double sx = offX + (pts[0].lon - minLon) * scale;
    double sy = offY + (maxLat - pts[0].lat) * scale;

    /*
       Calculate the SVG position of the last point in the route.
       This will be used for the red end marker.
    */
    double ex = offX + (pts[n - 1].lon - minLon) * scale;
    double ey = offY + (maxLat - pts[n - 1].lat) * scale;

    /*
       Draw a green circle at the first point.
    */
    fprintf(svg, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"5\" fill=\"green\" />\n", sx, sy);

    /*
       Draw a red circle at the last point.
    */
    fprintf(svg, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"5\" fill=\"red\" />\n", ex, ey);

    /*
       Close the SVG tag to finish the file properly.
    */
    fprintf(svg, "</svg>\n");

    /*
       Close the file after all writing is done.
    */
    fclose(svg);

    /*
       Print a success message to the terminal.
    */
    printf("SVG created successfully.\n");
}

int main() {
    /*
       Open the CSV file in read mode.

       This path is absolute, so the program looks in that exact location.
       That avoids the earlier working-directory problem.
    */
    FILE *fp = fopen("C:\\Code file\\c files\\Code-Files\\data.csv", "r");

    /*
       If the CSV could not be opened, stop the program.
    */
    if (fp == NULL) {
        printf("Could not open CSV file.\n");
        return 1;
    }

    /*
       Create an array to store up to 16000 points from the CSV.
    */
    Point pts[16000];

    /*
       n keeps track of how many valid points have been stored.
    */
    int n = 0;

    /*
       This stores one line from the CSV at a time while reading.
    */
    char line[256];

    /*
       Read the first line of the CSV and ignore it.

       This is the header line such as:
       X,Y,track_fid,track_seg_id,...
    */
    fgets(line, sizeof(line), fp);

    /*
       Read the remaining lines one by one until the file ends.
    */
    while (fgets(line, sizeof(line), fp)) {

        /*
           Read the first two numbers from the line and store them
           into the next Point in the array.

           %lf reads a double value.
           The CSV line begins with longitude and latitude, so:
           first value  -> pts[n].lon
           second value -> pts[n].lat

           If sscanf successfully reads 2 values, then increase n.
        */
        if (sscanf(line, "%lf,%lf", &pts[n].lon, &pts[n].lat) == 2) {
            n++;
        }
    }

    /*
       Close the CSV file because reading is finished.
    */
    fclose(fp);

    /*
       Print how many points were read from the file.
    */
    printf("Read %d points.\n", n);

    /*
       At least 2 points are needed to draw a route.
       If there are fewer than 2, stop the program.
    */
    if (n < 2) {
        printf("Not enough points to make SVG.\n");
        return 1;
    }

    /*
       Create the SVG file using all points read from the CSV.

       pts        = array of points
       n          = number of points
       route.svg  = output filename
       800        = canvas width
       600        = canvas height
    */
    write_route_svg(pts, n, "route.svg", 800, 600);

    /*
       End the program successfully.
    */
    return 0;
}