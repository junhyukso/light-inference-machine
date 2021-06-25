#ifndef _LAYER_
#define _LAYER_

template <int DIM_IN, int DIM_OUT>
class ILayer
{
public:
  virtual void forward(Tensor<DIM_IN> &src_tensor, Tensor<DIM_OUT> &dst_tensor) = 0;
  
  virtual Shape<DIM_OUT> infer_output_shape(Tensor<DIM_IN> &src_tensor) = 0;
};

#endif