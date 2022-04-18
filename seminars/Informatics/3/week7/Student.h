#pragma once

#include <string>

enum FormOfEducation { redovno, zadochno };

const int gradesCount = 5;

class Student {
private:
    char* fn;
    char* firstName;
    char* lastName;
    double grades[gradesCount];
    FormOfEducation fe;

    void clean();
    void copy(const Student& other, bool withClean = true);
public:
    Student(const char* fn = "",
            const char* firstName = "",
            const char* lastName = "",
            double grades[gradesCount] = nullptr,
            FormOfEducation fe = redovno);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    const char* getFN() const;
    void setFN(const char* newFN);

    const char* getFirstName() const;
    void setFirstName(const char* newFN);

    const char* getLastName() const;
    void setLastName(const char* newFN);

    bool isInformatics();

    double meanGrade();
    double maxGrade();

    friend class StudentReaderWriter;
};