#include <iostream>

using namespace std;

int N;
int score = 0;
int blue[4][6];
int green[6][4];

bool is_possible(int x, int y, int mode) {
	if (mode == 1) //파랑
		return (x >= 0 && x <= 3 && y >= 0 && y <= 5 && blue[x][y] == 0);
	else if (mode == 3) //파랑인데 2*1
		return ((x >= 0 && x <= 3 && y >= 0 && y <= 5 && blue[x][y] == 0) && (x + 1 >= 0 && x + 1 <= 3 && y >= 0 && y <= 5 && blue[x + 1][y] == 0));

	else if (mode == 2)//초록
		return (x >= 0 && x <= 5 && y >= 0 && y <= 3 && green[x][y] == 0);
	else if (mode == 4) //초록인데 2*1
		return ((x >= 0 && x <= 5 && y >= 0 && y <= 3 && green[x][y] == 0) && (x >= 0 && x <= 5 && y + 1 >= 0 && y + 1 <= 3 && green[x][y + 1] == 0));
	return false;
}


void toBlue(int t, int x, int y) {
	int y_check = 0;

	switch (t) { //x는 그대로 y가 바뀌면서 감
	case 1: //	t = 1: 크기가 1×1인 블록을 (x, y)에 놓은 경우
		while (is_possible(x, y_check++, 1)) {}
		blue[x][y_check - 2] = 1;
		break;
	case 2: //	t = 2: 크기가 1×2인 블록을 (x, y), (x, y+1)에 놓은 경우
		y_check = 1;
		while (is_possible(x, y_check++, 1)) {}
		blue[x][y_check - 3] = 1;
		blue[x][y_check - 2] = 1;
		break;
	case 3: //	t = 3: 크기가 2×1인 블록을 (x, y), (x+1, y)에 놓은 경우
		while (is_possible(x, y_check++, 3)) {}
		blue[x][y_check - 2] = 1;
		blue[x + 1][y_check - 2] = 1;
		break;
	default:
		break;
	}

	//파란색은 열 꽉찬게 있으면 비우기-> 비우고 나면 1점 추가, 
	for (int i = 5; i >= 0; i--) {//열
		int flag = 1;
		for (int j = 0; j < 4; j++) {
			if (blue[j][i] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			if (i != 0) {
				for (int j = 0; j < 4; j++) {
					if (blue[j][i - 1] == 0) {
						flag = 0;
						break;
					}
				}
				if (flag == 1)
					flag = 2;
				else if (flag == 0)
					flag = 1;
			}
			if (flag == 1) {
				for (int j = 0; j < 4; j++) {//비우기
					blue[j][i] = 0;
				}
				for (int k = i - 1; k >= 0; k--) {
					for (int z = 0; z < 4; z++) {
						blue[z][k + 1] = blue[z][k];
					}
				}

				score++;
			}
			else if (flag == 2) {
				for (int j = 0; j < 4; j++) {//비우기
					blue[j][i] = 0;
					blue[j][i - 1] = 0;
				}
				for (int k = i - 2; k >= 0; k--) {
					for (int z = 0; z < 4; z++) {
						blue[z][k + 2] = blue[z][k];
					}
				}

				score += 2;
			}
		}
	}

	//중간 지대에 있으면 오른쪽으로 밀기 ,파란색의 경우 행이 꽉차고 거기에 1*2가 놓일 수 있음
	int middle_area = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j < 4; j++) {
			if (blue[j][i] == 1) {
				middle_area++;
				break;
			}
		}
	}
	//if (y_check - 2 == 1) {
	if (middle_area == 2) {
		if (blue[x][2] == 1 && t == 2) {//2칸밀기
			for (int i = 0; i < 4; i++) {
				for (int j = 3; j >= 0; j--) {
					blue[i][j + 2] = blue[i][j];
				}
			}
		}
	}
	else if (middle_area == 1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 4; j >= 0; j--) {
				blue[i][j + 1] = blue[i][j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {//밀고나면 중간지대 0으로
		for (int j = 0; j < 2; j++)
			blue[i][j] = 0;
	}
}

void toGreen(int t, int x, int y) {

	int x_check = 0;

	switch (t) { //x는 그대로 y가 바뀌면서 감
	case 1: //	t = 1: 크기가 1×1인 블록을 (x, y)에 놓은 경우
		while (is_possible(x_check++, y, 2)) {}
		green[x_check - 2][y] = 1;
		break;
	case 2: //	t = 2: 크기가 1×2인 블록을 (x, y), (x, y+1)에 놓은 경우
		x_check = 1;
		while (is_possible(x_check++, y, 4)) {}
		green[x_check - 2][y] = 1;
		green[x_check - 2][y + 1] = 1;
		break;
	case 3: //	t = 3: 크기가 2×1인 블록을 (x, y), (x+1, y)에 놓은 경우
		while (is_possible(x_check++, y, 2)) {}
		green[x_check - 3][y] = 1;
		green[x_check - 2][y] = 1;
		break;
	default:
		break;
	}
	//행비우기, 한번 옮겼는데 한번더 옮겨야하는경우(g,b모두), i,i+1 동시인 경우
	for (int i = 5; i >= 0; i--) {//행
		int flag = 1;
		for (int j = 0; j < 4; j++) {
			if (green[i][j] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			if (i != 0) {
				for (int j = 0; j < 4; j++) {
					if (green[i - 1][j] == 0) {
						flag = 0;
						break;
					}
				}
				if (flag == 1)
					flag = 2;
				else if (flag == 0)
					flag = 1;
			}
			if (flag == 1) {
				for (int j = 0; j < 4; j++) {//비우기
					green[i][j] = 0;
				}
				for (int k = i - 1; k >= 0; k--) {
					for (int z = 0; z < 4; z++) {
						green[k + 1][z] = green[k][z];
					}
				}
				score++;
			}
			else if (flag == 2) {//두번 pop
				for (int j = 0; j < 4; j++) {//비우기
					green[i][j] = 0;
					green[i - 1][j] = 0;
				}
				for (int k = i - 2; k >= 0; k--) {
					for (int z = 0; z < 4; z++) {
						green[k + 2][z] = green[k][z];
					}
				}
				score += 2;
			}
		}
	}
	int middle_area = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j] == 1) {
				middle_area++;
				break;
			}
		}
	}

	//중간 지대에 있으면 아래쪽으로 밀기
	if (middle_area == 2) {
		if (green[2][y] == 1 && t == 3) {//2칸밀기
			for (int i = 0; i < 4; i++) {
				for (int j = 3; j >= 0; j--) {
					green[j + 2][i] = green[j][i];
				}
			}
		}
	}
	else if (middle_area == 1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 4; j >= 0; j--) {
				green[j + 1][i] = green[j][i];
			}
		}
	}


	for (int i = 0; i < 2; i++) {//밀고나면 중간지대 0으로
		for (int j = 0; j < 4; j++)
			green[i][j] = 0;
	}
}

int main() {
	cin >> N; //블록을 놓은 횟수
	for (int i = 0; i < N; i++) {
		int t, x, y;
		cin >> t >> x >> y;

		toBlue(t, x, y);
		toGreen(t, x, y);
	}
	int area = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 2; j < 6; j++) {
			if (blue[i][j] == 1) area++;
			if (green[j][i] == 1) area++;
		}
	}

	//출력
	cout << score << endl << area;

	return 0;
}