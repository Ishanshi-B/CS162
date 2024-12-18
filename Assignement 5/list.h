#pragma once
#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
#include "item.h"

class list {

private:
//Node struct
 struct Node {
		item * datas;
		Node * next;
	};
	Node * index;
  
  int size;

public:
//member functions
  list();
  list &operator=( list &original);
  ~list();
  list( list &original);


void add();
void inside(int pos, Node *tempNode, Node* current, Node* prev);
void scan(Node* tempNode);
void erase();
void remove();
void removeItem(int pos);
void update();
void display();
void removename();
void removeQuantity();
void removePrice();
};
char* input();
bool checkChar(char* charOption);
