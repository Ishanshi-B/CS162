//*********************************
// File name: list.cpp
// Author: Ishanshi Bhardwaj
// Date: 9/4/2022
// Description: Add, updates, removes, and erases all the words in the list.
// Output: the words present in the list
// Sources: None
//*********************************
#include "list.h"

// Default Constructor
list::list() {
  size = 0;
  index = nullptr;
}

// Assignment Operator
list &list::operator=(list &original) {
  Node *current = original.index;
  if (this != &original) {
    delete index;
    index = new Node;
    index = nullptr;
    while (current != nullptr) {
      index = original.index;
      current = current->next;
    }
  }
  return *this;
}

// Default Destructor
list::~list() {
  Node *curr = index;
  while (curr) {
    Node *temp = curr;
    curr = curr->next;
    delete temp->datas;
    delete temp;
  }
  size = 0;
}

// Copy Constructor
list::list(list &original) {
  if (original.index == nullptr) {
    index = nullptr;
  } else {
    index = new Node();
    Node *curr = index;
    Node *objIdx = original.index;
    Node *currObj = objIdx;
    while (currObj->next != nullptr) {
      curr->next = new Node();
      currObj = currObj->next;
      curr = curr->next;
    }
  }
}

// Name: checkChar
// Description: Checks the character whether it fits the options or not.
// return : true or false
// input: a c-string
bool checkChar(char *charOption) {
  // if any of these numbers/options return true
  if ((strcmp(charOption, "1") == 0) || (strcmp(charOption, "2") == 0) ||
      (strcmp(charOption, "3") == 0)) {
    return true;
  } else {
    cout << "?Unrecognized option: " << charOption << endl;
    return false;
  }
}

// Name: inside
// Description: Inserts the word into the right order.
// return: none
// input: position, the current word, the prev word, and the tempword
void list::inside(int pos, Node *tempNode, Node *current, Node *prev) {
  // this is where the function inserts into the linked list
  Node *target = tempNode;
  if (index == nullptr) {
    index = target;
  } else {
    if (pos <= 0) {
      target->next = index;
      index = target;
    } else if (pos >= size) {
      current = index;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = target;
      target->next = nullptr;
    } else {
      current = index;
      for (int i = 0; i < pos; i++) {
        prev = current;
        current = current->next;
      }
      target->next = current;
      prev->next = target;
    }
  }
}

// Name: add
// Description: This is the add function that has one purpose of adding the word
// into the roster of linked list return: none input: the words that the user
// puts in the console
void list::add() {
  bool flag = false;
  Node *current = index;
  Node *prev = nullptr;
  int pos = 0;
  int quantity = 0;
  float priced = 0.0;

  char str = '0';
  char *first = nullptr;
  char *second = nullptr;

  int count = 0;

  cout << "Enter name, quantity, price: ";
  cin.get(str);
  first = new char[1];
  first[0] = str;
  // dynamically adding the words into the linked list
  for (int i = 1; str != ','; i++) {
    cin.get(str);
    if (str != ',') {
      second = new char[i];
      strncpy(second, first, i);
      delete[] first;
      first = new char[i + 1];
      strncpy(first, second, i);
      first[i] = str;
      delete[] second;
    } else if (str == ',') {
      second = new char[i];
      strncpy(second, first, i);
      delete[] first;
      first = new char[i + 1];
      strncpy(first, second, i);
      first[i] = '\0';
      delete[] second;
    }
  }
  // getting the quantity and the price without dyanmic becuase they are int and
  // float
  cin.ignore(1, ' ');
  cin >> quantity;
  cin.ignore(1, ',');
  cin.ignore(1, ' ');
  cin >> priced;
  cin.ignore(1, '\n');

  Node *tempNode = new Node;
  tempNode->datas = new item;
  tempNode->datas->setName(first);
  delete[] first;
  first = nullptr;

  tempNode->datas->setQuant(quantity);
  tempNode->datas->setPrice(priced);
  tempNode->next = nullptr;
  char *itemInLst = nullptr;
  char *newitem = nullptr;

  while (current != nullptr) {
    itemInLst = current->datas->getName();
    newitem = tempNode->datas->getName();
    if (strcmp(itemInLst, newitem) == 0) { // check for a match
      flag = true;

      delete[] itemInLst;
      itemInLst = nullptr;
      delete[] newitem;
      newitem = nullptr;
      delete tempNode;
      break;
    }
    if (strcmp(itemInLst, newitem) > 0) {
      flag = false;
      delete[] itemInLst;
      itemInLst = nullptr;
      delete[] newitem;
      newitem = nullptr;

      break;
    }
    prev = current;
    current = current->next;
    delete[] itemInLst;
    itemInLst = nullptr;
    delete[] newitem;
    newitem = nullptr;
    pos++;
  }

  if (flag == false) {
    // if no match call the inside function that inserts the words
    inside(pos, tempNode, current, prev);

    size++;
  }
}

