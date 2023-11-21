#include <iostream>
#include <string>

using namespace std;

string str[1000];
char u[3][3], d[3][3], f[3][3], b[3][3], l[3][3], r[3][3];
//초기상태
void init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			u[i][j] = 'w';
			d[i][j] = 'y';
			f[i][j] = 'r';
			b[i][j] = 'o';
			l[i][j] = 'g';
			r[i][j] = 'b';
		}
	}

}
//지정한 면 돌리기
void self_rotate(char plane, char dir) {
	char temp[3][3] = { 'w' };

	if (plane == 'U') {

		if (dir == '+') {
			temp[2][2] = u[0][2], temp[1][2] = u[0][1], temp[0][2] = u[0][0];
			temp[2][0] = u[2][2], temp[2][1] = u[1][2], temp[2][2] = u[0][2];
			temp[0][0] = u[2][0], temp[1][0] = u[2][1], temp[2][0] = u[2][2];
			temp[0][2] = u[0][0], temp[0][1] = u[1][0], temp[0][0] = u[2][0];
			temp[1][1] = u[1][1];
		}
		else if (dir == '-') {
			temp[2][2] = u[2][0], temp[1][2] = u[2][1], temp[0][2] = u[2][2];
			temp[2][0] = u[0][0], temp[2][1] = u[1][0], temp[2][2] = u[2][0];
			temp[0][0] = u[0][2], temp[1][0] = u[0][1], temp[2][0] = u[0][0];
			temp[0][2] = u[2][2], temp[0][1] = u[1][2], temp[0][0] = u[0][2];
			temp[1][1] = u[1][1];
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				u[i][j] = temp[i][j];
			}
		}
	}

	if (plane == 'D') {

		if (dir == '+') {
			temp[2][2] = d[0][2], temp[1][2] = d[0][1], temp[0][2] = d[0][0];
			temp[2][0] = d[2][2], temp[2][1] = d[1][2], temp[2][2] = d[0][2];
			temp[0][0] = d[2][0], temp[1][0] = d[2][1], temp[2][0] = d[2][2];
			temp[0][2] = d[0][0], temp[0][1] = d[1][0], temp[0][0] = d[2][0];
			temp[1][1] = d[1][1];
		}
		else if (dir == '-') {
			temp[2][2] = d[2][0], temp[1][2] = d[2][1], temp[0][2] = d[2][2];
			temp[2][0] = d[0][0], temp[2][1] = d[1][0], temp[2][2] = d[2][0];
			temp[0][0] = d[0][2], temp[1][0] = d[0][1], temp[2][0] = d[0][0];
			temp[0][2] = d[2][2], temp[0][1] = d[1][2], temp[0][0] = d[0][2];
			temp[1][1] = d[1][1];
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				d[i][j] = temp[i][j];
			}
		}
	}

	if (plane == 'L') {

		if (dir == '+') {
			temp[2][2] = l[0][2], temp[1][2] = l[0][1], temp[0][2] = l[0][0];
			temp[2][0] = l[2][2], temp[2][1] = l[1][2], temp[2][2] = l[0][2];
			temp[0][0] = l[2][0], temp[1][0] = l[2][1], temp[2][0] = l[2][2];
			temp[0][2] = l[0][0], temp[0][1] = l[1][0], temp[0][0] = l[2][0];
			temp[1][1] = l[1][1];
		}
		else if (dir == '-') {
			temp[2][2] = l[2][0], temp[1][2] = l[2][1], temp[0][2] = l[2][2];
			temp[2][0] = l[0][0], temp[2][1] = l[1][0], temp[2][2] = l[2][0];
			temp[0][0] = l[0][2], temp[1][0] = l[0][1], temp[2][0] = l[0][0];
			temp[0][2] = l[2][2], temp[0][1] = l[1][2], temp[0][0] = l[0][2];
			temp[1][1] = l[1][1];
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				l[i][j] = temp[i][j];
			}
		}
	}

	if (plane == 'R') {

		if (dir == '+') {
			temp[2][2] = r[0][2], temp[1][2] = r[0][1], temp[0][2] = r[0][0];
			temp[2][0] = r[2][2], temp[2][1] = r[1][2], temp[2][2] = r[0][2];
			temp[0][0] = r[2][0], temp[1][0] = r[2][1], temp[2][0] = r[2][2];
			temp[0][2] = r[0][0], temp[0][1] = r[1][0], temp[0][0] = r[2][0];
			temp[1][1] = r[1][1];
		}
		else if (dir == '-') {
			temp[2][2] = r[2][0], temp[1][2] = r[2][1], temp[0][2] = r[2][2];
			temp[2][0] = r[0][0], temp[2][1] = r[1][0], temp[2][2] = r[2][0];
			temp[0][0] = r[0][2], temp[1][0] = r[0][1], temp[2][0] = r[0][0];
			temp[0][2] = r[2][2], temp[0][1] = r[1][2], temp[0][0] = r[0][2];
			temp[1][1] = r[1][1];
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				r[i][j] = temp[i][j];
			}
		}
	}

	if (plane == 'F') {

		if (dir == '+') {
			temp[2][2] = f[0][2], temp[1][2] = f[0][1], temp[0][2] = f[0][0];
			temp[2][0] = f[2][2], temp[2][1] = f[1][2], temp[2][2] = f[0][2];
			temp[0][0] = f[2][0], temp[1][0] = f[2][1], temp[2][0] = f[2][2];
			temp[0][2] = f[0][0], temp[0][1] = f[1][0], temp[0][0] = f[2][0];
			temp[1][1] = f[1][1];
		}
		else if (dir == '-') {
			temp[2][2] = f[2][0], temp[1][2] = f[2][1], temp[0][2] = f[2][2];
			temp[2][0] = f[0][0], temp[2][1] = f[1][0], temp[2][2] = f[2][0];
			temp[0][0] = f[0][2], temp[1][0] = f[0][1], temp[2][0] = f[0][0];
			temp[0][2] = f[2][2], temp[0][1] = f[1][2], temp[0][0] = f[0][2];
			temp[1][1] = f[1][1];
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				f[i][j] = temp[i][j];
			}
		}
	}

	if (plane == 'B') {

		if (dir == '+') {
			temp[2][2] = b[0][2], temp[1][2] = b[0][1], temp[0][2] = b[0][0];
			temp[2][0] = b[2][2], temp[2][1] = b[1][2], temp[2][2] = b[0][2];
			temp[0][0] = b[2][0], temp[1][0] = b[2][1], temp[2][0] = b[2][2];
			temp[0][2] = b[0][0], temp[0][1] = b[1][0], temp[0][0] = b[2][0];
			temp[1][1] = b[1][1];
		}
		else if (dir == '-') {
			temp[2][2] = b[2][0], temp[1][2] = b[2][1], temp[0][2] = b[2][2];
			temp[2][0] = b[0][0], temp[2][1] = b[1][0], temp[2][2] = b[2][0];
			temp[0][0] = b[0][2], temp[1][0] = b[0][1], temp[2][0] = b[0][0];
			temp[0][2] = b[2][2], temp[0][1] = b[1][2], temp[0][0] = b[0][2];
			temp[1][1] = b[1][1];
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				b[i][j] = temp[i][j];
			}
		}
	}


}


