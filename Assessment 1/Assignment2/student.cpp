//*********************************
// File name: student.cpp
// Author: Ishanshi Bhardwaj
// Date: 7/16/2022
// Description: The program is a collection of all the functions that are needed
// to show the desired output for the option picked from main.cpp Input: The user
// puts in the option in main.cpp and the functions as per their choice are
// supposed to output the result Output: The user is allowed to see the contents
// of the file, the average gpa, the total completion rate, the passing rate, the
// failing rate, and the audit rate Sources: None
//*********************************

#include "student.h"

// Default Constructor
Student::Student() {

  memset(name, 0, MAX_CHARS + 1);
  memset(gnum, 0, MAX_CHARS + 1);
  grade = 0;
  size = 0;
  capacity = MAX_SUBMISSIONS;
};

// setting the name
void Student::setName(char val[]) { strcpy(name, val); }
// setting the gnum
void Student::setGnum(char value[]) { strcpy(gnum, value); }
// setting the size
void Student::setSize(int v) { size = v; }
// setting the capacity
void Student::setCapacity(int va) { capacity = va; }

// getting the name
char *Student::getName() { return name; }
// getting the gnum
char *Student::getGnum() { return gnum; }

// Takes the assignment weight and grades and calculates the Final Grade
char Student::getGrade() {
  float grades = 0;
  for (int i = 0; i < size; i++) {
    grades += submissions[i].GetGrade() * submissions[i].GetWeight();
  }
  if (grades >= 3.4) {
    grade = 'A';
  } else if (grades >= 2.8 && grades < 3.4) {
    grade = 'B';
  } else if (grades >= 2.0 && grades < 2.8) {
    grade = 'C';
  } else if (grades >= 1.2 && grades < 2.0) {
    grade = 'D';
  } else if (grades < 1.2) {
    grade = 'F';
  }
  return grade;
}

// getting size
int Student::getSize() { return size; }
// getting capacity
int Student::getCapacity() { return capacity; }
// returns each assignment in submissions
Assignment Student::getSubmission(int assign) { return submissions[assign]; }

// this removes the submissions
void Student::removeit(int ind) {
  int i = 0;
  for (i = ind; i < size; ++i) {
    submissions[i] = submissions[i + 1];
  }
  size--;
}

// this adds an assignment to the submissions
void Student::addSubmission(Assignment submissions) {

  this->submissions[size] = submissions;
  ++size;
}

// Destructor
Student::~Student() {
  memset(name, 0, MAX_CHARS + 1);
  memset(gnum, 0, MAX_CHARS + 1);
  grade = 0;
  size = 0;
  capacity = MAX_SUBMISSIONS;
}

// Input functions takes in the user input files
void input(ifstream &file, char str3[30], char str4[30], char str5[30]) {

  char str[30];
  char str2[30];
  char str6[30];

  // asking for file name
  cout << "Enter file name of G-Number  file of up to 30 characters: ";
  cin.getline(str, 30);
  strcpy(str3, str);

  cout << "Enter file name of student name file of up to 30 characters: ";
  cin.getline(str2, 30);
  strcpy(str4, str2);

  cout << "Enter file name of student assignment file of up to 30 characters: ";
  cin.getline(str6, 30);
  strcpy(str5, str6);
}

