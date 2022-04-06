#ifndef RECORDH
#define RECORDH

class Record
{
private:
	char* word;
	char* meaning;

	void copy(const Record& other);

	void destroy();

public:

	Record();

	Record(const Record& other);

	Record(const char* word, const char* meaning);

	Record& operator=(const Record& other);

	~Record();

	void setWord(const char* word);

	void setMeaning(const char* meaning);

	char* getWord() const;

	char* getMeaning() const;

	void printWord();
};

#endif // !RECORDH