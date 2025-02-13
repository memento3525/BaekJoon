#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX_N = 200'002;
int t, n, m;
int tree[MAX_N + 1];
map<int, int> mp;

void Update(int i, int value)
{
    while (i <= MAX_N)
    {
        tree[i] += value;
        i += (i & -i);
    }
}

int Sum(int i)
{
    int ret = 0;
    while (i > 0)
    {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        fill(tree, tree + (MAX_N + 1), 0);
        mp.clear();
        
        cin >> n >> m;

        int offset = 100'001;
        for (int i = 1; i <= n; ++i)
        {
            Update(i + offset, 1);
            mp[i] = i + offset; // n번 책은 i + offset 위치에 있음
        }

        int temp;
        for (int i = 0; i < m; ++i)
        {
            cin >> temp;
            int index = mp[temp]; // n번 책이 있었던 위치
            cout << Sum(index) - 1 << " "; // 의 위에는 (배열기준 왼쪽에는) 책이 몇개있었는가?
            Update(index, -1); // n번 책이 있었던 위치의 오른쪽에서 -1씩 해준다(책을 뺀다)
            
            --offset;

            Update(offset, 1); // n번책이 새로운 위치(이전보다 왼쪽)로 이동하고, 해당 위치 오른쪽에 +1씩 해준다. 
            mp[temp] = offset; // 새로운 위치가 됨
        }

        cout << '\n';
    }
}