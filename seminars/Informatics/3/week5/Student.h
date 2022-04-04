#pragma once

#include <string>

enum FormOfEducation { redovno, zadochno };

const int gradesCount = 5;

class Student {
    std::string fn;
    std::string firstName;
    std::string lastName;
    double grades[gradesCount];
    FormOfEducation fe;

public:
    const std::string& getFN() const;
    void setFN(std::string newFN);
    void setFN(const std::string& newFN);

    bool isInformatics();

    double meanGrade();
    double maxGrade();

    friend class StudentReaderWriter;
};