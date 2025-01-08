#include <iostream>
#include <vector>
using namespace std;

vector<string> gear;
vector<int> offset;

char _getL(int index) 
{ 
    int i = (6 + offset[index]) % 8;
    return gear[index][i];
}
char _getR(int index) 
{
    int i = (2 + offset[index]) % 8;
    return gear[index][i];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, k, index, dir;

    cin >> t;

    gear.resize(t);
    for (int i = 0; i < t; ++i)
        cin >> gear[i];

    offset.resize(t);

    cin >> k;
    vector<int> moving(t);
    for (int i = 0; i < k; ++i)
    {
        cin >> index >> dir;
        --index;

        moving[index] = dir;

        int left = index;
        int leftDir = -dir;
        while (left - 1 >= 0)
        {
            if (_getR(left - 1) == _getL(left))
                break;

            moving[left - 1] += leftDir;
            --left;
            leftDir = -leftDir;
        }

        int right = index;
        int rightDir = -dir;
        while (right + 1 < t)
        {
            if (_getR(right) == _getL(right + 1))
                break;

            moving[right + 1] += rightDir;
            ++right;
            rightDir = -rightDir;
        }

        // 회전 실제 적용
        for (int i = 0; i < t; ++i)
        {
            offset[i] = (offset[i] - moving[i] + 8) % 8;
            moving[i] = 0;
        }
    }

    int ret = 0;
    for (int i = 0; i < t; ++i)
    {
        if (gear[i][offset[i] % 8] == '1')
            ++ret;
    }

    cout << ret;
}