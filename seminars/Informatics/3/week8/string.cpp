#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    int size;
	
	void copy(const String& other, bool withClear = true) {
		if(withClear) {
			clear();
		}
		
        size = other.size;
        data = new char[size];
        memcpy(data, other.data, size);
	}
	
	void clear() {
		delete[] data;
	}
	
public:
    String() {}

    String(const char* str) {
        size = strlen(str);
        data = new char[size];
        memcpy(data, str, size);
    } 

    String (const String& other) {
		copy(other, false);
    }
	
	String& operator=(const String& other) {
		if(this != &other) {
			copy(other);
		}
		
		return *this;
	}

    ~String() {
        delete[] data;
    }

    void print(std::ostream& out = std::cout) const {
        for (int i = 0; i < size; i++) {
            out << data[i];
        }
    }
	
	int length() const {
		return size;
	}
};

std::ostream& operator<<(std::ostream& out, const String& str) {
	str.print(out);
	return out;
}

class Entity {
private:
    String name;
public:
    Entity(const String& _name) : name(_name) {}

    void printName(std::ostream& out = std::cout) const {
        name.print(out);
    }
};

std::ostream& operator<<(std::ostream& out, const Entity& ent) {
	ent.printName();
	out<< std::endl;
	return out;
}

int main() {
    Entity e("nasko");
	std::cout<< e;
}