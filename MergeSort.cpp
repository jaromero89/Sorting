#include "MergeSort.h"
#include <iostream>
using namespace std;

MergeSort::MergeSort() {}

MergeSort::~MergeSort() {}

void MergeSort::mergeSort(double array[], int lo, int hi)
{
  if (lo < hi) {
    m = (lo + hi)/2;
    mergeSort(array, lo, m);
    mergeSort(array, m+1, hi);
    merge(array, lo, hi);
  }
}

void MergeSort::merge(double array[], int lo, int hi)
{
  int i, j, k, m, n = hi - lo + 1;
  double *tempArray = new double [n];

  k = 0;
  m = (lo + hi)/2;
  //copy lower half to tempArray
  for (i = lo; i <= m; i++) {
    tempArray[k++] = array[i];
  }
  //copy upper half tp tempArray in opposite order
  for (j = hi; j >= m+1; j--) {
    tempArray[k++] = array[j];
  }

  i = 0; j = n-1; k = lo;

  //copy back next greatest element at eavh time
  //until i and j cross

  while (i <= j) {
    if (tempArray[i] <= tempArray[j]) {
      array[k++] = tempArray[i++];
    }
    else {
      array[k++] = tempArray[j--];
    }
  }
}
