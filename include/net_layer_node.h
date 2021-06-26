#ifndef _NET_LAYER_NODE_
#define _NET_LAYER_NODE_

#include "layer.h"
#include "shape.h"
#include <iostream>

class LayerNode
{
    public : 
        const Layer* _layer;
        const Shape _input_shape;
        const Shape _output_shape;
        
        LayerNode(Layer* layer, const Shape& input_shape) : 
            _layer(layer) , 
            _input_shape(input_shape),
            _output_shape(layer->infer_output_shape(input_shape))
            {}
};

#endif