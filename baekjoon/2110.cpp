#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;

int main() {
	cin >> N >> C;
	vector<int> loc;
	//������ ������ �ϳ�, �ִ� C��
	//���� ������ ������ ������ �Ÿ��� �ִ��
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		cin >> tmp;
		loc.push_back(tmp);
	}
	sort(loc.begin(), loc.end());
	int start = 1; //�Ÿ�
	int end = loc[N - 1] - loc[0];
	int mid;
	int ans = 0;

	while (start <= end) {
		int router = 1;
		int st = loc[0];

		mid = (start + end) / 2;
		for (int i = 1; i < N; i++) {
			if (loc[i] - st >= mid) {
				router++;
				st = loc[i];
			}
		}
		if (router >= C) {
			ans = max(ans, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << ans;
	return 0;
}