// The functions loads the content of the file and stores it
void load(Student roster[], int &sizes, int &capacitys) {

  char tempName[MAX_CHARS + 1];
  char tempGnum[MAX_CHARS + 1];
  char tempGnums[MAX_CHARS + 1];
  char tempGnumss[MAX_CHARS + 1];
  char tempNames[MAX_CHARS + 1];
  double tempGrades = 0.0;
  double tempWeight = 0;
  ifstream file;

  char str[30];
  char str2[30];
  char str3[30];
  Assignment tempSub;

  // begin storing the file data
  
    input(file, str, str2, str3);
    file.open(str);
   
  while (!file.eof() && sizes < capacitys) {
    if (file.good() != true || file.eof() == true)
      continue;
    file.getline(tempGnum, MAX_CHARS, '\n');
    roster[sizes].setGnum(tempGnum);
    if(file.good() != true || file.eof() == true) continue;
    ++sizes;
    
  }

  file.close();

  file.open(str2);

  while (!file.eof() && sizes < capacitys) {

    if (file.good() != true || file.eof() == true)
      continue;
    file.getline(tempName, MAX_CHARS, ',');
    if (file.good() != true || file.eof() == true)
      continue;
    file.getline(tempGnums, MAX_CHARS, '\n');

    for (int i = 0; i < sizes; i++) {
      if (strcmp(roster[i].getGnum(), tempGnums) == 0) {
        roster[i].setName(tempName);
      }
    }
  }
  file.close();

  file.open(str3);

  while (!file.eof() && sizes < capacitys) {
    // gnum
    //  name
    // grade
    // weight

    if (file.good() != true || file.eof() == true)
      continue;

    file.getline(tempGnumss, MAX_CHARS, ',');

    if (file.good() != true || file.eof() == true)
      continue;

    file.getline(tempNames, MAX_CHARS, ',');

    if (file.good() != true || file.eof() == true)
      continue;
    file >> tempGrades;

    file.ignore(1, ',');

    if (file.good() != true || file.eof() == true)
      continue;
    file >> tempWeight;
    file.ignore(1, '\n');

    tempSub.SetGnum(tempGnumss);
    tempSub.SetGrade(tempGrades);
    tempSub.SetName(tempNames);
    tempSub.SetWeight(tempWeight);

    for (int i = 0; i < sizes; i++) {
      if (strcmp(roster[i].getGnum(), tempGnumss) == 0) {
        roster[i].addSubmission(tempSub);
      }
    }
  }

  file.close();
}

// This functions displays the content that has been saved
void display(Student roster[], int sizes) {
  int counter = 0;
  Assignment temp;

  for (int i = 0; i < sizes; i++) {
    double finalGrade = 0;

    // print the statements
    cout.width(4);
    cout << counter << ". ";
    cout << roster[i].getGnum() << " " << roster[i].getName();
    cout << endl;

    for (int j = 0; j < roster[i].getSize(); j++) {
      cout << "    " << roster[i].getSubmission(j).GetName() << "   ";
      cout << "    " << roster[i].getSubmission(j).GetGrade() << "   ";
      cout << " (" << (roster[i].getSubmission(j).GetWeight() * 100) << "%) ";
      cout << endl;
    }
    cout << "Final Grade: " << roster[i].getGrade();
    cout << endl;
    ++counter;
  }
}

// The functions finds the average gpa and prints it
void gpa(Student roster[], int sizes) {

  float gpa_counter = 0;
  char grade = 'A';

  for (int i = 0; i < sizes; i++) {
    // setting the values of get grade
    grade = roster[i].getGrade();

    if (grade == 'A') {
      gpa_counter = gpa_counter + 4;
    } else if (grade == 'B') {
      gpa_counter = gpa_counter + 3;
    } else if (grade == 'C') {
      gpa_counter = gpa_counter + 2;
    } else if (grade == 'D') {
      gpa_counter = gpa_counter + 1;
    } else {
      gpa_counter = gpa_counter + 0;
    }
  }
  cout << fixed << showpoint;
  cout.precision(2);
 // cout << gpa_counter;
  gpa_counter = gpa_counter / (float)sizes;
  cout << "Average GPA for " << sizes << " students is " << gpa_counter << "."
       << endl;
  cout << endl;
}

