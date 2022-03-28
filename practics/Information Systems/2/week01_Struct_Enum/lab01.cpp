#include <iostream>

enum Subject {
  UNKNOWN = -1,	
	ALGEBRA,
  DISKRETNI,
  DIS1,
  UP,
  SUBJECT_COUNT
};

struct Student{
  char name[24];
  char egn[10];
  int facultyNumber;
  double grades[Subject::SUBJECT_COUNT];
  Subject favorite;
};

struct Classroom{
  Student students[20];
  int studentsCount;
};

int _minTotalGradeIndex(const double* gradesTotals);

Subject getHardestSubject(const Classroom& classroom);

void printSubject(Subject subject);

void setFavoriteSub(Student& student);

void initialize(Student& stud);

void print(const Student& s);

void printAverageMarks(const Student* students, size_t count); 

const Student& getBestStudent(const Student* students, size_t count);


int main() {
  
    Student arr[3];
  
    for (int i = 0; i < 3; i++)
    { 
        std::cout << "Enter " << i << "-th student\n";
        initialize(arr[i]);
	  }
	printAverageMarks(arr, 3);
  
  Student theBest = getBestStudent(arr, 3);
  Classroom fmi;
  fmi.studentsCount = 3;
  
  for (int i = 0; i < fmi.studentsCount; i++) {
    fmi.students[i] = arr[i];
  }

  return 0;
}

int _minTotalGradeIndex(const double* gradesTotals)
{
  int minIndex = 0;
  double minValue = gradesTotals[0];
  
  for (int i = 1; i < Subject::SUBJECT_COUNT; i++)
  {
    if (gradesTotals[i] < minValue)
    {
      minValue = gradesTotals[i];
      minIndex = i;
    }
  }
  
  return minIndex;
}

Subject getHardestSubject(const Classroom& classroom)
{
  double gradesTotals[Subject::SUBJECT_COUNT];
  
  for (int i = 0; i < Subject::SUBJECT_COUNT; i++)
  {
    for (int j = 0; j < classroom.studentsCount; j++)
    {
      gradesTotals[i] += classroom.students[j].grades[i];
    }
  }
  
  int minIndex = _minTotalGradeIndex(gradesTotals);
  
  return (Subject)minIndex;
}

void printSubject(Subject subject)
{
  switch (subject) {
    case 0:
      std::cout << "Algebra" << std::endl;
      break;
    case 1:
      std::cout << "DISKRETNI" << std::endl;
      break;
    case 2:
      std::cout << "DIS1" << std::endl;
      break;
    case 3:
      std::cout << "UP" << std::endl;
      break;
    default:
      std::cout << "Unknown" << std::endl;
      break;
  }
}

void setFavoriteSub(Student& student){
  int subject;
  std::cin >> subject;
  
  
  switch (subject){
    case 0:
      student.favorite = Subject::ALGEBRA;
      break;
    case 1:
      student.favorite = Subject::DISKRETNI;
      break;
    case 2:
      student.favorite = Subject::DIS1;
      break;
    case 3:
      student.favorite = Subject::UP;
      break;
    default:
      std::cout << "No such subject";
      break;
  }
}

void initialize(Student& stud) {
  std::cin>>stud.name;
  std::cin>>stud.egn;
  std::cin>>stud.facultyNumber;
  std::cout << "Enter grades:\n";
  for(int i = 0; i < 4; i++){
    std::cin>>stud.grades[i];
  }
  
  setFavoriteSub(stud);
}

void print(const Student& s) {
  
  std::cout<< "Name: " << s.name << '\n';
  std::cout<< "EGN: " << s.egn << '\n';
  std::cout<< "Faculty Number: " << s.facultyNumber << '\n';
  for (int i = 0; i < 4; i++) {
    
    std::cout<< "Grades: " << s.grades[i] << '\n';
  }
}

void printAverageMarks(const Student* students, size_t count)
{
  int sum = 0;
  double average;
  for (int i = 0; i < count; i++)
  { 
    sum = 0;
    for (int j = 0; j < 4; j++)
    {
     	sum += students[i].grades[j];
      
		}
  	average = sum / 4.0;
    std::cout << average << " " << std:: endl; 
	}
}

double average(const Student& student){
  
  int sum = 0;
  for(int i = 0; i < 4; i++){
    
    sum += student.grades[i]; 
  }
  
  return (sum/4.0);
  
}

const Student& getBestStudent(const Student* students, size_t count) {
  
  double best = 0;
  int index;
  
  for(int i = 0; i < count; i++){
    
      if(best < average(students[i])){
        
        best = average(students[i]);
        index = i;
      }  
  }
  
  return students[index];
}