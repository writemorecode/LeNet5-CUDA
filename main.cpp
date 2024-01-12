#include <iostream>
#include <vector>

#include "lenet.hpp"
#include "mnist_reader.hpp"

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

  return 0;
}
