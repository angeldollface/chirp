# CHIRP :ribbon: :gear: :heart:

![GitHub CI](https://github.com/angeldollface/chirp/actions/workflows/main.yml/badge.svg)

***An implementation for a CLI tool in C that uses my algorithm to validate passwords. :ribbon: :gear: :heart:***

## ABOUT :books:

Since I've become a huge fan of C, I thought I'd reimplement a CLI tool that checks the validity of a password using an algorithm of my own design. This program is a reimplementation of [this tool](https://github.com/angeldollface/flek) I wrote in Rust. This repository contains the source code to that alternative. Enjoy. :heart:

## INSTALLATION :inbox_tray:

Make sure you have the following tools installed and available as commands from a terminal session:

- Git
- The GNU C Compiler
- Make
- Automake
- Autoconf
- Libtool

To install ***Chirp***, follow these steps:

- 1.) Download the utility's source code:

```bash
git clone https://github.com/angeldollface/chirp.git
```

- 2.) Change into the source code's root directory:

```bash
cd chirp
```

- 3.) Compile ***Chirp***:

```bash
make
```

- 4.) Move the resulting binary `chirp` to a location that is on your path.


## USAGE :hammer:

If you installed ***Chirp***, the `chirp` command should be available from a terminal session. You can use the `chirp` command like this:

- Check a password:

```bash
chirp pwd 1969HoglinSteak
```

- Get version information on ***Chirp*** itself:

```bash
chirp version
```

- Get information on how to use ***Chirp***:

```bash
chirp help
```

## CHANGELOG :black_nib:

### Version 0.2.0

- Split code into modules.
- Relicensed the project under the [DSL v1](https://github.com/angeldollface/doll-software-license).

### Version 0.1.0

- Initial release.
- Upload to GitHub.

# NOTE :scroll:

- *Chirp :ribbon: :gear: :heart:* by Alexander Abraham :black_heart: a.k.a. *"Angel Dollface" :dolls: :ribbon:*
- Licensed under the [DSL v1](https://github.com/angeldollface/doll-software-license).
