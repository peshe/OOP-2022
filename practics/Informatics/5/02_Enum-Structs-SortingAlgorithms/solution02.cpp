#include<iostream>

using std::cin;
using std::cout;
using std::endl;

const size_t SIZE = 16;

struct Person {

    size_t years;
    char   name[SIZE];
};

struct Subject {

    float  mark;
    char   subjectName[SIZE];
    Person teacher;
};

struct Student {

    Subject subjects[SIZE];
    Person  personInfo;
    size_t  countOfSubjects;
    size_t  fn;
};

void swapPersons(Person& p1, Person& p2) {

    char tempName[SIZE] { '\0' };
    size_t len = strlen(p1.name);
    memcpy(tempName, p1.name, len + 1);
    
    size_t tempYears = p1.years;

    len = strlen(p2.name);
    memcpy(p1.name, p2.name, len + 1);
    p1.years = p2.years;

    len = strlen(tempName);
    memcpy(p2.name, tempName, len + 1);
    p2.years = tempYears;
}

void sortPersons(Person arr[], size_t size) {

    bool isSwap;

    for (size_t i = 0; i < size - 1; ++i) {

        isSwap = false;
        for (size_t j = 0; j < size - i - 1; ++j) {

            if (arr[j].years > arr[j + 1].years) {

                swapPersons(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap) {
            break;
        }
    }
}

void printPerson(const Person& p) {

    cout << p.name << "   " << p.years << "   ";
}

void swapSubjects(Subject& p1, Subject& p2) {

    swapPersons(p1.teacher, p2.teacher);

    char temp[SIZE];
    strcpy_s(temp, SIZE, p1.subjectName);
    float tempMark = p1.mark;

    strcpy_s(p1.subjectName, SIZE, p2.subjectName);
    p1.mark = p2.mark;

    strcpy_s(p2.subjectName, SIZE, temp);
    p2.mark = tempMark;
}

void sortSubjects(Subject arr[], size_t size) {

    bool isSwap;

    for (size_t i = 0; i < size - 1; ++i) {

        isSwap = false;
        for (size_t j = 0; j < size - i - 1; ++j) {

            if (arr[j].mark > arr[j + 1].mark) {

                swapSubjects(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap) {
            break;
        }
    }
}

void printSubject(const Subject& s) {

    printPerson(s.teacher);
    cout << s.mark << "  " << s.subjectName << endl;
}

void cpyPerson(Person& p1, const Person& p2) {

    p1.years = p2.years;

    size_t len = strlen(p2.name);
    memcpy(p1.name, p2.name, len + 1);
}

void cpySubject(Subject& s1, const Subject& s2) {

    s1.mark = s2.mark;
    cpyPerson(s1.teacher, s2.teacher);

    size_t len = strlen(s2.subjectName);
    memcpy(s1.subjectName, s2.subjectName, len + 1);
}

void cpyStudent(Student& s1, const Student& s2) {

    cpyPerson(s1.personInfo, s2.personInfo);

    s1.fn = s2.fn;

    s1.countOfSubjects = s2.countOfSubjects;

    for (size_t i = 0; i < s1.countOfSubjects; ++i) {
        cpySubject(s1.subjects[i], s2.subjects[i]);
    }
}

void swapStudent(Student& s1, Student& s2) {

    swapPersons(s1.personInfo, s2.personInfo);

    Student temp;
    temp.fn = s1.fn;
    temp.countOfSubjects = s1.countOfSubjects;

    Subject tempSubjects[SIZE];
    for (size_t i = 0; i < s2.countOfSubjects && i < SIZE; ++i) {
        cpySubject(tempSubjects[i], s2.subjects[i]);
    }


    s1.fn = s2.fn;
    s1.countOfSubjects = s2.countOfSubjects;
    for (size_t i = 0; i < s1.countOfSubjects && i < SIZE; ++i) {
        cpySubject(s1.subjects[i], s2.subjects[i]);
    }


    s2.fn = temp.fn;
    s2.countOfSubjects = temp.countOfSubjects;
    for (size_t i = 0; i < s2.countOfSubjects && i < SIZE; ++i) {
        cpySubject(s2.subjects[i], temp.subjects[i]);
    }
}

void sortStudentsFN(Student arr[], size_t size) {

    bool isSwap;

    for (size_t i = 0; i < size - 1; ++i) {

        isSwap = false;
        for (size_t j = 0; j < size - i - 1; ++j) {

            if (arr[j].fn < arr[j + 1].fn) {

                swapStudent(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap) {
            break;
        }
    }
}

void sortStudentsYears(Student arr[], size_t size) {

    bool isSwap;

    for (size_t i = 0; i < size - 1; ++i) {

        isSwap = false;
        for (size_t j = 0; j < size - i - 1; ++j) {

            if (arr[j].personInfo.years < arr[j + 1].personInfo.years) {

                swapStudent(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap) {
            break;
        }
    }
}

void printStudent(const Student& s) {

    printPerson(s.personInfo);

    cout << endl;

    cout << "Faculty number:" << s.fn << "  " << "Counts of subjects:" << s.countOfSubjects << endl;

    for (size_t i = 0; i < s.countOfSubjects; ++i) {
        printSubject(s.subjects[i]);
    }
}

int main() {

    const size_t MAX = 6;

    Person arr[MAX] = { { 27, "Ivan" }, { 34, "Pesho" }, { 45, "Asen" }, { 17, "Ivanka" }, { 21, "Lily" }, { 47, "Poly" } };

    sortPersons(arr, MAX);

    for (size_t i = 0; i < MAX; ++i) {
        printPerson(arr[i]);
    }
    cout << endl;

    //****************************************************************************************************************************
    Subject sub1{ 3.55, "Biogoly", arr[0] };
    Subject sub2{ 5.45, "Mathematic", arr[1] };
    Subject sub3{ 4.35, "Mathematic", arr[2] };
    Subject sub4{ 5.45, "Biogoly", arr[3] };
    Subject sub5{ 3.30, "Mathematic", arr[4] };
    Subject sub6{ 2.45, "Biogoly", arr[5] };

    Subject subs[MAX]; 

    cpySubject(subs[0], sub1);
    cpySubject(subs[1], sub2);
    cpySubject(subs[2], sub3);
    cpySubject(subs[3], sub4);
    cpySubject(subs[4], sub5);
    cpySubject(subs[5], sub6);

    sortSubjects(subs, MAX);

    for (size_t i = 0; i < MAX; ++i) {
        printSubject(subs[i]);
    }
    cout << endl;

   //****************************************************************************************************************************
    const size_t CAPACITY = 2;

    Student students[CAPACITY];

    students[0].fn = 47645;
    students[0].countOfSubjects = 6;

    cpyPerson(students[0].personInfo, arr[1]);

    cpySubject(students[0].subjects[0], sub1);
    cpySubject(students[0].subjects[1], sub3);
    cpySubject(students[0].subjects[2], sub5);
    cpySubject(students[0].subjects[3], sub2);
    cpySubject(students[0].subjects[4], sub6);
    cpySubject(students[0].subjects[5], sub4);


    students[1].fn = 37221;
    students[1].countOfSubjects = 6;

    cpyPerson(students[1].personInfo, arr[3]);

    cpySubject(students[1].subjects[4], sub3);
    cpySubject(students[1].subjects[5], sub4);
    cpySubject(students[1].subjects[2], sub5);
    cpySubject(students[1].subjects[1], sub1);
    cpySubject(students[1].subjects[3], sub6);
    cpySubject(students[1].subjects[0], sub2);

    sortStudentsFN(students, CAPACITY);

    for (size_t i = 0; i < CAPACITY; ++i) {
        printStudent(students[i]);
        cout << endl;
    }
    

    sortStudentsYears(students, CAPACITY);

    for (size_t i = 0; i < CAPACITY; ++i) {
        printStudent(students[i]);
        cout << endl;
    }

    return 0;
}
