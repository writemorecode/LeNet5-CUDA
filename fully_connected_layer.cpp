#include "fully_connected_layer.hpp"

#include <iostream>

void FullyConnectedLayer::forward() { std::cout << "Forward layer '" << getName() << "'\n"; }
void FullyConnectedLayer::backward() { std::cout << "Backward layer '" << getName() << "'\n"; }

void FullyConnectedLayer::print() const {
  std::cout << "Fully connected layer: ";
  std::cout << "Input dimensions: " << inputDimension << " ";
  std::cout << "Output dimensions: " << outputDimension << "\n";
}
