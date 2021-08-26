#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int main(int argc, char *argv[])
{
	Display *display;
	char **font, **copy;
	int i, count;

	if (!(display = XOpenDisplay(0)))
		exit(1);

	font = copy = XListFonts(display, argc > 1 ? argv[1] : "*", 256, &count);

	printf("Found %d font matches.\n", count);

	for (i = 0; i < count; i++, font++)
		printf("%s\n", *font);

    if (count)
		XFreeFontNames(copy);

	XCloseDisplay(display);
	return 0;
}
