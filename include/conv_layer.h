#ifndef _CONV_
#define _CONV_

#include "tensor.h"
#include "layer.h"

class Convolution: public ILayer<3,3>
{
private:
	Tensor<4> _weight;
	int _padding;
	int _stride;
	int _ks;
	int _C;
	int _M;

public:
	Convolution(int in_channel, int out_channel, int kernel_size, int padding = 1, int stride = 1)
		: _weight(out_channel, in_channel, kernel_size, kernel_size) //Weight format = MCHW
	{
		_padding = padding;
		_stride = stride;
		_ks = kernel_size;
		_C = in_channel;
		_M = out_channel;
	}

	//Currently, All tensor assume CHW format
	
	void forward(Tensor<3> &src_tensor, Tensor<3> &dst_tensor)
	{
		int in_hw = src_tensor.get_shape().shape_arr[0];
		//int out_hw = (in_hw + 2 * _padding - _ks) / _stride + 1;

		//Naive 7-loop implmentation
		for (int m = 0; m < _M; ++m)
		{
			for (int h = 0; h < in_hw; ++h)
			{
				for (int w = 0; w < in_hw; ++w)
				{
					float acc = 0;
					for (int c = 0; c < _C; ++c)
					{
						for (int ky = 0; ky < _ks; ++ky)
						{
							for (int kx = 0; kx < _ks; ++kx)
							{
								// acc += _weight.index(m,c,ky,kx)*src_tensor.index(c,h+ky,w+kx); FIXME: implement index
							}
						}
					}
					//dst_tensor.index() = acc; //FIXME output tensor indexing
				}
			}
		}
	}

	Shape<3> infer_output_shape(Tensor<3> &src_tensor){
		int in_hw = src_tensor.get_shape().shape_arr[0];
		int out_hw = (in_hw + 2 * _padding - _ks) / _stride + 1;
		return Shape<3>(_M,out_hw,out_hw); //CHW Format
	}
};

#endif