// Name: erase
// Description: The erase function erases everything in the list. Sort of like a
// destructor but part of the menu driven program return: none input: none
void list::erase() {
  Node *temp = nullptr;
  Node *curr = index;
  while (curr != nullptr) {
    temp = curr->next;
    delete curr;
    curr = temp;
  }
  index = nullptr;
}

// Name: remove
// Description: Removes the name, price, and quantity according to the user
// input return: none input: the user input to remove which word
void list::remove() {
  char *removeopt = nullptr;
  bool checker = false;
  char *itemIdentifier = nullptr;
  int targetquan = 0;
  float targetprice = 0.0;

  bool found = false;
  Node *current = index;
  Node *prev = nullptr;
  char *inList = nullptr;
  int intList = 0;
  float priList = 0.0;
  int pos = 0;
  int freq = 0;
  int quant = 0;

  if (index == nullptr) {
    return;
  }
  do {
    cout << "Enter match criterion: 1 for name, 2 for qty, 3 for price: ";
    removeopt = input();
    checker = checkChar(removeopt);
    if (strcmp(removeopt, "1") == 0) {
      cout << "Enter item name to remove: ";
      itemIdentifier = input();
      // finds the name
      while (current != nullptr) {
        inList = current->datas->getName();
        if (strcmp(itemIdentifier, inList) == 0) {
          found = true;
          delete[] itemIdentifier;
          itemIdentifier = nullptr;
          delete[] inList;
          inList = nullptr;
          break;
        } else {

          current = current->next;
          pos++;

          delete[] inList;
          inList = nullptr;
        }
      }
      // if there is a match then remove
      if (found == true) {
        removeItem(pos);
        size--;
      } else {
        cout << "Item not found in list!" << endl;
      }
      delete[] itemIdentifier;
      itemIdentifier = nullptr;

    }
    // remove by quanitity
    else if (strcmp(removeopt, "2") == 0) {

      cout << "Enter quantity to remove: ";
      cin >> quant;
      if (index == nullptr) {
        cout << "There are no items in the list. " << endl;
        return;
      }
      Node *temp = current->next;
      while (temp) {
        intList = temp->datas->getQuant();
        if (quant == intList) {
          current->next = temp->next;

          delete temp;
          temp = temp->next;

          pos++;
          size--;

        } else {
          current = temp;
          temp = temp->next;
        }
      }
      current = index;
      quant = temp->datas->getQuant();
      if (quant == intList) {
        index = index->next;
        delete current;
        pos++;
        size--;
      }
      cout << pos << "items removed" << endl;

      cin.ignore(100, '\n');

    }
    // remove by price
    else if (strcmp(removeopt, "3") == 0) {
      cout << "Enter price to remove: ";
      itemIdentifier = input();
      // change to into float
      targetprice = atof(itemIdentifier);
      delete[] itemIdentifier;
      itemIdentifier = nullptr;
      while (current != nullptr) {
        priList = current->datas->getPrice();
        if (targetprice == priList) {
          removeItem(pos);
          pos = 0;
          size--;
          priList = -1;
        } else {
          found = false;
          pos++;
          priList = -1;
        }
        prev = current;
        current = current->next;
      }
      if (found == false) {
        cout << "Item not found in list!" << endl;
      }
    } else {
      cout << "?Invalid Option: " << removeopt << endl;
    }
  } while (checker == false);
  delete[] removeopt;
  removeopt = nullptr;
}

// Name: removeItem
// Description: Removes the item from the list
// return: none
// input: the position
void list::removeItem(int pos) {
  Node *curr = index;
  Node *prev = nullptr;
  int idx = 0;

  while (curr != nullptr && idx < pos) {
    prev = curr;
    curr = curr->next;
    idx++;
  }
  if (index == nullptr) {
  } else {
    if (prev == nullptr) {
      curr = index;
      index = index->next;
    } else if (curr == nullptr) {
      prev->next = nullptr;
    } else {
      prev->next = curr->next;
    }
  }
}

