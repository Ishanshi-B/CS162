#pragma once
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
#define MAX_SUBMISSIONS 10
#include "assignment.h"

class Student {
private:
  char name[MAX_CHARS + 1];
  char gnum[MAX_CHARS + 1];
  char grade;
  Assignment submissions[MAX_SUBMISSIONS];
  int size, capacity;

public:
  Student(); // default constructor

  //(const Student & old); // copy constructor
  // Student & operator =(const Student & old ); // assignment operator

  ~Student(); // destructor

  void setName(char val[]);
  void setGnum(char value[]);
  void setSize(int v);
  void setCapacity(int va);

  char *getName();
  char *getGnum();
  char getGrade();
  int getSize();
  int getCapacity();

  Assignment getSubmission(int assign);
  void addSubmission(Assignment submissions);

  void removeit(int ans);
};
void input(ifstream &file, char str3[30], char str4[30], char str5[30]);
void load(Student roster[], int &sizes, int &capacities);
void display(Student roster[], int sizes);
void gpa(Student roster[], int sizes);
void grade(Student roster[], int sizes);
void pct(Student roster[], int sizes);
void remove(Student roster[], int &sizes);
void add(Student roster[], int &sizes, int capacities);

