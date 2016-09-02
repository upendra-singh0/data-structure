#include <bits/stdc++.h>
using namespace std;



//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 //traversal bfs
//preorder <root> <left> <right>
void preorder(TreeNode* root)
{
    if(root == NULL) return;
    cout<<root->val<<" ";
    if(root->left != NULL ) preorder(root->left);
    if(root->right != NULL ) preorder(root->right);
}

//inorder <left> <root> <right>
void inorder(TreeNode* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

//postorder <left> <right> <root>
void postorder(TreeNode* root)
{
    if(root == NULL) return;
    if(root->left != NULL ) postorder(root->left);
    if(root->right != NULL ) postorder(root->right);
    cout<<root->val<<" ";
}

//level order traversal dfs queue
void levelorder(TreeNode* node)
{
    if(node == NULL) return;
    queue<TreeNode*> q ;
    q.push(node);
    while(q.size()>0)    
    {
        cout<<q.front()->val<<" ";
        if(q.front()->left != NULL) q.push(q.front()->left);
        if(q.front()->right != NULL) q.push(q.front()->right);
        q.pop();        
    }
}

//height root is at level 1 so if only root then height=level=1 
int height(TreeNode* root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else return max(height(root->left),height(root->right))+1;
}

//print all elements of a level
void print_level(TreeNode* root, int level)
{
    if(root==NULL || level <1) return; 
    if(level==1) 
    {
        cout<<root->val<<" ";
        return ;
    }
    else if (level > 1)
    {
        print_level(root->left,level-1);
        print_level(root->right,level-1);
    }
}
//print each level then break
void levelbylevel(TreeNode* node)
{
    if(node == NULL) return;
    queue<TreeNode*> q ;
    q.push(node);
    int count=0;
    while(1)    
    {
        count=q.size();
        if(count==0) break;
        
        while(count>0)
        {
            cout<<q.front()->val<<" ";
            if(q.front()->left != NULL) q.push(q.front()->left);
            if(q.front()->right != NULL) q.push(q.front()->right);
            q.pop();
            count--;
        }
    cout<<endl;
    }
}

void inorder_stack(TreeNode* root)
{
    if(root==NULL) return ;
    stack<TreeNode*> s;
    s.push(root);
    bool check=true;
    while(s.size()>0)
    {
        while(check && s.top()->left!=NULL )
        {
            s.push(s.top()->left);
        }
        
        check=false;
        cout<<s.top()->val<<" ";
        
        if(s.top()->right!=NULL)
        {
            check=true;
            TreeNode* temp=s.top();
            s.pop();
            s.push(temp->right);
        }
        else
        {
            s.pop();
        }
    }
}

int size(TreeNode* root)
{
    if(root==NULL) return 0;
    
    return(size(root->left)+1+size(root->right));
}

//------------------------------------------------------------------------------

//BST
//void insert(TreeNode* root,int val)
void insert(TreeNode* root,int val)
{
    /*if(*add_root==NULL) 
    {
        TreeNode* temp = new TreeNode(val);
        *add_root=temp;
    }*/
    
    if(root->val>=val)
    {
        if(root->left!=NULL) insert(root->left,val);
        else
        {
            TreeNode* temp = new TreeNode(val);
            root->left=temp;
        }
    }
    else
    {
        if(root->right!=NULL) insert(root->right,val);
        else
        {
            TreeNode* temp = new TreeNode(val);
            root->right=temp;
        }
    }
}

TreeNode* search(TreeNode* root, int val)
{
    if(root==NULL || root->val==val) return root;
    if(root->val>val) return search(root->left,val);
    else return search(root->right,val);
}

bool search_key(TreeNode* root, int val)
{
    if(root==NULL ) return false;
    if(root->val==val) return true;
    if(root->val>val) return search_key(root->left,val);
    else return search_key(root->right,val);
}



//or use inorder traversal and check waether sorted or not 
bool check_BST(TreeNode* root,int max, int min)
{
    if(root==NULL) return 1;
    if(root->val > max || root->val < min) return 0;
    return (check_BST(root->left,root->val-1,min) 
            && check_BST(root->right,max,root->val+1));
}

void deleteNode(TreeNode* root,int key)
{
    TreeNode* temp = search(root,key);
    if(temp == NULL) return ;
    if(temp->left==NULL && temp->right==NULL ) 
    {
        //delete temp ; previous of temp will point to same memory but nothing          //exist at that memory so default value 0 
        //temp=NULL; temp will point to null 
        //use of delete when new is used or for null pointer
        // free when malloc used or *ptr = &a  
        // write again correct code
    }
    else if(temp->left==NULL && temp->right!=NULL)
    {
        temp=temp->right;
    }
    else if(temp->left!=NULL && temp->right==NULL)
    {
        temp=temp->left;
    }
    else
    {
        TreeNode* node = temp->right;
        if(node->left==NULL && node->right==NULL)
        {
            temp->val=node->val;
            temp->right=NULL;
            //free(node);  
        }
        else if(node->left==NULL && temp->right!=NULL)
        {
            temp->val=node->val;
            temp->right=node->right;
            //free(node);
        }
        else if(node->left!=NULL && temp->right==NULL)
        {
            temp->val=node->left->val;
            node->left=NULL;
        }
        else
        {
            while(node->left->left!=NULL)
            {
                node=node->left;
            }
            temp->val=node->left->val;
            node->left=NULL;
        }
    }
}




int main(void){
   /*TreeNode* root = new TreeNode(1);
   TreeNode* left = new TreeNode(2);
   root->left=left;
   TreeNode* right = new TreeNode(3);
   root->right=right;
   TreeNode* left1 = new TreeNode(4);
   root->left->left=left1;
   TreeNode* right1 = new TreeNode(5);
   root->left->right=right1;
   TreeNode* left2 = new TreeNode(6);
   root->right->left=left2;
   TreeNode* right2 = new TreeNode(7);
   root->right->right=right2;
   
   preorder(root);cout<<endl;
   inorder(root);cout<<endl;
   postorder(root);cout<<endl;
   levelbylevel(root);cout<<endl;
   //cout<<height(root);cout<<endl;
   //print_level(root,1);cout<<endl;
   //print_level(root,2);cout<<endl;
   //print_level(root,3);cout<<endl;
   //levelbylevel(root);cout<<endl;
   inorder_stack(root);cout<<endl;
   cout<<size(root);cout<<endl;*/
    
//BST------------------------------------------------------------------------- 
    int max=100000,min=-100000;
    TreeNode* root1 = new TreeNode(4);
    //insert(&root,1);
    insert(root1,2);
    insert(root1,6);
    insert(root1,1);
    insert(root1,3);
    insert(root1,5);
    insert(root1,7);
    inorder(root1);cout<<endl;
    //levelbylevel(root1);//cout<<endl;
    //cout<<search_key(root1,4)<<endl;
    //cout<<search_key(root1,9)<<endl;
    //cout<<check_BST(root,max,min)<<endl;
    //cout<<search(root1,6)->val<<endl; 
    deleteNode(root1,2);
    inorder(root1);cout<<endl;
    /*insert(root1,1);
    deleteNode(root1,3);
    inorder(root1);cout<<endl;
    insert(root1,3);
    deleteNode(root1,2);
    inorder(root1);cout<<endl;
    insert(root1,2);
    */
    return 0;
}