
class ILayer
{
public:
  virtual void forward(float*src_tensor, float*dst_tensor)=0;
}
