#include <iostream>
#include <deque>

using namespace std;

int printOrder(deque < pair<int, int>> dq, int m) {
	//Q���� ���ǿ��� ���� m�� ���°��!
	int ans = 0;
	while (!dq.empty()) {
		pair<int, int> f = dq.front();
		int flag = 0;
		for (size_t i = 1; i < dq.size(); i++) {
			if (f.second < dq[i].second) { //�켱 ������ �� ū�� �ڿ� ����
				int tmp = dq[i].second;
				dq.pop_front();
				dq.push_back(f);
				flag = 1;
				break;
			}
		}
		//�� �����µ� pop ������
		if (!flag) {
			ans++;
			if (f.first == m)
				break;
			else
				dq.pop_front();
		}
	}

	return ans;
}


int main() {
	int T, N, M;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		deque < pair<int, int>> q;

		for (int i = 0; i < N; i++) {
			int pri;
			cin >> pri;
			q.push_back(make_pair(i, pri));
		}

		cout << printOrder(q, M) << endl;
	}


	return 0;
}