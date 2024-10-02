#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N = 0;
	int L = 0;
	cin >> N >> L;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	//N���� �����̸� ���̰� L�� �κ������ ��������, 
	//��� �������̸� ���� ���� �ʿ��� �κ������� �ּ� ����
	//a-b 
	sort(v.begin(), v.end());
	int prevEnd = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (prevEnd >= v[i].second)
			continue;
		int start = max(v[i].first, prevEnd);
		int last = v[i].second;
		int cnt = (last - start) / L;
		if ((last - start) % L != 0)
			cnt++;
		ans += cnt;
		prevEnd = start + cnt * L;
	}


	cout << ans;
	return 0;
}