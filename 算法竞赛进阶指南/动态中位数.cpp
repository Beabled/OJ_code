#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int t, m, now;

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int res = 1;
        priority_queue<int, vector<int>, greater<int>> heap1;
        priority_queue<int, vector<int>, less<int>> heap2;
        cin >> now >> m;
        cout << now << " " << (m + 1) / 2 << "\n";
        int a;
        cin >> a;
        cout << a << " ";
        heap1.push(a);
        for (int i = 2; i <= m; i++)
        {
            cin >> a;
            if (a >= heap1.top()) heap1.push(a);
            else heap2.push(a);
            if (i & 1)
            {
                if (heap1.size() < heap2.size())
                {
                    heap1.push(heap2.top());
                    heap2.pop();
                }
                else if (heap1.size() - heap2.size() == 3)
                {
                    heap2.push(heap1.top());
                    heap1.pop();
                }
                cout << heap1.top() << " ";
                res++;
                if (res % 10 == 0) cout << "\n";
            }
        }
        if (res % 10) cout << "\n";
    }
    return 0;
}