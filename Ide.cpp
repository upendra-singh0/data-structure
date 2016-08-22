#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node* next;
};

// add_head address of head pointer, a pointer that points to a pointer that //points to head
void insert_front(node ** add_head, int value)
{
    node* temp = new node();
    temp->value=value;
    temp->next= (*add_head);
    (*add_head) = temp;
}

void insert_after(node* previous, int value){
    if(previous==NULL ) return ;
    
    node* temp = new node();
    temp->value=value;
    temp->next=previous->next;
    previous->next=temp;
    
}


void insert_end(node* head, int value)
{
    node* temp = new node();
    temp->value=value;
    temp->next=NULL;
    
    if(head==NULL) {
        head=temp;
        return ;
    }
    
    node* ptr; //new node() cannot be used as need only pointer not a complete      //node  
    ptr = head;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}

void delete_key(node** add_head, int key){
    if((*add_head)->value==key) {
        *add_head = (*add_head)->next;
        return ;
    }
    
    node* ptr = (*add_head);
    while(ptr->next!=NULL){
        if(ptr->next->value==key){
            if(ptr->next->next==NULL) ptr->next=NULL;
            else ptr->next=ptr->next->next; 
            return;
        }
        ptr=ptr->next;
    }
}

void delete_pos(node** add_head, int pos){
    if(pos==0){
        *add_head = (*add_head)->next;
        return ;
    }
    
    int count=1;
    node* ptr = (*add_head);
    while(ptr->next!=NULL){
        if(count==pos){
            if(ptr->next->next==NULL) ptr->next=NULL;
            else ptr->next=ptr->next->next;    
            return ;
        }
        ptr=ptr->next;
        count++;
    }
}

void print_list(node* head){
    if(head==NULL) return ;
    while(head!=NULL){
        cout<<" "<<head->value;
        head=head->next;
    }
}

int length(node* head){
    if(head==NULL) return 0;
    int count=0;
    while(head!= NULL){
        count++;
        head=head->next;
    }return count;
}

int length_rec(node*head){
    if(head==NULL) return 0;
    return 1+length_rec(head->next);
}

bool search(node* head, int k){
    if(head==NULL) return 0;
    while(head!= NULL){
        if(head->value==k) return 1;
        head=head->next;
    }return 0;
}

bool search_rec(node*head, int k){
    if(head==NULL) return 0;
    if(head->value==k) return 1;
    else return search_rec(head->next,k);
}

int getNode(node* head, int pos){
    int count=0;
    while(head!=NULL){
        if(count==pos){
            return head->value;
        }
        head=head->next;
        count++;
    }return -1;
}

int getIndex(node* head, int value){
    int index=0;
    if(head==NULL) return -1;
    while(head!= NULL){
        if(head->value==value) return index;
        index++;
        head=head->next;
    }
    return -1;
}

int middle(node* head){
    node* ptr = head;
    while(head->next!=NULL && head->next->next!=NULL){
        head= head->next->next;
        ptr=ptr->next;
    }
    return ptr->value;
}


void swap_node(node** add_head,int x,int y)
{
    if(x==y) return ;
    
    //search x 
    node* prev1 = NULL;
    node* ptr1 = *add_head;
    while(ptr1 != NULL)
    {
        //cout<<" 1 ";
        if(ptr1->value == x) break;
        prev1=ptr1;
        ptr1=ptr1->next;
    }
    
    if(NULL==ptr1) return ;
    //if prev1==NULL then ptr1 =head
    
    //search y 
    node* prev2 = NULL;
    node* ptr2 = *add_head;
    while(ptr2 != NULL)
    {
        //cout<<" 0 ";
        if(ptr2->value == y) break;
        prev2=ptr2;
        ptr2=ptr2->next;
    }
    
    if(NULL==ptr2) return ;
    //if prev2==NULL then ptr2 =head
    
    if(prev1!=NULL)
        prev1->next=ptr2;
    else *add_head = ptr2;
    
    if(prev2!=NULL)
        prev2->next=ptr1;
    else *add_head = ptr1;
    
    node * temp;
    temp=ptr1->next;
    ptr1->next=ptr2->next;
    ptr2->next=temp;
    
}

void reverse(node** add_head)
{
    if(add_head==NULL) return ;
    node* pre = *add_head;
    node* curr = (*add_head)->next;
    pre->next=NULL;
    
    while(curr!=NULL)
    {
        node* temp=curr;
        curr = curr->next;
        temp->next=pre;
        pre=temp;
    }
    *add_head=pre;
}

