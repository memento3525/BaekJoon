#include <iostream>
#include <vector>
using namespace std;

struct Item
{
    int w, v;
};

int n, k;
int dp[100001][101]; // 현재 무게일 때 가치, 마지막 방문
vector<Item> map;

int Go(int curMass, int start)
{
    if (curMass > k)
        return -200001; // 실패

    int& ret = dp[curMass][start];
    if (ret != 0) return ret;

    for (int i = start; i < n; ++i)
    {
        ret = max(ret, (Go(curMass + map[i].w, i + 1) + map[i].v));
    }

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    map.resize(n);

    for (int i = 0; i < n; ++i)
    {
        Item item{};
        cin >> item.w >> item.v;
        map[i] = item;
    }

    cout << Go(0, 0);
}