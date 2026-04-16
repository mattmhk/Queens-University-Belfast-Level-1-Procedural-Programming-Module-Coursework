void write_route_svg(Point *pts, size_t n, const char *filename, int width, int height) {
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
    double spanLon = maxLon - minLon;
    if (spanLon == 0) spanLon = 1e-9;

    double spanLat = maxLat - minLat;
    if (spanLat == 0) spanLat = 1e-9;

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
        "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n",
        width, height, width, height);

    fprintf(svg,
        "  <rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" fill=\"#fff\" stroke=\"#ccc\"/>\n",
        width, height);

    fprintf(svg, "  <polyline fill=\"none\" stroke=\"#222\" stroke-width=\"2\" points=\"");
    for (size_t i = 0; i < n; ++i) {
        double x = offX + (pts[i].lon - minLon) * scale;
        double y = offY + (maxLat - pts[i].lat) * scale;
        fprintf(svg, "%.2f,%.2f%s", x, y, (i + 1 < n ? " " : ""));
    }
    fprintf(svg, "\"/>\n");

    double sx = offX + (pts[0].lon - minLon) * scale;
    double sy = offY + (maxLat - pts[0].lat) * scale;
    double ex = offX + (pts[n - 1].lon - minLon) * scale;
    double ey = offY + (maxLat - pts[n - 1].lat) * scale;

    fprintf(svg, "  <circle cx=\"%.2f\" cy=\"%.2f\" r=\"5\" fill=\"green\"/>\n", sx, sy);
    fprintf(svg, "  <circle cx=\"%.2f\" cy=\"%.2f\" r=\"5\" fill=\"red\"/>\n", ex, ey);

    fprintf(svg, "</svg>\n");
    fclose(svg);

    printf("SVG route written to %s\n", filename);
}