[![Build Status](https://travis-ci.org/Link-God/matrix_example.svg?branch=master)](https://travis-ci.org/Link-God/matrix3)

```
cmake -H. -B_builds -DBUILD_TESTS=ON -DBUILD_EXAMPLES=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
_builds/example
```
