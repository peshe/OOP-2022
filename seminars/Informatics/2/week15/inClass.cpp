#include <iostream>
#include <cassert>
#include "String.h"

bool isUpper(char c) {
	return 'A' <= c && c <= 'Z';
}

bool isDigit(char c) {
	return '0' <= c && c <= '9';
}

class Article {
private:
	String authors[10];
	std::size_t authorsSize;
	String title;
public:
	Article(String* authors, std::size_t authorsSize, const String& title) {
		if (authorsSize < 1 || authorsSize > 10) {
			throw "Authors must be between 1 and 10.";
		}
		for (std::size_t i = 0; i < authorsSize; ++i) {
			this->authors[i] = authors[i];
		}
		if (title.getLen() == 0) {
			throw "Title cannot be empty.";
		}
		this->title = title;
		this->authorsSize = authorsSize;
	}
	virtual Article* clone() const {
		return new Article(*this);
	}
};

class Report: public Article {
private:
	String reporter;
	String number;
	unsigned int duration;
public:
	Report(String* authors,
		std::size_t authorsSize,
		const String& title,
		const String& reporter,
		const String& number,
		unsigned durationInMinutes)
		:Article(authors, authorsSize, title)
	{
		size_t i = 0;
		for(;i<authorsSize;++i) {
			if(authors[i]==reporter) {
				this->reporter = reporter;
				break;
			}
		}
		if(i==authorsSize)
		{
			throw "Reporter not part of authors!";
		}
		if (number.getLen() != 4) {
			throw "number must be 4 characters";
		}
		for(i=0; i<3;++i)
		{
			if(isUpper(number[i]) == false)
			{
				throw "not to format";
			}
		}
		if(isDigit(number[3]) && number[3] != '0')
		{
			this->number = number;
		}
		if (durationInMinutes > 60)
		{
			throw "over max minutes";
		}
		duration = durationInMinutes;
	}
	virtual Report* clone() const override {
		return new Report(*this);
	}
};

class Poster : public Article {
private:
	struct Format {
		enum PresentationStyle { onPaper, projected };
		enum Orientation { portrait, landscape };
		enum ColorSpectrum { color, monochrome };

		PresentationStyle presentationStyle;
		Orientation orientation;
		ColorSpectrum colorSpectrum;
	};

	Format format;
	String date;
public:
	Poster(String* authors,
		std::size_t authorsSize,
		const String& title,
		Format format,
		const String& date)
		: Article(authors, authorsSize, title) {
		this->format = format;

		if (date.getLen() != 8) { // More validations needed
			throw "Invalid date.";
		}
		this->date = date;
	}
	/*virtual*/ Poster* clone() const {
		return new Poster(*this);
	}
};

class Session {
private:
	String name;
	String date;
	Article** articles;
	std::size_t size, capacity;
	unsigned int maxDurationInHours;

	void copy(const Session& other) {
		/*for () {
			this->articles[i] = other.articles[i]->clone();
		}*/
	}
public:
	static const unsigned int MAX_HOURS = 14;

	Session(const String& name, const String& date, unsigned int maxDurationInHours) {
		this->name = name;
		if (date.getLen() != 8) { // More validations needed
			throw "Invalid date.";
		}
		this->date = date;
		if (maxDurationInHours > Session::MAX_HOURS) {
			throw "Session cannot be that long";
		}
		this->maxDurationInHours = maxDurationInHours;
		this->size = 0;
		this->capacity = 8;
		this->articles = new Article * [this->capacity];
	}
	Session(const Session& other) {
		copy(other);
	}
	unsigned int maxDurationInMinutes() const {
		return maxDurationInHours * 60;
	}
	void add(Report& report)
	{

	}
	void add(Poster& poster) {

	}

};

int main() {
}
/*
Всяка сесия на конференцията се характеризира с:

име – точно 3 символа, главни латински букви (от A до Z);
дата на провеждане – символен низ с дължина точно 8, записан във формат “yyyymmdd”;
масив от доклади и постери, които ще бъдат представени по време на сесията;
максимална продължителност на сесията в часове (не може да надхвърля 14 часа).
За сесия в конференцията да се дефинират следните функционалности:

включване на доклад или постер в сесията. 

Ако е подаден доклад, той може да бъде представен в сесията само, 
ако в номера на доклада се съдържа името на сесията и в сесията за деня има достатъчно време за доклада. 
Ако условието е изпълнено, докладът се записва в масива от доклади и постери на сесията.

Ако е подаден постер, той може да бъде добавен в сесията само, ако датата на неговото представяне съвпада с датата на сесията. Масивът от доклади и постери се поддържа сортиран. Първи в масива са постерите. Те са подредени лексикографски по заглавието на постера. След тях са подредени докладите, като наредбата между тях е по дължината на представянето им;
определяне на броя на докладите и постерите, които са включени в сесията;
по подаден начален час на сесията да се генерира график за нея – символен низ, който включва заглавията, авторите и времето на представяне на всички статии, включени в сесията. За постерите това е цялото време на сесията (от началото до края, определен според максималната продължителност), за докладите – начално и крайно време за всеки доклад, като не се допуска два доклада да се застъпват. Освен това, трябва да има по минимум 5 минути пауза между два доклада и да се предвиди поне един час обедна почивка (в интервала между 11 и 15 часа).
Покажете работата на всеки от класовете си с кратък код в main или друга тестова функция.


Пролетната научна конференция на ФМИ се провежда в рамките на три последователни дни. 
В нея са включени предварително одобрени статии, които се представят като доклади или постери.

Всяка статия се характеризира с:

автори – масив от символни низове. Броят на авторите не нахвърля 10 и задължително има поне един;
заглавие – непразен символен низ с произволна дължина.

Докладът е статия, която се представя устно от един от авторите. Всеки доклад се характеризира с:

докладващ – символен низ с произволна дължина. Докладващият задължително е един от авторите.
номер на доклад – символен низ с дължина точно 4 символа, първите три от които са главни латински букви (от A до Z), съответстващи на името на сесията, в която ще бъде представен докладът, последвани от една цифра (от 1 до 9). Например “IFS2”;
продължителност на доклада в минути. Не може да надхвърля един час.

Постерите са статии, които не се представят устно, а са изложени и достъпни през цялата сесия, 
в която са включени. 

Всеки постер се характеризира с:

формат – множество от булеви стойности – дали е на хартия или се прожектира, 
дали е портретен или пейзажен (portrait, landscape), дали е цветен или монохромен;
дата на представяне – символен низ с дължина точно 8 символа, записан във формат “yyyymmdd“.

*/
