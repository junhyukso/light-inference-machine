#include <iostream>
#include "conv_layer.h"
int main()
{
  std::cout << "hello UAM!\n";
  Tensor<3> t1(224, 224, 3);
  Tensor<3> t2(224, 224, 64);
  Convolution conv1 = Convolution(3, 64, 3);
  conv1.forward(t1, t2);
  //t2.print();
  return 0;
}
