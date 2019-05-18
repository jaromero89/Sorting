#include "Insertion.h"
#include <iostream>
using namespace std;

Insertion::Insertion() {}

Insertion::~Insertion() {}

void Insertion::insertSort(double array[], unsigned int size)
{
  for (int j = 1; j < size; ++j) {	//marker
    double temp = array[j];	//store marked item
    int k = j;	//where to start shifting
    while (k > 0 && array[k-1] >= temp)	//while the thing to the left is larger, shift
    {
      array[k]=array[k-1];
      --k;
    }
      array[k] = temp;	//put marked item in right spot
  }
}
