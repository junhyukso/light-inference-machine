#ifndef _LAYER_
#define _LAYER_

#include "tensor.h"
#include "shape.h"

class Layer
{
public:
  virtual void forward(Tensor &src_tensor, Tensor &dst_tensor) = 0;

  virtual Shape infer_output_shape(const Shape &src_shape) = 0;
};

#endif