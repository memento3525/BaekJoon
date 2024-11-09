#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    string str;
    int n;
    cin >> str >> n;
    
    std::ostringstream oss;

    for (int i = 0; i < n; ++i)
        oss << str;
    
    cout << oss.str() << endl;
    
    return 0;
}