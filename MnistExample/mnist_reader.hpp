#ifndef MNIST_READER_HPP
#define MNIST_READER_HPP

#include <vector>

#include "mnist_reader_common.hpp"

namespace mnist {
	template <template <typename...> class Container, typename Image, typename Label>
	struct MNIST_dataset {
		Container<Image> training_images;
		Container<Image> test_images;
		Container<Label> training_labels;
		Container<Label> test_labels;

		void resize_training(std::size_t new_size) {
			if (training_images.size() > new_size) {
				training_images.resize(new_size);
				training_labels.resize(new_size);
			}
		}

		void resize_test(std::size_t new_size) {
			if (test_images.size() > new_size) {
				test_images.resize(new_size);
				test_labels.resize(new_size);
			}
		}
	};

	//************************************************************************
	//*                 read_mnist_image_file
	//************************************************************************
	template <template <typename...> class Container = std::vector, typename Image, typename Functor>
	void read_mnist_image_file(Container<Image>& images, const std::string& path, std::size_t limit, Functor func) {
		std::cout << "read_mnist_image_file()" << std::endl;

		auto buffer = read_mnist_file(path, 0x803);

		if (buffer) {
			auto count = read_header(buffer, 1);
			auto rows = read_header(buffer, 2);
			auto columns = read_header(buffer, 3);

			auto image_buffer = reinterpret_cast<unsigned char*>(buffer.get() + 16);

			if (limit > 0 && count > limit) {
				count = static_cast<unsigned int>(limit);
			}

			images.reserve(count);

			for (size_t i = 0; i < count; ++i) {
				images.push_back(func());

				for (size_t j = 0; j < rows * columns; ++j) {
					auto pixel = *image_buffer++;
					images[i][j] = static_cast<typename Image::value_type>(pixel);
				}
			}
		}

		return;
	}

	//************************************************************************
	//*                 read_mnist_label_file
	//************************************************************************
	template <template <typename...> class Container = std::vector, typename Label = uint8_t>
	void read_mnist_label_file(Container<Label>& labels, const std::string& path, std::size_t limit = 0) {
		std::cout << "read_mnist_label_file()" << std::endl;

		auto buffer = read_mnist_file(path, 0x801);

		if (buffer) {
			auto count = read_header(buffer, 1);

			auto label_buffer = reinterpret_cast<unsigned char*>(buffer.get() + 8);

			if (limit > 0 && count > limit) {
				count = static_cast<unsigned int>(limit);
			}

			labels.resize(count);

			for (size_t i = 0; i < count; ++i) {
				auto label = *label_buffer++;
				labels[i] = static_cast<Label>(label);
			}
		}
	}

	//************************************************************************
	//*                 read_training_images
	//************************************************************************
	template <template <typename...> class Container = std::vector, typename Image, typename Functor>
	Container<Image> read_training_images(const std::string& folder, std::size_t limit, Functor func) {
		std::cout << "read_training_images()" << std::endl;

		Container<Image> images;
		read_mnist_image_file<Container, Image>(images, folder + "/train-images.idx3-ubyte", limit, func);
		return images;
	}

	//************************************************************************
	//*                 read_training_labels
	//************************************************************************
	template <template <typename...> class Container = std::vector, typename Label = uint8_t>
	Container<Label> read_training_labels(const std::string& folder, std::size_t limit) {
		std::cout << "read_training_labels()" << std::endl;

		Container<Label> labels;
		read_mnist_label_file<Container, Label>(labels, folder + "/train-labels.idx1-ubyte", limit);
		return labels;
	}

	//************************************************************************
	//*                 read_test_images
	//************************************************************************
	template <template <typename...> class Container = std::vector, typename Image, typename Functor>
	Container<Image> read_test_images(const std::string& folder, std::size_t limit, Functor func) {
		std::cout << "read_test_images()" << std::endl;

		Container<Image> images;
		read_mnist_image_file<Container, Image>(images, folder + "/t10k-images.idx3-ubyte", limit, func);
		return images;
	}

	//************************************************************************
	//*                 read_test_labels
	//************************************************************************
	template <template <typename...> class Container = std::vector, typename Label = uint8_t>
	Container<Label> read_test_labels(const std::string& folder, std::size_t limit) {
		std::cout << "read_test_labels()" << std::endl;

		Container<Label> labels;
		read_mnist_label_file<Container, Label>(labels, folder + "/t10k-labels.idx1-ubyte", limit);
		return labels;
	}

	//************************************************************************
	//*                 read_dataset_direct
	//************************************************************************
	template <template <typename...> class Container, typename Image, typename Label = uint8_t>
	MNIST_dataset<Container, Image, Label> read_dataset_direct(const std::string& folder, std::size_t training_limit = 0, std::size_t test_limit = 0) {
		std::cout << "read_dataset_direct()" << std::endl;

		MNIST_dataset<Container, Image, Label> dataset;

		dataset.training_images = read_training_images<Container, Image>(folder, training_limit, [] { return Image(1 * 28 * 28); });
		dataset.training_labels = read_training_labels<Container, Label>(folder, training_limit);

		dataset.test_images = read_test_images<Container, Image>(folder, test_limit, [] { return Image(1 * 28 * 28); });
		dataset.test_labels = read_test_labels<Container, Label>(folder, test_limit);

		return dataset;
	}

	//************************************************************************
	//*                 read_dataset
	//************************************************************************
	template <template <typename...> class Container = std::vector, template <typename...> class Sub = std::vector, typename Pixel = uint8_t, typename Label = uint8_t>
	MNIST_dataset<Container, Sub<Pixel>, Label> read_dataset(const std::string& folder, std::size_t training_limit = 0, std::size_t test_limit = 0) {
		std::cout << "read_dataset()" << std::endl;

		return read_dataset_direct<Container, Sub<Pixel>>(folder, training_limit, test_limit);
	}

} // end of namespace mnist

#endif