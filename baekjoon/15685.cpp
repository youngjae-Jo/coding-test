#include <iostream>
#include <vector>

using namespace std;

struct pos {
	int x;
	int y;
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int N, d, g;
int map[101][101] = { 0, };

int find_dir(pos a, pos b) {
	int x_ = b.x - a.x;
	int y_ = b.y - a.y;
	int dir = -1;
	for (int i = 0; i < 4; i++) {
		if (x_ == dx[i] && y_ == dy[i])
			dir = i;
	}
	if (dir == 0)
		dir = 3;
	else
		dir--;

	return dir;
}

//각 드래곤 커브는 d에 따라 모양이 1개씩만 있음
void make_drg(int X, int Y, int d, int g) {
	int gen = 0;
	vector<pos> drg;
	drg.push_back({X,Y});
	map[Y][X] = 1;
	drg.push_back({X + dx[d],Y + dy[d]});
	map[Y + dy[d]][X + dx[d]] = 1;
	gen++;
	//마지막이 n이면 n+1: n->n-1 방향 다음 방향으로 n에서 출발, n+2: n-1->n-2 방향
	//다음 방향으로 n+1에서 출발
	while (g >= gen) {//반복문 한번 돌 때 마다 세대 하나씩
		int l = drg.size();
		for (int i = 1; i <= l-1; i++) {//끝부터 앞으로 가면서
			int dir = find_dir(drg[l - i], drg[l - i - 1]);
			drg.push_back({drg[l+i-2].x + dx[dir], drg[l+i-2].y + dy[dir]});
			map[drg[l + i - 2].y + dy[dir]][drg[l + i - 2].x + dx[dir]] = 1;
		}
		gen++;
	}
}

int check() {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j + 1] && map[i + 1][j])
				cnt++;
		}
	}
	return cnt;
}


//n세대는 n-1세대를 시계방향으로 90도 회전시키고 끝점끼리 이은 것
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y >> d >> g; //시작점, 방향, 세대
		make_drg(X, Y, d, g);
	}
	cout << check();
	
	return 0;
}