// Example: sorting 10 integers
// ----------------------------------
// Pedro Ribeiro (DCC/FCUP) - 04/10/2019
// ----------------------------------

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  // Example array
  int v[10] = {33, 4, 28, 18, 15, 2, 8, 17, 42, 39};

  cout << "Before sorting: ";
  for (int i=0; i<10; i++)
    cout << v[i] << " ";
  cout << endl;

  // Call to standard sort algorithm in C++
  // sort(array_start, array_end)
  sort(v, v+10);

  cout << "After sorting: ";
  for (int i=0; i<10; i++)
    cout << v[i] << " ";
  cout << endl;

  return 0;
}
