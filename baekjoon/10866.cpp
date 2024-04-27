#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N;
    cin >> N;
    deque<int> dq;

    string arr;
    for (int i = 0; i < N; i++) {
        cin >> arr;
        if (arr == "push_front") {
            int tmp = 0;
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if (arr == "push_back") {
            int tmp = 0;
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if (arr == "pop_front") {
            if (dq.empty() == 1)
                cout << "-1" << endl;
            else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if (arr == "pop_back") {
            if (dq.empty() == 1)
                cout << "-1" << endl;
            else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        else if (arr == "size") {
            cout << dq.size() << endl;
        }
        else if (arr == "empty") {
            cout << dq.empty() << endl;
        }
        else if (arr == "front") {
            if (dq.empty())
                cout << "-1" << endl;
            else
                cout << dq.front() << endl;
        }
        else if (arr == "back") {
            if (dq.empty())
                cout << "-1" << endl;
            else
                cout << dq.back() << endl;

        }

    }


    return 0;
}



