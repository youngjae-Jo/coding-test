#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> A(4, vector<int>(4));

//행의 개수>= 열의 개수 -> 모든 행에 대해서 정렬 , 가장 큰 행 기준으로 모든 행 크기 증가
//행의 개수<열의 개수 -> 모든 열에 대해서 정렬 , 가장 큰 열 기준으로 모든 열 크기 증가
//수,등장횟수  등장횟수 커지는 순으로, 여러개면 수가 커지는 순으로

void sort_R() {

}

void sort_C() {

}

int minToK(int r, int c, int k) {
	int res = 0;
	int i = 0;
	for (i; i < 100; i++) {
		if (A.size() >= A[1].size())
			sort_R();
		else
			sort_C();
	}
	if (i == 100)
		res = -1;

	return res;
}


int main() {
	int r, c, k;
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> A[i][j];
		}
	}
	cout << minToK(r, c, k);
	return 0;
}