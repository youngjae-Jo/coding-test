#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int s;
int visited[2000][2000]; //ȭ�鿡 i�� Ŭ���� j��
int maxi = 2000;

int main() {
	cin >> s;
	//3���� ����! 
	//1. ȭ�鿡 �ִ� ��Ƽ �����ؼ� Ŭ�����忡 ����
	//2. Ŭ�������� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ�
	//3. ȭ���� �̸�Ƽ�� �� �ϳ��� ����
	// 
	//���� �Ϸ��� 1�� ��
	//1���̸� ���� Ŭ������� �����
	//Ŭ�����忡�� ���� �Ұ�
	//2���ϸ� Ŭ�����忡 �ִ� �̸�Ƽ�� ������ ȭ�鿡 �߰�

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