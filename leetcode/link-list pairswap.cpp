#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* swapPairs(ListNode* head) {
	ListNode* fixvirhead = new ListNode();
	ListNode* vir = fixhead;
	ListNode* cur = head;
	if(head->next==NULL)return head;
	while(cur || cur->next){
		vir->next = cur->next;
		cur->next = vir ->next->next;
		vir->next->next = cur;
		
		vir=cur;
		cur=cur->next;
	}        
	return fixhead->next;
}
//link-list重排，操控方向
//cur->next改變後面要注意，cur本身指的不變
