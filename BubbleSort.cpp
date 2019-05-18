#include "BubbleSort.h"
#include <iostream>
using namespace std;

BubbleSort::BubbleSort() {}

BubbleSort::~BubbleSort() {}

void BubbleSort::bubbleSort(double array[], unsigned int size)
{
  for (int i = 0; i < size-1; i++)
  {
    for (int j = i+1; j < size; j++)
    {
      double temp;
      if (array[i] > array[j])
      {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}
