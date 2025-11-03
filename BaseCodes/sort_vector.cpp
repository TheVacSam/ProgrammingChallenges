// Example: sorting 10 integers
// ----------------------------------
// Pedro Ribeiro (DCC/FCUP) - 02/10/2022
// ----------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // Example array
  vector<int> v = {33, 4, 28, 18, 15, 2, 8, 17, 42, 39};

  cout << "Before sorting: ";
  for (int i=0; i<10; i++)
    cout << v[i] << " ";
  cout << endl;

  // Call to standard sort algorithm in C++
  // sort(iterator_start, iterator_end)
  sort(v.begin(), v.end());

  cout << "After sorting: ";
  for (int i=0; i<10; i++)
    cout << v[i] << " ";
  cout << endl;

  return 0;
}
