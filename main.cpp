#include <iostream>
#include <vector>

#include "conv_layer.hpp"
#include "fully_connected_layer.hpp"
#include "lenet.hpp"
#include "mnist_reader.hpp"
#include "network.hpp"
#include "pooling_layer.hpp"

Network buildNetwork() {
  Network lenet{};
  lenet.add_layer(std::make_unique<ConvolutionLayer>(32, 5, 1, 6, "C1"));
  lenet.add_layer(std::make_unique<PoolingLayer>(28, 2, 6, 6, "P1"));
  lenet.add_layer(std::make_unique<ConvolutionLayer>(14, 5, 6, 16, "C2"));
  lenet.add_layer(std::make_unique<PoolingLayer>(10, 2, 16, 16, "P2"));
  lenet.add_layer(std::make_unique<ConvolutionLayer>(5, 5, 16, 120, "C3"));
  lenet.add_layer(std::make_unique<FullyConnectedLayer>(120, 84, "FC1"));
  lenet.add_layer(std::make_unique<FullyConnectedLayer>(84, 10, "FC2"));
  return lenet;
}

int main() {
  auto train_data{read_image_data(FILE_TRAIN_IMAGE)};
  if (train_data.size() == 0) {
    std::cerr << "Error: Failed to read training image data.\n";
    return 1;
  }

  auto train_label{read_label_data(FILE_TRAIN_LABEL)};
  if (train_label.size() == 0) {
    std::cerr << "Error: Failed to read training labels.\n";
    return 1;
  }

  if (train_data.size() != train_label.size()) {
    std::cerr << "Number of training images does not match number of training labels.\n";
    return 1;
  }

  auto test_data{read_image_data(FILE_TEST_IMAGE)};
  if (test_data.size() == 0) {
    std::cerr << "Error: Failed to read testing image data.\n";
    return 1;
  }

  auto test_label{read_label_data(FILE_TEST_LABEL)};
  if (train_label.size() == 0) {
    std::cerr << "Error: Failed to read testing labels.\n";
    return 1;
  }

  if (test_data.size() != test_label.size()) {
    std::cerr << "Number of testing images does not match number of testing labels.\n";
    return 1;
  }

  auto lenet{buildNetwork()};
  lenet.display_layers();
  lenet.forward();
  lenet.backward();
}
