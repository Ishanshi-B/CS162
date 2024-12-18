#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace std;

const int MAX_CHARS = 100;
struct student {
    char name[MAX_CHARS + 1];
    char gnum[MAX_CHARS + 1];
    char grade[MAX_CHARS + 1];
};

//declare the functions
student init_student();
void input(ifstream & file, char str3[30]);

void load(ifstream & file, student roster[], int &size, int &capacity);
void display(student roster[], int size);
void gpa(student roster[], int size);
void pct(student roster[], int size);

