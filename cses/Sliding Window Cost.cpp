#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
 
long N, M;
long arr[200010];
multiset<long> up;
multiset<long> low;
 
void in(long val) {         
	long a = *low.rbegin();  
	if (a < val) {
		up.insert(val);
		if (up.size() > M / 2) {
			low.insert(*up.begin());
			up.erase(up.find(*up.begin()));
		}
	}else {
		low.insert(val);
		if (low.size() > (M + 1) / 2) {
			up.insert(*low.rbegin());
			low.erase(low.find(*low.rbegin()));
		}
	}
}
 
void out(long val) {  
    // 查找 val 在 up 集合中的迭代器
    if (up.find(val) != up.end()) 
        up.erase(up.find(val));  // 如果 val 存在于 up 集合中，则删除它
    else 
        low.erase(low.find(val));  // 否则，删除 val 在 low 集合中的迭代器 都沒有則不執行
 
    // 检查 low 集合是否为空
    if (low.empty()) {
        // 如果 low 集合为空，则将 up 集合中的最小值插入到 low 集合中
        low.insert(*up.begin());
        // 然后再从 up 集合中删除该最小值
        up.erase(up.find(*up.begin()));
    }
}
 
 
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	low.insert(arr[0]);
	for (int i = 1; i < M; i++) in(arr[i]);
	cout << *low.rbegin() << " ";
 
	for (long i = M; i < N; i++) {
		if (M == 1) {
			in(arr[i]);
			out(arr[i - M]);
		} else {
			out(arr[i - M]); //開始滑動窗口 
			in(arr[i]);
		}
		cout << *low.rbegin() << " ";
	}
	cout << endl;
