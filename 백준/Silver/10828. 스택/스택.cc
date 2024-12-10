#include <iostream>
#include <vector>
using namespace std;

class MyStack
{
    vector<int> v;

public:
    void push(int n)
    {
        v.emplace_back(n);
    }

    void pop()
    {
        if (v.size() == 0)
        {
            cout << "-1" << '\n';
            return;
        }

        cout << v.back() << '\n';
        v.pop_back();
    }

    void size() const
    {
        cout << v.size() << '\n';
    }

    void empty() const
    {
        cout << ((v.size() == 0) ? "1" : "0") << '\n';
    }

    void top() const
    {
        if (v.size() == 0)
        {
            cout << "-1" << '\n';
            return;
        }

        cout << v.back() << '\n';
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    MyStack stack;

    string temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;

        if (temp == "push")
        {
            int num;
            cin >> num;
            stack.push(num);
        }
        else if (temp == "pop")
        {
            stack.pop();
        }
        else if (temp == "size")
        {
            stack.size();
        }
        else if (temp == "empty")
        {
            stack.empty();
        }
        else if (temp == "top")
        {
            stack.top();
        }
    }
}