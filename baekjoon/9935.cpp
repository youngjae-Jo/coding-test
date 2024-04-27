#include<iostream>
#include<string.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a; // ��ü ���ڿ� ����
    string b; // ���� ���ڿ� ����
    string t = ""; // �ӽ� ���ڿ� 
    cin >> a >> b;
    int a_len = a.length(); // ��ü ���ڿ� ����
    int b_len = b.length(); // ���� ���ڿ� ����
    for (int i = 0; i < a.length(); i++)
    {
        t += a[i]; // ���� �߰�
        if (t.length() >= b_len) { // �ӽ� ���� ���̰� ���� ���ڿ� ���� ũ�ų� ���� ��
            bool flag = true; // ���� ���ڿ� �ִ��� Ȯ���ϴ� flag
            for (int j = 0; j < b_len; j++) {
                if (t[t.length() - b_len + j] != b[j]) {
                    flag = false;
                    break;
                } // t�ڿ��� ���� ���ڿ� ���̸�ŭ ��
            }

            if (flag) // ���� ���ڿ��� ��� ���� 
                t.erase(t.end() - b_len, t.end());
        }
    }
    if (t.empty()) // ���� �ִ� ���ڿ��� ���� ���
        cout << "FRULA" << '\n';
    else
        cout << t << '\n';
    return 0;
}
