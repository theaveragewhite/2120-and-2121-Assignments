/*
 * Name: Colton Owenby (coltono)
 * Date Submitted: Submitted 10/2/2023
 * Lab Section: 007
 * Assignment Name: Lab 4
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target)
{
  //Made an unsigned int since it is measuring the size of the data which can't be negative
  //Also makes sure the target within the data vector is the same as i
  for (unsigned int i = 0; i < data.size(); ++i)
  {
    if (data[i] == target)
    {
      return i;
    }
  }
  return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target)
{
  int high, low, mid;
  high = data.size() - 1;
  low = 0;
  while(high >= low)
  {
    //Cuts the vector data in "half" to determine which is the middle value
    mid = low + (high - low) / 2;
    if(data[mid] == target)
    {
      return mid;
    }
    else if(data[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      high = mid -1;
    }
  }
  return -1;
}
