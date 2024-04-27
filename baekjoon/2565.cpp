#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int A[501];
vector<int> v;
int dp[501];
int s;
int maxi = 0;

int main() {
	cin >> s;
	int res = 0;
	int Anum, Bnum;
	for (int i = 1; i <= s; i++) {
		cin >> Anum >> Bnum;
		A[Anum] = Bnum;
		dp[Anum] = 1;
		v.push_back(Anum);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (A[v[j]] < A[v[i]]) {
				dp[v[i]] = max(dp[v[i]], dp[v[j]] + 1);
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (maxi < dp[v[i]])
			maxi = dp[v[i]];
	}
	res = s - maxi;
	cout << res;

	return 0;
}