// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> res;
    vector<int> specialSort(int N) {
        res.push_back(1);
        if (N == 1) return res;
        if (compare(1, 2)) res.push_back(2);
        else res.insert(res.begin(), 2);
        for (int i = 3; i <= N; i++)
        {
            int l = 0, r = res.size() - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (compare(res[mid], i)) l = mid;
                else r = mid - 1;
            }
            res.push_back(i);
            for (int j = res.size() - 2; j > r; j -- ) swap (res[j], res[j + 1]);
            if (!compare(res[r], i)) swap(res[r], res[r + 1]);
            
        }
        return res;
    }
};