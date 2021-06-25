#include "layer.h"

class Convolution : public ILayer
{
public:
	void forward(float *src_tensor, float *dst_tensor)
	{	//Currently only care BatchN = 1
		//implement conv forward
		//may we need Tensor Class?
	}
};
