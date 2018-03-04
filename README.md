[![Build Status](https://travis-ci.org/Link-God/matrix_example)](https://travis-ci.org/Link-God/matrix_example)

```
cmake -H. -B_builds -DBUILD_TESTS=ON -DBUILD_EXAMPLES=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
_builds/example
```
