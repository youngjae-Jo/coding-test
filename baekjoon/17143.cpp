#include <iostream>
#include <vector>

using namespace std;

struct srk {
	int s = 0;
	int d = 0;
	int z = 0;
};

struct pool {
	vector<struct srk> shark;
};

int R, C, M;
int sum = 0;
struct pool field[101][101];
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };


void move() {
	//격자판 경계를 넘으면 방향 반대로 상하우좌 1<>2 3<>4
	for (int i = 1; i <= R; i++) {//전체
		for (int j = 1; j <= C; j++) {
			if (field[i][j].shark.size() != 0) {//있는 칸만

				for (int index = 0; index<field[i][j].shark.size() && field[i][j].shark.size() != 0; index++) {// 그 칸에 있는 애들
					int D = field[i][j].shark[index].d;
					int S = field[i][j].shark[index].s;
					if (i + dx[D] * S < 1 || i + dx[D] * S > R || j + dy[D] * S < 1 || j + dy[D] * S > C) { // 맵 나감: 방향 반대로

						if (D <= 2) { //상하
							if (D == 1) {
								S -= i - 1;
								D = 2;
							}
							else {
								S -= R - i;
								D = 1;
							}
							while (S >= R) {
								S -= R;
								if (D == 1)	D = 2;
								else		D = 1;
							}
						}
						else { //우좌
							if (D == 3) {
								S -= C - j;
								D = 4;
							}
							else {
								S -= j - 1;
								D = 3;
							}
							while (S >= C) {
								S -= C;
								if (D == 3)	D = 4;
								else		D = 3;
							}
						}

						if (D == 1) {
							field[i][j].shark[index].d = D;
							field[R+ dx[D] * S][j].shark.push_back(field[i][j].shark[index]);
						}
						else if (D == 2) {
							field[i][j].shark[index].d = D;
							field[dx[D] * S][j].shark.push_back(field[i][j].shark[index]);
						}
						else if (D == 3) {
							field[i][j].shark[index].d = D;
							field[i][dy[D] * S].shark.push_back(field[i][j].shark[index]);
						}
						else if (D == 4) {
							field[i][j].shark[index].d = D;
							field[i][C+dy[D] * S].shark.push_back(field[i][j].shark[index]);
						}

						field[i][j].shark.erase(field[i][j].shark.begin() + index);
						//index--;
					}
					else {
						field[i + dx[D] * S][j + dy[D] * S].shark.push_back(field[i][j].shark[index]);
						field[i][j].shark.erase(field[i][j].shark.begin() + index);
						//index--;
					}
				}

			}
		}
	}
}

void fisher(int col) {
	int idx = 0;
	int tmpM = 0;
	//해당 열에서 가장 가까운 상어 잡기(잡으면 상어 사라짐) sum 크기 갱신
	for (int i = 1; i <= R; i++) {
		if (field[i][col].shark.size() != 0) {
			tmpM = field[i][col].shark[idx].z;
			for (int index = 1; index < field[i][col].shark.size(); index++) {
				if (tmpM < field[i][col].shark[index].z) {
					tmpM = field[i][col].shark[index].z;
					idx = index;
				}
			}
			//최대 잡고 초기화
			sum += tmpM;
			field[i][col].shark.erase(field[i][col].shark.begin() + idx);
			idx = 0;
			tmpM = 0;
			break;
		}
	}

	//상어 이동
	move();
}

int main() {
	cin >> R >> C >> M;
	int r_, c_, s_, d_, z_;
	struct srk tmp;
	for (int i = 0; i <= R; i++)
		field[i][0].shark.push_back(tmp);
	for (int i = 0; i <= C; i++)
		field[0][i].shark.push_back(tmp);

	for (int i = 0; i < M; i++) {
		cin >> r_ >> c_ >> s_ >> d_ >> z_;
		tmp.s = s_, tmp.d = d_, tmp.z = z_;
		field[r_][c_].shark.push_back(tmp);
	}
	for (int i = 1; i <= C; i++)
		fisher(i);
	cout << sum;
	return 0;
}
