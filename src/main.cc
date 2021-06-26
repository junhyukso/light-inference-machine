#include <iostream>
#include "tensor.h"
#include "conv_layer.h"
#include <vector>
#include "layer.h"
#include "net_layer_node.h"

int main()
{
  Tensor t1({3,16,16});
  t1.print();
  
  Convolution conv1 = Convolution(3, 6, 3);

  Tensor t2 = conv1.infer_output_shape(t1.get_shape());
  t2.print();

  LayerNode ln1 = LayerNode(&conv1, t1.get_shape());

  conv1.forward(t1, t2);

  return 0;
}
