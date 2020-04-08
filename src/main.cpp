#include <iostream>
#include "File.hpp"

int main () {
	std::cout << "Hello world\n";

	std::filesystem::remove("./output2.bin");
	std::filesystem::copy_file("./output.bin", "./output2.bin");
	FileHelper::File file("./output2.bin", std::ios_base::binary | std::ios_base::in | std::ios_base::out);

	size_t delete_amount = 6;
	file.deletion<120>(5, delete_amount);
	file.resize(file.getSize() - delete_amount);
	file.insertion<120>(5, {std::byte(1), std::byte(2), std::byte(3), std::byte(4), std::byte(5), std::byte(6)});

	return 0;
}
