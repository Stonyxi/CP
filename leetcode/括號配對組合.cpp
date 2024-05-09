#include <bits/stdc++.h>
using namespace std;

vector<string> result;

vector<int> dfs(int left, int right, int n, string current) {
    if (left == n && right == n) {
        result.push_back(current);
        return result;
    }

    if (left < n) {
        dfs(left + 1, right, n, current + "(");
    }

    if (right < left) {
        dfs(left, right + 1, n, current + ")");
    }
}

vector<string> generateParenthesis(int n) {
    result.clear(); // Clear the result vector before generating new combinations
    dfs(0, 0, n, "");	        
    return result;
}

int main() {
    int n = 2;
    vector<string> combinations = generateParenthesis(n);
    for (const string& s : combinations) {
        cout << s << endl;
    }
    return 0;
}
