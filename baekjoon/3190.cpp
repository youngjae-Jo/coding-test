#include <iostream>
#include <vector>
//11퍼에서 틀림
using namespace std;

//사과 먹으면 길이가 늘어나고, 벽 또는 자신과 부딛히면 게임 끝
//board[0][0]에서 뱀 시작, board[0][1]로
//매초 이동, 몸길이+1->다음칸, 사과 있는 칸이면 늘어나고 끝, 
// 사과없으면 꼬리 길이 하나 줄여서 원래 몸길이 그대로 유지

struct turn
{
	int X;
	char C;
};

struct snake
{
	int row;
	int col;
};
//0오른쪽으로 갈 때 L/D -> 위/아래
//1왼쪽으로 갈 때 L/D -> 아래/위
//2위로 갈 때 L/D -> 왼/오
//3아래로 갈 때 L/D -> 오/왼
int way(int now, char c) {
	int after = 0;
	if (now == 0) {
		if (c == 'L')
			after = 2;
		if (c == 'D')
			after = 3;
	}
	else if (now == 1) {
		if (c == 'L')
			after = 3;
		if (c == 'D')
			after = 2;
	}
	else if (now == 2) {
		if (c == 'L')
			after = 1;
		if (c == 'D')
			after = 0;
	}
	else if (now == 3) {
		if (c == 'L')
			after = 0;
		if (c == 'D')
			after = 1;
	}
	return after;
}

int countTime(int N, vector<vector<int>>& map, int L, turn move[]) {
	int cnt = 0;
	int i = 0;
	int now = 0;//현재 방향과 move[].C들 고려해서
	int row = 0;
	int col = 0;

	struct snake tail[10000];
	tail[0].row = 0;
	tail[0].col = 0;
	int currentTail = 0;
	int tIndex = 0;
	map[tail[0].row][tail[0].col] = 2; //첫위치는 문제 조건에서 고정

	while (1) {
		cnt++;
		if (move[i].X + 1 == cnt) {//방향정하기
			now = way(now, move[i].C);
			i++;
		}
		if (now == 0) {//오
			col++;
			if (col >= N || map[row][col] == 2)//벽또는 자신과 충돌
				return cnt;
			else if (map[row][col] == 0) {//이동한 곳이 빈 곳이면 꼬리처리
				map[tail[currentTail].row][tail[currentTail].col] = 0;
				currentTail++;
			}
			tIndex++;
			tail[tIndex].row = row;
			tail[tIndex].col = col;
			map[row][col] = 2;
		}

		else if (now == 1) {//왼
			col--;
			if (col < 0 || map[row][col] == 2)//벽또는 자신과 충돌
				return cnt;
			else if (map[row][col] == 0) {//이동한 곳이 빈 곳이면 꼬리처리
				map[tail[currentTail].row][tail[currentTail].col] = 0;
				currentTail++;
			}
			tIndex++;
			tail[tIndex].row = row;
			tail[tIndex].col = col;
			map[row][col] = 2;
		}

		else if (now == 2) {//위
			row--;
			if (row < 0 || map[row][col] == 2)//벽또는 자신과 충돌
				return cnt;
			else if (map[row][col] == 0) {//이동한 곳이 빈 곳이면 꼬리처리
				map[tail[currentTail].row][tail[currentTail].col] = 0;
				currentTail++;
			}
			tIndex++;
			tail[tIndex].row = row;
			tail[tIndex].col = col;
			map[row][col] = 2;
		}

		else if (now == 3) {//아래
			row++;
			if (row >= N || map[row][col] == 2)//벽또는 자신과 충돌
				return cnt;
			else if (map[row][col] == 0) {//이동한 곳이 빈 곳이면 꼬리처리
				map[tail[currentTail].row][tail[currentTail].col] = 0;
				currentTail++;
			}
			tIndex++;
			tail[tIndex].row = row;
			tail[tIndex].col = col;
			map[row][col] = 2;
		}
	}
	return cnt;
}

int main() {
	int N = 0, K = 0, col = 0, row = 0, L = 0;
	int endTime = 0;
	vector<vector<int>> board(101, vector<int>(101, 0));
	struct turn sel[100];
	sel[0].X = -2, sel[0].C = 'C';
	cin >> N;//보드 크기
	cin >> K;//사과 개수
	for (int i = 0; i < K; i++) {//사과위치
		cin >> col >> row;
		board[col - 1][row - 1] = 1;
	}

	cin >> L;
	for (int j = 0; j < L; j++) {//회전방향(L-왼쪽,D-오른쪽)
		cin >> sel[j].X >> sel[j].C;
	}
	endTime = countTime(N, board, L, sel);
	cout << endTime;
	return 0;
}