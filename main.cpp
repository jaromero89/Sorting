#include "Insertion.h"
#include "BubbleSort.h"
#include "Quick.h"
#include "MergeSort.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <math.h>
using namespace std;

unsigned int option;
int randomNumbers;
double *insertionArray, *bubbleArray, *quickArray, *mergeArray;
double values;
ifstream sortingFile;
string filename, s;



int main () {

  Insertion insertion;
  BubbleSort bubble;
  Quick quick;
  MergeSort mergeobj;
  Time time;

  randomNumbers = 0;

  cout << "---Welcome to the sorting speed test!---" << endl;

  cout << "Select option below - " << endl;
  cout << "1 - Generate random numbers to sort" << endl;
  cout << "2 - Enter a text file that contains list of values" << endl;
  cin >> option;
  cin.get();

  if (option == 1) {
    cout << "Please enter how many random numbers you want to generate and sort" << endl;
    cin >> randomNumbers;

    insertionArray = new double [randomNumbers];
    bubbleArray = new double [randomNumbers];
    quickArray = new double [randomNumbers];
    mergeArray = new double [randomNumbers];

    for (int i = 0; i < randomNumbers; i++) {
      insertionArray[i] = rand();
      bubbleArray[i] = rand();
      quickArray[i] = rand();
      mergeArray[i] = rand();
    }

    if (randomNumbers == 0) {
      cout << "There are no values present in the file to sort!" << endl;
    }
    else if (randomNumbers == 1) {
      cout << "There is only one value. Nothing to sort!" << endl;
    }
    else {
      cout << "----------------" << '\n';
      cout << "Thank you, you entered: " << randomNumbers << "random numbers."<<'\n';
      cout << "InsertionSort - " << endl << "Start: " << time.timeNow();
      insertion.insertSort(insertionArray, randomNumbers);
      cout << "End: " << time.timeNow() << endl;
      cout << "----------------" << '\n';
      cout << "BubbleSort - " << endl << "Start: " << time.timeNow();
      bubble.bubbleSort(bubbleArray, randomNumbers);
      cout << "End: " << time.timeNow() << endl;
      cout << "----------------" << '\n';
      cout << "QuickSort - " << endl << "Start: " << time.timeNow();
      quick.quickSort(quickArray, 0, randomNumbers-1);
      cout << "End: " << time.timeNow() << endl;
      cout << "----------------" << '\n';
      cout << "MergeSort - " << endl << "Start: " << time.timeNow();
      mergeobj.mergeSort(mergeArray, 0, randomNumbers-1);
      cout << "End: " << time.timeNow() << endl;
      cout << "----------------" << '\n';
    }
  }
  else if (option == 2) {
    cout << "Please enter the name of the file along with the extension" << endl;
    cin >> filename;

    sortingFile.open (filename);

    getline (sortingFile,s);
    istringstream firstrow (s);
    firstrow >> randomNumbers;

    insertionArray = new double [randomNumbers];
    bubbleArray = new double [randomNumbers];
    quickArray = new double [randomNumbers];
    mergeArray = new double [randomNumbers];

    int a = 0;

    while (sortingFile >> values) {
      insertionArray[a] = values;
      bubbleArray[a] = values;
      quickArray[a] = values;
      mergeArray[a] = values;
      ++a;
    }

    if (randomNumbers == 0) {
      cout << "There are no values present in the file to sort!" << endl;
    }
    else if (randomNumbers == 1) {
      cout << "There is only one value. Nothing to sort!" << endl;
    }
    else {
      cout << "Insertion Sort - " << endl << "Start: " << time.timeNow();
      insertion.insertSort(insertionArray, randomNumbers);
      cout << "End: " << time.timeNow() << endl;
      cout << "Bubble Sort - " << endl << "Start: " << time.timeNow();
      bubble.bubbleSort(bubbleArray, randomNumbers);
      cout << "End: " << time.timeNow() << endl;
      cout << "Quick Sort - " << endl << "Start: " << time.timeNow();
      quick.quickSort(quickArray, 0, randomNumbers-1);
      cout << "End: " << time.timeNow() << endl;
      cout << "Merge Sort - " << endl << "Start: " << time.timeNow();
      mergeobj.mergeSort(mergeArray, 0, randomNumbers-1);
      cout << "End: " << time.timeNow() << endl;
    }
  }
}
//output:
/*
JamesMacBookPro:CPSC_350_6 jlloyd$ ./a.out
---Welcome to the sorting speed test!---
Select option below -
1 - Generate random numbers to sort
2 - Enter a text file that contains list of values
1
Please enter how many random numbers you want to generate and sort
10000
----------------
Thank you, you entered: 10000random numbers.
InsertionSort -
Start: Fri May 17 17:45:50 2019
End: Fri May 17 17:45:50 2019
----------------
BubbleSort -
Start: Fri May 17 17:45:50 2019
End: Fri May 17 17:45:51 2019

----------------
QuickSort -
Start: Fri May 17 17:45:51 2019
End: Fri May 17 17:45:51 2019
----------------
MergeSort -
Start: Fri May 17 17:45:51 2019
End: Fri May 17 17:45:51 2019

----------------

*/
