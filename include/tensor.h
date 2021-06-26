#ifndef _TENSOR_
#define _TENSOR_

#include <iostream>
#include <initializer_list>
#include "shape.h"

class Tensor
{
private:
	Shape _shape;
	float *_data_arr;
	int _length;

	//init _data_arr, _length.
	//MUST be called after _shape created.
	void init_data_members()
	{
		int length = 1;
		for (int i = 0; i < _shape.dim; ++i)
		{
			length *= _shape.shape_arr[i];
		}
		_length = length;
		_data_arr = new float[length];
	}

public:
	Tensor(std::initializer_list<int> li) : _shape(Shape(li))
	{
		init_data_members();
	}

	Tensor(const Shape& shape) : _shape(shape)
	{
		init_data_members();
	}

	~Tensor()
	{
		delete[] _data_arr;
	}

	int get_dim()
	{
		return _shape.dim;
	}

	Shape get_shape()
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
		for (int i = 0; i < _shape.dim; ++i)
			std::cout << _shape.shape_arr[i] << ' ';
		std::cout << "\n Data : \n";
		for (int i = 0; i < _length; i++)
			std::cout << _data_arr[i] << ' ';
		std::cout << std::endl;
	}
};

#endif
