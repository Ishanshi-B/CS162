//*********************************
// File name: assignment.cpp
// Author: Ishanshi Bhardwaj
// Date: 7/16/2022
// Description: Defines the constructors and destructors of the assignment
// class. The mutators and assesors store in the assignments for each student.
// Input: None
// Output: None
// Sources: None
//*********************************
#include "assignment.h"

// Default Constructor
Assignment::Assignment() {
  memset(name, 0, MAX_CHARS + 1);
  grade = 0;
  weight = 0;
  memset(gnum, 0, MAX_CHARS + 1);
  assignmentsSize = 0;
}

// Default Destructor
Assignment::~Assignment() {
  memset(name, 0, MAX_CHARS + 1);
  grade = 0;
  weight = 0;
  memset(gnum, 0, MAX_CHARS + 1);
}

// setting the name
void Assignment::SetName(char name_one[]) { strcpy(name, name_one); }
// setting the grade
void Assignment::SetGrade(int grade_one) { grade = grade_one; }
// setting the weight
void Assignment::SetWeight(float weight_one) { weight = weight_one; }
// setting the gnum
void Assignment::SetGnum(char gnum_one[]) { strcpy(gnum, gnum_one); }

// getting the name (returning the name)
char *Assignment::GetName() { return name; }
// getting the grade (returning the grade)
int Assignment::GetGrade() { return grade; }
// getting the weight (returning the weight)
float Assignment::GetWeight() { return weight; }
// getting the gnum (returning the gnum)
char *Assignment::GetGnum() { return gnum; }

