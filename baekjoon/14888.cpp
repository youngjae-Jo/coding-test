#include <iostream>

using namespace std;

int N;
int A[12];
int n_op[4];
int M = -1000000001;
int m = 1000000001;

int calc(int mode, int n1, int n2) {
	int res = 0;
	if (mode == 0)
		res = n1 + n2;
	else if (mode == 1)
		res = n1 - n2;
	else if (mode == 2)
		res = n1 * n2;
	else if (mode == 3)
		res = n1 / n2;
	return res;
}

void find_(int numb, int total) {
	if (numb == N) {
		if (total > M)
			M = total;
		if (total < m)
			m = total;
		return;
	}

	int temp = total;
	for (int i = 0; i < 4; i++) {//현재에서 4개
		if (n_op[i] > 0) {
			n_op[i]--;
			find_(numb + 1, calc(i, temp, A[numb + 1]));
			n_op[i]++;
		}
	}

}


int main() {
	cin >> N;
	A[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int j = 0; j < 4; j++)
		cin >> n_op[j]; //덧셈개수, 뺄셈 개수, 곱셈 개수, 나눗셈 개수
	find_(1, A[1]);
	cout << M << endl << m;

	return 0;
}