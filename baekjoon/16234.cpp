#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, L, R;

struct country{
    int border[4] = {0,}; //동서남북
    int population = 0;
    int visited = 0;
};

struct country A[51][101];
//동서남북
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 ,0};

struct pos{
    int x;
    int y;
};

vector<pos> ally;

int open(){ //전체에 대해서 국경 열기
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){

            for(int way = 0; way <4; way++){
                if(i+dx[way] >= 1 && i+dx[way] <= N && j+dy[way] >= 1 && j+dy[way] <= N){ //맵 내에 있으면 국경 열지 판단
                    if(abs(A[i][j].population - A[i+dx[way]][j+dy[way]].population) >= L && abs(A[i][j].population - A[i+dx[way]][j+dy[way]].population) <= R){
                        A[i][j].border[way] = 1;
                        cnt++;
                    }
                }
            }

        }
    }

    return cnt;
}

void close(){ //연합 이동 후 국경 닫기
    for(int idx = 0; idx < ally.size(); idx++){
        for(int way = 0; way <4; way++){
            if(ally[idx].x+dx[way] >= 1 && ally[idx].x+dx[way] <= N && ally[idx].y+dy[way] >= 1 && ally[idx].y+dy[way] <= N)//닫기
                A[ally[idx].x][ally[idx].y].border[way] = 0;    
        }
    }
}

void search(int i, int j){ //dfs, 연합이 어디까지인지 판별, 하는 과정에서 연합인 애들 기록
    
    for(int way = 0; way <4; way++){
        if(i+dx[way] >= 1 && i+dx[way] <= N && j+dy[way] >= 1 && j+dy[way] <= N){ //맵 내에
            if(A[i][j].border[way] == 1 && A[i+dx[way]][j+dy[way]].visited == 0){ //국경 열려있고 갈 수 있는 곳
                A[i][j].visited = 1; //제일 처음 때문(이미 1일 수 있긴함)
                A[i+dx[way]][j+dy[way]].visited = 1; //갔더니 갈 곳 없을 수 있으니까 미리
                struct pos temp;
                temp.x = i+dx[way];
                temp.y = j+dy[way];
                ally.push_back(temp);
                search(i+dx[way], j+dy[way]);
            }
        }
    }

}
    

int move(){
    int day = 0;
    int sum = 0;
    while(open() != 0){
        day++;
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                search(i, j); //연합 찾기
                if(ally.size() != 0){ //갈 곳들만 연합에 넣어서 시작 지점도 넣어줘야함
                    struct pos temp;
                    temp.x = i;
                    temp.y = j;
                    ally.push_back(temp);        
                }
                for(int idx = 0; idx < ally.size(); idx++)
                    sum+=A[ally[idx].x][ally[idx].y].population;
                if(ally.size()!=0)
                    sum/=ally.size();
                for(int idx = 0; idx < ally.size(); idx++) // 인구 수 같게
                    A[ally[idx].x][ally[idx].y].population = sum;
                sum = 0;
                close(); //해당 연합쪽 국경 닫아서 탐색 시간 줄이기
                ally.clear(); //다음 탐색을 위해서
            }
        }
        for(int i = 1; i<=N; i++){ //다음 탐색을 위해서
            for(int j = 1; j<=N; j++)
                A[i][j].visited = 0;
        }
    }
    return day;
}


int main(){

    cin >> N >> L >> R;
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            cin>>A[i][j].population;
        }
    }
    cout<<move();
    return 0;
}