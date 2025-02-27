/*
 * Name: Colton Owenby (coltono)
 * Date Submitted: Submitted 10/2/2023
 * Lab Section: 007
 * Assignment Name: Lab 4
 */
#pragma once

#include <vector>

template <class T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right)
{
  std::vector<T> result;
  size_t leftIndex = 0, rightIndex = 0;

  while(leftIndex < left.size() && rightIndex < right.size())
  {
    if (left[leftIndex] < right[rightIndex])
    {
      //Pushes back the left index in the left vector
      result.push_back(left[leftIndex]);
      leftIndex++;
    }
    else
    {
      //Pushes back the right index in the right vector
      result.push_back(right[rightIndex]);
      rightIndex++;
    }
  }
  //Runs while the leftIndex is smaller then the size of the left vector
  while(leftIndex < left.size())
  {
    result.push_back(left[leftIndex]);
    leftIndex++;
  }
  //Runs while the rightIndex is smaller then the size of the right vector
  while(rightIndex < right.size())
  {
    result.push_back(right[rightIndex]);
    rightIndex++;
  }
  return result;
}

template <class T>
std::vector<T> mergeSort(std::vector<T> lst)
{
  //Validation Checking
  if (lst.size() <= 1)
  {
    return lst;
  }
  // Splits the size of list into 2 to determine the bigger value of
  // the left and right vector. Then sorts them smallest to largest.
  size_t mid = lst.size() / 2;
  std::vector<T> left(lst.begin(), lst.begin() + mid);
  std::vector<T> right(lst.begin() + mid, lst.end());
  left = mergeSort(left);
  right = mergeSort(right);

  return merge(left, right);
}

template <class T>
size_t partition(std::vector<T>& lst, size_t low, size_t high)
{
  size_t end = high;
  size_t start = low;
  for(size_t i = start; i < end; ++i)
  {
    //Checks if the lst at position i is greater then lst at the beginning of the vector
    if(lst[i]<lst[end])
    {
      //Swaps the value for position i with the end position
      std::swap(lst[i],lst[start]);
      ++start;
    }
  }

  std::swap(lst[start], lst[end]);
  return start;
}

template <class T>
void quickSortHelper(std::vector<T>& lst, size_t low, size_t high)
{
  //If the size of low is less than the size of high
  if (low < high)
  {
    size_t pivotIndex = partition(lst, low, high);
  if (pivotIndex > 0)
  {
    quickSortHelper(lst, low, pivotIndex - 1);
  }
    quickSortHelper(lst, pivotIndex + 1, high);
  }
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst)
{
  if (lst.empty())
  {
    return lst;
  }
  //Calls the quickSortHelper
  quickSortHelper(lst, 0, lst.size() - 1);

  return lst;
}
