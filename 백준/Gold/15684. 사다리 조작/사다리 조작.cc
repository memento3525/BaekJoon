#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> visited;
int width, m, height;
int ret = INT32_MAX;

bool IsValid()
{
    for (int x = 1; x <= width; ++x)
    {
        int current = x;
        for (int y = 1; y <= height; ++y)
        {
            if (visited[y][current])
                ++current;
            else if (visited[y][current - 1])
                --current;
        }

        if (current != x)
            return false;
    }
    return true;
}

void Combi(int here, int cnt)
{
    if (IsValid())
    {
        if (cnt < ret)
            ret = cnt;
        return;
    }

    for (int y = here; y <= height; ++y)
    {
        for (int x = 1; x <= width; ++x)
        {
            if (visited[y][x]) continue;
            if (visited[y][x - 1] || visited[y][x + 1]) continue;
            if (cnt + 1 > 3 || cnt + 1 >= ret) continue;
            
            visited[y][x] = 1;
            Combi(y, cnt + 1);
            visited[y][x] = 0;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> width >> m >> height;

    visited.resize(height + 1);
    for (int i = 0; i <= height; ++i)
        visited[i].resize(width + 2); // 좌우 범위검사 제외용

    int a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        visited[a][b] = 1;
    }

    Combi(1, 0);

    cout << ((ret == INT32_MAX) ? -1 : ret);
}