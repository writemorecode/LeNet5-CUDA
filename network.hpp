#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <memory>
#include <vector>

#include "layer.hpp"

class Network {
 private:
  std::vector<std::unique_ptr<Layer>> layers;

 public:
  Network() = default;

  void add_layer(std::unique_ptr<Layer> &&layer);

  void display_layers() const;

  void forward();
  void backward();
};

#endif
