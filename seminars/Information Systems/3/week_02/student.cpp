#include <iostream>
#include <fstream>
#include <cstring>

struct Student {
    int fn;
    char name[100];
    double grade;
};

void writeStudents(Student students[], std::ofstream& out) {
    for (int i = 0; i < 3; i++) {
        out << students[i].fn << " ";
        out << students[i].name << '\n';
        out << students[i].grade << '\n';
    }    
}

int main() {
    Student nasko;
    nasko.fn = 71937;
    nasko.grade = 5.50;
    strcpy(nasko.name, "Nasko");

    Student nasko2;
    nasko2.fn = 71607;
    nasko2.grade = 5.70;
    strcpy(nasko2.name, "Nasko2");

    Student nasko3;
    nasko3.fn = 72937;
    nasko3.grade = 5.20;
    strcpy(nasko3.name, "Nasko3");

    Student students[] = {nasko, nasko2, nasko3};
    std::ofstream out;
    out.open("students.txt");
    writeStudents(students, out);

    out.close();

    // std::fstream file;
    // file.open("students.txt", std::ios::out);
}