#include<iostream>
#include<fstream>

bool isLowerAlpha(char ch) {

	return (ch >= 'a' && ch <= 'z');
}

void writeInBinFile(const char* fileName) {

	std::cout << "How many symbols?\n";
	size_t cnt;
	do {
		std::cin >> cnt;
	} while (cnt <= 0);


	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open()) {

		std::cerr << "Error!\n";
		return;
	}

	std::cout << "Enter symbols:\n";
	char symbol;
	for (size_t i = 0; i < cnt; ++i) {

		std::cin >> symbol;

		ofs.write((const char*)&symbol, sizeof(char));

		char space = ' ';
		ofs.write((const char*)&space, sizeof(char));
	}

	if (ofs) {

		std::cout << "Successfully written!\n";
	}

	ofs.close();
}

void readFromBinFile(const char* fileName) {

	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs.is_open()) {

		std::cerr << "Error!\n";
		return;
	}

	char ch;
	while (!ifs.eof()) {

		ifs.read((char*)&ch, sizeof(char));

		if (ifs.good()) {

		ifs.seekg(sizeof(char), std::ios::cur);

			if (isLowerAlpha(ch)) {

				std::cout << ch;
			}
		}
		std::cout << std::endl;
	}

	ifs.close();
}

int main() {

	writeInBinFile("symbol.bin");
	readFromBinFile("symbol.bin");

	return 0;
}
