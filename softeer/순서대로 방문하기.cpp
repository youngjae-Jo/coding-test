#include<iostream>


using namespace std;

int n, m;
int ans = 0;
int maap[5][5]; //0�̸� ��ĭ, 1�̸� ��
struct pos {
    int x;
    int y;
};
pos locate[16];
int dx[4] = { -1, 1, 0, 0 }; //�����¿�
int dy[4] = { 0, 0, -1, 1 };
bool visited[5][5];

bool is_possible(int X, int Y, int R) {//�ʾȿ� �ְ� ���� �ƴϰ� �湮���� �ʾҴ� ��, �ٸ� �������� �ƴ� ��
    bool result = true;

    for (int i = 0; i < m; i++) {
        if (i != R && locate[i].x == X && locate[i].y == Y) {
            return false;
        }
    }
    result = (X >= 1 && X <= n && Y >= 1 && Y <= n && maap[X][Y] == 0);

    return result;
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            visited[i][j] = false;
    }
    visited[locate[0].x][locate[0].y] = true;
}

void solve(int curr_x, int curr_y, int reached, int visit[][17]) {
    //cout<<"curr_x = "<<curr_x<<", curr_y = "<<curr_y<<", reached = "<<reached<<endl;
    //visited[curr_x][curr_y] = true; //�湮
    visit[curr_x][curr_y] = 1;
    if (curr_x == locate[reached + 1].x && curr_y == locate[reached + 1].y)
        reached++;
    if (reached == m - 1) {//curr_x == locate[m-1].x && curr_y == locate[m-1].y && reached == m-1){
        ans++;
        visit[curr_x][curr_y] = 0;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = curr_x + dx[i];
        int ny = curr_y + dy[i];
        int tr = reached + 1;
        if (is_possible(nx, ny, tr)) {//���� �������� �� �� ����
            if (visit[nx][ny] == 0) { //�湮���� �ʾ��� ���
                //Ȯ�ο�
                /*if(nx == 1 && ny == 3){
                    cout<<endl<<"let's see"<<endl;
                    for(int i = 1; i<=n; i++){
                        for(int j = 1; j<=n; j++)
                            cout << visit[i][j] <<" ";
                        cout<<endl;
                    }
                    cout<<endl;
                }*/

                solve(nx, ny, reached, visit);
            }
        }

    }
    visit[curr_x][curr_y] = 0;
    //visited[curr_x][curr_y] = false; //�� �� �� ���� ��� -> �Ű������� ���� �� �湮 ��ü�� ���ó�� �Ǳ� ������ �Լ� ó�� ������ false�� ���¿��� �ٽ� ����
}

int main(int argc, char** argv)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> maap[i][j];
    }
    for (int i = 0; i < m; i++)
        cin >> locate[i].x >> locate[i].y;
    init();

    int v[17][17];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            v[i][j] = 0;
    }
    solve(locate[0].x, locate[0].y, 0, v);
    cout << ans;

    return 0;
}