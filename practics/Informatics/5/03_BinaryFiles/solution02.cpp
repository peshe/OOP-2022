#include<iostream>
#include<fstream>

const int MAX = 64;

void compressesText(const char* fileName) {

	std::ifstream ifs(fileName);
	if (!ifs.is_open()) {

		std::cerr << "Error!\n";
		return;
	}

	std::cout << "Name of output file:";
	char outputName[MAX] = { '\0' };
	std::cin.getline(outputName, MAX, ' ');

	std::ofstream ofs(outputName);
	if (!ofs.is_open()) {

		std::cerr << "Error!\n";
		return;
	}

	char ch;
	while (ifs.get(ch)) {

		if (ch != ' ') {
			ofs.put(ch);
		}
	}

	ifs.close();
	ofs.close();
}


int main() {

	return 0;
}
