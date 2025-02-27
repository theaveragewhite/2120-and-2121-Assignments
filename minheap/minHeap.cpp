#include "minHeap.h"
#include <iostream>


void minHeap::siftUp(int pos)
{
  while (pos > 0)
  {
    int parent = (pos - 1) / 2;
    if (heap[pos] < heap[parent])
    {
      swap(heap[pos], heap[parent]);
      pos = parent;
    }
    else
    {
      break;
    }
  }
}

void minHeap::siftDown(int pos)
{
  int size = heap.size();
  while (2 * pos + 1 < size)
  {
    int leftChild = 2 * pos + 1;
    int rightChild = 2 * pos + 2;
    int minIndex = pos;

    if (leftChild < size && heap[leftChild] < heap[minIndex])
    {
      minIndex = leftChild;
    }
    if (rightChild < size && heap[rightChild] < heap[minIndex])
    {
      minIndex = rightChild;
    }
    if (minIndex != pos)
    {
      swap(heap[pos], heap[minIndex]);
      pos = minIndex;
    }
    else
    {
      break;  // Heap property is satisfied
    }
  }
}

minHeap::minHeap() {}

minHeap::minHeap(vector<int> data)
{
    heap = data;
    int size = heap.size();
    for (int i = size / 2 - 1; i >= 0; --i)
    {
        siftDown(i);
    }
}

void minHeap::insert(int value)
{
  heap.push_back(value);
  siftUp(heap.size() - 1);
}

int minHeap::removeMin()
{
  if (heap.empty())
  {
    cerr << "Heap is empty." << endl;
    return -1;  // Return a sentinel value or handle error as appropriate
  }

  int minValue = heap[0];
  heap[0] = heap.back();
  heap.pop_back();
  siftDown(0);

  return minValue;

}

vector<int> minHeap::getHeap()
{
    return heap;
}
