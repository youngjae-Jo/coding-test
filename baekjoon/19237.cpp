#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define MAX 25

using namespace std;

struct SHARK {
    int x;
    int y;
    int Dir;
    bool Live;
    vector<int> Priority[5];
};

struct MAP_INFO {
    vector<int> V;
    int Smell_Time;
    int Smell_Host;
};

int N, M, K;
MAP_INFO MAP[MAX][MAX];
SHARK Shark[410];
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };

void Input() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if (a != 0) {
                MAP[i][j].V.push_back(a);
                Shark[a].x = i;
                Shark[a].y = j;
            }
            MAP[i][j].Smell_Time = 0;
            MAP[i][j].Smell_Host = 0;
        }
    }
    for (int i = 1; i <= M; i++) {
        int Dir;
        cin >> Dir;
        Shark[i].Dir = Dir;
        Shark[i].Live = true;
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 4; j++) {
            int Arr[4];
            cin >> Arr[0] >> Arr[1] >> Arr[2] >> Arr[3];
            for (int k = 0; k < 4; k++) {
                Shark[i].Priority[j].push_back(Arr[k]);
            }
        }
    }
}

bool Check() {
    for (int i = 2; i <= M; i++) {
        if (Shark[i].Live == true)
            return false;
    }
    return true;
}

void Setting_Smell(int Time) {
    for (int i = 1; i <= M; i++) {
        if (Shark[i].Live == false)
            continue;
        int x = Shark[i].x;
        int y = Shark[i].y;
        MAP[x][y].Smell_Time = Time + K;
        MAP[x][y].Smell_Host = i;
    }
}

void Move_Shark(int Time) {
    for (int i = 1; i <= M; i++) {
        if (Shark[i].Live == false)
            continue;
        int x = Shark[i].x;
        int y = Shark[i].y;
        MAP[x][y].V.clear();
    }
    for (int i = 1; i <= M; i++) {
        if (Shark[i].Live == false)
            continue;
        int x = Shark[i].x;
        int y = Shark[i].y;
        int Dir = Shark[i].Dir;
        int Self_x, Self_y, Self_Dir;
        Self_x = Self_y = Self_Dir = -1;
        bool Flag = false;
        for (int j = 0; j < Shark[i].Priority[Dir].size(); j++) {
            int nDir = Shark[i].Priority[Dir][j];
            int nx = x + dx[nDir];
            int ny = y + dy[nDir];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (MAP[nx][ny].Smell_Time <= Time) {
                    Flag = true;
                    MAP[nx][ny].V.push_back(i);
                    Shark[i].x = nx;
                    Shark[i].y = ny;
                    Shark[i].Dir = nDir;
                    break;
                }
                else {
                    if (MAP[nx][ny].Smell_Host == i) {
                        if (Self_x == -1) {
                            Self_x = nx;
                            Self_y = ny;
                            Self_Dir = nDir;
                        }
                    }
                }
            }
        }
        if (Flag == false) {
            MAP[Self_x][Self_y].V.push_back(i);
            Shark[i].x = Self_x;
            Shark[i].y = Self_y;
            Shark[i].Dir = Self_Dir;
        }
    }
}

void Killing_Shark() {
    for (int i = 1; i <= M; i++) {
        if (Shark[i].Live == false)
            continue;
        int x = Shark[i].x;
        int y = Shark[i].y;
        if (MAP[x][y].V.size() >= 2) {
            sort(MAP[x][y].V.begin(), MAP[x][y].V.end());
            int Live_Num = MAP[x][y].V[0];
            for (int j = 1; j < MAP[x][y].V.size(); j++) {
                int Shark_Num = MAP[x][y].V[j];
                Shark[Shark_Num].Live = false;
            }
            MAP[x][y].V.clear();
            MAP[x][y].V.push_back(Live_Num);
            MAP[x][y].Smell_Host = Live_Num;
        }
    }
}

void Solution() {
    for (int Time = 0; Time < 1001; Time++) {
        if (Check() == true) {
            cout << Time << endl;
            return;
        }
        Setting_Smell(Time);
        Move_Shark(Time);
        Killing_Shark();
    }
    cout << -1 << endl;
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("Input.txt", "r", stdin);
    Solve();
    return 0;
}
