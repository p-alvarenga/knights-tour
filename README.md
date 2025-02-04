# knights-tour
This is a repository to explore optimization using a CS classic problem: [KnightsTour](https://en.wikipedia.org/wiki/Knight%27s_tour)

### Configuration 
You can set `constants.h` the way you prefer, setting: 

`N` to define the board size. _note: there are no solutions for `N < 5`_
`INIT_X`, `INIT_Y` to define the init position of the knight. 


### Building: 

`g++ g++ -O3 -march=native -flto -fprofile-generate -funroll-loops -ftree-vectorize -fomit-frame-pointer -ffast-math -fno-exceptions main.cpp -o knight`


## 
