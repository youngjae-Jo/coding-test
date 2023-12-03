#include <iostream>

using namespace std;

int R = 0, T = 0, C = 0;
int A[51][51] = { 0, };
int dx[4] = { -1, 1, 0, 0 }; //상하좌우
int dy[4] = { 0,0,-1,1 };

void afterSec(int r1, int r2) {
	int tmp[51][51] = { 0, };

	//확산	//동시, 인접 네 방향(공기 청정기 or 칸 x -> 확산 x), 확산되는 총량 Ar,c / 5 *(확산된 방향)
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			
			if (A[i][j] != -1) {//(i != r1 || i != r2) && j != r2) { //공청기 x
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					if (i + dx[dir] >=1 && i + dx[dir] <= R && j + dy[dir] >= 1 && j + dy[dir] <= C) {//(i+dx[dir] != r1 || i+dx[dir] != r2) && j != r2))
						if (A[i + dx[dir]][j + dy[dir]] != -1) {
							tmp[i + dx[dir]][j + dy[dir]] += A[i][j] / 5;
							cnt++;
						}
					}
				}
				A[i][j] -= (A[i][j] / 5) * cnt;
			}

		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			A[i][j] += tmp[i][j];
	}
	//위쪽 공기 청정기 : 반시계    아래쪽 : 시계
	/*int temp1, temp2, temp3, temp4;
	//1
	temp1 = A[r1][C]; temp2 = A[r2][C];
	for (int i = 0; i < C-2; i++) {//2~C    
		A[r1][C - i] = A[r1][C - i - 1];
		A[r2][C - i] = A[r2][C - i - 1];
	}
	A[r1][2] = 0; A[r2][2] = 0;
	
	//2
	temp3 = A[1][C]; temp4 = A[R][C];		
	for (int i = 1; i <r1 - 1 ; i++) {
		A[i][C] = A[i + 1][C];
	}
	A[r1 - 1][C] = temp1;

	for (int i = 0; R-i >= 2; i++) { //R-i-1 = r2 + 1까지 
		A[R - i][C] = A[R - i - 1][C];
	} 
	A[r2 + 1][C] = temp2;
	
	//3
	temp1 = A[1][1]; temp2 = A[R][1];
	for (int i = 1; i <= C-2; i++) {
		A[1][i] = A[1][i+1];
		A[R][i] = A[R][i+1];
	}
	A[1][C - 1] = temp3;
	A[R][C - 1] = temp4;
	
	//4
	for (int i = 1; r1-i-1>=2; i++) { //r1-i-2 = 2 -> r1-4 = i
		A[r1 - i][1] = A[r1 - i - 1][1];
	}
	A[2][1] = temp1;
	for (int i = 1; r2 + i <= R - 2; i++) {//r2+i = R - 2
		A[r2 + i][1] = A[r2 + i + 1][1];
	}
	A[R - 1][1] = temp2;*/
}


int main() {

	cin >> R >> C >> T;
	int puri_r[2] = {0, };
	int idx = 0, sum = 2;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> A[i][j];
			if (A[i][j] == -1) {
				puri_r[idx] = i;
				idx++;
			}
		}
	}
	for(int i = 0; i<T; i++)
		afterSec(puri_r[0], puri_r[1]);
	cout << endl;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			//sum += A[i][j];
			cout << A[i][j] << " ";
		cout << endl;	
	}
	//cout << sum;
	return 0;
}