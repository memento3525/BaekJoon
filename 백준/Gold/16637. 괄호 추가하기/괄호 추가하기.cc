#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> nums;
vector<char> operChar;

int Oper(char o, int a, int b)
{
    if (o == '+') return a + b;
    if (o == '-') return a - b;
    if (o == '*') return a * b;
}

int result = INT32_MIN;
void Go(int i, int n)
{
    if (i == nums.size() - 1)
    {
        result = max(result, n);
        return;
    }

    Go(i + 1, Oper(operChar[i], n, nums[i + 1]));

    if (i + 2 <= nums.size() - 1)
    {
        int temp = Oper(operChar[i + 1], nums[i + 1], nums[i + 2]);
        Go(i + 2, Oper(operChar[i], n, temp));
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int tempI;
    char tempC;
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
        {
            cin >> tempI;
            nums.push_back(tempI);
        }
        else
        {
            cin >> tempC;
            operChar.push_back(tempC);
        }
    }

    Go(0, nums[0]);
    cout << result;
}