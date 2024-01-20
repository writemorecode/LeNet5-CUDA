#ifndef LAYER_HPP
#define LAYER_HPP

#include <string>

class Layer {
 protected:
  const unsigned int inputDimension, outputDimension;
  const std::string name;

 public:
  Layer(unsigned int inputDimension, unsigned int outputDimension, const std::string &name)
      : inputDimension(inputDimension), outputDimension(outputDimension), name(name){};

  virtual ~Layer() = default;

  unsigned int getInputDimension() const { return inputDimension; }
  unsigned int getOutputDimension() const { return outputDimension; }

  virtual void print() const = 0;

  virtual void forward() = 0;
  virtual void backward() = 0;
};

#endif
