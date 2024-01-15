#ifndef LENET_HPP
#define LENET_HPP

#include <vector>
#define FILE_TRAIN_IMAGE "data/train-images-idx3-ubyte"
#define FILE_TRAIN_LABEL "data/train-labels-idx1-ubyte"
#define FILE_TEST_IMAGE "data/t10k-images-idx3-ubyte"
#define FILE_TEST_LABEL "data/t10k-labels-idx1-ubyte"
#define LENET_FILE "model.dat"
#define COUNT_TRAIN 60000
#define COUNT_TEST 10000

#define LENGTH_KERNEL 5

#define LENGTH_FEATURE0 32
#define LENGTH_FEATURE1 (LENGTH_FEATURE0 - LENGTH_KERNEL + 1)
#define LENGTH_FEATURE2 (LENGTH_FEATURE1 >> 1)
#define LENGTH_FEATURE3 (LENGTH_FEATURE2 - LENGTH_KERNEL + 1)
#define LENGTH_FEATURE4 (LENGTH_FEATURE3 >> 1)
#define LENGTH_FEATURE5 (LENGTH_FEATURE4 - LENGTH_KERNEL + 1)

#define INPUT 1
#define LAYER1 6
#define LAYER2 6
#define LAYER3 16
#define LAYER4 16
#define LAYER5 120
#define OUTPUT 10

#define ALPHA 0.5
#define PADDING 2

#define IMAGE_SIZE 32

typedef std::vector<unsigned char> image;


#endif
