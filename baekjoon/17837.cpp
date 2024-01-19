#include <iostream>
#include <vector>

using namespace std;

int N, K;
int chess[13][13];
vector<int> arr[13][13];

struct Piece {
	int row;
	int col;
	int way; //우좌상하
};

Piece piece[11];
int turn = 1;
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int white(int k, int newRow, int newCol, int originalRow, int originalCol) {
	int tmp = 0;
	for (int i = 0; i < arr[piece[k].row][piece[k].col].size(); i++) {//vector에서 k의 인덱스 찾기
		if (k == arr[piece[k].row][piece[k].col][i]) {
			tmp = i;
			break;
		}
	}
	int sz = arr[piece[k].row][piece[k].col].size();
	for (int i = tmp; i < sz; i++) {//이동
		int val = arr[piece[k].row][piece[k].col][i];
		arr[newRow][newCol].push_back(val);
	}

	for (int i = tmp; i < sz; i++) {//이동
		piece[arr[originalRow][originalCol][i]].row = newRow;
		piece[arr[originalRow][originalCol][i]].col = newCol;
	}
	
	return tmp;
}

int red(int k, int newRow, int newCol, int originalRow, int originalCol) {
	int tmp = 0;
	for (int i = 0; i < arr[piece[k].row][piece[k].col].size(); i++) {//vector에서 k의 인덱스 찾기
		if (k == arr[piece[k].row][piece[k].col][i]) {
			tmp = i;
			break;
		}
	}
	int sz = arr[piece[k].row][piece[k].col].size();
	for (int i = sz - 1; i >= tmp; i--) {//층뒤집기
		int val = arr[piece[k].row][piece[k].col][i];
		arr[newRow][newCol].push_back(val);
	}
	for (int i = tmp; i < sz; i++) {//이동
		piece[arr[originalRow][originalCol][i]].row = newRow;
		piece[arr[originalRow][originalCol][i]].col = newCol;
	}
	
	return tmp;
}

int is_out(int newRow, int newCol) {
	int res = 0;
	if (newRow < 1 || newRow > N || newCol < 1 || newCol > N)
		return 1;
	else if (chess[newRow][newCol] == 2)
		return 1;
	return res;
}


void move() {
	
	for (turn; turn <= 1000; turn++) {
	//2,3에 3개 얹어지고, 1번부터 다시 움직이는 turn2에서부터 생각하면 돼
		for (int k = 1; k <= K; k++) {
			
			int newRow = piece[k].row + dx[piece[k].way];
			int newCol = piece[k].col + dy[piece[k].way];
			int originalRow = piece[k].row;
			int originalCol = piece[k].col;
			
			if (is_out(newRow, newCol)) {//맵밖이거나 파란색
				
				int backway = 0;
				if (piece[k].way == 1)
					backway = 2;
				else if (piece[k].way == 2)
					backway = 1;
				else if (piece[k].way == 3)
					backway = 4;
				else if (piece[k].way == 4)
					backway = 3;

				int backRow = piece[k].row + dx[backway];//뒤쪽 확인
				int backCol = piece[k].col + dy[backway];
				piece[k].way = backway;
				if (is_out(backRow, backCol)) {//또 맵밖이거나 파란색이면 정지
					continue;
				}
				else if (chess[backRow][backCol] == 0) {//뒤가 하얀색
					int tmp = white(k, backRow, backCol, originalRow, originalCol);
					if (arr[backRow][backCol].size() >= 4)
						return;
					//갔으니까 비우기
					arr[originalRow][originalCol].erase(arr[originalRow][originalCol].begin() + tmp, arr[originalRow][originalCol].end());
				}
				else if (chess[backRow][backCol] == 1) {//뒤가 빨간색
					int tmp = red(k, backRow, backCol, originalRow, originalCol);
					if (arr[backRow][backCol].size() >= 4)
						return;
					//갔으니까 비우기
					arr[originalRow][originalCol].erase(arr[originalRow][originalCol].begin() + tmp, arr[originalRow][originalCol].end());
				}
			}

			else if (chess[newRow][newCol] == 0) {

				int tmp = white(k, newRow, newCol, originalRow, originalCol);
				if (arr[newRow][newCol].size() >= 4)
					return;
				//갔으니까 비우기
				arr[originalRow][originalCol].erase(arr[originalRow][originalCol].begin() + tmp, arr[originalRow][originalCol].end());
			}

			else if (chess[newRow][newCol] == 1) {
				int tmp = red(k, newRow, newCol, originalRow, originalCol);
				if (arr[newRow][newCol].size() >= 4)
					return;
				//갔으니까 비우기
				arr[originalRow][originalCol].erase(arr[originalRow][originalCol].begin() + tmp, arr[originalRow][originalCol].end());
			}

		}
		
	}
	
	turn = -1;
}


int main() {

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> chess[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		piece[i].row = a;
		piece[i].col = b;
		piece[i].way = c;
		arr[a][b].push_back(i);
	}
	move();
	
	cout << turn;
	return 0;
}