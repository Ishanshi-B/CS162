#pragma once
#include <iostream>
#include <cstring>
#include "main.h"
#include "data.h"

const int MAX_CHARS = 30;
class     student
{
     private:
     char                name[MAX_CHARS + 1];
     float               gpa;
     unsigned long int   gnum;
     bool                enrolled;
     double              tuition;
    data result[MAX_CHARS +1];

     public:
     student();
     ~student();
     student(const student &);
     student & operator = (const student &);

    void getName(char names[]) const;
    float getGpa(float gpas);
    unsigned long int getGnum(unsigned long int gnums);
    bool getEnrolled(bool enroll);
    double getTuiton(double tuitons);





};


