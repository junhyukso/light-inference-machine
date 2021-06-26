#include <iostream>
#include "tensor.h"
#include "conv_layer.h"
#include <vector>
#include "layer.h"
#include "net_layer_node.h"
#include "relu_layer.h"
int main()
{
  Tensor t1({3,16,16});
  float* t1_ptr = t1.get_tensor_ptr();
  t1_ptr[0] = -1;
  t1_ptr[1] = -2;
  t1_ptr[2] = 0;
  t1_ptr[3] = 3;
  t1_ptr[4] = 5;

  t1.print();

  ReLU relu1 = ReLU();

  Tensor t2 = Tensor(relu1.infer_output_shape(t1.get_shape()));
  t2.print();

  relu1.forward(t1,t2);
  t2.print();

  /*
  Convolution conv1 = Convolution(3, 6, 3);

  Tensor t2 = Tensor(conv1.infer_output_shape(t1.get_shape()));
  t2.print();

  LayerNode ln1 = LayerNode(&conv1, t1.get_shape());

  conv1.forward(t1, t2);
  */
  return 0;
}
