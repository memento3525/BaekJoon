#include <iostream>
using namespace std;

int main(void)
{
    string input;
    cin >> input;
    
    string answer;
    for (char c : input)
    {
        if (islower(c))
            answer += toupper(c);
        else
            answer += tolower(c);
    }

    cout << answer;
}