#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;
    queue<int> q;
    string arr;
    for (int i = 0; i < N; i++) {
        cin >> arr;
        if (arr == "push") {
            int tmp = 0;
            cin >> tmp;
            q.push(tmp);
        }
        else if (arr == "pop") {
            if (q.empty() == 1)
                cout << "-1" << endl;
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (arr == "size") {
            cout << q.size() << endl;
        }
        else if (arr == "empty") {
            cout << q.empty() << endl;
        }
        else if (arr == "front") {
            if (q.empty())
                cout << "-1" << endl;
            else
                cout << q.front() << endl;
        }
        else if (arr == "back") {
            if (q.empty())
                cout << "-1" << endl;
            else
                cout << q.back() << endl;

        }

    }


    return 0;
}



