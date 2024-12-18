/**
 * File name: student.cpp
 * Author: Ishanshi Bhardwaj
 * Date: 7/3/2022
 * Summary: The program is a collection of all the functions that are needed to show the desired output for the option picked from main.cpp
 * Input: The user puts in the option in main.cpp and the functions as per their choice are supposed to output the result
 * Output: The user is allowed to see the contents of the file, the average gpa, the total completion rate, the passing rate, the failing rate, and the audit rate
 */
#include "student.h"
#include <iomanip>

/**
 * Function: input
 * Description: Asks for an input file and a c-string to store filename to open the file 
 * Parameters: The function takes in input file and c-string 
 * Pre-Conditions: Assuming that the user will put in the input file and c-string
 * Post-Conditions: opens the file 
 */
void input(ifstream &file, char str3[30])
{

    char str[30];

    char str2[] = ".txt";
    do
    {
      //asking for file name
        cout << "Enter a file name: ";
        cin >> str;
        //copy the string
        strcpy(str3, str);
        //concatinate the string
        strcat(str, str2);
        file.open(str);
        cout << endl;
        if (file.fail())
        {
            cout << "Invalid File! Enter a valid file name " << endl;
        }
    } while (file.fail());
}

/**
 * Function: init_student
 * Description: Asks for nothing from the user as it declares the roster to be initalized to 0
 * Parameters: The function takes in the student structure 
 * Pre-Conditions: A student structure 
 * Post-Conditions: returns result which is a struct inialized to 0 
 */
student init_student()
{
    student result;
      //all the arrays in stuent to be initalized to 0

    for (auto idx = 0; idx < MAX_CHARS + 1; idx++)
    {
        result.name[idx] = '\0';
        result.gnum[idx] = '\0';
        result.grade[idx] = '\0';
    }
    return result;
}

/**
 * Function: load
 * Description: Asks for input file, student roster[], size, and capacity to load the file in this function
 * Parameters: The function takes in input file, student roster[], size, and capacity
 * Pre-Conditions: Assuming that the user will put in input file, student roster[], size, and capacity
 * Post-Conditions: opens the user given file  
 */
void load(ifstream &file, student roster[], int &size, int &capacity)
{
    init_student();
    char str[30];
    input(file, str);
//initalize the size to 0
    size = 0;

    //begin storing the file data 
    file.getline(roster[size].name, MAX_CHARS, ',');
    file.getline(roster[size].gnum, MAX_CHARS, ',');
    file.getline(roster[size].grade, MAX_CHARS);

    while (!file.eof() && size < capacity)
    {
        file.getline(roster[size].name, MAX_CHARS, ',');
        file.getline(roster[size].gnum, MAX_CHARS, ',');
        file.getline(roster[size].grade, MAX_CHARS);
        size++;
    }
    cout << "[ " << size << " records read from \"" << str << "\"" "]" << endl;
    cout << endl;

    file.close();
}


/**
 * Function: display
 * Description: Asks for roster and size to show the file records 
 * Parameters: The function takes in roster[] and size 
 * Pre-Conditions: Assuming that the user will have the file loaded and opened 
 * Post-Conditions: displays the file content
 */
void display(student roster[], int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        //print the statements

        cout << setw(4) << counter << "." << setw(35) << roster[i].name << setw(12) << roster[i].gnum << setw(10) << roster[i].grade << endl;

        counter++;
    }
}

/**
 * Function: gpa
 * Description: Asks for roster and size to display the average records 
 * Parameters: The function takes in roster[] and size 
 * Pre-Conditions: Assuming that the user will have the file loaded and opened 
 * Post-Conditions: displays the average gpa 
 */
