// Example of custom sorting of persons (using lambda declarations)
// First increasingly by age and in case of tie be alphabetical order
// ----------------------------------
// Pedro Ribeiro (DCC/FCUP) - 02/10/2022
// ----------------------------------

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Type to store a person
typedef struct {
  int age;
  string name;
} Person;

int main() {
  int n;

  cin >> n;
  Person v[n];

  for (int i=0; i<n; i++)
    cin >> v[i].age >> v[i].name;

  // Using anonymous lambda declaration
  sort(v, v+n,
       [](const Person & p1, const Person & p2) {
           if (p1.age < p2.age) return true;
           if (p1.age > p2.age) return false;
           return p1.name.compare(p2.name)<0;
       }
       );
  
  for (int i=0; i<n; i++)
    cout << v[i].age << " " << v[i].name << endl;
  
  return 0;
}
