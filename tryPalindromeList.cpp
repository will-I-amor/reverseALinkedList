 #include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
ListNode* reverseListNode(ListNode* head){
	ListNode* tmp;
	ListNode* prev = NULL;
	while(head!= NULL){
		tmp = head->next;
		head->next = prev;
		prev = head;
		head = tmp;
	}
	// if(head == NULL){
	// 	cout<<"head is NULL"<<endl;
	return prev;
}
ListNode* copyListNode(ListNode* head){
	if(head!=NULL){
		//cout<<"head isn't NULL"<<endl;
		ListNode* pOri = head->next;//让pOri等于头Node的下一个Node
		ListNode* pNew = new ListNode(head->val);//给pNew一个值，以防pForNew指的一直是个NULL
		ListNode* pforNew = pNew;
		while(pOri!=NULL){
			pNew->next = new ListNode(pOri->val);
			pforNew->next = pforNew->next; 
			//pforNew = pNew;
			pNew = pNew->next;
			pOri = pOri->next;
		}
		return pforNew;//此时pForNew是新copy的链表的头Node
	}
	else{
		cout<<"the linkedlist u wanna copy is a NULL list"<<endl;
		return NULL;
	}
}
void printALinkedList(ListNode* head){
	ListNode* p = head;
	while(p!=NULL){
		cout<<p->val<<"-> ";
		p = p->next;
	}
	cout<<endl;
}
bool comparePalindrome(ListNode* one, ListNode* two){
	ListNode* p = one;
	ListNode* q = two;
	bool flag = true;
	while(p!=NULL && flag == true){
		if(p->val == q->val){
			flag = true;
			p = p->next;
			q = q->next;
		}
		else{
			flag = false;
		}
	}
	return flag;
}
int main()
{
	//再写一个构造函数，把创建linked list封装起来
	//或者读一个vector,把那个vec读进linked List
	ListNode* listNormal = new ListNode(1);
	listNormal->next = new ListNode(2);
	listNormal->next->next = new ListNode(2);
	listNormal->next->next->next = new ListNode(1);
	ListNode* aNewList = copyListNode(listNormal);
	ListNode* reverseListNormal = reverseListNode(listNormal);
	//reverse之后，listNormal变了，print listNormal只打出10
	//但是copy的list,aNewList没变，是原先的listNormal
	// cout<<"The reversed List is :  ";
	// printALinkedList(reverseListNormal);
	// cout<<"The copied List is :  ";
	// printALinkedList(aNewList);
	bool flag = comparePalindrome(aNewList,reverseListNormal);
	cout<<"the list is palindrome is "<<flag<<endl;
	return 0; 

}



