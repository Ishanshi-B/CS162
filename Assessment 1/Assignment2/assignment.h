//*********************************
// File name: assignment.h
// Author: Ishanshi Bhardwaj
// Date: 7/16/2022
// Description: Declares the Assignment Class
// Input: None
// Output: None
// Sources: None
//*********************************

#pragma once
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_CHARS = 30;

// Creating the assignment class
class Assignment {

private:
  char name[MAX_CHARS + 1];
  int grade;
  float weight;
  char gnum[MAX_CHARS + 1];
  int assignmentsSize;

public:
  Assignment();
  ~Assignment();

  void SetName(char name_one[]);
  void SetGrade(int grade_one);
  void SetWeight(float weight_one);
  void SetGnum(char gnum_one[]);

  char *GetName();
  int GetGrade();
  float GetWeight();
  char *GetGnum();
};

