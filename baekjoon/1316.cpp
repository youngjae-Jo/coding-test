#include <iostream>

using namespace std;

int check_cont(string S) {
	//	bool is_there[26] = {false, }; //A가 0, Z가 25
	bool alp_flag[26] = { false, };

	for (int i = 0; i < 26; i++) {//초기화
		//is_there[i] = false;
		alp_flag[i] = false;
	}

	for (int i = 0; i < S.size(); i++) {
		if (i >= 1 && S[i] != S[i - 1]) {//다른게 나왔으면
			int post_idx = S[i - 1] - 'a';
			alp_flag[post_idx] = true;
		}
		int idx = S[i] - 'a';
		if (alp_flag[idx] == true) //이전에 나왔던게 또 나옴
			return 0;
	}
	return 1;
}


int main() {
	int N, ans;
	string s;

	cin >> N;
	ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> s;
		ans += check_cont(s);
	}
	cout << ans;
	return 0;
}