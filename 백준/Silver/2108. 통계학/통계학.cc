#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> map;
    double sum = 0;
    int min = 4001;
    int max = -4001;
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        v[i] = temp;
        sum += temp;
        ++map[temp];

        if (temp < min)
            min = temp;

        if (temp > max)
            max = temp;
    }

    sort(v.begin(), v.end());

    // 1. 산술평균
    cout << (int)round(sum / n) << '\n';

    // 2. 중앙값
    int middleIndex = ((n == 1) ? 0 : ((n - 1) / 2));
    int middle = v[middleIndex];
    cout << middle << '\n';
    
    // 3. 최빈값
    vector<pair<int, int>> mapV(map.begin(), map.end());
    std::sort(mapV.begin(), mapV.end(), [](const auto& a, const auto& b) 
        {
            if (a.second > b.second) return true;
            if (a.second < b.second) return false;
            if (a.first < b.first) return true;
            if (a.first > b.first) return false;

            return true;
        });

    if (mapV.size() > 1 && (mapV[0].second == mapV[1].second))
    {
        cout << mapV[1].first << '\n';
    }
    else
    {
        cout << mapV[0].first << '\n';
    }

    // 4. 범위
    cout << max - min;
}