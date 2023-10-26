#include <iostream>

using namespace std;

int N, M; //3~50
int map[50][50]; //0이면 청소 x, 1이면 벽
int clean = 1;
int dx[] = { -1,0,1,0 };
int dy[] = {0,1,0,-1};

int search(int r, int c) {
	int res = -1;

	if (r - 1 >= 0 && r - 1 < N && c >= 0 && c < M && map[r - 1][c] == 0)
		res = 0;
	if  (r >= 0 && r < N && c + 1 >= 0 && c + 1 < M && map[r][c + 1] == 0)
		res = 1;
	if (r + 1 >= 0 && r + 1 < N && c >= 0 && c < M && map[r + 1][c] == 0)
		res = 2;
	if (r >= 0 && r < N && c - 1 >= 0 && c - 1 < M && map[r][c - 1] == 0)
		res = 3;
	return res;
}

void robot(int r, int c, int d) {
	int dir = d;
	int row = r;
	int col = c;
	//현재칸 청소
	int mode = search(row, col);
	int count = 0;
	while (1) {
		count = 0;
		if (map[row][col] == 0) {
			clean++;
			map[row][col] = 2;
		}
		mode = search(row, col);
		//주변 4칸 모두 0인 상태 없으면 후진하고 청소(후진 불가능하면 정지)
		if (mode == -1) {
			int rr = row + dx[(dir + 2) % 4];
			int rc = col + dy[(dir + 2) % 4];
			if (rr >= 0 && rr < N && rc >= 0 && rc < M && map[rr][rc] != 1) {
				row = rr;
				col = rc;
				if (map[row][col] == 0) {
					clean++;
					map[row][col] = 2;
				}
			}
			else
				return;
		}
		//4방 중 빈칸있으면 반시계 90도 회전 (3->2, 2->1, 1->0, 0->3)
		//돌고서 본 곳이 0 -> 감
		else {
			while (count < 4) {
				if (dir != 0)//반시계
					dir--;
				else if (dir == 0)
					dir = 3;

				if (row + dx[dir] >= 0 && row + dx[dir] < N && col + dy[dir] >= 0 && col + dy[dir] < M && map[row + dx[dir]][col + dy[dir]] == 0) {//그방향이 0이면
					row += dx[dir];
					col += dy[dir];
					count = 5;
				}
				count++;
			}
		
		}
	}
}

int main() {
	int r=0, c=0, d=-1; //(row,col,direction-nesw)
	cin >> N >> M;
	cin >> r >> c >> d; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	map[r][c] = 2;
	robot(r,c,d);
	cout << clean;
	return 0;
}