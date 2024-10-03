#include <iostream>
#include <cstring>

using namespace std;

int sushi[30001];
int ate[3001];

int main() {
	//N개 접시, 초밥 가짓수 d, 연속해서 먹는 k개의 접시, 쿠폰 번호 c
	int N, d, k, c;
	int maxi = -1;
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		int coupon = 1; //없으면 추가해야 하니까 일단 더 준다 생각
		for (int j = i; j < i + k; j++) {
			if (ate[sushi[j % N]] == 1)
				cnt++;
			else
				ate[sushi[j % N]] = 1;
			if (sushi[j % N] == c) //k개 뒤졌을 때 있으면 안줌
				coupon = 0;
		}
		maxi = max(maxi, k - cnt + coupon); //k개 중에서 cnt개 겹치고 coupon만큼 더 줌
		memset(ate, 0, sizeof(ate));
	}
	cout << maxi;
	//k개 연속으로 먹으면 할인, 쿠폰에 적힌 c를 공짜로 추가(벨트 위에 없으면 만들어서)
	//다양한 종류가 목표
	return 0;
}