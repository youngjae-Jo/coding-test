#include <iostream>
#include <string>
using namespace std;

int ans, change;
string s;

void dfs(int index, int current) {
    if(current == change) {
        ans = max(ans, stoi(s));
        return;
    }

    for (int i = index; i < s.size() - 1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            swap(s[i], s[j]); // 두 문자의 위치 교환
            dfs(i, current + 1); // 위치 교환 횟수를 증가시켜 재귀 호출
            swap(s[i], s[j]); // 원래로 복원
        }
    }
}

int main(void) {
    int t;
    int bump=0;
    int i = 0, flag = 0, sz = 0;

    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> s >> change; 

        ans = 0;
        sz = s.size();
        if (change > sz){
            bump = change;
            change = sz - 1; // 위치 교환 횟수가 문자열 길이를 초과하지 않도록 제한
        }
        dfs(0, 0);
        
        if((bump - change)%2 == 1){
            for(int i = 0; i < sz - 1; i++){
                for(int j = i+1; j< sz; j++){
                    if(s[i] == s[j])
                    flag = 1;
                }
            }
            if(!flag){
            	string str = to_string(ans);
        		swap(str[sz - 1], str[sz - 2]);
            	ans = stoi(str);
            }
        }
            
        cout << "#" << i << " " << ans << endl;
        flag = 0, bump = 0;
    }
    return 0;
}
