#ifndef _SHAPE_
#define _SHAPE_

#include <vector>
#include <initializer_list>

struct Shape
{
    std::vector<int> shape_arr;
    int dim;
    Shape(std::initializer_list<int> li) : shape_arr(li)
    {
        dim = shape_arr.size();
    }
};

#endif