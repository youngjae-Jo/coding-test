ㅇ#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

void input();
void solve();

int N, Q;
int line;
int maap[65][65];
int m[65][65]; //돌리기 전에 
int L[1001];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };


void input() {
	cin >> N >> Q;
	line = pow(2, N);
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= line; j++) {
			cin >> maap[i][j];
		}
	}

	for (int i = 1; i <= Q; i++)
		cin >> L[i];
}

void rotate(int idx) {//부분 격자로 나누고, 회전

	if (L[idx] == 0)
		return;
	int sz = pow(2, L[idx]);

	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= line; j++) {
			m[i][j] = maap[i][j]; // 돌리기 전 배열 복사
		}
	}

	for (int i = 1; i < line; i = i + sz) {
		for (int j = 1; j < line; j = j + sz) {

			int leng = pow(2, L[idx]);
			int ni = i;
			int nj = j;
			int nl = L[idx];

			while (leng >= 1) {

				for (int iter = 0; iter < leng; iter++) {
					maap[ni + iter][nj + leng - 1] = m[ni][nj + iter]; //윗줄->오른쪽줄
					maap[ni + leng - 1][nj + leng - 1 - iter] = m[ni + iter][nj + leng - 1]; // 오른쪽줄->아랫줄
					maap[ni + leng - 1 - iter][nj] = m[ni + leng - 1][nj + leng - 1 - iter]; // 아랫줄->왼쪽줄
					maap[ni][nj + iter] = m[ni + leng - 1 - iter][nj]; // 왼쪽줄->윗줄
				}

				leng -= 2;
				ni++;
				nj++;
			}

		}
	}

}

void is_tri() {//얼음이 있는 칸과 3개 미만 인접한 칸의 얼음양 1 줄어듦
	int candi[65][65];
	for (int row = 1; row <= line; row++) { //얼음이 있는 칸과 3개 미만 인접한 칸의 얼음양 1 줄어듦
		for (int col = 1; col <= line; col++) {
			candi[row][col] = 0;
		}
	}


	for (int row = 1; row <= line; row++) { //얼음이 있는 칸과 3개 미만 인접한 칸의 얼음양 1 줄어듦
		for (int col = 1; col <= line; col++) {

			int check = 0;

			for (int idx = 0; idx < 4; idx++) {
				int nx = row + dx[idx];
				int ny = col + dy[idx];

				if (nx >= 1 && nx <= line && ny >= 1 && ny <= line) {
					if (maap[nx][ny] > 0)
						check++;
				}
			}
			if (check < 3 && maap[row][col] != 0)
				candi[row][col]++;
		}
	}
	for (int row = 1; row <= line; row++) {
		for (int col = 1; col <= line; col++) {
			maap[row][col] -= candi[row][col];
		}
	}

}

void solve() {
	for (int i = 1; i <= Q; i++) {
		rotate(i);//부분 격자로 나누고, 회전
		is_tri();
	}
}

int maxA = 0;
int crrnt = 0;

void search(bool visited[][65], int row, int col) {

	if (row < 1 || row > line || col <1 || col >line || visited[row][col] || !maap[row][col])
		return;
	crrnt++;

	visited[row][col] = true;
	maxA = max(maxA, crrnt);

	for (int i = 0; i < 4; i++) {
		int nr = row + dx[i];
		int nc = col + dy[i];
		search(visited, nr, nc);
	}
}

void max_area() {
	bool visited[65][65];
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= line; j++)
			visited[i][j] = false;
	}

	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= line; j++) {
			if (maap[i][j] && !visited[i][j]) {
				int current_vol = 0;
				search(visited, i, j);
				crrnt = 0;
			}
		}
	}
}

void output() {
	int sum = 0;
	max_area();

	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= line; j++) {
			sum += maap[i][j];
		}
	}

	cout << sum << endl;
	cout << maxA; //둘째 줄에 가장 큰 덩어리가 차지하는 칸의 개수
}

int main() {
	input();
	solve();
	output();

	return 0;
}
/*
cout << "let's check" << endl;
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= line; j++) {
			cout << maap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
*/