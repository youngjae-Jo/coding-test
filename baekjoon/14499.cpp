#include <iostream>

using namespace std;

int map[20][20];
int dc[7]; //전개도에서 각각의 수를 위치 정보로 취급, 헷갈리니까 0번째 인덱스는 무시
#define FAKE -1

void dice(int way, int m[][20], int N, int M) {//이동할때마다 제일 위의 수 출력
	int temp[7] = {FAKE, dc[1], dc[2], dc[3], dc[4], dc[5], dc[6]};
	//동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
	if (way == 1) {
		dc[1] = temp[4];
		dc[3] = temp[1];
		dc[4] = temp[6];
		dc[6] = temp[3];
	}
	else if (way == 2) {
		dc[1] = temp[3];
		dc[3] = temp[6];
		dc[4] = temp[1];
		dc[6] = temp[4];
	}
	else if (way == 3) {
		dc[2] = temp[1];
		dc[1] = temp[5];
		dc[5] = temp[6];
		dc[6] = temp[2];
	}
	else if (way == 4) {
		dc[2] = temp[6];
		dc[1] = temp[2];
		dc[5] = temp[1];
		dc[6] = temp[5];
	}
}

int main() {
	int N = 0, M = 0, x = 0, y = 0, K = 0;
	int way = -1;
	int dx[5] = {FAKE, 0, 0, -1, 1};
	int dy[5] = {FAKE, 1, -1, 0, 0};
	cin >> N >> M >> x >> y >> K; //조건 세팅
	int currX = x, currY = y;

	for (int i = 0; i < N; i++) {//맵 입력 받기
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {//주사위 이동 명령 받기
		cin >> way;
		if (currX + dx[way] < N && currX + dx[way] >=0 &&
			currY + dy[way] < M && currY + dy[way] >=0) {//맵 내에서 이동했다면
			currX += dx[way];
			currY += dy[way];
			dice(way, map, N, M);
			if(map[currX][currY] == 0)
				map[currX][currY] = dc[6];
			else{
				dc[6] = map[currX][currY];
				map[currX][currY] = 0;
			}
			cout << dc[1] <<endl;
		}
	}


	return 0;
}