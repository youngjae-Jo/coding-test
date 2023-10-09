#include <iostream>
#include <vector>

using namespace std;

int A[501][501] = { -1, };

// 좌, 하, 우, 상 순으로
int lastLeft = 0; //줄어들면서 j == lastLeft -1까지
int lastDown = 0; //증가하면서 i == lastDown +1까지
int lastRight = 0; //증가하면서 j == lastRight +1까지
int lastUp = 0; //줄어들면서 i == lastUp -1까지

int blow(int way, int row, int col, int N) { //바람직하지 않은데 그냥 
	int moved = 0;
	int out = 0; //이동 시키고 넘어온거라서 A[row][col]에 대해 생각하면 됨
	if (way == 1) {
		//첫줄
		if (col >= 3) {
			moved += (A[row][col] * 5) / 100;
			A[row][col - 2] += (A[row][col] * 5) / 100;
		}
		else { 
			out += (A[row][col] * 5) / 100; 
			moved += (A[row][col] * 5) / 100;
		}
		
		//두번째줄
		if (col >= 2 && row >= 2) {
			moved += (A[row][col] * 10) / 100;
			A[row - 1][col - 1] += (A[row][col] * 10) / 100;
		}
		else { 
			out += (A[row][col] * 10) / 100;
			moved += (A[row][col] * 10) / 100;
		}
		if (col >= 2 && row <= N - 1) {
			moved += (A[row][col] * 10) / 100;
			A[row + 1][col - 1] += (A[row][col] * 10) / 100;
		}
		else { 
			out += (A[row][col] * 10) / 100;
			moved += (A[row][col] * 10) / 100;
		}

		//가운데 줄
		if (row >= 2) {
			moved += (A[row][col] * 7) / 100;
			A[row - 1][col] += (A[row][col] * 7) / 100;
		}
		else {
			out += (A[row][col] * 7) / 100;
			moved += (A[row][col] * 7) / 100;
		}
		if (row <= N - 1) {
			moved += (A[row][col] * 7) / 100;
			A[row + 1][col] += (A[row][col] * 7) / 100;
		}
		else { 
			out += (A[row][col] * 7) / 100;
			moved += (A[row][col] * 7) / 100;
		}
		if (row >= 3) {
			moved += (A[row][col] * 2) / 100;
			A[row - 2][col] += (A[row][col] * 2) / 100;
		}
		else { 
			moved += (A[row][col] * 2) / 100;
			out += (A[row][col] * 2) / 100;
		}
		if (row <= N - 2) {
			moved += (A[row][col] * 2) / 100;
			A[row + 2][col] += (A[row][col] * 2) / 100;
		}
		else { 
			out += (A[row][col] * 2) / 100;
			moved += (A[row][col] * 2) / 100;
		}

		//끝줄
		if (row >= 2 && col <= N - 1) {
			moved += (A[row][col] * 1) / 100;
			A[row - 1][col + 1] += (A[row][col] * 1) / 100;
		}
		else { 
			out += (A[row][col] * 1) / 100;
			moved += (A[row][col] * 1) / 100;
		}
		if (row <= N - 1 && col <= N - 1) {
			moved += (A[row][col] * 1) / 100;
			A[row + 1][col + 1] += (A[row][col] * 1) / 100;
		}
		else { 
			out += (A[row][col] * 1) / 100;
			moved += (A[row][col] * 1) / 100;
		}
		//alpha
		if(col >= 2) {
			A[row][col - 1] += (A[row][col] - moved);
		}
		else { out += (A[row][col] - moved); }

		A[row][col] = 0;
	}
	if (way == 2) {
		//첫줄
		if (row <= N - 2) {
			moved += (A[row][col] * 5) / 100;
			A[row + 2][col] += (A[row][col] * 5) / 100;
		}
		else {
			moved += (A[row][col] * 5) / 100;
			out += (A[row][col] * 5) / 100; 
		}

		//두번째줄
		if (col >= 2 && row <= N - 1) {
			moved += (A[row][col] * 10) / 100;
			A[row + 1][col - 1] += (A[row][col] * 10) / 100;
		}
		else { 
			moved += (A[row][col] * 10) / 100;
			out += (A[row][col] * 10) / 100;
		}
		if (col <= N - 1 && row <= N - 1) {
			moved += (A[row][col] * 10) / 100;
			A[row + 1][col + 1] += (A[row][col] * 10) / 100;
		}
		else { 
			moved += (A[row][col] * 10) / 100;
			out += (A[row][col] * 10) / 100;
		}

		//가운데 줄
		if (col >= 2) {
			moved += (A[row][col] * 7) / 100;
			A[row][col - 1] += (A[row][col] * 7) / 100;
		}
		else { 
			moved += (A[row][col] * 7) / 100; 
			out += (A[row][col] * 7) / 100; }
		if (col <= N - 1) {
			moved += (A[row][col] * 7) / 100;
			A[row][col + 1] += (A[row][col] * 7) / 100;
		}
		else { 
			moved += (A[row][col] * 7) / 100; 
			out += (A[row][col] * 7) / 100;
		}
		if (col >= 3) {
			moved += (A[row][col] * 2) / 100;
			A[row][col - 2] += (A[row][col] * 2) / 100;
		}
		else { 
			moved += (A[row][col] * 2) / 100; 
			out += (A[row][col] * 2) / 100; }
		if (col <= N - 2) {
			moved += (A[row][col] * 2) / 100;
			A[row][col + 2] += (A[row][col] * 2) / 100;
		}
		else { 
			moved += (A[row][col] * 2) / 100; 
			out += (A[row][col] * 2) / 100; }

		//끝줄
		if (row >= 2 && col <= N - 1) {
			moved += (A[row][col] * 1) / 100;
			A[row - 1][col + 1] += (A[row][col] * 1) / 100;
		}
		else { 
			moved += (A[row][col] * 1) / 100; 
			out += (A[row][col] * 1) / 100; }
		if (row >= 2 && col >= 2) {
			moved += (A[row][col] * 1) / 100;
			A[row - 1][col - 1] += (A[row][col] * 1) / 100;
		}
		else { 
			moved += (A[row][col] * 1) / 100; 
			out += (A[row][col] * 1) / 100; }

		if (row <= N - 1) {
			A[row + 1][col] += (A[row][col] - moved);
		}
		else { out += (A[row][col] - moved); }

		A[row][col] = 0;
	}
	if (way == 3) {
		//첫줄
		if (col <= N - 2) {
			moved += (A[row][col] * 5) / 100;
			A[row][col + 2] += (A[row][col] * 5) / 100;
		}
		else {
			moved += (A[row][col] * 5) / 100;
			out += (A[row][col] * 5) / 100; }
		
		//두번째줄
		if (col <= N - 1 && row >= 2) {
			moved += (A[row][col] * 10) / 100;
			A[row - 1][col + 1] += (A[row][col] * 10) / 100;
		}
		else { 
			moved += (A[row][col] * 10) / 100; 
			out += (A[row][col] * 10) / 100; }
		if (col <= N - 1 && row <= N - 1) {
			moved += (A[row][col] * 10) / 100;
			A[row + 1][col + 1] += (A[row][col] * 10) / 100;
		}
		else {
			moved += (A[row][col] * 10) / 100;
			out += (A[row][col] * 10) / 100;
		}

		//가운데 줄
		if (row >= 2) {
			moved += (A[row][col] * 7) / 100;
			A[row - 1][col] += (A[row][col] * 7) / 100;
		}
		else {
			moved += (A[row][col] * 7) / 100;
			out += (A[row][col] * 7) / 100;
		}
		if (row <= N - 1) {
			moved += (A[row][col] * 7) / 100;
			A[row + 1][col] += (A[row][col] * 7) / 100;
		}
		else {
			moved += (A[row][col] * 7) / 100;
			out += (A[row][col] * 7) / 100;
		}
		if (row >= 3) {
			moved += (A[row][col] * 2) / 100;
			A[row - 2][col] += (A[row][col] * 2) / 100;
		}
		else {
			moved += (A[row][col] * 2) / 100;
			out += (A[row][col] * 2) / 100;
		}
		if (row <= N - 2) {
			moved += (A[row][col] * 2) / 100;
			A[row + 2][col] += (A[row][col] * 2) / 100;
		}
		else {
			moved += (A[row][col] * 2) / 100;
			out += (A[row][col] * 2) / 100;
		}

		//끝줄
		if (row >= 2 && col >= 2) {
			moved += (A[row][col] * 1) / 100;
			A[row - 1][col - 1] += (A[row][col] * 1) / 100;
		}
		else {
			moved += (A[row][col] * 1) / 100;
			out += (A[row][col] * 1) / 100;
		}
		if (row <= N - 1 && col >= 2) {
			moved += (A[row][col] * 1) / 100;
			A[row + 1][col - 1] += (A[row][col] * 1) / 100;
		}
		else {
			moved += (A[row][col] * 1) / 100;
			out += (A[row][col] * 1) / 100;
		}
		
		if (col <= N - 1) {
			A[row][col+1] += (A[row][col] - moved);
		}
		else { out += (A[row][col] - moved); }

		A[row][col] = 0;
	}
	if (way == 4) {
		//첫줄
		if (row >= 3) {
			moved += (A[row][col] * 5) / 100;
			A[row - 2][col] += (A[row][col] * 5) / 100;
		}
		else {
			moved += (A[row][col] * 5) / 100;
			out += (A[row][col] * 5) / 100;
		}

		//두번째줄
		if (col >= 2 && row >= 2) {
			moved += (A[row][col] * 10) / 100;
			A[row - 1][col - 1] += (A[row][col] * 10) / 100;
		}
		else {
			moved += (A[row][col] * 10) / 100;
			out += (A[row][col] * 10) / 100;
		}
		if (col <= N - 1 && row >= 2) {
			moved += (A[row][col] * 10) / 100;
			A[row - 1][col + 1] += (A[row][col] * 10) / 100;
		}
		else {
			moved += (A[row][col] * 10) / 100;
			out += (A[row][col] * 10) / 100;
		}

		//가운데 줄
		if (col >= 2) {
			moved += (A[row][col] * 7) / 100;
			A[row][col - 1] += (A[row][col] * 7) / 100;
		}
		else {
			moved += (A[row][col] * 7) / 100;
			out += (A[row][col] * 7) / 100;
		}
		if (col <= N - 1) {
			moved += (A[row][col] * 7) / 100;
			A[row][col + 1] += (A[row][col] * 7) / 100;
		}
		else {
			moved += (A[row][col] * 7) / 100;
			out += (A[row][col] * 7) / 100;
		}
		if (col >= 3) {
			moved += (A[row][col] * 2) / 100;
			A[row][col - 2] += (A[row][col] * 2) / 100;
		}
		else {
			moved += (A[row][col] * 2) / 100;
			out += (A[row][col] * 2) / 100;
		}
		if (col <= N - 2) {
			moved += (A[row][col] * 2) / 100;
			A[row][col + 2] += (A[row][col] * 2) / 100;
		}
		else {
			moved += (A[row][col] * 2) / 100;
			out += (A[row][col] * 2) / 100;
		}

		//끝줄
		if (row <= N - 1 && col <= N - 1) {
			moved += (A[row][col] * 1) / 100;
			A[row + 1][col + 1] += (A[row][col] * 1) / 100;
		}
		else {
			moved += (A[row][col] * 1) / 100;
			out += (A[row][col] * 1) / 100;
		}
		if (row <= N - 1 && col >= 2) {
			moved += (A[row][col] * 1) / 100;
			A[row + 1][col - 1] += (A[row][col] * 1) / 100;
		}
		else {
			moved += (A[row][col] * 1) / 100;
			out += (A[row][col] * 1) / 100;
		}

		if (row >= 2)
			A[row - 1][col] += (A[row][col] - moved);
		else { out += (A[row][col] - moved); }
	

		A[row][col] = 0;
	}

	return out;
}

