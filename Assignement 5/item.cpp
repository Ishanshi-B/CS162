//*********************************
// File name: item.cpp
// Author: Ishanshi Bhardwaj
// Date: 9/4/2022
// Description: Defines the constructors and destructors of the item class. The mutators and assesors stores the words.
// Input: None
// Output: None
// Sources: None
//*********************************
#include "item.h"

//Default constructor 
item::item() {
  name = nullptr;
  quant = 0;
  price = 0.0;
}

//Copy Assignment operator 
item &item::operator=( item &orig) {
  if (this != &orig){
    int copy = strlen(orig.name);
    quant = 0;
    price = 0.0;
    delete [] name;
    quant = orig.quant;
    price = orig.price;
    name = new char [copy +1];
    strncpy(name, orig.name, copy);
    name[copy] ='\0';
  }
  return *this;
   

}

//Copy Constructor 
item::item(item &orig) {
  strcpy(name, orig.name);
  quant = orig.quant;
  price = orig.price;

}

//Default Destructor 
item::~item() {
  if (name) {
    delete[] name;
    name = nullptr;
  }
  quant = 0;
  price = 0.0;
}

//Mutator function for setting name 
void item ::setName(char *item) {
  int num = strlen(item);
  delete [] name;
  name = new char[num+1];
  strncpy(name, item, num);
  name[num] = '\0';
}

//Accessor function to get the name 
 char * item::getName() { 
  int itemss = strlen(name);
  char *gettingitems = new char[itemss + 1];
  strcpy(gettingitems, name);
  gettingitems[itemss] = '\0';
  return gettingitems;  
  }

//Mutator function to set the quantity
void item::setQuant(int quantity){ quant = quantity; }
//function to add the quantities
void item::addQuant() { quant++; }

//Accessors to get the quanitity
int item::getQuant() { return quant; }

//Mutator to set the price
void item::setPrice(float prices){ price = prices; }
//Acessor to get the price 
float item::getPrice() { return price; }


