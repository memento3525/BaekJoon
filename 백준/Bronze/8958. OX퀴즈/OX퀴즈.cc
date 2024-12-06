#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;

        int score = 0;
        int combo = 0;
        for (char c : str)
        {
            if (c == 'O')
            {
                ++combo;
                score += combo;
            }
            else // X
            {
                combo = 0;
            }
        }

        cout << score << '\n';
    }
}