#include <iostream>

using namespace std;

const int N = 11;

int a[N], n;
bool st[N];

void dfs(int index)
{
    if (index == n + 1)
    {
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            a[index] = i;
            st[i] = true;
            dfs(index + 1);
            st[i] = false;
        }
    }
}

int main()
{
    n = 8;
    dfs(1);
    return 0;
}