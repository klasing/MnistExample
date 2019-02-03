#include "pch.h"
#include <iostream>
#include "mnist_reader.hpp"

//****************************************************************************
//*                     main
//****************************************************************************
int main(int argc, char* argv[]) {
	const std::string MNIST_DATA_LOCATION = "C:/Users/Klasing/MyProgramming/MyCpp/Tmp2AvoidLongName/Machinelearning_May_10_2018/MachineLearning_Sep_9_2018/Mnist/Data";
	std::cout << "MNIST data directory: " << MNIST_DATA_LOCATION.c_str() << std::endl;

	// load MNIST data
	mnist::MNIST_dataset<std::vector, std::vector<uint8_t>, uint8_t> dataset =
		mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>(MNIST_DATA_LOCATION);

	std::cout << "Nbr of training images = " << dataset.training_images.size() << std::endl;
	std::cout << "Nbr of training labels = " << dataset.training_labels.size() << std::endl;
	std::cout << "Nbr of test images = " << dataset.test_images.size() << std::endl;
	std::cout << "Nbr of test labels = " << dataset.test_labels.size() << std::endl;

	return 0;
}
