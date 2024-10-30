#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int arr[100][100];
int ans;

void shape1(int r, int c, int mode) { // ㅡ |   시작점 r,c 모드 0 or 1
	int tmp = 0;
	if (mode == 0) tmp += arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r][c + 3];
	else if (mode == 1) tmp += arr[r][c] + arr[r + 1][c] + arr[r + 2][c] + arr[r + 3][c];

	if (tmp > ans) ans = tmp;
}
void shape2(int r, int c, int mode) { // z 2개 가능
	int tmp = 0;
	if (mode == 0) tmp += arr[r][c] + arr[r][c + 1] + arr[r + 1][c + 1] + arr[r + 1][c + 2];
	else if (mode == 1) tmp += arr[r][c] + arr[r + 1][c] + arr[r + 1][c - 1] + arr[r + 2][c - 1];

	if (tmp > ans) ans = tmp;
}
void shape3(int r, int c, int mode) { // ㄱ 4개 가능
	int tmp = 0;
	if (mode == 0) tmp += arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r + 1][c + 2];
	else if (mode == 1) tmp += arr[r][c] + arr[r][c + 1] + arr[r - 1][c + 1] + arr[r - 2][c + 1];
	else if (mode == 2) tmp += arr[r][c] + arr[r + 1][c] + arr[r + 1][c + 1] + arr[r + 1][c + 2];
	else if (mode == 3) tmp += arr[r][c] + arr[r][c + 1] + arr[r + 1][c] + arr[r + 2][c];

	if (tmp > ans) ans = tmp;
}
void shape4(int r, int c, int mode) { // ㅜ ㅓ ㅗ ㅏ //고쳐야행
	int tmp = 0;
	if (mode == 0) tmp += arr[r][c] + arr[r][c + 1] + arr[r][c + 2] + arr[r + 1][c + 1];
	else if (mode == 1) tmp += arr[r][c] + arr[r][c + 1] + arr[r - 1][c + 1] + arr[r + 1][c + 1];
	else if (mode == 2) tmp += arr[r][c] + arr[r][c + 1] + arr[r - 1][c + 1] + arr[r][c + 2];
	else if (mode == 3) tmp += arr[r][c] + arr[r + 1][c] + arr[r + 1][c + 1] + arr[r + 2][c];

	if (tmp > ans) ans = tmp;
}
void shape5(int r, int c) { // ㅁ
	int tmp = 0;
	tmp += arr[r][c] + arr[r][c + 1] + arr[r + 1][c] + arr[r + 1][c + 1];

	if (tmp > ans) ans = tmp;
}

int main() {
	int t = 1;
	while (1) {

		cin >> N;
		if (N == 0) break;

		ans = INT_MIN;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (j + 3 < N) shape1(i, j, 0);
				if (i + 3 < N) shape1(i, j, 1);

				if (i + 1 < N && j + 2 < N) shape2(i, j, 0);
				if (i + 2 < N && j - 1 >= 0) shape2(i, j, 1);

				if (i + 1 < N && j + 2 < N) {//ㄱ 시계 방향 회전
					shape3(i, j, 0);
					shape3(i, j, 2);
				}
				if (i - 2 >= 0 && j + 1 < N) shape3(i, j, 1);
				if (i + 2 < N && j + 1 < N) shape3(i, j, 3);

				//ㅜㅓㅗㅏ
				if (i + 1 < N && j + 2 < N) shape4(i, j, 0);
				if (i - 1 >= 0 && i + 1 < N && j + 1 < N) shape4(i, j, 1);
				if (i - 1 >= 0 && j + 2 < N) shape4(i, j, 2);
				if (i + 2 < N && j + 1 < N) shape4(i, j, 3);

				if (i + 1 < N && j + 1 < N) shape5(i, j);
			}
		}
		cout << t << ". " << ans << endl;
		t++;

	}
	return 0;
}