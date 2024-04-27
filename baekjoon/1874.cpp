#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> s;
    vector<char> result;
    int num;
    int cnt = 1;

    for (int i = 0; i < n; i++) {
        cin >> num;
        while (cnt <= num) {
            s.push(cnt);
            cnt++;
            result.push_back('+');
        }
        if (s.top() == num) {
            s.pop();
            result.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }


    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}



