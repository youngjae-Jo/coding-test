#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    // ��� ������ ���� ī��Ʈ �迭
    int count[10] = { 0 };

    // �� ������ �󵵸� ����
    for (char c : s) {
        count[c - '0']++;
    }

    // ������������ ���
    for (int i = 9; i >= 0; i--) {
        while (count[i]--) {
            cout << i;
        }
    }

    return 0;
}
