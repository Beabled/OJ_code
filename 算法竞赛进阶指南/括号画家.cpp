#include <bits/stdc++.h>
using namespace std;
string str;
stack<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> str;
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ')' && s.size() && str[s.top()] == '(') s.pop();
        else if (str[i] == ']' && s.size() && str[s.top()] == '[') s.pop();
        else if (str[i] == '}' && s.size() && str[s.top()] == '{') s.pop();
        else s.push(i);
        if (s.size()) res = max(res, i - s.top());
        else res = max(res, i + 1); 
    }
    cout << res << "\n";
    return 0;
}