// The function asks for roster and size to display the total completitions,
// passing students, not passing students, audit students
void pct(Student roster[], int sizes) {
  // result shows the percentage
  int result = 100;
  int completion = 0;
  int passing = 0;
  int no_pass = 0;
  int audit = 0;
  char grade = 'A';

  cout << endl;
  cout << "Total Students: " << sizes << " (" << result << "%)" << endl;

  for (int i = 0; i < sizes; i++) {
    grade = roster[i].getGrade();
    // compare the strings to see the grade

    if (grade == 'A') {
      completion = completion + 1;
      passing = passing + 1;
    } else if (grade == 'B') {
      completion = completion + 1;
      passing = passing + 1;
    } else if (grade == 'C') {
      completion = completion + 1;
      passing = passing + 1;
    } else if (grade == 'D') {
      completion = completion + 1;
      no_pass = no_pass + 1;
    } else if (grade == 'P') {
      completion = completion + 1;
      passing = passing + 1;
    } else if (grade == 'F') {
      completion = completion + 1;
      no_pass = no_pass + 1;
    }
    // the precent values being calculated
  }
  float new_result = ((float)completion / (float)sizes) * 100;
  float new_passing = ((float)passing / (float)sizes) * 100;
  float new_failing = ((float)no_pass / (float)sizes) * 100;
  float new_audit = ((float)audit / (float)sizes) * 100;

  cout << fixed << showpoint;
  cout.precision(2);

  cout << "Total Completions: " << completion << " (" << new_result << "%)"
       << endl;
  cout << "Passing Grades: " << passing << " (" << new_passing << "%)" << endl;
  cout << "Non-Passing Grades: " << no_pass << " (" << new_failing << "%)"
       << endl;
  cout << "AUD Grades: " << audit << " (" << new_audit << "%)" << endl;
  cout << endl;
}

// The function finds the Grade as per the student's name or G-Number
void grade(Student roster[], int sizes) {

  char answer[MAX_CHARS + 1];
  Assignment temp;
  cout << "Enter Student Name or Student G-Number: ";

  cin.getline(answer, MAX_CHARS);

  if (answer[0] == 'G' || answer[1] == 0) {

    int counter = 0;
    Assignment temp;
    float grades = 0;
    cout << endl;

    for (int i = 0; i < sizes; i++) {
      double finalGrade = 0;
      if (strcmp(roster[i].getGnum(), answer) == 0) {

        // print the statements
        cout.width(4);
        cout << counter << ". ";
        cout << roster[i].getGnum() << " " << roster[i].getName() << " ";
        cout << "Final Grade: " << roster[i].getGrade();
        cout << endl;

        // Prints the name, weight, score, and contribution of each assignment
        for (int j = 0; j < roster[i].getSize(); j++) {
          cout << "     ";
          cout << "Name: " << roster[i].getSubmission(j).GetName();
          cout.width(10);
          cout << "Weight: " << (roster[i].getSubmission(j).GetWeight() * 100)
               << "%  ";
          cout.width(12);
          cout << "Score: " << roster[i].getSubmission(j).GetGrade() << " ";
          cout.width(14);
          cout << "Contribution: "
               << roster[i].getSubmission(j).GetGrade() *
                      roster[i].getSubmission(j).GetWeight();
          cout << endl;

          grades += roster[i].getSubmission(j).GetGrade() *
                    roster[i].getSubmission(j).GetWeight();

          cout << endl;
          cout << endl;
        }
      }
    }
    cout.width(10);
    cout << "Total: " << grades << endl << endl;
  }

  else if (answer[0] != 'G' && answer[1] != 0) {
    int counter = 0;
    Assignment temp;
    float grades = 0;

    for (int i = 0; i < sizes; i++) {
      double finalGrade = 0;
      if (strcmp(roster[i].getName(), answer) == 0) {

        // print the statements
        cout << counter << ". ";
        cout << roster[i].getGnum() << " " << roster[i].getName() << "  ";
        cout << "Final Grade: " << roster[i].getGrade();
        cout << endl;

        // prints the name, weight, score, and contribution of each assignment
        for (int j = 0; j < roster[i].getSize(); j++) {
          cout << "Name: " << roster[i].getSubmission(j).GetName() << "  ";
          cout << "Weight: " << (roster[i].getSubmission(j).GetWeight() * 100)
               << "%  ";
          cout << "Score: " << roster[i].getSubmission(j).GetGrade() << "  ";
          cout << "Contribution: "
               << roster[i].getSubmission(j).GetGrade() *
                      roster[i].getSubmission(j).GetWeight();

          grades += roster[i].getSubmission(j).GetGrade() *
                    roster[i].getSubmission(j).GetWeight();
          cout << endl;
          cout << endl;
        }
      }
    }
    cout << endl;
    cout << endl;
    cout.width(4);
    cout << "Total: " << grades << endl << endl;
  } else {
    cout << "Invalid input";
    return;
  }
}

