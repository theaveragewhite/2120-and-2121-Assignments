#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value)
{

  back = (back + 1) % size;
  array[back] = value;
  return true;

  if((back + 1) % size == front)
  {
    return false;
  }

}

int IntegerArrayQueue::dequeue()
{
  if(front == (back + 1) % size)
  {
    return 0;
  }
  int value = array[front];
  front = (front + 1) % size;
  return value;

}
