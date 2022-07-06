#include <bits/stdc++.h>
using namespace std;
string a, b;
int t;

string dfs(string seq, int &u) 
{
    vector<string> seqs;
    u++;
    while (seq[u] == '0') seqs.push_back(dfs(seq, u));
    u++;
    sort(seqs.begin(), seqs.end());
    string res = "0";
    for (auto e: seqs) res += e;
    res += '1';
    return res; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        a = '0' + a + '1', b = '0' + b + '1';
        int u1 = 0, u2 = 0;
        if (dfs(a, u1) == dfs(b, u2)) puts("same");
        else puts("different");
    }
    return 0;
}