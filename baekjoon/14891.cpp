#include <iostream>

using namespace std;

int K;
//12시부터 시계 방향으로
int wheel[4][8]; //N극은 0, S극은 1

void rotate_f(int idx) {//시계방향
	int prev = wheel[idx][0];
	for (int i = 0; i < 7; i++) {
		int temp = wheel[idx][i + 1];
		wheel[idx][i + 1] = prev;//wheel[idx][i];
		prev = temp;
	}
	wheel[idx][0] = prev;

}

void rotate_b(int idx) {//반시계방향
	int prev = wheel[idx][0];
	for (int i = 8; i > 1; i--) {
		int temp = wheel[idx][i - 1];
		wheel[idx][i - 1] = prev;//wheel[idx][i];
		prev = temp;
	}
	wheel[idx][0] = prev;
}


void rotate(int w, int d) {//한칸 회전
	//옆에 있는 애랑 같은 극이면 냅두고 반대극이었으면 같이 돎
	//w번을 시계로 돌릴 때 돈다면 반시계, 반시계->시계

	if (w == 1) {
		if (wheel[0][2] != wheel[1][6]) {//오른쪽
			if (wheel[1][2] != wheel[2][6]) {//그옆
				if (wheel[2][2] != wheel[3][6]) {//그옆
					if (d == 1)
						rotate_b(3);
					else if (d == -1)
						rotate_f(3);
				}
				if (d == 1)
					rotate_f(2);
				else if (d == -1)
					rotate_b(2);
			}
			if (d == 1)
				rotate_b(1);
			else if(d==-1)
				rotate_f(1);
		}
		if (d == 1)
			rotate_f(0);
		else if (d == -1)
			rotate_b(0);
	}


	if (w == 2) {
		if (wheel[1][2] != wheel[2][6]) {//오른쪽
			if (wheel[2][2] != wheel[3][6]) {//그옆
				if (d == 1)
					rotate_f(3);
				else if (d == -1)
					rotate_b(3);
			}
			if (d == 1)
				rotate_b(2);
			else if (d == -1)
				rotate_f(2);
		}
		if (wheel[1][6] != wheel[0][2]) {//왼쪽
			if (d == 1)
				rotate_b(0);
			else if (d == -1)
				rotate_f(0);
		}
		if (d == 1)
			rotate_f(1);
		else if (d == -1)
			rotate_b(1);
	}


	if (w == 3) {
		if (wheel[2][2] != wheel[3][6]) {//오른쪽
			if (d == 1)
				rotate_b(3);
			else if (d == -1)
				rotate_f(3);
		}
		if (wheel[2][6] != wheel[1][2]) {//왼쪽
			if (wheel[0][2] != wheel[1][6]) {// 그옆
				if (d == 1)
					rotate_f(0);
				else if (d == -1)
					rotate_b(0);
			}
			if (d == 1)
				rotate_b(1);
			else if (d == -1)
				rotate_f(1);
		}
		if (d == 1)
			rotate_f(2);
		else if (d == -1)
			rotate_b(2);
	}

	if (w == 4) {
		if (wheel[3][6] != wheel[2][2]) {//왼쪽
			if (wheel[2][6] != wheel[1][2]) {//왼쪽
				if (wheel[0][2] != wheel[1][6]) {// 그옆
					if (d == 1)
						rotate_b(0);
					else if (d == -1)
						rotate_f(0);
				}
				if (d == 1)
					rotate_f(1);
				else if (d == -1)
					rotate_b(1);
			}
			if (d == 1)
				rotate_b(2);
			else if (d == -1)
				rotate_f(2);
		}
		if (d == 1)
			rotate_f(3);
		else if (d == -1)
			rotate_b(3);
	}
}

int main() {
	int numb = 0, dir = 0; //1->wheel[numb]시계, -1 -> wheel[numb]반시계
	int temp = 0;
	for(int n = 0; n<4; n++){
		cin >> temp;
		for (int i = 7; i >=0; i--){
			wheel[n][i] = temp % 10;
			temp /= 10;
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> numb >> dir;
		rotate(numb, dir);
	}
	//12시방향
	cout << wheel[0][0] + 2 * wheel[1][0] + 4 * wheel[2][0] + 8 * wheel[3][0];
	
	return 0;
}