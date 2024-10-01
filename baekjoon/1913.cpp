#include <iostream>
#include <vector>

using namespace std;

int maap[999][999];
int dx[4] = { 1, 0, -1, 0 }; //하우상좌
int dy[4] = { 0, 1, 0, -1 };
int N;

bool right_dir(int x, int y, int dir, int try_dir) {
	//이전에 움직인게 dir 방향일 때 try_dir방향으로 해서 x, y로 가도 됨?
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;

	if (try_dir == 0) {

		if (dir == 3) {
			int check_x = x + dx[2] + dx[3];
			int check_y = y + dy[2] + dy[3];

			if (check_x >= 0 && check_x < N && check_y >= 0 && check_y < N && !maap[check_x][check_y])
				return false;
		}

		return (maap[x][y] == 0 && x < N && (dir == 0 || dir == 3));
	}
	else if (try_dir == 1) {
		if (dir == 0) {
			int check_x = x + dx[3] + dx[0];
			int check_y = y + dy[3] + dy[0];

			if (check_x >= 0 && check_x < N && check_y >= 0 && check_y < N && !maap[check_x][check_y])
				return false;
		}

		return(maap[x][y] == 0 && y < N && (dir == 1 || dir == 0));
	}
	else if (try_dir == 2) {
		if (dir == 1) {
			int check_x = x + dx[0] + dx[1];
			int check_y = y + dy[0] + dy[1];

			if (check_x >= 0 && check_x < N && check_y >= 0 && check_y < N && !maap[check_x][check_y])
				return false;
		}

		return(maap[x][y] == 0 && x >= 0 && (dir == 2 || dir == 1));
	}
	else {
		if (dir == 2) {
			int check_x = x + dx[1] + dx[2];
			int check_y = y + dy[1] + dy[2];

			if (check_x >= 0 && check_x < N && check_y >= 0 && check_y < N && !maap[check_x][check_y])
				return false;
		}

		return(maap[x][y] == 0 && y >= 0 && (dir == 3 || dir == 2));
	}



	return true;
}

int main() {
	int ans = -1;
	cin >> N;
	cin >> ans;

	int curr_x = 0;
	int curr_y = 0;
	int num = N * N;
	int curr_dir = 0;
	int ans_x = -1;
	int ans_y = -1;

	while (1) {
		maap[curr_x][curr_y] = num--;
		if (maap[curr_x][curr_y] == ans) {
			ans_x = curr_x + 1;
			ans_y = curr_y + 1;
		}

		if (curr_x == N / 2 && curr_y == N / 2) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];
			if (right_dir(nx, ny, curr_dir, i)) {
				curr_dir = i;
				curr_x = nx;
				curr_y = ny;
				break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << maap[i][j] << " ";
		}
		cout << endl;
	}
	cout << ans_x << " " << ans_y;



	return 0;
}