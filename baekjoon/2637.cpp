#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int tUse[101], cnt[101]; //몇번 사용될 것인가, 필요한 부품의 개수

int main() {
	int N = 0, M = 0;
	cin >> N;
	cin >> M;
	vector<pair<int, int>>v[101];
	for (int i = 0; i < M; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		v[X].push_back(make_pair(Y, Z));
		tUse[Y]++;
	}
	vector<int> ans;
	queue<int> q;
	q.push(N);
	cnt[N] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (v[cur].empty()) //기본 부품
			ans.push_back(cur);
		for (auto c : v[cur]) { //N~필요한 하위 부품들로 계속 내려가기
			int next = c.first;
			int count = c.second;
			cnt[next] += cnt[cur] * count; //현재 부품 cur를 만들기 위해 next가 count개 필요
			if (--tUse[next] == 0) //next를 한번 털었으니까, 털고나니 다 쓴거면 걔도 이제 하위 부품 보러가야됨
				q.push(next);
		}
	}
	sort(ans.begin(), ans.end());

	for (auto i : ans)
		cout << i << " " << cnt[i] << endl;
	return 0;
}