bool detect_loop(node* head){
    //two pointer approach 
    // another way attach bool with every node
    node* ptr=head; // , ptr2 =head wrong
    node* ptr2=head;
    while(ptr!=NULL && ptr->next!=NULL)  //ptr->next!=NULL &&ptr!=NULL wrong            //runtime error
    {
        ptr=ptr->next->next;
        ptr2=ptr2->next;
        if(ptr==ptr2) return true;
    }
    return false;
}
/*
node* merge(node** add_head1, node** add_head2){
    node* next1 = (*add_head1)->next;
    node* curr1 = (*add_head1);
    
    node* next2 = (*add_head2)->next;
    node* curr2 = (*add_head2);
    //bool temp=false;
    
    while(next1!=NULL && next2!=NULL  )
    {
        if(curr1->value <= curr2->value ){
            if(next2->value <= next1->value){
                curr1->next=curr2;
                curr1=next1;
                next1=next1->next;          
            }else {
                next1=next1->next;
                curr1=curr1->next;
            }
           
           
        }else{
            
            if(next1->value <= next2->value){
                curr1->next=curr2;
                curr1=next1;
                next1=next1->next;         
            }else {
                next2=next2->next;
                curr2=curr2->next;
            }
           
        }    
    }
    if((*add_head1)->value <= (*add_head2)->value)
    return *add_head1;
    else *add_head2;
}*/

node* merge_rec(node* first, node* second)
{
    node* result=NULL;
    if(first==NULL) return second;
    if(second==NULL) return first;
    
    if(first->value <= second->value){
        result=first;
        result->next=merge_rec(first->next,second);
    }
    else {
        result=second;
        result->next=merge_rec(first,second->next);
    }
    
    return result;
}

///palindrome

void reverse_rec(node *head){
    if(head==NULL)
    return;
    reverse_rec(head->next);
    cout<<head->value;
}

node* remove_duplicate(node* A){
    if(A==NULL) return A;
    if(A->next==NULL) return A;
    node* a= A;
    while(a->next!=NULL){
        if(a->value==a->next->value){
            node* temp=a->next;
            a->next=temp->next;
        }else{
            a=a->next;   
        }
    }
    return A;
}

node* swap_pairwise(node* A) { // returning pointer so without sending address //of head every thing workking fine
// if address of head is used then dont need to return pointer, void can be used 


    if(A==NULL) return NULL;
    if(A->next==NULL) return A;
    node* ptr = A;
    node* pre = NULL;
    bool change =false;
    while(ptr!=NULL && ptr->next!=NULL){
            node* next = ptr->next;
            node* curr = ptr;  
            ptr->next=next->next;
            next->next=ptr;
            if(ptr!=A) pre->next=next;
            else A=next; 
            pre=ptr;
            ptr=ptr->next;    
    }
    return A;
}








int main() {
    node* first = new node();
    node* second = new node();
	node* third = new node();
	node* forth = new node();
	first->value=1;
	first->next=second;
	second->value=2;
	second->next=third;
	third->value=4;
	third->next=NULL; //forth; for checking detect_loop()
	
	//function implementation section
	insert_front(&first,0);
	insert_after(second,3);
	insert_end(first,7);
	//print_list(first);
	//delete_key(&first,0);
	//delete_key(&first,30);
	//delete_pos(&first,2);
	print_list(first);
	cout<<endl;//0 1 2 3 4 5
	//cout<<" length "<<length_rec(first)<<endl;
	//cout<<" search 14 "<<search(first,14)<<endl;
	//cout<<" node index 2 "<<getNode(first,2)<<endl;
	//cout<<" node value 4 index "<<getIndex(first,4)<<endl;
	//cout<<" middle "<<middle(first)<<endl;
	//delete_pos(&first,2);
	//print_list(first);
	//cout<<endl; 
	//cout<<" middle "<<middle(first)<<endl;
// 	swap_node(&first,1,4);
// 	cout<<endl;
// 	print_list(first);
// 	cout<<endl; //0 1 2 3 4 5
	
	//forth->value=1;
	//forth->next=second;
	//cout<<detect_loop(first);
	node* one = first;
	//reverse(&first);
 	//print_list(one);cout<<endl; // value of first changed as its passed by              //reference 
    //print_list
    
    /*node* f = new node();
    node* s = new node();
	node* t = new node();
	node* u = new node();
	f->value=5;
	f->next=s;
	s->value=6;
	s->next=t;
	t->value=8;
	t->next=u;
	u->value=9;
	u->next=NULL;
	print_list(f); cout<<endl;
    print_list(merge_rec(first,f)); cout<<endl;*/
    //reverse_rec(first);
    first=swap_pairwise(first);
    print_list(first);
	return 0;
}

//Given only a pointer/reference to a node to be deleted in a singly linked list// how do you delete it?
    //struct node *temp  = node_ptr->next;
    //node_ptr->data  = temp->data;
    //node_ptr->next  = temp->next;














