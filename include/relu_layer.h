#ifndef _RELU_
#define _RELU_

#include "tensor.h"
#include "layer.h"
#include <limits>
#include <stdexcept>

class ReLU : public Layer
{
private:
    float _lower_bound;
    float _upper_bound;

public:
	ReLU(float lower_bound=0.0f,float upper_bound=std::numeric_limits<float>::max())
		:   _lower_bound(lower_bound), 
            _upper_bound(upper_bound)
	{
        if (_upper_bound < _lower_bound){
            throw std::invalid_argument("Upper bound must be bigger than Lower bound.");
        }
    }

	void forward(Tensor &src_tensor, Tensor &dst_tensor)
	{
		int src_size = src_tensor.get_length();
        float * src_tensor_ptr = src_tensor.get_tensor_ptr();
        float * dst_tensor_ptr = dst_tensor.get_tensor_ptr();

        float src_val;
        for(int i =0; i<src_size; ++i){
            float src_val = src_tensor_ptr[i];
            if (src_val < _lower_bound){
                dst_tensor_ptr[i] = 0;
            }
            else if(src_val > _upper_bound){
                dst_tensor_ptr[i] = _upper_bound;
            }
            else{
                dst_tensor_ptr[i] = src_tensor_ptr[i];
            }
        }
	}

	Shape infer_output_shape(const Shape &src_shape)
	{
		return Shape(src_shape);
	}
};

#endif