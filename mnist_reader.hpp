#ifndef MNIST_READER_HPP
#define MNIST_READER_HPP

#include <string>
#include <vector>

#define MNIST_IMAGE_SIZE 28

typedef std::vector<unsigned char> image;

void normalize_image(image &img);
void normalize_images(std::vector<image> &images);

image resize_image(image &mnist_image);
std::vector<image> resize_images(std::vector<image> &mnist_images);

std::vector<unsigned char> read_label_data(const std::string &filename);
std::vector<image> read_image_data(const std::string &filename);
void write_pgm_image(const image &img, unsigned int dim, const std::string &filename);

#endif
