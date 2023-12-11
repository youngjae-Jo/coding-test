#include <iostream>
#include <vector>

using namespace std;

struct srk {
	int s = -1;
	int d = -1;
	int z = -1;
};

struct pool {
	vector<struct srk> shark;
};

int R, C, M;
int sum = 0;
struct pool field[101][101];
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

void fight(){
	for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; j++) {
			int idx = 0;
			int tmpM = 0;
			if (field[i][j].shark.size() >= 2) {
				tmpM = field[i][j].shark[idx].z;
				for (int index = 1; index < field[i][j].shark.size(); index++) {
					if (tmpM < field[i][j].shark[index].z) {
						tmpM = field[i][j].shark[index].z;
						idx = index;
					}
				}
				field[i][j].shark.push_back(field[i][j].shark[idx]);
				field[i][j].shark.erase(field[i][j].shark.begin(),field[i][j].shark.end()-1);
			}
		}
	}
	
}

void move() {
	struct pool fake[101][101];
	//격자판 경계를 넘으면 방향 반대로 상하우좌 1<>2 3<>4
	for (int i = 1; i <= R; i++) {//전체
		for (int j = 1; j <= C; j++) {
							
			for (int index = 0; index<field[i][j].shark.size() && field[i][j].shark.size()>0; index++) {// 그 칸에 있는 애들
				int check = 0;	
				if (field[i][j].shark.size() != 0) {//있는 칸만
					int D = field[i][j].shark[index].d;
					int S = field[i][j].shark[index].s;
					if(S == 0)
						continue;

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
								S -= R-1;
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
								S -= C-1;
								if (D == 3)	D = 4;
								else		D = 3;
							}
						}

						if (D == 1) {
							field[i][j].shark[index].d = D;
							if(R+dx[D]*S != i)
								fake[R+ dx[D] * S][j].shark.push_back(field[i][j].shark[index]);
							else check++;
						}
						else if (D == 2) {
							field[i][j].shark[index].d = D;
							if(1+dx[D]*S != i)
								fake[1+dx[D] * S][j].shark.push_back(field[i][j].shark[index]);
							else check++;
						}
						else if (D == 3) {
							field[i][j].shark[index].d = D;
							if(1+dy[D]*S != j)
								fake[i][1+dy[D] * S].shark.push_back(field[i][j].shark[index]);
							else check++;
						}
						else if (D == 4) {
							field[i][j].shark[index].d = D;
							if(C+dy[D]*S != j)			
								fake[i][C+dy[D] * S].shark.push_back(field[i][j].shark[index]);
							else check++;
						}

						if(check==0){
							field[i][j].shark.erase(field[i][j].shark.begin() + index);
							index--;
						}
							
					}
					else {
						fake[i + dx[D] * S][j + dy[D] * S].shark.push_back(field[i][j].shark[index]);
						field[i][j].shark.erase(field[i][j].shark.begin() + index);
						index--;
					}
					
				}
			}	
		}
	}

	for (int i = 1; i <= R; i++) {//상호작용 안생기게 따로 빼둔거 저장
		for (int j = 1; j <= C; j++) {
			if(fake[i][j].shark.size()!= 0){
				for(int idx = 0; idx<fake[i][j].shark.size(); idx++)
					field[i][j].shark.push_back(fake[i][j].shark[idx]);
			}
		}
	}

	fight();
}

void fisher(int col) {
	
	int Z = 0;
	//해당 열에서 가장 가까운 상어 잡기(잡으면 상어 사라짐) sum 크기 갱신
	for (int i = 1; i <= R; i++) {
		if (field[i][col].shark.size() != 0) {
			Z = field[i][col].shark[0].z;
			sum += Z;
			field[i][col].shark.pop_back();
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
	for (int i = 1; i <= C; i++){
		fisher(i);
	}
	cout << sum;
	return 0;
}
