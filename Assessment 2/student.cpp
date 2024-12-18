#include "student.h"

// Destructor
student::~student() 
{
// *** TASK 1: Implement The Destructor HERE
if(name){

delete [] name;
name = NULL;
}
if(gpa){
delete []gpa;
gpa = NULL;
}
if(enrolled){
delete [] enrolled;
enrolled = NULL;

}
if(tuition){
delete []tuition;
tuition = NULL;
}
//name = nulilptr;
//delete gpa;
//gpa = 0;
//delete enrolled;
//enrolled = 0;
//delete tuition;
//tuition=0;
//credits = 0;
}

// Copy Assignment
student & student::operator = (const student & source)
{
// *** TASK 2: Implement The Copy Assignment Operator HERE
if(this == &source){
	return *this;
}
else{
delete [] name;
name = new char[strlen(source.name)+1];
delete [] gpa;
gpa = new char[strlen(source.gpa)+1];
delete [] enrolled;
enrolled = new char[strlen(source.enrolled)+1];
delete [] tuition;
tuition = new char[strlen(source.tuition)+1];
credits = source.credits;

strcpy(name, source.name);
strcpy(gpa, source.gpa);
strcpy(enrolled, source.enrolled);
strcpy(tuition, source.tuition);
//this->strcpy(name, source.name);
//this->gpa = source.gpa;
//this->enrolled = source.enrolled;
//this->tuition = source.tuition;
//this->credits = source.credits;
return *this;
}
}

// *** DO NOT CHANGE CODE AFTER THIS LINE ***

// Default Constructor
student::student() {
	name      = nullptr;
	gpa       = nullptr;
	enrolled  = nullptr;
	tuition   = nullptr;
	credits   = 0.0f;
}

// Parameter Constructor
student::student(const char * name, const char * gpa, const char * enrolled, const char * tuition, double credits) : student::student()
{
	this->name          = new char[strlen(name) + 1]{0};
	strcpy(this->name,name);
	this->gpa          = new char[strlen(gpa) + 1]{0};
	strcpy(this->gpa,gpa);
	this->enrolled          = new char[strlen(enrolled) + 1]{0};
	strcpy(this->enrolled,enrolled);
	this->tuition          = new char[strlen(tuition) + 1]{0};
	strcpy(this->tuition,tuition);
	this->credits       = credits;
}

// Stream Insertion
std::ostream & operator << (std::ostream & out, const student & source)
{
	out  <<  "Name: " << source.name << " "
		<<  "GPA: " <<  source.gpa << " "
		<< "Enrolled: " << source.enrolled << " "
		<< "Tuition: " << source.tuition << " "
		<< "Credits: ";
	out << static_cast<int>(static_cast<int>(source.credits * 100.00) / 100);
	out << ".";
	if (static_cast<int>(static_cast<int>(source.credits * 100.00) % 100) < 10)
		out << "0";
	out << static_cast<int>(static_cast<int>(source.credits * 100.00) % 100);
	return out;
}
