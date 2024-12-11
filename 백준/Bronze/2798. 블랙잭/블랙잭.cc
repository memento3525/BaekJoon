#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, maxValue;

    cin >> n >> maxValue;

    vector<int> cards(n);

    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        cards[i] = temp;
    }

    int result = 0;
    for (int a = 0; a < n; ++a)
    {
        int sum1 = cards[a];
        if (sum1 > maxValue) continue;

        for (int b = 0; b < n; ++b)
        {
            if (a == b) continue;

            int sum2 = sum1 + cards[b];
            if (sum2 > maxValue) continue;

            for (int c = 0; c < n; ++c)
            {
                if (a == b) continue;
                if (a == c) continue;
                if (b == c) continue;

                int sum3 = sum2 + cards[c];
                if (sum3 > maxValue) continue;

                if (result < sum3)
                    result = sum3;
            }
        }
    }

    cout << result;
}