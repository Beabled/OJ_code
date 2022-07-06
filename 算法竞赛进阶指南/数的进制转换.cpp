#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n;
string str;
vector<int> res, nums;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y >> str;
        for (auto e: str)
        {
            if (e <= '9') nums.push_back(e - '0');
            else if (e >= 'A' && e <= 'Z') nums.push_back(e - 'A' + 10);
            else nums.push_back(e - 'a' + 36);
        }
        res.clear();
        reverse(nums.begin(), nums.end());
        while (nums.size())
        {
            int t = 0;
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                nums[i] += t * x;
                t = nums[i] % y;
                nums[i] /= y;
            }
            res.push_back(t);
            while (nums.size() && !nums.back()) nums.pop_back();
        }
        cout << x << " " << str << "\n" << y << " ";
        reverse(res.begin(), res.end());
        for (auto e: res)
        {
            if (e <= 9) cout << e;
            else if (e >= 10 && e <= 35) cout << char(e - 10 + 'A');
            else cout << char(e - 36 + 'a'); 
        }
        cout << "\n\n";
    }
    return 0;
}