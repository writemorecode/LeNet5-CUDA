#ifndef FULLY_CONNECTED_LAYER_HPP
#define FULLY_CONNECTED_LAYER_HPP

#include <string>

#include "layer.hpp"

class FullyConnectedLayer : public Layer {
 private:
 public:
  FullyConnectedLayer(unsigned int inputDimension, unsigned int outputDimension, const std::string &name)
      : Layer(inputDimension, outputDimension, name){};

  std::string getName() const { return name; }
  void print() const;

  void forward();
  void backward();
};

#endif