void cube(int num) {
	//초기 상태에서 str[0 ~ num-1]까지 보면서 회전
	//자기 회전, 상호 작용 회전
	//u+ ->  b/r/f/l    |  d+ -> b/l/f/r
	//l+ ->  u/f/d/b	 |  r+ -> u/b/d/f
	//f+ -> u/r/d/l	
	//b+ -> u/l/d/r
	char tmp[3];
	for (int i = 0; i < num; i++) {
		self_rotate(str[i][0], str[i][1]);
		
		if (str[i][0] == 'U') {
			if (str[i][1] == '+') {//b->r->f->l->b
				tmp[0] = l[0][0]; tmp[1] = l[0][1]; tmp[2] = l[0][2];

				l[0][0] = f[0][0]; l[0][1] = f[0][1]; l[0][2] = f[0][2];
				f[0][0] = r[0][0]; f[0][1] = r[0][1]; f[0][2] = r[0][2];
				r[0][0] = b[0][0]; r[0][1] = b[0][1]; r[0][2] = b[0][2];
				b[0][0] = tmp[0]; b[0][1] = tmp[1]; b[0][2] = tmp[2];
			}
			if (str[i][1] == '-') { //r<-f<-l<-b
				tmp[0] = r[0][0]; tmp[1] = r[0][1]; tmp[2] = r[0][2];

				r[0][0] = f[0][0]; r[0][1] = f[0][1]; r[0][2] = f[0][2];
				f[0][0] = l[0][0]; f[0][1] = l[0][1]; f[0][2] = l[0][2];
				l[0][0] = b[0][0]; l[0][1] = b[0][1]; l[0][2] = b[0][2];
				b[0][0] = tmp[0]; b[0][1] = tmp[1]; b[0][2] = tmp[2];
			}
		}

		else if (str[i][0] == 'D') { //d+ -> b/l/f/r
			if (str[i][1] == '+') {
				tmp[0] = r[2][0]; tmp[1] = r[2][1]; tmp[2] = r[2][2];

				r[2][0] = f[2][0]; r[2][1] = f[2][1]; r[2][2] = f[2][2];
				f[2][0] = l[2][0]; f[2][1] = l[2][1]; f[2][2] = l[2][2];
				l[2][0] = b[2][0]; l[2][1] = b[2][1]; l[2][2] = b[2][2];
				b[2][0] = tmp[0]; b[2][1] = tmp[1]; b[2][2] = tmp[2];
			}
			if (str[i][1] == '-') { // b<l<f<r
				tmp[0] = b[2][0]; tmp[1] = b[2][1]; tmp[2] = b[2][2];

				b[2][0] = l[2][0]; b[2][1] = l[2][1]; b[2][2] = l[2][2];
				l[2][0] = f[2][0]; l[2][1] = f[2][1]; l[2][2] = f[2][2];
				f[2][0] = r[2][0]; f[2][1] = r[2][1]; f[2][2] = r[2][2];
				r[2][0] = tmp[0]; r[2][1] = tmp[1]; r[2][2] = tmp[2];
			}
		}
		//f+ -> u/r/d/l		 |  b+ -> u/l/d/r
		else if (str[i][0] == 'F') {
			if (str[i][1] == '+') {
				tmp[0] = l[0][2]; tmp[1] = l[1][2]; tmp[2] = l[2][2];

				l[0][2] = d[0][0]; l[1][2] = d[0][1]; l[2][2] = d[0][2];
				d[0][0] = r[2][0]; d[0][1] = r[1][0]; d[0][2] = r[0][0];
				r[0][0] = u[2][0]; r[1][0] = u[2][1]; r[2][0] = u[2][2];
				u[2][0] = tmp[2]; u[2][1] = tmp[1]; u[2][2] = tmp[0];
			}
			if (str[i][1] == '-') { //u<r<d<l
				tmp[0] = u[2][0]; tmp[1] = u[2][1]; tmp[2] = u[2][2];
				u[2][0] = r[0][0]; u[2][1] = r[1][0]; u[2][2] = r[2][0];
				r[0][0] = d[0][2]; r[1][0] = d[0][1]; r[2][0] = d[0][0];
				d[0][0] = l[0][2]; d[0][1] = l[1][2]; d[0][2] = l[2][2];
				l[0][2] = tmp[2]; l[1][2] = tmp[1]; l[2][2] = tmp[0];
			}
		}

		else if (str[i][0] == 'B') {
			if (str[i][1] == '+') {
				tmp[0] = r[2][2]; tmp[1] = r[1][2]; tmp[2] = r[0][2];

				r[2][2] = d[2][0]; r[1][2] = d[2][1]; r[0][2] = d[2][2];
				d[2][0] = l[0][0]; d[2][1] = l[1][0]; d[2][2] = l[2][0];
				l[0][0] = u[0][2]; l[1][0] = u[0][1]; l[2][0] = u[0][0];
				u[0][2] = tmp[0]; u[0][1] = tmp[1]; u[0][0] = tmp[2];
			}
			if (str[i][1] == '-') { //u<l<d<r
				tmp[0] = u[0][2]; tmp[1] = u[0][1]; tmp[2] = u[0][0];

				u[0][2] = l[0][0]; u[0][1] = l[1][0]; u[0][0] = l[2][0];
				l[0][0] = d[2][0]; l[1][0] = d[2][1]; l[2][0] = d[2][2];
				d[2][0] = r[2][2]; d[2][1] = r[1][2]; d[2][2] = r[0][2];
				r[2][2] = tmp[0]; r[1][2] = tmp[1]; r[0][2] = tmp[2];
			}
		}
		//l+ ->  u/f/d/b	 |  r+ -> u/b/d/f
		else if (str[i][0] == 'L') {
			if (str[i][1] == '+') {
				tmp[0] = b[0][2]; tmp[1] = b[1][2]; tmp[2] = b[2][2];

				b[0][2] = d[2][0]; b[1][2] = d[1][0]; b[2][2] = d[0][0];
				d[0][0] = f[0][0]; d[1][0] = f[1][0]; d[2][0] = f[2][0];
				f[0][0] = u[0][0]; f[1][0] = u[1][0]; f[2][0] = u[2][0];
				u[2][0] = tmp[0]; u[1][0] = tmp[1]; u[0][0] = tmp[2];
			}
			if (str[i][1] == '-') { //u<f<d<b
				tmp[0] = u[0][0]; tmp[1] = u[1][0]; tmp[2] = u[2][0];

				u[0][0] = f[0][0]; u[1][0] = f[1][0]; u[2][0] = f[2][0];
				f[0][0] = d[0][0]; f[1][0] = d[1][0]; f[2][0] = d[2][0];
				d[0][0] = b[2][2]; d[1][0] = b[1][2]; d[2][0] = b[0][2];
				b[0][2] = tmp[2]; b[1][2] = tmp[1]; b[2][2] = tmp[0];
			}
		}

		else if (str[i][0] == 'R') {
			if (str[i][1] == '+') { // u/b/d/f
				tmp[0] = f[0][2]; tmp[1] = f[1][2]; tmp[2] = f[2][2];

				f[0][2] = d[0][2]; f[1][2] = d[1][2]; f[2][2] = d[2][2];
				d[0][2] = b[2][0]; d[1][2] = b[1][0]; d[2][2] = b[0][0];
				b[0][0] = u[2][2]; b[1][0] = u[1][2]; b[2][0] = u[0][2];
				u[0][2] = tmp[0]; u[1][2] = tmp[1]; u[2][2] = tmp[2];
			}
			if (str[i][1] == '-') { // u<b<d<f
				tmp[0] = u[0][2]; tmp[1] = u[1][2]; tmp[2] = u[2][2];

				u[0][2] = b[2][0]; u[1][2] = b[1][0]; u[2][2] = b[0][0];
				b[0][0] = d[2][2]; b[1][0] = d[1][2]; b[2][0] = d[0][2];
				d[0][2] = f[0][2]; d[1][2] = f[1][2]; d[2][2] = f[2][2];
				f[0][2] = tmp[0]; f[1][2] = tmp[1]; f[2][2] = tmp[2];
			}
		}

	}
}

int main() {
	int T, n;
	cin >> T;
	init();
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> str[j];
		}
		cube(n);
		cout << u[0][0] << u[0][1] << u[0][2] << endl;
		cout << u[1][0] << u[1][1] << u[1][2] << endl;
		cout << u[2][0] << u[2][1] << u[2][2] << endl;
		init();
	}
	return 0;
}