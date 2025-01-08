#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a[33]; // next, score;

int token[4];
int dice[10];
int ret = 0;

int _hasBlue(int i)
{
    if (i == 5) return 21;
    if (i == 10) return 24;
    if (i == 15) return 26;
    return -1;
}

int _move(int cur, int step)
{
    int blueNext = _hasBlue(cur);
    if (blueNext != -1)
    {
        cur = blueNext;
        --step;
    }

    while (step > 0)
    {
        int next = a[cur][0];
        cur = next;
        --step;
    }
    return cur; // a[cur][1];
}

bool _existToken(int pos)
{
    if (pos >= 32) return false;

    for (int i : token)
        if (i == pos) return true;
    
    return false;
}

int cnt = 0;
void _go(int moveIndex, int score)
{
    if (moveIndex == 10)
    {
        if (score > ret)
            ret = score;

        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (token[i] >= 32) continue;

        // 캐싱
        int origin = token[i];
        int originScore = score;
        
        // 동작
        int cur = token[i];
        int targetPos = _move(cur, dice[moveIndex]);
        if (!_existToken(targetPos))
        {
            token[i] = targetPos;
            score += a[targetPos][1];
            _go(moveIndex + 1, score);
        }

        // 복구
        token[i] = origin;
        score = originScore;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    a[0] = { 1, 0 };
    a[1] = { 2, 2 };
    a[2] = { 3, 4 };
    a[3] = { 4, 6 };
    a[4] = { 5, 8 };
    a[5] = { 6, 10 };
    a[6] = { 7, 12 };
    a[7] = { 8, 14 };
    a[8] = { 9, 16 };
    a[9] = { 10, 18 };
    a[10] = { 11, 20 };
    a[11] = { 12, 22 };
    a[12] = { 13, 24 };
    a[13] = { 14, 26 };
    a[14] = { 15, 28 };
    a[15] = { 16, 30 };
    a[16] = { 17, 32 };
    a[17] = { 18, 34 };
    a[18] = { 19, 36 };
    a[19] = { 20, 38 };
    a[20] = { 32, 40 }; // 가장큰점수

    a[21] = { 22, 13 };
    a[22] = { 23, 16 };
    a[23] = { 29, 19 };

    a[24] = { 25, 22 };
    a[25] = { 29, 24 };

    a[26] = { 27, 28 };
    a[27] = { 28, 27 };
    a[28] = { 29, 26 };

    a[29] = { 30, 25 };

    a[30] = { 31, 30 };
    a[31] = { 20, 35 };

    a[32] = { 32, 0 }; // 제자리 루프

    for (int i = 0; i < 10; ++i)
        cin >> dice[i];

    _go(0, 0);

    cout << ret;
    return 0;
}