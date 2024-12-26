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
- keccak224
- keccak256
- keccak384
- keccak512
- **blake3**

The six functions `sha224` through `sha512t256` are all part of SHA-2.<br />
Skein was one of the SHA-3 proposals, but in the end it lost to [Keccak](https://keccak.team/).

The software implementations of SHA-3 are twice as slow as SHA-2, but<br />
the hardware implementations of SHA-3 are faster than SHA-1 and SHA-2.

By setting `S3=true` you can use the bundled "libs3" for SHA-3 support.

The default is to use libXKCP, which has both SIMD and generic version.

<https://github.com/XKCP/XKCP>

[BLAKE3](https://blake3.io/) is based on [BLAKE2](https://blake2.net/), which is based on the SHA-3 proposal BLAKE.

It is faster in software, but yet no common implementations in hardware.

By setting `B3=true` you can use the bundled "libb3" for BLAKE3 support.

The default is to use libblake3, which has both SIMD and portable version.

<https://github.com/BLAKE3-team/BLAKE3>

## Formats

### BSD

`sha256`

```
SHA256 (empty) = e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
```

`blake3`

```
BLAKE3 (empty) = af1349b9f5f9a1a6a0404dea36dcc9499bcb25c9adc112b7cc9a93cae41f3262
```

### GNU

`sha256sum`

```
e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855  empty
```

`blake3sum`

```
af1349b9f5f9a1a6a0404dea36dcc9499bcb25c9adc112b7cc9a93cae41f3262  empty
```

## Benchmark

Comparing the algorithms on two machines, macOS arm64 and Linux amd64.

![](assets/bsdsum-benchmark.png)

`make benchmark` runs the built-in benchmark (the `-t` command line flag)

Note that it uses a small test set: `Digesting 100000 10000-byte blocks`.

## Timing

Comparing the time it takes to checksum the Ubuntu cloud image, 1 thread.

![](assets/bsdsum-timing.png)

On macOS you want to be using `sha256sum`, on Linux instead `blake3sum`.

Assuming that macOS uses aarch64 (arm64), and Linux uses x86_64 (amd64).

---

https://opensource.apple.com/releases/

| macOS Version | text_cmds (md5)       | CommonCrypto (CommonDigest)   |
|---------------|-----------------------|-------------------------------|
| 12.1          | text_cmds-118         | CommonCrypto-60190            |
| 11.1          | text_cmds-106         | CommonCrypto-60178.40.2       |
| 10.15         | text_cmds-101.11.1    | CommonCrypto-60165            |
| 10.10         | text_cmds-88          | CommonCrypto-60061            |
