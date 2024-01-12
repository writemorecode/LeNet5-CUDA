#ifndef MNIST_READER_HPP
#define MNIST_READER_HPP

#include <string>
#include <vector>

#define RAW_IMAGE_HEIGHT 28
#define RAW_IMAGE_WIDTH 28

typedef std::vector<unsigned char> image;

std::vector<unsigned char> read_label_data(const std::string &filename);
std::vector<image> read_image_data(const std::string &filename);
void write_pgm_image(const image &img, const std::string &filename);

#endif
