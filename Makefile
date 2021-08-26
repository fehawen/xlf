LIBS   = -lX11
CFLAGS := -std=c99 -Wall -Wextra -pedantic -Os
PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
CC ?= gcc

all: xlf

xlf: xlf.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 xlf $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/xlf

clean:
	rm -f xlf *.o

.PHONY: all install uninstall clean
