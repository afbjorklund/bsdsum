SHA3 ?= false
BLAKE3 ?= true

PROG = md5
UNAME ?= $(shell uname)
LINKS = rmd160 sha1 sha256 sha512
LINKS += md5sum rmd160sum sha1sum sha256sum sha512sum
ifneq ($(UNAME),Darwin)
LINKS += sha224 sha384
LINKS += sha224sum sha384sum
ifneq ($(UNAME),Linux)
LINKS += sha512t224 sha512t256
LINKS += sha512t224sum  sha512t256sum
LINKS += skein256 skein512 skein1024
LINKS += skein256sum skein512sum skein1024sum
endif
endif
ifeq ($(SHA3),true)
LINKS += keccak256 keccak512
LINKS += keccak256sum keccak512sum
endif
ifeq ($(BLAKE3),true)
LINKS += blake3 blake3sum
endif
PROGS = $(PROG) $(LINKS)

prefix = /usr/local

all: $(PROGS)

CFLAGS ?= -O2 -Wall

LN_S = ln -sf

ifeq ($(UNAME),FreeBSD)
MD = true
else
MD ?= false
endif
S3 ?= false
B3 ?= false

ifeq ($(MD),true)
CFLAGS += -DUSE_MD
LIBS += -lmd
else
ifeq ($(UNAME),Linux)
LIBS += -lcrypto
endif
endif
ifeq ($(SHA3),true)
CFLAGS += -DUSE_SHA3
ifeq ($(S3),true)
CFLAGS += -DUSE_S3 -Ilibs3
else
LIBS += -lXKCP
endif
endif
ifeq ($(BLAKE3),true)
CFLAGS += -DUSE_BLAKE3
ifeq ($(B3),true)
CFLAGS += -DUSE_B3 -Ilibb3
else
LIBS += -lblake3
endif
endif

md5: md5.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(LIBS)

ifeq ($(MD),false)
ifeq ($(UNAME),Darwin)
md5: commoncrypto.o
endif
ifeq ($(UNAME),Linux)
md5: libcrypto.o
endif
endif
ifeq ($(SHA3),true)
md5: libkeccak.o
ifeq ($(S3),true)
md5: libs3/s3.o
endif
endif
ifeq ($(BLAKE3),true)
md5: libblake3.o
ifeq ($(B3),true)
md5: libb3/b3.o
endif
endif

.PHONY: install
install: install-bin install-man

install-bin: $(PROG)
	install -d $(DESTDIR)$(prefix)/bin
	install $< $(DESTDIR)$(prefix)/bin
	for link in $(LINKS); do $(LN_S) $< $(DESTDIR)$(prefix)/bin/$$link; done

install-man: $(PROG).1
	install -d $(DESTDIR)$(prefix)/share/man/man1
	install $< $(DESTDIR)$(prefix)/share/man/man1
	for link in $(LINKS); do $(LN_S) $< $(DESTDIR)$(prefix)/share/man/man1/$$link.1; done

.PHONY: clean
clean:
	$(RM) *.o
	$(RM) $(PROGS)

.PHONY: test
test: test-unit test-sh

test-unit: $(PROGS)
	for prog in $(PROGS); do echo $$prog | grep -q "sum$$" || ./$$prog -x; done

benchmark:
	for prog in $(PROGS); do echo $$prog | grep -q "sum$$" || ./$$prog -t; done

test-sh: $(PROGS)
	PATH="$(PWD):$$PATH" $(MAKE) -C tests

$(LINKS): $(PROG)
	$(LN_S) $< $@
