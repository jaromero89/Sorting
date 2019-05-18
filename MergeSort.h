#include <iostream>
using namespace std;

class MergeSort {
public:
  MergeSort();
  ~MergeSort();

  void mergeSort(double array[], int lo, int hi);
  void merge(double array[], int lo, int hi);

private:
  int m;
};
