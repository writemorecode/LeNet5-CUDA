
#include "mnist_reader.hpp"

#include <bit>
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

std::vector<unsigned char> read_label_data(const std::string &filename) {
  std::ifstream f_label(filename, std::ios::binary);
  if (!f_label) {
    return std::vector<unsigned char>{};
  }

  uint32_t magic_number = 0, label_count = 0;
  f_label.read(reinterpret_cast<char *>(&magic_number), sizeof(uint32_t));
  f_label.read(reinterpret_cast<char *>(&label_count), sizeof(uint32_t));
  if (std::endian::native == std::endian::little) {
    magic_number = std::byteswap(magic_number);
    label_count = std::byteswap(label_count);
  }

  std::vector<unsigned char> labels(label_count);
  f_label.read(reinterpret_cast<char *>(labels.data()), sizeof(unsigned char) * labels.size());
  return labels;
}

std::vector<image> read_image_data(const std::string &filename) {
  std::ifstream f_image(filename, std::ios::binary);
  if (!f_image) {
    return std::vector<image>{};
  }
  uint32_t magic_number = 0, image_count = 0;
  uint32_t rows = 0, cols = 0;
  f_image.read(reinterpret_cast<char *>(&magic_number), sizeof(uint32_t));
  f_image.read(reinterpret_cast<char *>(&image_count), sizeof(uint32_t));
  f_image.read(reinterpret_cast<char *>(&rows), sizeof(uint32_t));
  f_image.read(reinterpret_cast<char *>(&cols), sizeof(uint32_t));

  if (std::endian::native == std::endian::little) {
    magic_number = std::byteswap(magic_number);
    image_count = std::byteswap(image_count);
    rows = std::byteswap(rows);
    cols = std::byteswap(cols);
  }

  std::vector<image> images(image_count, image{});
  for (auto &image : images) {
    image.resize(rows * cols);
  }

  for (auto &image : images) {
    f_image.read(reinterpret_cast<char *>(image.data()), image.size());
  }
  return images;
}

void write_pgm_image(const image &img, unsigned int dim, const std::string &filename) {
  std::ofstream f(filename, std::ios::binary);
  f << "P5\n"
    << dim << "\n"
    << dim << "\n"
    << "255\n";
  f.write(reinterpret_cast<const char *>(img.data()), img.size());
}
