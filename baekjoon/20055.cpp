#include <iostream>
#include <vector>

using namespace std;
int N, K;
int stage = 0;
int up[200] = { 1, };
int down[200];
int ans = 1;

struct belt {
	int robot = 0;
	int energy = 0;
};
belt A[201];
vector<int> v;

int is_end() {
	int res = 0;
	int cnt = 0;
	for (int i = 1; i <= 2 * N; i++) {
		if (A[i].energy == 0)
			cnt++;
	}
	if (cnt >= K)
		res = 1;
	return res;
}

void move() {

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 2 * N) {
			if (A[1].energy && !A[1].robot) {
				A[v[i]].robot = 0;
				A[1].energy--;
				if (down[stage] == 1) {// ������ ���� ���� ������
					A[1].robot = 0;
					v.erase(v.begin() + i--);
				}
				else {//�Ϲ����� ���
					A[1].robot = 1;
					v[i] = 1;
				}
			}
		}
		else {
			if (A[v[i] + 1].energy && !A[v[i] + 1].robot) {
				A[v[i]].robot = 0;
				A[v[i] + 1].energy--;
				if (down[stage] == v[i] + 1) {
					A[v[i] + 1].robot = 0;
					v.erase(v.begin() + i--);
				}
				else {
					A[v[i] + 1].robot = 1;
					v[i]++;
				}
			}
		}
	}
}

void solve() {
	down[0] = N;
	for (int i = 1; i < 2 * N; i++) {
		up[i] = 2 * N + 1 - i;
		if (i < N)
			down[i] = N - i;
		else if (i >= N)
			down[i] = 3 * N - i;
	}

	while (1) {

		stage++; // step1, stage �ϳ� �����ϴ°ɷ� ��Ʈ�� �̵�
		if (stage == 2 * N)	stage = 0;

		if (A[down[stage]].robot) {// �κ� ������ ������ �����ϸ� ����
			if (v[0] == down[stage]) {//�κ�����
				v.erase(v.begin());
			}
			A[down[stage]].robot = 0;
		}

		move(); //step 2
		//if (!A[up[stage]].robot && A[up[stage]].energy) {//step 3
		if (A[up[stage]].energy) {//step 3
			A[up[stage]].robot = 1; // �κ� �ø�
			A[up[stage]].energy--; // ������ ����
			v.push_back(up[stage]);
		}

		if (is_end()) {
			cout << ans;
			return;
		}
		ans++;
	}

}


int main() {
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++)
		cin >> A[i].energy;

	solve();
	return 0;
}