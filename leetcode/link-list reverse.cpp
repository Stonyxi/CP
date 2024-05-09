#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
prev 则应该用于记录反转后链表的结构
first 应该保持在原始链表的遍历过程中
second 应该继续指向当前节点 first 的下一个节点
*/

ListNode* reverse(ListNode* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	ListNode* prev=NULL;//moving的前1
	ListNode* first=head;//moving
	ListNode* second=head->next;
	while(true){
		first -> next = prev;//divert direction
		prev = first;
		first = second;
		if(first == NULL){
			second = first->next;
		}
	}
	return prev;
}

ListNode* doubleIt(ListNode* head){
    ListNode *headd = reverse(head);
    ListNode* prev = new ListNode();
    ListNode* fixprev = prev;
    int carry = 0;
    while(carry || headd != NULL){
    	int sum=0;
    	if(headd){
    		sum = headd ->val*2;
    		headd = headd->next;
    	}
    	sum += carry;   //注意這兩行順序會倒過來
    	carry = sum/10;
    	ListNode* newnode = new ListNode(sum%10);//宣告完心結點記得串起來
    	prev -> next = newnode; 
    	prev = prev->next;
    }
    ListNode* headdd = reverse(fixprev->next);
    return headdd;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
   
}
