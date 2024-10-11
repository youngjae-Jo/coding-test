#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int s;
int visited[2000][2000]; //화면에 i개 클립에 j개
int maxi = 2000;

int main() {
	cin >> s;
	//3가지 연산! 
	//1. 화면에 있는 임티 복사해서 클립보드에 저장
	//2. 클립보드의 이모티콘을 화면에 붙여넣기
	//3. 화면의 이모티콘 중 하나를 삭제
	// 
	//연산 하려면 1초 듦
	//1번이면 기존 클립보드는 덮어씌움
	//클립보드에서 삭제 불가
	//2번하면 클립보드에 있는 이모티콘 개수를 화면에 추가

	queue<pair <pair<int, int>, int>> Q;
	Q.push(make_pair(make_pair(1, 0), 0));
	visited[1][0] = 1;
	int t = 0;
	while (!Q.empty()) {
		int screen = Q.front().first.first;
		int clip = Q.front().first.second;
		int time = Q.front().second;
		Q.pop();

		if (screen == s) {
			t = time; break;
		}
		if (screen > 0 && screen < maxi) {
			if (!visited[screen][screen]) {//1
				visited[screen][screen] = true;
				Q.push(make_pair(make_pair(screen, screen), time + 1));
			}
			if (!visited[screen - 1][clip]) {//3
				visited[screen - 1][clip] = true;
				Q.push(make_pair(make_pair(screen - 1, clip), time + 1));
			}
		}
		if (clip > 0 && screen + clip < maxi) {
			if (!visited[screen + clip][clip]) {//2
				visited[screen + clip][clip] = true;
				Q.push(make_pair(make_pair(screen + clip, clip), time + 1));
			}
		}
	}
	cout << t;

}