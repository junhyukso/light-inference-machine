#include <iostream>
#include <initializer_list>

template <int N>
class Tensor
{
private:
	int _shape[N];
	float *_data_arr;
	int _dim = N;
	int _length;

public:
	template <typename... T>
	Tensor(T... shape) : _shape{shape...}
	{ // note the use of brace-init-list
		int length = 1;
		for (int i = 0; i < N; ++i)
		{
			length *= _shape[i];
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
		return _dim;
	}

	int *get_shape()
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
		for (int i = 0; i < N; ++i)
			std::cout << _shape[i] << ' ';
		std::cout << "\n Data : \n";
		for (int i = 0; i < _length; i++)
			std::cout << _data_arr[i] << ' ';
		std::cout << std::endl;
	}
};
