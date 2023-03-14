// Twan Tran
// CECS 325-02
// Prog 5 - Sorting Contest(Threading)
// 10/25/2022
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.

#include <fstream>
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <unistd.h>

using namespace std;

void radixSort(int *arr, int sz) {
  int max = arr[0];
  for (int i = 1; i < sz; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  int d = 1;
  int res[sz];

  while (max / d > 0) {
    int count[10] = {0};
    for (int i = 0; i < sz; i++) {
      count[(arr[i] / d) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (int i = sz - 1; i >= 0; i--) {
      res[count[(arr[i] / d) % 10] - 1] = arr[i];
      count[(arr[i] / d) % 10]--;
    }
    for (int i = 0; i < sz; i++) {
      arr[i] = res[i];
    }
    d *= 10;
  }
}

void merge(int *a1, int s1, int *a2, int s2, int *a, int s) {
  int i = 0, j = 0, k = 0;
  int b[s1+s2];
  while (i < s1 && j < s2) {
    if (a1[i] < a2[j])
      b[k++] = a1[i++];
    else
      b[k++] = a2[j++];
  }

  while (i < s1)
    b[k++] = a1[i++];

  while (j < s2)
    b[k++] = a2[j++];

  for (int z = 0; z < s1+s2; z++){
    a[s] = b[z];
    s++;
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    cout
        << "Please include input filename and output filename in param list.\n";
    cout << "Example:\n";
    cout << "     % mySort numbers.txt mySorted.txt\n";
    exit(EXIT_SUCCESS);
  }

  ifstream InFile;
  ofstream outFile;

  const int MAX = 1000000;
  int arr[MAX];
  int i = 0;
  int val;

  InFile.open(argv[1]);
  while (InFile >> val) {
    arr[i] = val;
    i++;
  }

  cout << "Starting Threading Radix Sort with " << i << " items\n";

  thread thread0(radixSort, &arr[0], 125000);
  thread thread1(radixSort, &arr[125000], 125000);
  thread thread2(radixSort, &arr[250000], 125000);
  thread thread3(radixSort, &arr[375000], 125000);
  thread thread4(radixSort, &arr[500000], 125000);
  thread thread5(radixSort, &arr[625000], 125000);
  thread thread6(radixSort, &arr[750000], 125000);
  thread thread7(radixSort, &arr[875000], 125000);

  thread0.join();
  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
  thread5.join();
  thread6.join();
  thread7.join();

  thread thread00(merge, &arr[0], 125000, &arr[125000], 125000, arr, 0);
  thread thread01(merge, &arr[250000], 125000, &arr[375000], 125000, arr, 250000);
  thread thread02(merge, &arr[500000], 125000, &arr[625000], 125000, arr, 500000);
  thread thread03(merge, &arr[750000], 125000, &arr[875000], 125000, arr, 750000);

  thread00.join();
  thread01.join();
  thread02.join();
  thread03.join();

  thread thread04(merge, &arr[0], 250000, &arr[250000], 250000, arr, 0);
  thread thread05(merge, &arr[500000], 250000, &arr[750000], 250000, arr, 500000);

  thread04.join();
  thread05.join();

  thread thread06(merge, &arr[0], 500000, &arr[500000], 500000, arr, 0);
  thread06.join();

  cout << "Ending Threading Radix Sort\n";

  outFile.open(argv[2], ios::out | ios::trunc);
  for (int j = 0; j < i; j++) {
    outFile << arr[j] << endl;
  }

  outFile.close();
  InFile.close();
  return 0;
}
