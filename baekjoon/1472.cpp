#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    // 계수 정렬을 위한 카운트 배열
    int count[10] = { 0 };

    // 각 숫자의 빈도를 센다
    for (char c : s) {
        count[c - '0']++;
    }

    // 내림차순으로 출력
    for (int i = 9; i >= 0; i--) {
        while (count[i]--) {
            cout << i;
        }
    }

    return 0;
}
