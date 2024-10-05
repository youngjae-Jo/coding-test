#include <iostream>
#include <string>
#include <stack>

using namespace std;

int check[30];

int main() {
	string s;
	cin >> s;
	stack<char> candi;
	// ( ) [ ] 4����
	// (),[]�� -> (()), ([]), ()[] ����
	//(): 2, []: 3, (x): 2*x, [x]: 3*x, xy: x+y

	//Ž���ϸ鼭 (�� �߰��ϸ� �����̳ʿ� �������, 
	// ( / [ �� ���� �� ) ] �����°� ������ ([)] �Ұ�
	// ���߿� ������ ���� ���;� �ϴϱ� �̰� stack!
	int ans = 0;
	int inside = 1;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			inside *= 2;
			candi.push('(');
		}
		else if (s[i] == '[') {
			inside *= 3;
			candi.push('[');
		}
		else if (s[i] == ')') {
			if (candi.empty() || candi.top() != '(') {
				ans = 0;
				break;
			}
			if (s[i - 1] == '(') {
				ans += inside;
				inside /= 2;
				candi.pop();
			}
			else {
				inside /= 2;
				candi.pop();
			}
		}
		else if (s[i] == ']') {
			if (candi.empty() || candi.top() != '[') {
				ans = 0;
				break;
			}
			if (s[i - 1] == '[') {
				ans += inside;
				inside /= 3;
				candi.pop();
			}
			else {
				inside /= 3;
				candi.pop();
			}

		}

	}
	if (!candi.empty())
		cout << "0";
	else
		cout << ans;
	return 0;
}