# chromCov
Calculate Chromosome Coverage with C++

## Install

#### Clone from GitHub

```
git clone --recursive https://github.com/dantaki/chromCov.git
```

#### Compile with [CMake](https://cmake.org/)

```
cd chromCov
mkdir build
cd build/

cmake .. 

make 
```

#### Binary executable found under `src/chromCov`

## Usage 

`chromCov --help`

```
chromCov calculate coverage for each chromosome
Version: 1.0	Author: Danny Antaki <dantaki@ucsd.edu>

Usage: chromCov -i <in.bam> -q <INT> -o <output.txt>

Options:
    -i        Input: BAM filename
    -q        Mapping quality threshold [10]
    -o        Output: filename
```

## Output


| CONTIG | COVERAGE | AVERAGE_READ_LENGTH | N_READS |
| ------ | -------- | ------------------- | ------- |
| 1      | 8.10809  | 2469.35             |  818414 |
| 2      | 8.75724  | 2581.93             |  824868 |

## Acknowledgements

chromCov uses [BamTools](https://github.com/pezmaster31/bamtools) and [zlib](http://zlib.net/)

> *BamTools*
> Copyright (c) 2009-2010 Derek Barnett, Erik Garrison, Gabor Marth, Michael Stromberg

> *zlib*
> Copyright (C) 1995-2012 Jean-loup Gailly and Mark Adler

## License


