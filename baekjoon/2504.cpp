#include <iostream>
#include <string>
#include <stack>

using namespace std;

int check[30];

int main() {
	string s;
	cin >> s;
	stack<char> candi;
	// ( ) [ ] 4가지
	// (),[]굿 -> (()), ([]), ()[] ㄱㄴ
	//(): 2, []: 3, (x): 2*x, [x]: 3*x, xy: x+y

	//탐색하면서 (를 발견하면 컨테이너에 집어넣음, 
	// ( / [ 가 있을 때 ) ] 나오는건 괜찮음 ([)] 불가
	// 나중에 넣은게 먼저 나와야 하니까 이건 stack!
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