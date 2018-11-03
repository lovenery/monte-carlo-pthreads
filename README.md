# Monte Carlo method using Pthreads

> Parallelized Monte Carlo method applied to approximating the value of π.

## Build

```bash
make
./pi 8 10000000
make clean

# OR
g++ -pthread -std=c++11 -O2 -s pi.cpp -o pi
./pi 8 10000000
```

## Refs

- Monte Carlo method
    - https://en.wikipedia.org/wiki/Monte_Carlo_method
- Random
    - https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c
    - https://blog.gtwang.org/programming/c-cpp-rand-random-number-generation-tutorial-examples/
    - http://edisonx.pixnet.net/blog/post/35196668-%5Bc&++%5D-%E4%BA%82%E6%95%B8%E5%9F%BA%E6%9C%AC%E4%BD%BF%E7%94%A8
- Argument
    - https://stackoverflow.com/questions/2797813/how-to-convert-a-command-line-argument-to-int