// Name: update
// Description: Updates the word according to the user input. Updates the name,
// price, and quantity. return: none input: the user input
void list::update() {
  char *updateopt = nullptr;
  bool found = false;
  bool flag = false;
  bool checker = false;
  char *itemIdentifier = nullptr;
  char *newIdentifier = nullptr;
  char *ogname = nullptr;
  int origqua = 0;
  float origprice = 0.0;
  int targetquan = 0;
  int newqua = 0;
  float targetprice = 0.0;
  float newprice = 0.0;

  Node *current = index;
  Node *prev = nullptr;
  char *inList = nullptr;
  int intList = -1;
  float priList = 0.0;
  int pos = -1;
  int ipos = -1;

  if (index == nullptr) {
    return;
  }

  do {
    cout << "Enter match criterion: 1 for name, 2 for qty, 3 for price: ";
    updateopt = input();
    checker = checkChar(updateopt);
    // if the user enters the name to update
    if (strcmp(updateopt, "1") == 0) {
      cout << "Enter item name to match: ";
      itemIdentifier = input();
      while (current != nullptr) {
        // find the name first in the list
        inList = current->datas->getName();
        if (strcmp(itemIdentifier, inList) == 0) {
          origqua = current->datas->getQuant();
          origprice = current->datas->getPrice();
          found = true;
          delete[] itemIdentifier;
          itemIdentifier = nullptr;
          delete[] inList;
          inList = nullptr;
          break;
        } else {
          found = false;
          cout << "Item not found in list!" << endl;
          pos++;
          delete[] inList;
          inList = nullptr;
        }
        prev = current;
        current = current->next;
      }
      delete[] itemIdentifier;
      itemIdentifier = nullptr;
      if (found == true) {
        // remove that item
        removeItem(pos);
        size--;
        // ask the user for the new item name
        cout << "Enter new item name: ";
        newIdentifier = input();
        Node *tempNode = new Node;
        // set the new item name
        tempNode->datas = new item;
        tempNode->datas->setName(newIdentifier);
        // also set the quantity and price again
        tempNode->datas->setQuant(origqua);
        tempNode->datas->setPrice(origprice);
        tempNode->next = nullptr;
        delete[] newIdentifier;
        newIdentifier = nullptr;

        char *itemInNew = nullptr;
        char *upditem = nullptr;
        while (current != nullptr) {
          itemInNew = current->datas->getName();
          upditem = tempNode->datas->getName();
          if (strcmp(itemInNew, upditem) > 0) {
            flag = false;
            delete[] itemInNew;
            itemInNew = nullptr;
            delete[] upditem;
            upditem = nullptr;
            break;
          }
          prev = current;
          current = current->next;
          delete[] itemInNew;
          itemInNew = nullptr;
          delete[] upditem;
          upditem = nullptr;
          ipos++;
        }

        if (flag == false) {
          inside(ipos, tempNode, current, prev);
          size++;
        }
      }
      // update for the quantity
    } else if (strcmp(updateopt, "2") == 0) {
      cout << "Enter quantity to match: ";
      itemIdentifier = input();
      targetquan = atoi(itemIdentifier);
      cout << "Enter new item quantity: ";
      newIdentifier = input();
      while (current != nullptr) {
        // get the quanitity to match
        intList = current->datas->getQuant();
        if (targetquan == intList) {
          newqua = atoi(newIdentifier);
          // set the new quantity
          current->datas->setQuant(newqua);
        } else {
          cout << "Item not found in list!" << endl;
          prev = current;
          current = current->next;
          intList = -1;
        }
      }
      delete[] itemIdentifier;
      itemIdentifier = nullptr;
      delete[] newIdentifier;
      newIdentifier = nullptr;

      // update the new price
    } else if (strcmp(updateopt, "3") == 0) {
      cout << "Enter price to match: ";
      // find the price
      itemIdentifier = input();
      targetprice = atof(itemIdentifier);
      cout << "Enter new item price: ";
      // update the new price
      newIdentifier = input();
      while (current != nullptr) {
        priList = current->datas->getPrice();
        if (targetprice == priList) {
          newprice = atof(newIdentifier);
          // set the new price
          current->datas->setPrice(newprice);
        } else {
          cout << "Item not found in list!" << endl;
          prev = current;
          current = current->next;
          priList = 0.0;
        }
      }
      delete[] itemIdentifier;
      itemIdentifier = nullptr;
      delete[] newIdentifier;
      newIdentifier = nullptr;
    } else {
      cout << "?Invalid Option: " << updateopt << endl;
    }
  } while (checker == false);
  delete[] updateopt;
  updateopt = nullptr;
}

// Name: display
// Description: display all the inputs when user presses the view command
// return: tbe user inputs
// input: the set quanity, price, and the name of the item

void list::display() {
  char *itemInLst = nullptr;
  int qua = 0;
  float priced = 0.0;
  float icost = 0.0;
  float tcost = 0.0;

  if (index == nullptr) {
    return;
  }
  // first get the quanitities, price present
  for (Node *curr = index; curr; curr = curr->next) {
    qua = curr->datas->getQuant();
    priced = curr->datas->getPrice();
    // cast it is as a float and then multiply
    icost = (static_cast<float>(qua) * (priced));
    // total cost calculations
    tcost = tcost + icost;
  }
  cout << size << " Items in the list. Total cost is " << tcost << endl;

  // Displays the quantity, price, and name
  for (Node *curr = index; curr; curr = curr->next) {
    qua = curr->datas->getQuant();
    priced = curr->datas->getPrice();
    itemInLst = curr->datas->getName();

    icost = (static_cast<float>(qua) * (priced));

    cout << itemInLst << " (" << qua << " at "
         << "$" << priced << ") ";
    cout << "Total cost "
         << "$" << icost << endl;
    delete[] itemInLst;
    itemInLst = nullptr;
  }
}

// Name: input
// Description: inserts the word into the list in ASCII ordering and with no
// duplicates. return: none input: the word
char *input() {
  char str = '0';
  char *first = nullptr;
  char *second = nullptr;
  cin.get(str);
  first = new char[1];
  first[0] = str;

  // A dynamic way to take in the letters
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
  return first;
  delete[] first;
}

