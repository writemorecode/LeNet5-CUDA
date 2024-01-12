#include <iostream>
#include <vector>

#include "lenet.hpp"
#include "mnist_reader.hpp"

int main() {
  auto mnist_train_data{read_image_data(FILE_TRAIN_IMAGE)};
  if (mnist_train_data.size() == 0) {
    std::cerr << "Error: Failed to read training image data.\n";
    return 1;
  }

  auto train_label{read_label_data(FILE_TRAIN_LABEL)};
  if (train_label.size() == 0) {
    std::cerr << "Error: Failed to read training labels.\n";
    return 1;
  }

  if (mnist_train_data.size() != train_label.size()) {
    std::cerr << "Number of training images does not match number of training labels.\n";
    return 1;
  }

  auto mnist_test_data{read_image_data(FILE_TEST_IMAGE)};
  if (mnist_test_data.size() == 0) {
    std::cerr << "Error: Failed to read testing image data.\n";
    return 1;
  }

  auto test_label{read_label_data(FILE_TEST_LABEL)};
  if (train_label.size() == 0) {
    std::cerr << "Error: Failed to read testing labels.\n";
    return 1;
  }

  if (mnist_test_data.size() != test_label.size()) {
    std::cerr << "Number of testing images does not match number of testing labels.\n";
    return 1;
  }

  normalize_images(mnist_train_data);
  normalize_images(mnist_test_data);

  auto train_data = resize_images(mnist_train_data);
  auto test_data = resize_images(mnist_test_data);
}
