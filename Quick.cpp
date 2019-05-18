#include "Quick.h"
#include <iostream>
using namespace std;

Quick::Quick () {}

Quick::~Quick() {}

void Quick::quickSort (double array[], int a, int b)
{
  if (a >= b) return;
  double pivot = array[b];
  int l = a;
  int r = b - 1;
  while (l <= r) {
    while (l <= r && array[l] <= pivot) {
      l++;
    }
    while (r >= l && pivot <= array[r]) {
      r--;
    }
    if (l < r) {
      double temp = array[l];
      array[l] = array[r];
      array[r] = temp;
    }
  }
  double temp = array[l];
  array[l] = array[b];
  array[b] = temp;
  quickSort(array, a, l-1 );
  quickSort(array, l+1, b);
}
