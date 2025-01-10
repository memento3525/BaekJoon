#include <iostream>
#include <vector>
using namespace std;

int psum_a[2002]; // 누적합
int psum_b[2002];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, m, n;
    cin >> t >> m >> n;

    vector<int> a(m + 1);
    vector<int> b(n + 1);

    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i];
        psum_a[i] = psum_a[i - 1] + a[i];
    }

    // 2배 길이로.
    for (int i = m + 1; i <= 2 * m; ++i)
        psum_a[i] = psum_a[i - 1] + a[i - m];

    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        psum_b[i] = psum_b[i - 1] + b[i];
    }

    // 2배 길이로.
    for (int i = n + 1; i <= 2 * n; ++i)
        psum_b[i] = psum_b[i - 1] + b[i - n];

    vector<int> aa(t + 1);
    vector<int> bb(t + 1);

    for (int slice = 1; slice <= m; ++slice)
    {
        for (int i = slice; i <= m + slice - 1; ++i)
        {
            int sum = psum_a[i] - psum_a[i - slice];
            if (sum <= t)
                ++aa[sum];

            if (slice == m) break; // 전체는 한 번만
        }
    }

    for (int slice = 1; slice <= n; ++slice)
    {
        for (int i = slice; i <= n + slice - 1; ++i)
        {
            int sum = psum_b[i] - psum_b[i - slice];
            if (sum <= t)
                ++bb[sum];

            if (slice == n) break; // 전체는 한 번만
        }
    }

    // 혼자 만드는 경우
    int ret = (aa[t] + bb[t]);
    
    // 두개로 만드는 경우
    for (int ai = 1; ai < t; ++ai)
        ret += (aa[ai] * bb[t - ai]);

    cout << ret;
}