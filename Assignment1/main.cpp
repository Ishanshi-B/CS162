#include "main.h"

/**
 * File name: main.cpp
 * Author: Ishanshi Bhardwaj
 * Date: 7/3/2022
 * Summary: The program is a menu-drive student database interpreter 
 * Input: The user puts in a file and they are asked to pick from the menu to give the desired output
 * Output: The user is allowed to see the contents of the file, the average gpa, the total completion rate, the passing rate, the failing rate, and the audit rate
 */

int main(){
    ifstream file;
    student roster[MAX_STUDENTS];
    int size = 0;
    int capacity = MAX_STUDENTS;
    int filename;
    welcome();
    char option;  
    while (( option = menu() ) != 'Q') {
        switch(option) {
                  //switch case to check for the right option and then calling the functions 

               case 'Q':
                    break;
               case 'L':
load(file,roster,size,capacity);
                 


                    break;
               case 'D':
                 display(roster, size);
                    break;
               case 'G':
                gpa(roster, size);
              
                    break;
               case 'P':
                 pct(roster,size);
                    break;
                case 'U':
                    break;

               default:
                    cerr << "?Option error" << endl;
                    return 1;
                    break;
          }
    }
    return 0;
}

/**
 * Function: welcome
 * Description: Displays welcome message 
 * Parameters: The function displays the welcome message 
 * Pre-Conditions: The user starts the code
 * Post-Conditions: the welcome message is displayed
 */
void welcome(){
cout << "Welcome to my class management program!"  << endl;

}
/**
 * Function: menu
 * Description: Displays the options for the user to pick
 * Parameters: The function displays the options
 * Pre-Conditions: After the welcome message is displayed assuming the user began the code or anytime the user picks an option that is not quit
 * Post-Conditions: return the char option as per the user input 
 */
char menu(){

//give the user the options 
char option[15];
cout << "Please enter one of the following options: " << endl;
cout << "    LOAD - Load roster data from an input file" << endl;
cout << "    DISPLAY - Display the current roster data " << endl;
cout << "    GPA - Display the average GPA for the roster " << endl;
cout << "    PCT - Display the Pass, Fail, and Completion percentages" << endl;
cout << "    QUIT - End this program \n" << endl;

cout << "Enter Option: ";
cin >> option;
//check the options 
if (strlen(option) > 7 ){
    cout << "?Unrecognized option: " << "\"" << option << "\"" << endl;
    return 'U';

}

for (int i = 0; i < strlen(option); i++)
{
    //checks for the valid rules 
    
    
        if(tolower(option[0]) == 'l' && tolower(option[1]) == 'o' && tolower(option[2]) == 'a' && tolower(option[3]) == 'd'){
            
           
           return 'L';
        }
        else if (tolower(option[0]) == 'd' && tolower(option[1]) == 'i' && tolower(option[2]) == 's' && tolower(option[3]) == 'p' && tolower(option[4])== 'l' && tolower(option[5])== 'a' && tolower(option[6])== 'y')
            return 'D';
        else if (tolower(option[0]) == 'g' && tolower(option[1]) == 'p' && tolower(option[2]) == 'a')
            return 'G';
        else if (tolower(option[0]) == 'p' && tolower(option[1]) == 'c' && tolower(option[2]) == 't')
            return 'P';
        else if (tolower(option[0]) == 'q' && tolower(option[1]) == 'u' && tolower(option[2]) == 'i' && tolower(option[3]) =='t')
        
            return 'Q';
        
        else{
          
        cout << "?Unrecognized option: " << "\"" << option << "\"" << endl;
            return 'U';
        }
}
return true;



}


