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
| ...    |  ...     | ...                 | ...    |
| GENOME | 8.18593  | 2569.92             |  9880127 |

## Acknowledgements

chromCov uses [BamTools](https://github.com/pezmaster31/bamtools) and [zlib](http://zlib.net/)

> *BamTools*
> Copyright (c) 2009-2010 Derek Barnett, Erik Garrison, Gabor Marth, Michael Stromberg

> *zlib*
> Copyright (C) 1995-2012 Jean-loup Gailly and Mark Adler

## License

MIT License

Copyright (c) 2017 Danny Antaki

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Contact

dantaki@ucsd.edu
