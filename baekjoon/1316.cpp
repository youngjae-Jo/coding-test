#include <iostream>

using namespace std;

int check_cont(string S) {
	//	bool is_there[26] = {false, }; //A�� 0, Z�� 25
	bool alp_flag[26] = { false, };

	for (int i = 0; i < 26; i++) {//�ʱ�ȭ
		//is_there[i] = false;
		alp_flag[i] = false;
	}

	for (int i = 0; i < S.size(); i++) {
		if (i >= 1 && S[i] != S[i - 1]) {//�ٸ��� ��������
			int post_idx = S[i - 1] - 'a';
			alp_flag[post_idx] = true;
		}
		int idx = S[i] - 'a';
		if (alp_flag[idx] == true) //������ ���Դ��� �� ����
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