#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int N; int a[3];
int visited[64][64][64];

int attack[6][3] =
{
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

struct A {
	int a, b, c;
};


int bfs(int a, int b, int c) {
	queue<A> q;
	visited[a][b][c] = 1;
	q.push({ a,b,c });

	while (!q.empty()) {
		int anum = q.front().a;
		int bnum = q.front().b;
		int cnum = q.front().c;
		q.pop();

		if (visited[0][0][0]) break;
		for (int i = 0; i < 6; i++) {
			int na = max(0, anum - attack[i][0]);
			int nb = max(0, bnum - attack[i][1]);
			int nc = max(0, cnum - attack[i][2]);

			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[anum][bnum][cnum] + 1;
			q.push({ na,nb,nc });
		}
	}
	return visited[0][0][0] - 1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	cout << bfs(a[0], a[1], a[2]);
}