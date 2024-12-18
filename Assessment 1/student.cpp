#include "student.h"

student::student() {
     memset(name,0,MAX_CHARS + 1);
     gpa       = 0.0;
     gnum      = 0;
     enrolled  = false;
     tuition   = 0.0;
}

student::~student() {
     memset(name,0,MAX_CHARS + 1);
     gpa       = 0.0;
     gnum      = 0;
     enrolled  = false;
     tuition   = 0.0;
}

student::student(const student & source) : student::student()
{
     strcpy(name,source.name);
     gpa       = source.gpa;
     gnum      = source.gnum;
     enrolled  = source.enrolled;
     tuition   = source.tuition;
}
student & student::operator = (const student & source)
{
     if (this != &source) {
          memset(name,0,MAX_CHARS + 1);
          gpa       = 0.0;
          gnum      = 0;
          enrolled  = false;
          tuition   = 0.0;
          strcpy(name,source.name);
          gpa       = source.gpa;
          gnum      = source.gnum;
          enrolled  = source.enrolled;
          tuition   = source.tuition;
     }
     return *this;
}

void student:: getName(char names[]) const{
  strncpy(names, name, MAX_CHARS);
}

float student:: getGpa(float gpas){
  gpas = gpa;
  return gpas;
}
unsigned long int student:: getGnum(unsigned long int gnums){
  gnums = gnum;
  return gnums;
}
bool student:: getEnrolled(bool enroll){
  enroll = enrolled;
  return enroll;
}
double student:: getTuiton(double tuitons){
  tuitons = tuition;
  return tuitons;
}


