#ifndef POOLING_LAYER_HPP
#define POOLING_LAYER_HPP

#include <string>

#include "layer.hpp"

class PoolingLayer : public Layer {
 private:
  const unsigned int kernelWidth;
  const unsigned int inputChannels, outputChannels;

 public:
  PoolingLayer(unsigned int inputDimension, unsigned int kernelWidth, unsigned int inputChannels, unsigned int outputChannels,
               const std::string &name)
      : Layer(inputDimension, inputDimension / kernelWidth, name),
        kernelWidth(kernelWidth),
        inputChannels(inputChannels),
        outputChannels(outputChannels){};

  std::string getName() const { return name; }
  void print() const;

  void forward();
  void backward();
};

#endif
