#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

bool st[N];
int n, a[N];

void dfs(int index, int sum)
{
    if (index == n + 1)
    {
        for (int i = 1; i <= sum; i++) cout << a[i] << " ";
        cout << endl;
        return;
    }
    
    a[sum + 1] = index;
    dfs(index + 1, sum + 1);
    a[sum + 1] = 0;
    dfs(index + 1, sum);
}

int main()
{
    cin >> n;
    dfs(1, 0);
    return 0;
}