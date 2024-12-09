#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int* arr = new int[n]{};

    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        arr[i] = temp;
    }

    std::sort(arr, arr + n);

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << '\n';
    }

    delete[] arr;
}