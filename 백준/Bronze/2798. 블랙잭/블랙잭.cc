#include <iostream>
#include <vector>
using namespace std;

void Combi(vector<int> v, int cur);

int n;
int pickSize = 3;
int maxValue;
vector<int> cards;
int result = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> maxValue;

    cards = vector<int>(n);

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        cards[i] = temp;
    }

    vector<int> v;
    Combi(v, -1);

    cout << result;
}

void Combi(vector<int> v, int start)
{
    if (v.size() == pickSize)
    {
        int sum = 0;
        for (const int& index : v)
        {
            sum += cards[index];
        }

        if (sum > maxValue)
            return;

        if (result < sum)
            result = sum;

        return;
    }

    for (int i = start + 1; i < n; ++i)
    {
        v.push_back(i);
        Combi(v, i);
        v.pop_back();
    }
}