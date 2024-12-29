#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> words;
int ret = 0;

void Go(int start, int learnCnt, int mask)
{
    if (start >= 26) return;
    if (learnCnt == 0)
    {
        int cnt = 0;
        for (int word : words)
        {
            if ((word & mask) == word)
                ++cnt;
        }

        if (cnt > ret)
            ret = cnt;

        return;
    }

    for (int i = start + 1; i < 26; ++i)
    {
        if (mask & (1 << i)) continue;

        mask |= (1 << i);
        Go(i, learnCnt - 1, mask | (1 << i));
        mask &= ~(1 << i);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    words.resize(n);
    string str;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        for (char c : str)
            words[i] |= (1 << (c - 'a'));
    }

    // 최소 5개 이상 알아야 단어 읽는다.
    if (m < 5)
    {
        cout << 0;
    }
    else if (m == 26)
    {
        cout << n;
    }
    else
    {
        int mask = 0;
        mask |= 1 << ('a' - 'a');
        mask |= 1 << ('n' - 'a');
        mask |= 1 << ('t' - 'a');
        mask |= 1 << ('i' - 'a');
        mask |= 1 << ('c' - 'a');
        Go(0, m - 5, mask);

        cout << ret;
    }
}