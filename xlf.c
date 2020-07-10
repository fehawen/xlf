#include <X11/Xlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    Display *d;
    char **cp, **cp0;
    int i, c;

    d = XOpenDisplay(NULL);

    if (d == NULL) {
        fprintf(stderr, "Cannot open display\n");
        return(-1);
    }

    cp = cp0 = XListFonts(d, argc > 1 ? argv[1] : "*", 256, &c);

    printf("Found %i font matches.\n", c);

    for (i = 0; i < c; i++, cp++) {
        printf("%s\n", *cp);
    }

    if (c) {
        XFreeFontNames(cp0);
    }

    XCloseDisplay(d);
    return 0;
}
