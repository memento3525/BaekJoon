#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w;
    cin >> h >> w;

    vector<pair<int, int>> cloud;
    vector<vector<int>> visited;
    visited.resize(h);

    string str;
    for (int y = 0; y < h; ++y)
    {
        cin >> str;
        visited[y].resize(w);
        for (int x = 0; x < w; ++x)
        {
            if (str[x] == 'c')
                cloud.emplace_back(make_pair(y, x));

            visited[y][x] = str[x] == 'c' ? 0 : -1;
        }
    }

    for (int time = 1; time < w; ++time)
    {
        for (const auto& item : cloud)
        {
            int nx = item.second + time;
            if (nx >= w) continue;

            int ny = item.first;

            if (visited[ny][nx] == -1)
            {
                visited[ny][nx] = time;
            }
        }
    }

    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            cout << visited[y][x] << " ";
        }

        cout << '\n';
    }
}