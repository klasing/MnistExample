#ifndef MNIST_READER_COMMON_HPP
#define MNIST_READER_COMMON_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>
#include <memory>

namespace mnist {
	//************************************************************************
	//*                 read_header
	//************************************************************************
	inline uint32_t read_header(const std::unique_ptr<char[]>& buffer, size_t position) {
		std::cout << "read_header()" << std::endl;

		auto header = reinterpret_cast<uint32_t*>(buffer.get());

		auto value = *(header + position);
		return (value << 24) | ((value << 8) & 0x00FF0000) | ((value >> 8) & 0x0000FF00) | (value >> 24);
	}

	//************************************************************************
	//*                 read_mnist_file
	//************************************************************************
	inline std::unique_ptr<char[]> read_mnist_file(const std::string& path, uint32_t key) {
		std::cout << "read_mnist_file()" << std::endl;

		std::ifstream file;
		file.open(path, std::ios::in | std::ios::binary | std::ios::ate);

		if (!file) {
			std::cout << "Error opening file" << std::endl;
			return {};
		}

		auto size = file.tellg();
		std::unique_ptr<char[]> buffer(new char[size]);

		file.seekg(0, std::ios::beg);
		file.read(buffer.get(), size);
		file.close();

		auto magic = read_header(buffer, 0);

		if (magic != key) {
			std::cout << "Invalid magic number, probably not a MNIST file" << std::endl;
			return {};
		}

		auto count = read_header(buffer, 1);

		if (magic == 0x803) {
			auto rows = read_header(buffer, 2);
			auto columns = read_header(buffer, 3);

			if (size < count * rows * columns + 16) {
				std::cout << "The file is not large enough to hold all the data, probably corrupted" << std::endl;
				return {};
			}
		}
		else if (magic == 0x801) {
			if (size < count + 8) {
				std::cout << "The file is not large enough to hold all the data, probably corrupted" << std::endl;
				return {};
			}
		}

		return buffer;
	}
} // end of namespace mnist

#endif