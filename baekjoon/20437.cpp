#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, K;
string W;
vector<int> v;
vector<int> detect_idx[26];

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> W;
		cin >> K;

		for (int i = 0; i < W.size(); i++) {
			int idx = W[i] - 'a';
			detect_idx[idx].push_back(i);
		}
		for (int i = 0; i < 26; i++) {
			if (detect_idx[i].size() >= K) v.push_back(i);
		}
		if (v.empty())
			cout << -1 << endl;
		else {
			//v�� �ִ� �ֵ鸸 �������� �� detect_idx����
			int mini = 1000000;
			int maxi = 0;
			for (int i = 0; i < v.size(); i++) {
				int idx = v[i];
				//int cnt1 = 0;
				//int cnt2 = 0;

				for (int j = 0; j + K - 1 < detect_idx[idx].size(); j++) {
					int cnt1 = detect_idx[idx][j + K - 1] - detect_idx[idx][j] + 1;
					mini = min(cnt1, mini);
					maxi = max(cnt1, maxi);
				}
			}
			cout << mini << " " << maxi << endl;

		}

		for (int i = 0; i < 26; i++) {
			if (!detect_idx[i].empty())
				detect_idx[i].erase(detect_idx[i].begin(), detect_idx[i].end());
		}
		v.erase(v.begin(), v.end());
		//� ���ڸ� ��Ȯ�� K���� �����ϴ� ���� ª�� ���� ���ڿ��� ����
		//� ���ڸ� ��Ȯ�� K���� �����ϰ� ���ڿ��� ù������ ������ ���ڰ�
		//�ش� ���ڷ� ���� ���� �� ���� ���ڿ��� ����
	}

	return 0;
}