void gpa(student roster[], int size)
{
    float gpa_counter = 0;
        
    for (int i = 0; i < size; i++)
    {
      //compare the strings 

        if (strcmp(roster[i].grade, "A") == 0)
        {
                      //add respective number to the gpa_counter

            gpa_counter = gpa_counter + 4;
        }
        else if (strcmp(roster[i].grade, "B") == 0)
        {
            gpa_counter = gpa_counter + 3;
        }
        else if (strcmp(roster[i].grade, "C") == 0)
        {
            gpa_counter = gpa_counter + 2;
        }
        else if (strcmp(roster[i].grade, "D") == 0)
        {
            gpa_counter = gpa_counter + 1;
        }
        else if (strcmp(roster[i].grade, "P") == 0)
        {
            gpa_counter = gpa_counter + 2;
        }
        else
        {
            gpa_counter = gpa_counter + 0;
        }
    }
    // finds the average and subtracts by 1 because size starts at 0;
    cout << fixed << showpoint << setprecision(2);

    gpa_counter = gpa_counter / (size - 1);
    cout << "Average GPA for " << size << " students is " << gpa_counter << "." << endl;
    cout << endl;
}

/**
 * Function: pct
 * Description: Asks for roster and size to display the total completitions, passing students, not passing students, audit students
 * Parameters: The function takes in roster[] and size 
 * Pre-Conditions: Assuming that the user will have the file loaded and opened 
 * Post-Conditions: displays the total completitions, passing students, not passing students, audit students
 */
void pct(student roster[], int size)
{
      //result shows the percentage 

    int result = (size / size) * 100;
    int completion = 0;
    int passing = 0;
    int no_pass = 0;
    int audit = 0;

    cout << endl;
    cout << "Total Students: " << size << " (" << result << "%)" << endl;

    for (int i = 0; i < size; i++)
    {
              //compare the strings to see the grade 

        if (strcmp(roster[i].grade, "A") == 0)
        {
                      //add completion and passing

            completion = completion + 1;
            passing = passing + 1;
        }
        else if (strcmp(roster[i].grade, "B") == 0)
        {
            completion = completion + 1;
            passing = passing + 1;
        }
        else if (strcmp(roster[i].grade, "C") == 0)
        {
            completion = completion + 1;
            passing = passing + 1;
        }
        else if (strcmp(roster[i].grade, "D") == 0)
        {
                      //add completion and no_pass

            completion = completion + 1;
            no_pass = no_pass + 1;
        }
        else if (strcmp(roster[i].grade, "P") == 0)
        {
            completion = completion + 1;
            passing = passing + 1;
        }
        else if (strcmp(roster[i].grade, "F") == 0)
        {
            completion = completion + 1;
            no_pass = no_pass + 1;
        }
        else if (strcmp(roster[i].grade, "NP") == 0)
        {
            completion = completion + 1;
            no_pass = no_pass + 1;
        }
        else if (strcmp(roster[i].grade, "AUD") == 0)
        {
            completion = completion + 1;
            audit = audit + 1;
        }
        else if (strcmp(roster[i].grade, "W") == 0)
        {
                      //add 0 to completetion and 1 to no_pass 

            completion = completion + 0;
            no_pass = no_pass + 1;
        }
        else if (strcmp(roster[i].grade, "I") == 0)
        {
            completion = completion + 0;
            no_pass = no_pass + 1;
        }
    }
    // the precent values being calculated 

    float new_result = ((float)completion / (float)size) * 100;
    float new_passing = ((float)passing / (float)size) * 100;
    float new_failing = ((float)no_pass / (float)size) * 100;
    float new_audit = ((float)audit / (float)size) * 100;

    cout << fixed << showpoint << setprecision(2);

    cout << "Total Completions: " << completion << " (" << new_result << "%)" << endl;
    cout << "Passing Grades: " << passing << " (" << new_passing << "%)" << endl;
    cout << "Non-Passing Grades: " << no_pass << " (" << new_failing << "%)" << endl;
    cout << "AUD Grades: " << audit << " (" << new_audit << "%)" << endl;

    cout << endl;
}

