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
?????????? ?????????? ???? ?????????????????????????? ???? ?????????????????????????? ??:

?????? ??? ?????????? 3 ??????????????, ???????????? ???????????????? ?????????? (???? A ???? Z);
???????? ???? ???????????????????? ??? ???????????????? ?????? ?? ?????????????? ?????????? 8, ?????????????? ?????? ???????????? ???yyyymmdd???;
?????????? ???? ?????????????? ?? ??????????????, ?????????? ???? ?????????? ?????????????????????? ???? ?????????? ???? ??????????????;
???????????????????? ?????????????????????????????? ???? ?????????????? ?? ???????????? (???? ???????? ???? ?????????????????? 14 ????????).
???? ?????????? ?? ?????????????????????????? ???? ???? ?????????????????? ???????????????? ??????????????????????????????:

?????????????????? ???? ???????????? ?????? ???????????? ?? ??????????????. 

?????? ?? ?????????????? ????????????, ?????? ???????? ???? ???????? ???????????????????? ?? ?????????????? ????????, 
?????? ?? ???????????? ???? ?????????????? ???? ?????????????? ?????????? ???? ?????????????? ?? ?? ?????????????? ???? ???????? ?????? ???????????????????? ?????????? ???? ??????????????. 
?????? ?????????????????? ?? ??????????????????, ???????????????? ???? ?????????????? ?? ???????????? ???? ?????????????? ?? ?????????????? ???? ??????????????.

?????? ?? ?????????????? ????????????, ?????? ???????? ???? ???????? ?????????????? ?? ?????????????? ????????, ?????? ???????????? ???? ???????????????? ?????????????????????? ?????????????? ?? ???????????? ???? ??????????????. ?????????????? ???? ?????????????? ?? ?????????????? ???? ???????????????? ????????????????. ?????????? ?? ???????????? ???? ??????????????????. ???? ???? ?????????????????? ???????????????????????????? ???? ???????????????????? ???? ??????????????. ???????? ?????? ???? ?????????????????? ??????????????????, ???????? ?????????????????? ?????????? ?????? ?? ???? ?????????????????? ???? ?????????????????????????? ????;
???????????????????? ???? ???????? ???? ?????????????????? ?? ??????????????????, ?????????? ???? ???????????????? ?? ??????????????;
???? ?????????????? ?????????????? ?????? ???? ?????????????? ???? ???? ???????????????? ???????????? ???? ?????? ??? ???????????????? ??????, ?????????? ?????????????? ????????????????????, ???????????????? ?? ?????????????? ???? ?????????????????????? ???? ???????????? ????????????, ???????????????? ?? ??????????????. ???? ?????????????????? ???????? ?? ???????????? ?????????? ???? ?????????????? (???? ???????????????? ???? ????????, ?????????????????? ???????????? ???????????????????????? ??????????????????????????????), ???? ?????????????????? ??? ?????????????? ?? ???????????? ?????????? ???? ?????????? ????????????, ???????? ???? ???? ?????????????? ?????? ?????????????? ???? ???? ??????????????????. ?????????? ????????, ???????????? ???? ?????? ???? ?????????????? 5 ???????????? ?????????? ?????????? ?????? ?????????????? ?? ???? ???? ???????????????? ???????? ???????? ?????? ???????????? ?????????????? (?? ?????????????????? ?????????? 11 ?? 15 ????????).
???????????????? ???????????????? ???? ?????????? ???? ?????????????????? ???? ?? ???????????? ?????? ?? main ?????? ?????????? ?????????????? ??????????????.


???????????????????? ???????????? ?????????????????????? ???? ?????? ???? ???????????????? ?? ?????????????? ???? ?????? ???????????????????????????? ??????. 
?? ?????? ???? ???????????????? ?????????????????????????? ???????????????? ????????????, ?????????? ???? ???????????????????? ???????? ?????????????? ?????? ??????????????.

?????????? ???????????? ???? ?????????????????????????? ??:

???????????? ??? ?????????? ???? ???????????????? ????????????. ?????????? ???? ???????????????? ???? ???????????????? 10 ?? ???????????????????????? ?????? ???????? ????????;
???????????????? ??? ???????????????? ???????????????? ?????? ?? ???????????????????? ??????????????.

???????????????? ?? ????????????, ?????????? ???? ?????????????????? ?????????? ???? ???????? ???? ????????????????. ?????????? ???????????? ???? ?????????????????????????? ??:

?????????????????? ??? ???????????????? ?????? ?? ???????????????????? ??????????????. ???????????????????????? ???????????????????????? ?? ???????? ???? ????????????????.
?????????? ???? ???????????? ??? ???????????????? ?????? ?? ?????????????? ?????????? 4 ??????????????, ?????????????? ?????? ???? ?????????? ???? ???????????? ???????????????? ?????????? (???? A ???? Z), ?????????????????????????? ???? ?????????? ???? ??????????????, ?? ?????????? ???? ???????? ???????????????????? ????????????????, ???????????????????? ???? ???????? ?????????? (???? 1 ???? 9). ???????????????? ???IFS2???;
?????????????????????????????? ???? ?????????????? ?? ????????????. ???? ???????? ???? ?????????????????? ???????? ??????.

?????????????????? ???? ????????????, ?????????? ???? ???? ???????????????????? ??????????, ?? ???? ???????????????? ?? ???????????????? ???????? ???????????? ??????????, 
?? ?????????? ???? ????????????????. 

?????????? ???????????? ???? ?????????????????????????? ??:

???????????? ??? ?????????????????? ???? ???????????? ?????????????????? ??? ???????? ?? ???? ???????????? ?????? ???? ????????????????????, 
???????? ?? ?????????????????? ?????? ???????????????? (portrait, landscape), ???????? ?? ???????????? ?????? ????????????????????;
???????? ???? ?????????????????????? ??? ???????????????? ?????? ?? ?????????????? ?????????? 8 ??????????????, ?????????????? ?????? ???????????? ???yyyymmdd???.

*/
