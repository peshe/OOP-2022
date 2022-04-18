#include<cstring>
#include<fstream>
#include<stdexcept>
#include <iostream>

using namespace std;

class Player {
private:
	char* name;
	unsigned years;
	unsigned height;
	void copy(const Player& other)
	{
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);
		height = other.height;
		years = other.years;
	}
public:
	Player()
	{
		name = new char[1];
		name[0] = '\0';
		years = 0;
		height = 0;
	}
	Player(const char* name, const unsigned years, const unsigned height)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->years = years;
		this->height = height;
	}
	Player(const Player& other)
	{
		copy(other);
	}
	Player& operator=(const Player& other)
	{
		if (this != &other)
		{
			delete[] name;
			copy(other);
		}
		return *this;
	}
	~Player() {
		delete[] name;
	}
	bool operator<(const Player& other) const
	{
		return this->years < other.years;
	}
	const char* getName() const
	{
		return this->name;
	}
	const unsigned getHeight() const
	{
		return this->height;
	}
	const unsigned getYears() const
	{
		return this->years;
	}
};

class PlayerWriter {
private:
	std::ostream& out;
public:
	PlayerWriter(std::ostream& out): out(out) { }

	void write(const Player& player) const {
		const unsigned int years = player.getYears();
		out.write(reinterpret_cast<const char*>(&years), sizeof(years));

		const unsigned int height = player.getHeight();
		out.write(reinterpret_cast<const char*>(&height), sizeof(height));

		const std::size_t nameLenght = strlen(player.getName()) + 1;
		out.write(reinterpret_cast<const char*>(&nameLenght), sizeof(nameLenght));

		out.write(player.getName(), nameLenght);
	}
};

class PlayerBinaryFileSerializer {
	const Player& player;
	std::ofstream fout;
public:
	PlayerBinaryFileSerializer(const char* fileName, const Player& player) : player(player) {
		fout.open(fileName, std::ios::app | std::ios::binary);
		if (fout.is_open() == false) {
			throw std::runtime_error("File could not be opened");
		}
	}

	void serialize() {
		PlayerWriter writer(fout);
		writer.write(player);
	}
};

class PlayerReader
{
	std::istream& in;
public:
	PlayerReader(std::istream& fin) : in(fin) {}

	Player read()
	{
		unsigned int years;
		in.read(reinterpret_cast<char*>(&years), sizeof(years));

		unsigned int height;
		in.read(reinterpret_cast<char*>(&height), sizeof(height));

		std::size_t nameLenght;
		in.read(reinterpret_cast<char*>(&nameLenght), sizeof(nameLenght));

		char* name = new char[nameLenght];
		in.read(name, nameLenght);

		Player result(name, years, height);
		delete[] name;

		return result;
	}
};

class PlayerBinaryFileDeserializer
{
private:
	std::ifstream fin;

public:
	PlayerBinaryFileDeserializer(const char* fileName)
	{
		fin.open(fileName, std::ios::binary);
		if (fin.is_open() == false) {
			throw std::runtime_error("File could not be opened");
		}
	}

	Player deserialize()
	{
		PlayerReader reader(fin);
		return reader.read();
	}
};

int main()
{

}
