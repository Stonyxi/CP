#include <bits/stdc++.h>
using namespace std;

char grip[1000][1000];

string convert(string s, int numRows) {
    int len = s.size(), x = 0;
    vector<vector<char>> grip(numRows, vector<char>(len, ' ')); // 初始化 2D 向量，使用空格填充
    int column = 0, row = numRows;
    
	if(numRows == 1) {
	     return s;
	}
	
    while (x < len) {
        if( column==0 || column % (row - 1) == 0) {
            for (int i = 0; i < row && x < len; i++){
                grip[i][column] = s[x++];
            }
            column++;
        } 
        else{
            int up = row - 2;
            while (x < len && up >= 1) {
                grip[up--][column++] = s[x++];
            }
        }
    }
    string re;
    for(auto i : grip) {
	    for(auto j : i) {
	     	if(j == ' ')continue;
	     	re += j;   
	    }
		
	}
    return re;
}

int main(){
	cout << convert("PAYPALISHIRING",3);
	
}
