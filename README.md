# knights-tour
This is a repository to explore optimization using a CS classic problem: [KnightsTour](https://en.wikipedia.org/wiki/Knight%27s_tour)

### Configuration 
You can set `constants.h` the way you prefer, setting: 

1. `N` to define the board size. _note: there are no solutions for `N < 5`_
2. `INIT_X`, `INIT_Y` to define the init position of the knight. 


### Building 

```
g++ -O3 -march=native -flto -fprofile-generate -funroll-loops -ftree-vectorize -fomit-frame-pointer -ffast-math -fno-exceptions main.cpp -o knight
```

<br/>

> [!IMPORTANT] 
> 
> The program may not be able to solve any N with N Init Position because of the constant `OPT_MV` constant declared inside `constants.h` file. 
> 
> So, if you are getting any problems to solve a given case, you can try setting `OPT_MV` to a value between 0 and 6. 
> Also, performance may be affected by changing the `OPT_MV` constant.

### The Project Destiny 

- [ ] Reduce the classes `Knight` and `Pos` into one class `Position` and a namespace `kni` (responsible to the functional functions, such as `Knight::move()`), making the Knight a instance of the class ``.  
