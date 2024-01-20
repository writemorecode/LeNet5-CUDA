#include "network.hpp"

#include "layer.hpp"

void Network::add_layer(std::unique_ptr<Layer>&& layer) { layers.emplace_back(std::move(layer)); }

void Network::display_layers() const {
  for (auto& layer : layers) {
    layer->print();
  }
}

void Network::forward() {
  for (auto& layer : layers) {
    layer->forward();
  }
}

void Network::backward() {
  for (auto it = layers.rbegin(); it != layers.rend(); ++it) {
    auto& layer{*(it)};
    layer->backward();
  }
}
