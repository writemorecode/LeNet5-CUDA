#include "lenet.hpp"

#include <algorithm>
#include <cmath>
#include <numeric>

#include "mnist_reader.hpp"

/*
 * Normalizes an image to have mean 0 and std.dev. 1.
 */
void normalize_image(image &img) {
  const auto N = img.size();
  const auto sum = std::accumulate(img.cbegin(), img.cend(), float(0));
  const auto mean = sum / N;
  const auto ssq = std::inner_product(img.cbegin(), img.cend(), img.cbegin(), float(0));
  const auto stddev = std::sqrt((ssq / N) - mean * mean);
  std::transform(img.cbegin(), img.cend(), img.begin(), [&](const auto &p) { return (p - mean) / stddev; });
}

/*
 * Normalizes an array of images.
 */
void normalize_images(std::vector<image> &images) { std::for_each(images.begin(), images.end(), normalize_image); }

/*
 * Resizes an array of 28x28 MNIST images
 * to 32x32 LeNet5 images.
 * */
std::vector<image> resize_images(std::vector<image> &mnist_images) {
  std::vector<image> images(mnist_images.size());
  std::transform(mnist_images.begin(), mnist_images.end(), images.begin(), resize_image);
  return images;
}

/*
 * Resizes a 28x28 image from the MNIST dataset to
 * a 32x32 image usable with LeNet5.
 * */
image resize_image(image &mnist_image) {
  image lenet_image;
  lenet_image.resize(IMAGE_SIZE * IMAGE_SIZE);
  for (int i = 0; i < MNIST_IMAGE_SIZE; i++) {
    for (int j = 0; j < MNIST_IMAGE_SIZE; j++) {
      auto mnist_index = i * MNIST_IMAGE_SIZE + j;
      auto lenet_index = (i + PADDING) * IMAGE_SIZE + (j + PADDING);
      lenet_image[lenet_index] = mnist_image[mnist_index];
    }
  }
  return lenet_image;
}
