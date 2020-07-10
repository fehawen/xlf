LIBS   = -lX11
CFLAGS := -std=c99 -g -Wall -Wextra
PREFIX ?= $(HOME)
BINDIR ?= $(PREFIX)/bin
CC     ?= gcc

all: xlf

xlf: xlf.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

install: all
	install -Dm755 xlf $(DESTDIR)$(BINDIR)/xlf

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/xlf

clean:
	rm -f xlf *.o

.PHONY: all install uninstall clean
