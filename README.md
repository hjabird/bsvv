# BSVV

Bird Small Vectors (Vectorised)

A header only library for small vectors and matrices with both single and double precision,
vectorised using SIMD instructions. Vectorisation is done in groups of 8 for 
double precision values and 16 for single precision.

Includes Vectors of length 2, 3 & 4 in both single and double precision and square
matrices of size 2x2, 3x3 & 4x4 in single and double precision.

## Building

BSVV is header only - it doesn't have anything to build.

## Usage

The easiest way to obtain BSVV is probably my own branch of VCPKG.
It can the be included in a CMAKE project using

```
find_package(bsv CONFIG REQUIRED)
target_link_libraries(main PRIVATE bsv)
```
BSVV depends on the BSV library and the SIMDE library. These dependencies
are automatically managed when VCPKG is used.

To include everything ```#include "bsvv/bsvv.h"```.
To just include types ```#include "bsvv/bsvv_types.h"```.
And to include the function only of one particular type, use the type name: ```#include "bsvv/bsvv_V3f.h"```.

Everything starts with ```bsvv_```.

The only types (typedef'ed) are
```
bsvv_V2f
bsvv_V2d
bsvv_V3f
bsvv_V3d
bsvv_V4f
bsvv_V4d
bsvv_M2f
bsvv_M2d
bsvv_M3f
bsvv_M3d
bsvv_M4f
bsvv_M4d
```
where a M or V means matrix or vector. The number represents the size, and d and f 
correspond to double or float.

Accessing the elements of a vector is done using ```bsvv_Vxt.x[index]```.
Accessing the elements of a matrix is done using ```bsvv_Mxt.x[index]```.
All access are performed on all 8 or 16 values at the index at once. To
extract or set an individual vec3f (for example) use 
```bsv_V3f bsvv_get_V3f(*bsvv_V3f, int idx)``` or ```void bsvv_set_V3f(*bsvv_V3f, bsv_V3f, idx)```
respectively.

The size in bytes of a type can found safely using ```sizeof(bsvv_Mxt)```.

## Authors
HJA Bird

## Licence 
MIT




