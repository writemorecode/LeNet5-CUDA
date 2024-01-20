#include "pooling_layer.hpp"

#include <iostream>

void PoolingLayer::forward() { std::cout << "Forward layer '" << getName() << "'\n"; }
void PoolingLayer::backward() { std::cout << "Backward layer '" << getName() << "'\n"; }

void PoolingLayer::print() const {
  std::cout << "Pooling layer: ";
  std::cout << "Input dimensions: "
            << "(" << inputDimension << "x" << inputDimension << ") ";
  std::cout << "Output dimensions: "
            << "(" << outputDimension << "x" << outputDimension << ")\n";
  std::cout << "Kernel width: " << kernelWidth << "\n";
  std::cout << "Input channels: " << inputChannels << " ";
  std::cout << "Output channels: " << outputChannels << "\n";
}
