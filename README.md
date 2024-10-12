# bsdsum

This is the FreeBSD "md5" program, which also does other digests...

`src/sbin/md5`

It uses libmd for the digests, the OpenBSD version is also in Linux:

<https://www.hadrons.org/software/libmd/>

It is available on macOS (`/sbin`), but only `md5` has been linked.

`text_cmds/md5`

There it uses CommonCrypto, which is a part of `libSystem.B.dylib`

<https://opensource.apple.com/source/CommonCrypto/>

Note that Linux version is only for checking for portability issues.

Using OpenSSL is much faster, since it has optimized implementations.

---

https://opensource.apple.com/releases/

| macOS Version | text_cmds (md5)       | CommonCrypto (CommonDigest)   |
|---------------|-----------------------|-------------------------------|
| 10.15         | text_cmds-101.11.1    | CommonCrypto-60165            |
| 10.10         | text_cmds-88          | CommonCrypto-60061            |
