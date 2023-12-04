#include <iostream>
#include <vector>
using namespace std;

struct srk {
	int r;
	int c;
	int s;
	int d;
	int z;
};

vector<struct srk> shark
int R, C, M;
int sum = 0;
int field[101][101] = { 0, };
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

void move() {

}

void fisher(int col) {

	//해당 열에서 가장 가까운 상어 잡기(잡으면 상어 사라짐) sum 크기 갱신

	//상어 이동
	move();
}

int main() {
	cin >> R >> C >> M;
	int r_, c_, s_, d_, z_;
	struct srk tmp;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		tmp.r = r_, tmp.c = c_, tmp.s = s_, tmp.d = d_, tmp.z = z_;
		shark.push_back(tmp);
	}
	for (i = 1; i <= C; i++)
		fisher(i);
	cout << sum;
	return 0;
}