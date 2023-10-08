#include <iostream>
#include <vector>

using namespace std;

int N=0, M=0, K=0;
int map[51][51] = { 0, };
int r, c, m, s, d;

struct Fireball {
	int row = 0 ; //1부터 N
	int col = 0; //1부터 N
	int mass = 0;
	int direction = -1; //0~7
	int speed = 0;
};

vector <Fireball> fireball;
//struct fireball fireball[2500+2*1000];

void new_fireball(int row, int col) {	//겹치는거 있으면 하나로 합치고 4개로 나누기

	int index[2500] = {-1,}; //몇번째 fireball들끼리 겹치는지 저장
	int cnt = 0; //j, map[j][k]
	int L = 0, S = 0; //mass, speed
	int oddFlag = 1; //짝수면 0
	int evenFlag = 1; //홀수면 0
	int deleted = 0;

	for (int i = 0; i < fireball.size(); i++) {//저장
		if (fireball[i].row == row && fireball[i].col == col) {
			index[cnt] = i; 
			cnt++; //몇개
		}
	}
	for (int j = 0; j < cnt; j++) {
		L += fireball[index[j]].mass;
		S += fireball[index[j]].speed;
		if (fireball[index[j]].direction % 2 == 0)
			oddFlag = 0;
		else
			evenFlag = 0;
	}
	int flag = 0;
	if (!(oddFlag || evenFlag)) // 둘다 아니면 direction 1,3,5,7
		flag = 1;

	L /= 5;
	S /= cnt;

	if (cnt == 2) {
		for (int k = 0; k < 2; k++) {//2개
			fireball[index[k] - deleted].mass = L;
			fireball[index[k] - deleted].speed = S;
			fireball[index[k] - deleted].direction = 2 * k + flag;
			if (L == 0) {
				fireball.erase(fireball.begin() + index[k] - deleted);
				deleted++;
				map[row][col]--;
			}
		}
		struct Fireball F;
		//3번째
		F.row = row;
		F.col = col;
		F.mass = L;
		F.speed = S;
		F.direction = 2 * 2 + flag;
		if (L != 0) {
			fireball.push_back(F);
			map[row][col]++;
		}

		//4번째
		F.row = row;
		F.col = col;
		F.mass = L;
		F.speed = S;
		F.direction = 2 * 3 + flag;
		if (L != 0) {
			fireball.push_back(F);
			map[row][col]++;
		}
	}
	else if (cnt == 3) {
		for (int k = 0; k < 3; k++) {
			fireball[index[k] - deleted].mass = L;
			fireball[index[k] - deleted].speed = S;
			fireball[index[k] - deleted].direction = 2 * k + flag;
			if (L == 0) {
				fireball.erase(fireball.begin() + index[k] - deleted);
				deleted++;
				map[row][col]--;
			}
		}
		struct Fireball F;
		//4번째
		F.row = row;
		F.col = col;
		F.mass = L;
		F.speed = S;
		F.direction = 2 * 3 + flag;
		if (L != 0) {		
			fireball.push_back(F);
			map[row][col]++;
		}
	}
	else if (cnt >= 4) {
		for (int k = 0; k < 4; k++) {
			fireball[index[k] - deleted].mass = L;
			fireball[index[k] - deleted].speed = S;
			fireball[index[k] - deleted].direction = 2 * k + flag;
			if (L == 0) {
				fireball.erase(fireball.begin() + index[k] - deleted);
				deleted++;
				map[row][col]--;
			}
		}
		for (int idx = 4; idx < cnt; idx++) {//4개이후로는 지우기
			fireball.erase(fireball.begin() + index[idx] - deleted);
			deleted++;
			map[row][col]--;
		}
	}
}

void move_fireball() {
	int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; //문제에서 주어진 순서대로 이동
	int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

	for (int i = 0; i < fireball.size(); i++) { //fireball 전체에 대해서
			int prevRow = fireball[i].row;
			int prevCol = fireball[i].col;

			fireball[i].row = fireball[i].row + dx[fireball[i].direction] * fireball[i].speed; //해당 방향으로 해당 속도로
			fireball[i].col = fireball[i].col + dy[fireball[i].direction] * fireball[i].speed;
			
			if (fireball[i].row > N || fireball[i].row <= 0 || fireball[i].col > N || fireball[i].col <= 0) { //맵 나가면
				if (fireball[i].row > N)
					fireball[i].row = (fireball[i].row - 1) % N + 1;
				else if (fireball[i].row <= 0)
					fireball[i].row = N + (fireball[i].row % N);
				if (fireball[i].col > N)
					fireball[i].col = (fireball[i].col - 1) % N + 1;
				else if (fireball[i].col <= 0)
					fireball[i].col = N + (fireball[i].col % N);
			}			
			map[fireball[i].row][fireball[i].col]++; //옮겨간 곳
			map[prevRow][prevCol]--; //원래 있던 자리 비우기	
	}

	for (int j = 1; j <= N; j++) { 
		for (int k = 1; k <= N; k++) {//2개 이상 있어서 합치고 쪼개기
			if (map[j][k] >= 2)
				new_fireball(j, k);
		}
	}
}

int totalMass() {
	int sum = 0;
	for (int i = 0; i < fireball.size(); i++)
		sum += fireball[i].mass;
	return sum;
}

int main() {//1번~N번
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		//vector <Fireball> f;
		struct Fireball f;
		f.row = r;//1~N
		f.col = c;//1~N
		f.mass = m;
		f.speed = s;
		f.direction = d;
		fireball.push_back(f);
		map[r][c]++;
	}
	for (int j = 0; j < K; j++) {
		move_fireball();
	}
	cout << totalMass();
	return 0;
}