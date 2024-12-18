#pragma once
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

class item {

private:
  char *name;
  int quant;
  float price;

public:
  item();
  item &operator=(item &orig);
  item(item &orig);
  ~item();

void setName(char *word);
void setQuant(int quantity);
void setPrice(float prices);
char * getName();
int getQuant();
void addQuant(); 
float getPrice();
};
