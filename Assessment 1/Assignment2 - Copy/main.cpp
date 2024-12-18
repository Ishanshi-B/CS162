//*********************************
//File name: main.cpp
//Author: Ishanshi Bhardwaj
//Date: 7/16/2022
//Description: The program is a menu-drive student database interpreter 
//Input: The user puts in a file and they are asked to pick from the menu to give the desired output
//Output: The user is allowed to see the contents of the file, the average gpa, the total completion rate, the passing rate, the failing rate, and the audit rate
//Sources: None
//*********************************
#include "main.h"

int main(){
    ifstream file;

    Student roster[MAX_STUDENTS];
    int size = 0;
    int capacity = MAX_STUDENTS;
    int filename;
    welcome();
    Student s;
    char option;  
    while (( option = menu() ) != 'f') {
        switch(option) {
 //switch case to check for the right option and then calling the functions 
               case 'a':
                  load(roster, size, capacity);
                    break;
               case 'b':
                display(roster, size);
                    break;
               case 'c':
                gpa(roster, size);
                    break;
               case 'd':
                grade(roster,size);
                    break;
               case 'e':
                pct(roster,size);
                    break;
               case 'f':
                    break;
               case 'g':
                 remove(roster,size);
                    break;
               case 'h':
                cout << "size before is " << size << endl;
                 add(roster, size, capacity);
                 cout << "Size after is " << size << endl;
                    break;
               default:
                    break;
          }
    }
    return 0;
}


//This function displays welcome message 
void welcome(){
cout << "Welcome to my class management program!"  << endl;

}
//Displays the options for the user to pick. After the welcome message is displayed assuming the user began the code or anytime the user picks an option that is not quit
char menu(){

char option[15];
char letter;

  
do{

cout << "Please enter one of the following options: " << endl;
cout << "    LOAD - Load roster data from an input file" << endl;
cout << "    DISPLAY - Display the current roster data " << endl;
cout << "    GPA - Display the average GPA for the roster " << endl;
cout << "    GRADE - Display grade inforamtion for one student" << endl;
cout << "    PCT - Display the Pass, Fail, and Completion percentages" << endl;
cout << "    REMOVE - Remove item from a list" << endl;
cout << "    ADD - Add item to a list" << endl;
cout << "    QUIT - End this program \n" << endl;
cout << "Enter Option: ";
cin.getline(option, 15);
  
      for(int i = 0; i < strlen(option); i++)      {
        option[i] = tolower(option[i]);
      }
    if(strcmp(option, "load") == 0)
        letter  = 'a';
    else if (strcmp(option, "display") == 0 )
        letter= 'b';
    else if (strcmp(option, "gpa") == 0)
        letter ='c';
    else if (strcmp(option, "grade") == 0)
      letter = 'd';
    else if (strcmp(option, "pct") == 0)
      letter = 'e';
    else if (strcmp(option, "quit") == 0)
      letter =  'f';
    else if (strcmp(option, "remove") == 0)
      letter ='g';
    else if (strcmp(option, "add") == 0)
      letter ='h';
    else{
       cout << "?Unrecognized option: " << option << endl;
    }
  }while(letter != 'a' && letter != 'b' && letter != 'c' && letter != 'd' && letter != 'e' && letter != 'f' && letter != 'g' && letter != 'h' );
return letter;
}
