
class ILayer
{
public:
  virtual void forward(float*src_tensor, float*dst_tensor)=0;
  virtual int get_weight_size()=0;
}
