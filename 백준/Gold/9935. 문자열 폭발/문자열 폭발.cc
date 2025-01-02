#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, bomb;
    cin >> str >> bomb;

    string temp;
    for (char c : str)
    {
        temp += c;
        if (temp.size() >= bomb.size())
        {
            string subStr = temp.substr(temp.size() - bomb.size(), bomb.size());
            if (bomb == subStr)
                temp.erase(temp.end() - bomb.size(), temp.end());
        }
    }

    cout << (temp.empty() ? "FRULA" : temp);
}