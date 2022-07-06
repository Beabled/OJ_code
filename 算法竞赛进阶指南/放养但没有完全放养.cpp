#include <bits/stdc++.h>
using namespace std;
string s1, s2;
map<char, int> s;

int main()
{
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) s[s1[i]] = i;
    int res = 1, last = -1;
    for (int i = 0; i < s2.size(); i++)
        if (s[s2[i]] <= last) last = s[s2[i]], res++;
        else last = s[s2[i]];
    cout << res << "\n";
    return 0;
}