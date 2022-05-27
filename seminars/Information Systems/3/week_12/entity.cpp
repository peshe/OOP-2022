#include <iostream>
#include <cstring>

class Entity {
public:
    virtual const char* getName() {
        return "Entity";
    };
};

class Player : public Entity {
private:
    char* name;
public:
    Player(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    const char* getName() {
        return this->name;
    }
};

void printName(Entity* entity) {
    std::cout << entity->getName() << std::endl;
}

int main() {
    Entity* e = new Entity();
    printName(e);

    Player* p = new Player("Atanas");
    printName(p);

    Entity* entityPlayer = p;
    printName(entityPlayer);
}