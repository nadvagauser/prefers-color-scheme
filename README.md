# prefers-color-scheme
Just like the web one! Only for GNOME[^tested]

^[tested]: Tested on GNOME 42.1

# Developing
## Requirements:
- glib-dev
- make
- pkg-config
- C compiler

## Building
1. Clone the repository and enter the diretory
```sh
~ $ git clone https://github.com/nadvagauser/prefers-color-scheme
~ $ cd prefers-color-scheme
```
2. Run `make`
```sh
~/prefers-color-scheme $ make
```
3. Done
```sh
~/prefers-color-scheme $ file ./prefers-color-scheme
prefers-color-scheme: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib/ld-musl-x86_64.so.1, with debug_info, not stripped
```

You can also install it with `make install`, uninstall with `make uninstall, and
build and run for easier development cycle (`make run`).

`make install` installs a stripped executable.

## Assistance or questions
You can either [create an Issue](https://github.com/nadvagauser/prefers-color-scheme/issues/new)
or [send me an e-mail](mailto:nadvagauser+pcs@proton.me).

## License
This extension is [MIT-licensed](https://choosealicense.com/licenses/mit), per the
[`LICENSE`](./LICENSE) file.

