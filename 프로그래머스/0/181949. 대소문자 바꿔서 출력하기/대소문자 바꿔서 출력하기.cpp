#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    int offset = 'a' - 'A'; // 32
    int numOfZ = 'Z';
    
    for (char c : str)
    {
        if (c < numOfZ) // 대문자인경우
            cout << char(c + offset);
        else // 소문자
            cout << char(c - offset);
    }

    cout << endl;
    
    return 0;
}