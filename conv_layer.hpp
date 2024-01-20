#ifndef CONV_LAYER_HPP
#define CONV_LAYER_HPP

#include <string>

#include "layer.hpp"

class ConvolutionLayer : public Layer {
 private:
  const unsigned int kernelWidth;
  const unsigned int inputChannels, outputChannels;

 public:
  ConvolutionLayer(unsigned int inputDimensions, unsigned int kernelWidth, unsigned int inputChannels,
                   unsigned int outputChannels, const std::string &name)
      : Layer(inputDimensions, inputDimensions - kernelWidth + 1, name),
        kernelWidth(kernelWidth),
        inputChannels(inputChannels),
        outputChannels(outputChannels){};

  std::string getName() const { return name; }
  void print() const;

  void forward();
  void backward();
};

#endif
