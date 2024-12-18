//*********************************
// Program name: HW 5 - Menu 
// Author: Ishanshi Bhardwaj
// Date: 9/4/2022
// Description: The program is a menu-driven inventory list that collects the items name, price, and quanity. It adds, displays, erases, removes, and updates the list
// word.
// Input: The user enters the options in the console
// Output: The user sess the list being displayed  // Sources: None
//*********************************


#include "main.h"
using namespace std;


int main() {
  list li;
  char option;

  welcome();

 
//looks at which option did the user pick 
  while ((option = menu()) != 'a') {
    switch (option) {
    case 'a':
      break;
    case 'b':
       li.erase();
      break;
    case 'c':
       li.add();
      break;
    case 'd':
       li.remove();
      break;
    case 'e':
       li.update();
      break;
    case 'f':
        li.display();
      break;
    case 'u':
      break;
    default:
      cerr << "?Option error" << endl;
      return 1;
      break;
    }
  }

  cout << "Goodbye!" << endl;

  return 0;
}

// welcome function displays the welcome message.
void welcome() { cout << "Welcome to Shopping List Maintenance!" << endl; }


// Name: checkcstring
// Description: checks the cstring and matches any of the options 
// return: true or false 
// input: the c-string
bool checkcstring(char *opt) {
  if (strcmp(opt, "1") == 0 || strcmp(opt, "2") == 0 || strcmp(opt, "3") == 0 ||
      strcmp(opt, "4") == 0 || strcmp(opt, "5") == 0 || strcmp(opt, "6") == 0) {
    return true;
  } else {
    return false;
  }
}


// Name: menu
// Description:Shows the different options and validates the options by checking the user inputs. 
// return: char that is used in the main
// input: the user input 
char menu() {

  char str = '0';
  char *first = nullptr;
  char *second = nullptr;
  bool checker = false;

  //ask the user for the inputs 
  do {
    cout << "Please enter one of the following options: " << endl;
    cout << '\t' << "1" << '\t' << '\t' << "- Quit the program" << endl;
    cout << '\t' << "2" << '\t' << '\t'
         << "- Erase all items from the list (resulting in an empty list)"
         << endl;
    cout << '\t' << "3" << '\t' << '\t' << "- Add an item to the list" << endl;
    cout << '\t' << "4" << '\t' << '\t' << "- Remove an item from the list"
         << endl;
    cout << '\t' << "5" << '\t' << '\t' << "- Update an item in the list"
         << endl;
    cout << '\t' << "6" << '\t' << '\t' << "- Display all items in the list"
         << endl;
    cout << "Enter Option: ";
    cin.get(str);
    first = new char[1];
    first[0] = str;

    //dynamically put the user input in 
    for (int i = 1; str != '\n'; i++) {
      cin.get(str);
      if (str != '\n') {
        second = new char[i];
        strncpy(second, first, i);
        delete[] first;
        first = new char[i + 1];
        strncpy(first, second, i);
        first[i] = str;
        delete[] second;
      } else if (str == '\n') {
        second = new char[i];
        strncpy(second, first, i);
        delete[] first;
        first = new char[i + 1];
        strncpy(first, second, i);
        first[i] = '\0';
        delete[] second;
      }
    }
    //check the option that the user provided 
    checker = checkcstring(first);
    //if the user input was any of the following numbers return the corresponding characters. 
    if (strcmp(first, "1") == 0) {
      delete[] first;
      first = nullptr;
      return 'a';
    } else if (strcmp(first, "2") == 0) {
      delete[] first;
      first = nullptr;
      return 'b';
    } else if (strcmp(first, "3") == 0) {
      delete[] first;
      first = nullptr;
      return 'c';
    } else if (strcmp(first, "4") == 0) {
      delete[] first;
      first = nullptr;
      return 'd';
    } else if (strcmp(first, "5") == 0) {
      delete[] first;
      first = nullptr;
      return 'e';
    } else if (strcmp(first, "6") == 0) {
      delete[] first;
      first = nullptr;
      return 'f';
    } else {
      cout << "?Invalid Option: " << first << endl;
      delete[] first;
      return 'u';
    }
  } while (checker == false);
  delete[] first;
  first = nullptr;
}
