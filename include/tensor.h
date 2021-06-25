#ifndef _TENSOR_
#define _TENSOR_

#include <iostream>
#include <initializer_list>
#include "shape.h"

template <int DIM>
class Tensor
{
private:
	Shape<DIM> _shape;
	float *_data_arr;
	int _length;

public:
	template <typename... T>
	Tensor(T... shape) : _shape(shape...)
	{ // note the use of brace-init-list
		int length = 1;
		for (int i = 0; i < DIM; ++i)
		{
			length *= _shape.shape_arr[i];
		}
		_length = length;
		_data_arr = new float[length];
	}

	~Tensor()
	{
		delete[] _data_arr;
	}

	int get_dim()
	{
		return _shape.dim;
	}

	Shape<DIM> get_shape()
	{
		return _shape;
	}

	int get_length()
	{
		return _length;
	}

	float *get_tensor_ptr()
	{
		return _data_arr;
	}

	void print()
	{
		std::cout << "Shape : \n";
		for (int i = 0; i < DIM; ++i)
			std::cout << _shape.shape_arr[i] << ' ';
		std::cout << "\n Data : \n";
		for (int i = 0; i < _length; i++)
			std::cout << _data_arr[i] << ' ';
		std::cout << std::endl;
	}
};

#endif
