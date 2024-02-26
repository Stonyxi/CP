#include<iostream>
using namespace std;
 
int dx[4] = {-1, 0, 1, 0}; // 上下左右四個方向
int dy[4] = {0, 1, 0, -1};
int p[48]; // 指令序列
bool onpath[9][9]; // 路徑標記
 
int dfs(int n, int x, int y) {
    // 檢查路徑是否合法
    if((onpath[x][y-1] && onpath[x][y+1]) && (!onpath[x-1][y] && !onpath[x+1][y]))
        return false;
    if((onpath[x-1][y] && onpath[x+1][y]) && (!onpath[x][y-1] && !onpath[x][y+1]))
        return false;
    
    // 判斷是否抵達終點
    if(x == 7 && y == 1) {
        if(n == 48) return true;
        return false;
    }
    
    // 遍歷完所有指令，但未抵達終點
    if(n == 48) return false;
    
    int re = 0;
    onpath[x][y] = true;
    
    // 根據當前指令移動
    if(p[n] < 4) { 
        int nextx = x + dx[p[n]];
        int nexty = y + dy[p[n]];
        if(onpath[nextx][nexty]==0) {
            re += dfs(n + 1, nextx, nexty);
        }
    } else { // '?'部分
        for(int i = 0; i < 4; i++) { // 嘗試所有方向
            int nextx = x + dx[i];
            int nexty = y + dy[i];
            if(onpath[nextx][nexty]==0) {
                re += dfs(n + 1, nextx, nexty);
            }
        }
    }
    
    onpath[x][y] = false; // 回溯
    return re;
}
 
int main() {
    string s;
    cin >> s;
 
    for(int i = 0; i < 48; i++) {
        char cur = s[i];
        if(cur == 'U') p[i] = 0;
        else if(cur == 'R') p[i] = 1;
        else if(cur == 'D') p[i] = 2;
        else if(cur == 'L') p[i] = 3;
        else p[i] = 4; // '?'
    }
 
    // 初始化迷宮邊界和路徑標記
    for(int i = 0; i < 9; i++) {
        onpath[0][i] = true;
        onpath[8][i] = true;
        onpath[i][0] = true;
        onpath[i][8] = true;
    }
    
    for(int i = 1; i <= 7; i++) {
        for(int j = 1; j <= 7; j++) {
            onpath[i][j] = false;
        }
    }
    int ans = dfs(0, 1, 1); // 從起點開始遞歸尋找解
    cout << ans << endl; // 輸出結果
 
    return 0;
}