int sandAmount(int N) {
	int res = 0;
	int mid = N / 2 + 1;
	int row = mid;
	int col = mid;
	int way = 1;
	int dx[5] = {0, 0, 1, 0, -1}; //0번 인덱스는 무시 좌하우상
	int dy[5] = {0, -1, 0, 1, 0};

	while (!(row == 1 && col == 1)) {
		if (way == 1) {//방향 전환 체크
			if (col + dy[way] == lastLeft - 1) {//일반적인 경우
				if(col + dy[way] > 0)
					lastLeft--;
				way++;
			}
			
		}
		else if (way == 2) {
			if (row + dx[way] == lastDown + 1) {
				if (row + dx[way] != N+1)
					lastDown++;
				way++;
			}
		}
		else if (way == 3) {
			if (col + dy[way] == lastRight + 1) {
				if (col + dy[way] != N+1)
					lastRight++;
				way++;
			}
		}
		else if (way == 4) {
			if (row + dx[way] == lastUp - 1) {
				if (row + dx[way] != 0)
					lastUp--;
				way = 1;
			}
		}
		row = row + dx[way];
		col = col + dy[way];
		res += blow(way, row, col, N);
		/*cout << endl << "current map" << endl;
		for (int i = 1; i <= N; i++) {//0번 행과 열은 안씀
			for (int j = 1; j <= N; j++) {
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		cout << res;*/
	}
	
	return res;
}

int main() {
	int N = 0; // N은 홀수, 3~499
	cin >> N;
	int mid = N / 2 + 1;
	lastLeft = mid - 1;
	lastDown = mid + 1;
	lastRight = mid + 1;
	lastUp = mid - 1;
	for (int i = 1; i <= N; i++) {//0번 행과 열은 안씀
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	cout << sandAmount(N);
	return 0;
}