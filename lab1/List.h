/*
 * Name: Colton Owenby
 * Date Submitted: 9/11/2023
 * Lab Section: 007
 * Assignment Name: Lab1
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List()
{
  start = nullptr;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List()
{
  if(!empty())
  {
    Node<T> *currentNode = start;
    Node<T> *tempNode;

    while(currentNode != nullptr)
    {
      tempNode = currentNode;
      currentNode = currentNode->next;
      delete tempNode;
    }
  }

}

//Return the size of this list
template <class T>
int List<T>::size()
{
  if(start == nullptr)
  {
    return 0;
  }
  Node<T> * temp = start;
  int count = 0;

  while(temp != nullptr)
  {
    count += 1;
    temp = temp->next;
  }

  return count;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty()
{
  if(mySize == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value)
{
  Node<T> *newNode = new Node<T>(value);
  newNode->next = start;
  start = newNode;
  mySize++;

}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value)
{
  Node<T> *newNode = new Node<T> (value);

  if(empty())
  {
    start = newNode;
  }
  else
  {
    Node<T> *tempNode = start;
    while(tempNode->next != nullptr)
    {
      tempNode = tempNode->next;
    }

    tempNode->next = newNode;
  }
  mySize++;

}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j)
{

  if(j == 0)
  {
    insertStart(value);
  }
  else
  {
    Node<T> *newNode = new Node<T>(value);
    Node<T> *tempNode = start;

    for(int i = 0; i < j-1; i++)
    {
      tempNode = tempNode->next;
    }

    newNode->next = tempNode->next;
    tempNode->next = newNode;
    mySize++;
  }


}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart()
{
  if(!empty())
  {
    Node<T>* tempNode = start;
    start=start->next;
    delete tempNode;
    mySize--;
  }


}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd()
{
  if(!empty())
  {
    Node<T> *tempNode = start;
    while(tempNode->next->next != nullptr)
    {
      tempNode=tempNode->next;
    }
    delete tempNode->next;
    tempNode->next = nullptr;
    mySize--;
  }

}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j)
{
  Node<T> *tempNode = start;
  for(int i = 0; i< j; i++)
  {
    tempNode = tempNode->next;
  }
  Node<T> * tempNodeOld = tempNode->next;
  tempNode->next = tempNode->next->next;
  delete tempNodeOld;
  mySize--;
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst()
{
  if(!empty())
  {
    return start->value;
  }

}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast()
{
  if(start == 0)
  {
    return -1;
  }

  {
    Node<T>* tempNode = start;
    while(tempNode->next != nullptr)
    {
      tempNode = tempNode->next;
    }
    return tempNode->value;
  }
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j)
{
  if(start == 0)
  {
    return -1;
  }
  else if(j < 0 || j >= mySize)
  {
    return -1;
  }
  else if(j == 0)
  {
    return start->value;
  }
  else
  {
    Node<T> *tempNode = start;
    for(int i = 0; i < j; i++)
    {
      tempNode = tempNode->next;
    }
    return tempNode->value;
  }

}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key)
{
  Node<T> *tempNode = start;
  int index = 0;

  while(tempNode != nullptr)
  {
    if(tempNode->value == key)
    {
      return index;
    }
    tempNode = tempNode->next;
    index++;
  }

  return -1;
}
