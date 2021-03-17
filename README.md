# statisticaltest

Statistical test library for C++

---
## Contents
1. [Statistical hypothesis tests](#h1)<br>
1.1. [Fisher's exact test](#h11)<br>
2. [Manhattan Plot](#h2)<br>
2.1. [Parameters](#h21)<br>
---

## How to use library
Core statistical test methods are in `header` folder.
You just need to bring the files to your code.

You can check the sample out in `src/main.cpp`.

## Build
```shell
$ cd header
$ make
$ cd src
$ make
```

## <a name="h1">1. Statistical hypothesis tests</a>
### <a name="h11">1.1. Fisher's exact test</a>
> This method is based on https://genome.sph.umich.edu/w/images/b/b3/Bios615-fa12-lec03-presentation.pdf
```c
#include "header/statistical.h"
```


## <a name="h2">2. Sample Quality Control</a>
### <a name="h21">2.1. Variant Allele Frequency</a>

