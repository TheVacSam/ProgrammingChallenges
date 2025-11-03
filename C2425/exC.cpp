#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<int, int> lastPos;
    
    for (int i = 1; i <= n; i++) {
        int event;
        cin >> event;
        
        if (lastPos.find(event) != lastPos.end()) {
            cout << lastPos[event];
        } else {
            cout << -1;
        }
        
        if (i < n) cout << " ";
        
        lastPos[event] = i;
    }
    
    cout << endl;
    
    return 0;
}
