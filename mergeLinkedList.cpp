#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* merge(ListNode* h1,ListNode* h2){
    ListNode* temp=NULL;
    ListNode* head=NULL;
    while(h1 and h2){
      ListNode* curr=new ListNode;
      if(h1->val<=h2->val){
        curr->val=h1->val;
        h1=h1->next;
      }else{
        curr->val=h2->val;
        h2=h2->next;
      }
      if(head==NULL)head=curr;
      if(temp){//always assign sth->next as it is this time when we are accessing the right place
        temp->next=curr;
        temp=temp->next;
      }else{
        temp=curr;
      }
    }
    while(h1){
      ListNode* curr=new ListNode;
      curr->val=h1->val;
      h1=h1->next; 
      if(head==NULL)head=curr;
      if(temp){
        temp->next=curr;
        temp=temp->next;
      }else{
        temp=curr;
      } 
    }
    while(h2){
      ListNode* curr=new ListNode;
      curr->val=h2->val;
      h2=h2->next; 
      if(head==NULL)head=curr;
      if(temp){
        temp->next=curr;
        temp=temp->next;
      }else{
        temp=curr;
      } 
    }
    
    return head;
}

ListNode* mergesort(ListNode* head) {
   if(head==NULL)return NULL;
   if(head->next==NULL)return head;
   ListNode* slow=head;
   ListNode* fast=head;
   ListNode* prev=NULL;
   while(fast){
    fast=fast->next;
    if(fast){
        prev=slow;
        slow=slow->next;
        fast=fast->next;
    }
   }
   if(prev)prev->next=NULL;
   head=mergesort(head);
   slow=mergesort(slow);
   return merge(head,slow);
}

ListNode* GetList(vector<int> &num) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < (int)num.size(); i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }
    
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    ListNode* head = GetList(num);

    head = mergesort(head);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
    
    return 0;
}
