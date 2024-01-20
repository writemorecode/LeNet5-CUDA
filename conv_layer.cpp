#include "conv_layer.hpp"

#include <iostream>

void ConvolutionLayer::forward() { std::cout << "Forward layer '" << getName() << "'\n"; }
void ConvolutionLayer::backward() { std::cout << "Backward layer '" << getName() << "'\n"; }

void ConvolutionLayer::print() const {
  std::cout << "Convolution layer: ";
  std::cout << "Input dimensions: "
            << "(" << inputDimension << "x" << inputDimension << ") ";
  std::cout << "Output dimensions: "
            << "(" << outputDimension << "x" << outputDimension << ")\n";
  std::cout << "Kernel width: " << kernelWidth << "\n";
  std::cout << "Input channels: " << inputChannels << " ";
  std::cout << "Output channels: " << outputChannels << "\n";
}
