#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int tUse[101], cnt[101]; //��� ���� ���ΰ�, �ʿ��� ��ǰ�� ����

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

		if (v[cur].empty()) //�⺻ ��ǰ
			ans.push_back(cur);
		for (auto c : v[cur]) { //N~�ʿ��� ���� ��ǰ��� ��� ��������
			int next = c.first;
			int count = c.second;
			cnt[next] += cnt[cur] * count; //���� ��ǰ cur�� ����� ���� next�� count�� �ʿ�
			if (--tUse[next] == 0) //next�� �ѹ� �о����ϱ�, �а��� �� ���Ÿ� �µ� ���� ���� ��ǰ �������ߵ�
				q.push(next);
		}
	}
	sort(ans.begin(), ans.end());

	for (auto i : ans)
		cout << i << " " << cnt[i] << endl;
	return 0;
}