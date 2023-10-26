#include <iostream>
#include <cstdlib>

using namespace std;

int N;//4~20인 짝수
int S[20][20]; //S_ii = 0. S_ij 1~100
int start[10]; //1~N 사이의 수 N/2개
int m = 9999999;

int isStart(int i, int j) {
	int res = 0;
	for (int idx = 0; idx < 10; idx++) {
		if (start[idx] == i+1)
			res++;
		if (start[idx] == j+1)
			res++;
	}
	res /= 2;
	return res;
}

int isLink(int i, int j) {
	int res = 1;
	for (int idx = 0; idx < 10; idx++) {
		if (start[idx] == i+1 || start[idx] == j+1)
			res = 0;
	}
	return res;
}


//스타트팀과 링크팀의 능력치 차이 최소로
//a,b번 -> S_ab + S_ba  || c,d번 -> S_cd + S_dc
int count(int mode) {
	int sum = 0;
	//1~N 중에 절반(N/2개): start, 나머지: link
	if (mode == 0) { //start팀
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (isStart(i,j) && (i!=j)) {
					sum += S[i][j];
				}
			}
		}
	}
	if (mode == 1) { //start아닌팀
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (isLink(i, j) && (i != j)) {
					sum += S[i][j];
				}
			}
		}
	}

	return sum;
}
//번호 기반으로 팀을 저장, 
void split(int d, int next) {
	if (start[0] > N / 2)
		return;

	if (d == N / 2) {
		int sum_s = count(0);
		int sum_l = count(1);
		int dff = abs(sum_s - sum_l);
		if (dff < m)
			m = dff;
		return;
	}
	//모든 경우의 수를 구하기만 하면 됨
	for (int i = next; i < N; i++) {
			start[d] = i+1;
			split(d + 1, i+1);
	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin>>S[i][j];
		}
	}
	split(0,0);
	cout << m;
	return 0;
}
