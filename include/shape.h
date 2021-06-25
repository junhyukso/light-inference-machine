#ifndef _SHAPE_
#define _SHAPE_

template <int DIM>
struct Shape {
    int shape_arr[DIM];
    int dim = DIM;
    template <typename... T>
    Shape(T... shape) : shape_arr{shape...}{}
};

#endif