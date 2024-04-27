#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int bamb[501][501];
int DP[501][501];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int Move(int x, int y) {
	if (DP[x][y] != 0) return DP[x][y];
	DP[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (bamb[x][y] < bamb[nx][ny]) {
				DP[x][y] = max(DP[x][y], Move(nx, ny) + 1);
			}
		}
	}
	return DP[x][y];
}



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> bamb[i][j];
		}
	}
	//이전보다 더 큰 곳으로 가면서 이동하는 수가 최대가 되도록
	//시작 지점도 선택 가능하다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			ans = max(ans, Move(i, j));
		}
	}
	cout << ans;
	return 0;
}