// functions that prints the remove and add options
int remove1() {
  char answer[15];

  char letter;

  do {
    cout << "     A or a  - for Assignment" << endl;
    cout << "     S or s  - for Student" << endl;
    cout << "     B or b  - return to previous" << endl;
    cout << "Enter choice: ";
    cin.getline(answer, 15);

    for (int i = 0; i < strlen(answer); i++) {
      answer[i] = tolower(answer[i]);
    }
    if (strcmp(answer, "a") == 0) {
     // cout << "Assignment " << endl;
      letter = 'a';
    } else if (strcmp(answer, "s") == 0) {
     // cout << "Student " << endl;
      letter = 's';

    } else if (strcmp(answer, "b") == 0) {
      cout << "returning back to menu " << endl;

      letter = 'b';

    } else {
      cout << "?Invalid option" << endl;
      letter = 'd';
    }

  } while (letter == 'd');
  return letter;
}

// The functions removes the assignment or student as per the choice made by the
// user
void remove(Student roster[], int &sizes) {
  int answer = remove1();
  char tempName[MAX_CHARS + 1];
  char tempAssignment[MAX_CHARS + 1];
  Assignment tempSub;
  if (answer == 'a') {
    cout << "Enter student name: ";
    cin.getline(tempName, MAX_CHARS + 1);
    cout << "Enter assignment name: ";
    cin.getline(tempAssignment, MAX_CHARS + 1);

    for (int i = 0; i < sizes; i++) {
      roster[i].getName();
      tempSub.GetName();
      int index;
      if (strcmp(roster[i].getName(), tempName) == 0) {

        for (int j = 0; j < roster[i].getSize(); j++) {
          // if the stored assignment name and the user input assignment name
          // are similar
          if (strcmp(roster[i].getSubmission(j).GetName(), tempAssignment) ==
              0) {
            index = j;
            // call the removeit to implement the removing process
            roster[i].removeit(index);
          }
        }
      }
    }

  } else if (answer == 's') {

    cout << "Enter student name: ";
    cin.getline(tempName, MAX_CHARS + 1);
    int index1 = 0;

    // going in a loop to find the name and removing it
    for (int i = 0; i < sizes; ++i) {
      if (strcmp(tempName, roster[i].getName()) == 0) {
        for (int j = 0; j < roster[i].getSize(); ++i) {
          roster[i] = roster[i + 1];
        }
      }
    }
    --sizes;
  }

  else if (answer == 'b') {
    return;
  }
}

// this function adds the student and assignments
void add(Student roster[], int &sizes, int capacities) {
  int answer = remove1();
  char tempName[MAX_CHARS + 1];
  char tempNames[MAX_CHARS + 1];
  char tempGnum[MAX_CHARS + 1];
  char tempAssignment[MAX_CHARS + 1];
  float tempWeight;
  int tempGrade;
  Assignment tempSub;
  char rosterName[MAX_CHARS + 1];

  if (answer == 'a') {
    cout << "Enter student name: ";
    cin.clear();
    cin.getline(tempName, MAX_CHARS, '\n');
    cout << "Enter assignment name: ";
    cin.clear();
    cin.getline(tempAssignment, MAX_CHARS, '\n');
    cout << "Enter assignment weight: ";
    cin >> tempWeight;
    cout << "Enter assignment grade: ";
    cin >> tempGrade;

    tempSub.SetName(tempAssignment);
    tempSub.SetWeight(tempWeight);
    tempSub.SetGrade(tempGrade);

    for (int i = 0; i < sizes; i++) {

      strcpy(rosterName, roster[i].getName());
      if (strcmp(rosterName, tempName) == 0) {
        // begin adding the assignmnet towards the end of the student set of
        // submissions
        roster[i].addSubmission(tempSub);
        cin.ignore(10, '\n');
      }
    }
    cin.clear();

  } else if (answer == 's') {
    cout << "Enter student name: ";
    cin.clear();
    cin.getline(tempNames, MAX_CHARS, '\n');
    cout << "Enter G-Number for" << tempNames << ": ";
    cin.clear();
    cin.getline(tempGnum, MAX_CHARS, '\n');

    if (sizes < capacities) {
      roster[sizes].setName(tempNames);
      roster[sizes].setGnum(tempGnum);

      sizes++;
      //cout << "size in function is " << sizes << endl;
    }
  }

  cin.clear();
}

