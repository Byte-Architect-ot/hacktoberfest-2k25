#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};
ListNode* deleteMiddle(ListNode* head){
    if(!head||!head->next){
        delete head;
        return nullptr;
    }
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=nullptr;
    while(fast&&fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=slow->next;
    delete slow;
    return head;
}
int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(3);
    head->next->next=new ListNode(4);
    head->next->next->next=new ListNode(7);
    head->next->next->next->next=new ListNode(1);
    head->next->next->next->next->next=new ListNode(2);
    head->next->next->next->next->next->next=new ListNode(6);
    head=deleteMiddle(head);
    for(ListNode* p=head;p;p=p->next)
        cout<<p->val<<(p->next?"->":"\n");
    while(head){
        ListNode* nxt=head->next;
        delete head;
        head=nxt;
    }
    return 0;
}
