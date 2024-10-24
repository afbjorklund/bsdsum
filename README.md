# bsdsum

## FreeBSD

This is the FreeBSD "md5" program, which also does other digests...

`src/sbin/md5`

It uses libmd for the digests, the OpenBSD version is available:

<https://www.hadrons.org/software/libmd/>

## Darwin

It is available on macOS (`/sbin`), but only `md5` has been linked.

`text_cmds/md5`

There it uses CommonCrypto, which is a part of `libSystem.B.dylib`

<https://opensource.apple.com/source/CommonCrypto/>

## Linux

You can also build this for Linux, where it uses openssl libcrypto.

<https://www.openssl.org/>

By setting `MD=true` you can use libmd for checking portability issues.

It is the default on FreeBSD, but optional on macOS and GNU/Linux.

## Algorithms

- **md5**
- **rmd160**
- **sha1**
- sha224
- **sha256**
- sha384
- **sha512**
- sha512t224
- sha512t256
- skein256
- skein512
- skein1024

## Formats

### BSD

`sha256`

```
SHA256 (empty) = e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
```

### GNU

`sha256sum`

```
e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855  empty
```

---

https://opensource.apple.com/releases/

| macOS Version | text_cmds (md5)       | CommonCrypto (CommonDigest)   |
|---------------|-----------------------|-------------------------------|
| 12.1          | text_cmds-118         | CommonCrypto-60190            |
| 11.1          | text_cmds-106         | CommonCrypto-60178.40.2       |
| 10.15         | text_cmds-101.11.1    | CommonCrypto-60165            |
| 10.10         | text_cmds-88          | CommonCrypto-60061            |
