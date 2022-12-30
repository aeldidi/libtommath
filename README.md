This fork of [LibTomMath](https://www.libtom.net/LibTomMath/) provides a script
to amalgamate the source code into a single `tommath.c` and `tommath.h`.

A small number of patches are applied, which you can find by searching the
`git log` for commits made by `Ayman El Didi`.

## Usage

Go to the [releases](https://github.com/aeldidi/libtommath/releases) page and
download the latest release, which contains a self contained `tommath.c` and
`tommath.h` which you can simply compile and use.

## To Amalgamate It Yourself

Compile `tools/amalgamate.c` into a an executable and run it like so:

```
$ amalgamate <path to repository root>
```

This will generate `tommath.c` and `tommath.h` in the directory it was run
from.
