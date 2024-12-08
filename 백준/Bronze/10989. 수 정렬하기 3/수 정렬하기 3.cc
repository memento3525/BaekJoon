#include <iostream>
using namespace std;

int main(void)
{    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n;
    cin >> n;

    int arr[10001]{};

    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        ++arr[temp];
    }

    for (int i = 1; i <= 10000; ++i)
    {
        if (arr[i] == 0) continue;

        for (int k = 0; k < arr[i]; ++k)
            cout << i << '\n';
    }
}