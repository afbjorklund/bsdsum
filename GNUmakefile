
PROG = md5
LINKS = rmd160 sha1 sha256
PROGS = $(PROG) $(LINKS)

prefix = /usr/local

all: $(PROGS)

CFLAGS ?= -O2 -Wall

LN_S = ln -sf

LIBS += -lmd

md5: md5.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LIBS)

.PHONY: install
install: install-bin install-man

install-bin: $(PROG)
	install -D $< $(DESTDIR)$(prefix)/bin
	for link in $(LINKS); do $(LN_S) $< $(DESTDIR)$(prefix)/bin/$$link; done

install-man: $(PROG).1
	install -D $< $(DESTDIR)$(prefix)/share/man/man1
	for link in $(LINKS); do $(LN_S) $< $(DESTDIR)$(prefix)/share/man/man1/$$link.1; done

.PHONY: clean
clean:
	$(RM) *.o
	$(RM) $(PROGS)

$(LINKS): $(PROG)
	$(LN_S) $< $@
