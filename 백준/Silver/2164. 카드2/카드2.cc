#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int* arr = new int[2 * n];

    for (int i = 0; i <= n; ++i)
    {
        arr[i] = i + 1;
    }

    int top = 0;
    int bottom = n - 1;

    while (top != bottom)
    {
        ++top;

        arr[bottom + 1] = arr[top];

        ++top;
        ++bottom;
    }

    cout << arr[top];
    delete[] arr;
}