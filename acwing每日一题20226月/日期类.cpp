#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define x first
#define y second
const int inf = 0x3f3f3f3f;
int t;
int f[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isRun(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return true;
	return false;
}

int main() 
{
	cin >> t; while (t--) {
		int y, m, d;
		cin >> y >> m >> d;
		int mon = f[m];
		if (isRun(y)) mon++;
		if (d == mon) {
			if (m == 12) y++, m = 1, d = 1;
			else m++, d = 1;
		}
		else d++;
		printf("%04d-%02d-%02d\n", y, m, d);
	}
    return 0;
}