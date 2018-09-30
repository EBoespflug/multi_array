# multi_arrray

## Overview

```multi_array``` is a multidimensional linearized ```std::array``` written in *C++17*.

## Installation

```multi_array``` is defined in an unique header file. To use it, simply include this header in your source folder.

## Usage

### Generalities

This repository includes several example of usage of ```multi_array``` [here](https://github.com/EBoespflug/multi_array/tree/master/examples).

A ```multi_array``` is defined by the type of the array's items, and a variadic number of unsigned integers defining the size of each dimension. The dimensions and their sizes cannot be dynamically modified during the execution.

Here is some example of ```multi_array``` constructions :

```cpp
#include "multi_array.hpp"

int main()
{
    eb::multi_array<int, 10> a1; // one-dimensional array of 10 ints.
    eb::multi_array<int, 8, 11, 4> a2; // two-dimensional array of double. Semantically equivalent to double[8][11][4].
}
```

Element access is uses ```operator()```. No bound-checking is done for now :

```cpp
a1(8) = 0; // modify 9th item a2
std::cout << a1(0); // access first item of a1.
a2(5, 4, 2) = 0.1; // modify item at a2[5, 4, 2], i.e. the linearised index : idx = 5*(11*4) + 5*(4) + 2 = 242.
```

### Member functions

```multi_array``` provides the following member function corresponding to the equivalent on a linearised ```std::array``` :

 - item access : ```at```, ```operator[]```, ```front```, ```back``` and ```data```.
 - iterators : ```begin```, ```cbegin```, ```rbegin```, ```crbegin```, ```end```, ```cend```, ```rend``` and ```crend```.
 - capacity : ```empty```, ```size```, ```max_size```.
 - ```fill```.
 - ```swap```.

Also, the several comparison non-member operators are provided for equality and ordering comparisons (applied on the entire linearised array).

## Future works

This section includes several unordored future improvement ideas :
 - bound-checking.
 - contract (pre-cond, post-cond, invariant) using **C++20**'s feature.
 - algorithms such as ```std::array``` <=> ```multi_array``` conversion.
 - dynamic equivalent ```multi_vector```.
 - span-based equivalent, to provide generic view adaptor for mutli-dimensional arrays.

## Contributors

 - Etienne BOESPFLUG [etienne.boespflug@gmail.com].

## Licence

[![CC0](https://licensebuttons.net/p/zero/1.0/88x31.png)](http://creativecommons.org/publicdomain/zero/1.0/)

This software has no license and is free to use.

## Disclaimer

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
