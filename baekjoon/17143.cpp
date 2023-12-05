#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct srk {
	int s = 0;
	int d = 0;
	int z = 0;
};

int R, C, M;
int sum = 0;
vector<struct srk> field[101][101] = { };
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

int reverseD(int D){
	int res = 0;
	
	if(D == 1)	res = 2;
	else if(D == 2) res = 1;
	else if(D == 3) res = 4;
	else if(D == 4) res = 3;
	
	return res;
}

void move() {
	//격자판 경계를 넘으면 방향 반대로 상하우좌 1<>2 3<>4
	for(int i = 1; i<=R; i++){//전체
		for(int j = 1; j<=C; j++){
			if(field[i][j].size() != 0){//있는 칸만
				
				for(int index = 0; index < field[i][j].size(); index++){// 그 칸에 있는 애들
					int D = field[i][j][index].d;
					int S = field[i][j][index].s;
					if(i+dx[D]*S < 1 || i+dx[D]*S > R || j+dx[D]*S < 1 || j+dx[D]*S > C){ // 맵 나감: 방향 반대로
						
						if(D <= 2){ //상하
							if(D==1){
								S -= i - 1;
								D = 2;
							}
							else{
								S -= R - i;
								D = 1;
							}
							while(S>= R){
								S -= R;
								if(D==1)	D = 2;
								else		D = 1;
							}
						}
						else{ //우좌
							if(D==3){
								S -= R - j;
								D = 4;
							}
							else{
								S -= j - 1;
								D = 3;
							}
							while(S>= R){
								S -= R;
								if(D==3)	D = 4;
								else		D = 3;
							}
						}
						
						if(D == 1){
							field[i][j][index].d = D;
							field[dx[D]*S][j].push_back(field[i][j][index]);
						}
						else if(D == 2){
							field[i][j][index].d = D;
							field[R - dx[D]*S][j].push_back(field[i][j][index]);
						}
						else if(D == 3){
							field[i][j][index].d = D;
							field[i][dy[D]*S].push_back(field[i][j][index]);
						}
						else if(D == 4){
							field[i][j][index].d = D;
							field[i][dy[D]*S].push_back(field[i][j][index]);
						}

						field[i][j].erase(field[i][j].begin() + index);
						index--;
					}
					else{
						field[i+dx[D]*S][j+dy[D]*S].push_back(field[i][j][index]);
						field[i][j].erase(field[i][j].begin() + index);
						index--;
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
	for(int i = 1; i<= R; i++){
		if(field[i][col].size() != 0){
			tmpM = field[i][col][idx].z;
			for(int index = 0; index < field[i][col].size(); index++){
				if(tmpM < field[i][col][index].z){
					tmpM = field[i][col][index].z;
					idx = index;
				}
			}
			//최대 잡고 초기화
			sum+=tmpM;
			field[i][col].erase(field[i][col].begin() + idx);
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
	for(int i = 0; i<R; i++)
		field[i][0].push_back(tmp);
	for(int i = 0; i<C; i++)
		field[0][i].push_back(tmp);

	for (int i = 0; i < M; i++) {
		cin >> r_ >> c_ >> s_ >> d_ >> z_;
		tmp.s = s_, tmp.d = d_, tmp.z = z_;
		field[r_][c_].push_back(tmp);
	}
	for (int i = 1; i <= C; i++)
		fisher(i);
	cout << sum;
	return 0;
}
