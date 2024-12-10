#include <iostream>
#include <vector>
using namespace std;

class MyQueue
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

        cout << v.front() << '\n';
        v.erase(v.begin());
    }

    void size() const
    {
        cout << v.size() << '\n';
    }

    void empty() const
    {
        cout << ((v.size() == 0) ? "1" : "0") << '\n';
    }

    void front() const
    {
        if (v.size() == 0)
        {
            cout << "-1" << '\n';
            return;
        }

        cout << v.front() << '\n';
    }

    void back() const
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

    MyQueue queue;

    string temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;

        if (temp == "push")
        {
            int num;
            cin >> num;
            queue.push(num);
        }
        else if (temp == "pop")
        {
            queue.pop();
        }
        else if (temp == "size")
        {
            queue.size();
        }
        else if (temp == "empty")
        {
            queue.empty();
        }
        else if (temp == "front")
        {
            queue.front();
        }
        else if (temp == "back")
        {
            queue.back();
        }
    }
}
