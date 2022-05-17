#include <iostream>
#include <cstring>

class Creature
{
public:
	Creature()
		: Creature("", 0, 0, 0)
	{}

	Creature(const char* name,
		unsigned int hp, unsigned int defence,
		unsigned int attack)
		: hp(hp), defence(defence), attack(attack)
	{
		this->initName(name);
	}

	Creature(const Creature& other)
	{
		this->copy(other);
	}

	Creature& operator=(const Creature& other)
	{
		if (this != &other)
		{
			this->deleteName();
			this->copy(other);
		}
		return *this;
	}

	~Creature()
	{
		this->deleteName();
	}

	void takeDamage(unsigned int damage)
	{
		if (this->hp >= damage - defence)
		{
			this->hp -= damage - defence;
		}
		else
		{
			this->hp = 0;
		}
	}

	bool isDead() const
	{
		return this->hp == 0;
	}

	const unsigned int getAttack() const
	{
		return this->attack;
	}

	unsigned int getHp() const
	{
		return this->hp;
	}

	const unsigned int getDefence() const
	{
		return this->defence;
	}

private:
	char* name;
	unsigned int hp;
	unsigned int defence;
	unsigned int attack;

	void initName(const char* name)
	{
		this->name = new char[std::strlen(name) + 1];
		strcpy_s(this->name, std::strlen(name) + 1, name);
	}

	void deleteName()
	{
		delete[] this->name;
	}

	void copy(const Creature& other)
	{
		this->initName(other.name);
		this->hp = other.hp;
		this->defence = other.defence;
		this->attack = other.attack;
	}
};

class Orc : public Creature
{
public:
	Orc(const char* name,
		unsigned int hp, unsigned int defence,
		unsigned int attack, unsigned int strength)
		: Creature(name, hp, defence, attack),
		strength(strength)
	{}

	void attackTarget(Creature& target) const
	{
		target.takeDamage(this->getAttack() + this->strength);
		std::clog << target.getHp() << std::endl;
	}

	void takeDamage(unsigned int damage)
	{
		this->takeDamage(damage - strength);
	}

private:
	unsigned int strength;
};

int main()
{
	Creature Gosho("Gosho", 100, 50, 10);
	Orc Thral("Thral", 500, 60, 40, 10);
	Orc Garosh("Garosh", 200, 30, 300, 20);
	//Thral.attackTarget(Gosho);
	//Thral.attackTarget(Gosho);
	Garosh.attackTarget(Thral);


}
/*
Да се създаде клас Creature, който съдържа в себе си име на създание, живот, защита и атака. Също така трябва да се създадат класовете Orc и Elf, които наследяват класа Creature и добавят следната функционалност.

За класа Orc:

трябва да се добави поле сила, което ще добавя бонус
атака и живот на орка
За класа Elf:

трябва да се реализира метод за специален ефект върху атаката или защитата на елф
За всеки един от класовете трябва да се реализира голяма 4-ка(ако е нужно). Да се реализират операторите за изход и за сравнение.
*/