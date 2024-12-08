#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int five = n / 5;
    int remain = n % 5;

    while (five > 0 && remain % 3 != 0)
    {
        five -= 1;
        remain += 5;
    }

    if (remain % 3 != 0)
    {
        cout << "-1";
        return 0;
    }

    int three = remain / 3;

    cout << five + three;
}