
PROG = md5
UNAME ?= $(shell uname)
LINKS = rmd160 sha1 sha256 sha512
LINKS += md5sum rmd160sum sha1sum sha256sum sha512sum
ifneq ($(UNAME),Darwin)
LINKS += sha224 sha384 sha512t256
LINKS += sha224sum sha384sum sha512t256sum
ifneq ($(UNAME),Linux)
LINKS += skein256 skein512 skein1024
LINKS += skein256sum skein512sum skein1024sum
endif
endif
PROGS = $(PROG) $(LINKS)

prefix = /usr/local

all: $(PROGS)

CFLAGS ?= -O2 -Wall

LN_S = ln -sf

ifneq ($(UNAME),Darwin)
LIBS += -lmd
endif

md5: md5.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LIBS)

ifeq ($(UNAME),Darwin)
md5: commoncrypto.o
endif

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

.PHONY: test
test: test-unit test-sh

test-unit: $(PROGS)
	for prog in $(PROGS); do echo $$prog | grep -q "sum$$" || ./$$prog -x; done

test-sh: $(PROGS)
	PATH="$(PWD):$$PATH" $(MAKE) -C tests

$(LINKS): $(PROG)
	$(LN_S) $< $@
