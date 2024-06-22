#include<iostream>
#include<vector>
using namespace std;
int n, m, S, T, n1, n2, ret;
int visited1[100001], visited2[100001];
vector<int> v[100001];

bool go2(int t, int s) {
	if (!v[t].size() and s != t) return false;

	bool flag = false;
	for (auto var : v[t]) {
		if (var == s) {
			flag = true; continue;
		}
		if (visited2[var]) {
			flag = true; continue;
		}
		visited2[var] = 1;
		if (!go2(var, s)) visited2[var] = 0;
		else flag = true;
	}
	return flag;
}

bool go1(int s, int t) {
	if (!v[s].size() and s != t) return false;

	bool flag = false;
	for (auto var : v[s]) {
		if (var == t) {
			flag = true; continue;
		}
		if (visited1[var]) {
			flag = true; continue;
		}
		visited1[var] = 1;
		if (!go1(var, t)) visited1[var] = 0;
		else flag = true;
	}
	return flag;
}

int check() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i == S or i == T) continue;
		if (visited1[i] and visited2[i]) cnt++;
	}
	return cnt;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
	}
	cin >> S >> T;
	visited1[S] = 1; visited1[T] = 1;
	visited2[S] = 1; visited2[T] = 1;
	go1(S, T);
	go2(T, S);
	cout << check();
}