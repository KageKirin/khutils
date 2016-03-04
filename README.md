khutils
=======

** KageKirin Header only Utils**

Lead Developer, Maintainer: [KageKirin](mailto:kagekirin+khutils@gmail.com)

# About

This is a collection C++14 (mostly) functions, classes, structures targeted to be re-used in several projects.

# Usage

Add `<repo-path>/include` to your includes, then `#include "khutils/<whatever>.hpp` in your source.
The files are self-contained, i.e. don't require any linking.
However, in some cases you need to `#define KHUTIL_<SOMETHING>_IMPL` in one `.cpp` file to include the implementation source as well.
Please refer to each separate header to fetch the correct define.

Furthermore, some of the header files have **INCLUDE DEPENDENCIES**, which in turn might result in **LINKER DEPENCIES**.
Among those dependencies, there are:

- [Bandit](http://banditcpp.org/) and [Snowhouse](https://github.com/banditcpp/snowhouse) -- used for unit testing and assertions. Dependency lies in `assertion.hpp`.
- [Boost](http://www.boost.org/) 1.62 at the time of writing this (Sorry!)
	- `spiritual_cast and spiritual_compare` rely on [Boost.Spirit.X3](http://boost-spirit.com/home/category/spirit-x3/) for parsing
- [Boost.Nowide](http://cppcms.com/files/nowide/html/) and iconv for `khutils/utf`
- [glm](http://glm.g-truc.net/) for everything inside `khutils/glm`.
- [FlatBuffers](https://google.github.io/flatbuffers/)


Also, the code tends to rely heavily on [C++14](https://isocpp.org) features, such as lambdas.

---

# Functionality overview


## Algorithm_index

Some standard STL algorithms which provide the current element's index along with the element itself.

### Header only

### Dependencies

Pythonic is required for the functions marked as `_pythonic`.
Pythonic is header only as well.

### Usage example


## Logging

Logging functionality

### Link dependency

### Dependencies

STL

### Usage example

```
khutil::logger::info() << "some information";
khutil::logger::warn() << "a warning indicating that something might be off";
khutil::logger::error() << "an error message indicating that something is off";
khutil::logger::debug() << "debug information";

struct tag;
khutil::logger::debug_t<tag>() << "debug information that requires debug_t<> to be explicitly implemented for provided struct";
```



## Runtime_exceptions

Implementation of some (base class) runtime exceptions.
Namely, ImportExpection and ExportException.

### Link dependency

### Dependency

STL

### Usage example



## Streamhandler

Implements endian-dependent read and write functionality for binary data.

### Header only

### Dependency

Boost.Endian (header only as well)

### Usage example

```
code here
```


## Spiritual_cast

A lexical_cast<>(std::string) implementation based on Boost.Spirit.X3's fast parsers.
"Casts" or rather converts the provided string into the template type parameter.

#### Why re-implementing boost::lexical_cast<>?

- Boost.Spirit.X3 is supposed to be the fastest parser around. [link]()
- `istringstream >> val` is slow as hell.
- Need more control than std::stoi et al. can provide.


### Link dependency

### Dependency

STL,
Boost.Spirit.X3

### Usage example

```
int i = spiritual_cast<int>("42");
float f = spiritual_cast<float>("3.14");
double d = spiritual_cast<double>("3.14");

```

### Caveats

Overloading spiritual_cast<> to fit a specific target type might be required.


