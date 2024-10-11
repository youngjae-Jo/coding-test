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
			//v에 있는 애들만 뒤져보면 됨 detect_idx에서
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
		//어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열의 길이
		//어떤 문자를 정확히 K개를 포함하고 문자열의 첫번쨰와 마지막 글자가
		//해당 문자로 같은 가장 긴 연속 문자열의 길이
	}

	return 0;
}