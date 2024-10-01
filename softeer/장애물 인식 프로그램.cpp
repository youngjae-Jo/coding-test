#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int maap[25][25];
int N;
int visited[25][25];
int dx[4] = { 0,0,-1,1 }; //동서남북
int dy[4] = { 1,-1,0,0 };

bool isBlock(int x, int y) {

    return (x >= 0 && x < N && y >= 0 && y < N && !visited[x][y] && maap[x][y]);
}

int main(int argc, char** argv)
{
    //1은 장애물 0은 도로
    //상하좌우 인접이면 모임으로 넣어줌
    vector<int>candi;
    string s;
    //입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            maap[i][j] = s[j] - '0';
        }
    }


    //처리
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            queue<pair<int, int>> q;
            if (isBlock(i, j)) {
                visited[i][j] = 1;
                candi.push_back(1);
                q.push(make_pair(i, j));
                int sz = 0;
                while (!q.empty()) {
                    sz++;
                    pair<int, int> cur = q.front();
                    int cx = cur.first;
                    int cy = cur.second;

                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];

                        if (isBlock(nx, ny)) {
                            visited[nx][ny] = 1;
                            q.push(make_pair(nx, ny));
                        }
                    }

                }
                if (candi.size() != 0)
                    candi[candi.size() - 1] = sz;
            }
        }
    }

    sort(candi.begin(), candi.end());

    //출력
    cout << candi.size() << endl;
    for (int i = 0; i < candi.size(); i++)
        cout << candi[i] << endl;



    return 0;
}