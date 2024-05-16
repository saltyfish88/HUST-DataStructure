#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
    int value;
    int cnt;
    struct TreeNode*left;
    struct TreeNode*right;
}Node;
void insert(Node*T,int a);
void print(Node*T);
int findmax(Node*T);
void del(Node*T,int a);
int main()
{
    int i=0,n=0,m=0;
    n=10;
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    Node*T=(Node*)malloc(sizeof(Node));
    T->right=NULL;
    T->left=NULL;
    T->cnt=0;
    for(i=0;i<n;i++){insert(T,a[i]);}
    m=findmax(T);
    printf("%d\n",m);
    print(T);
    return 0;
}
void insert(Node*T,int a)
{
    Node*p=(Node*)malloc(sizeof(Node));
    p->right=NULL;
    p->left=NULL;
    p->cnt=1;
    p->value=a;
    if(T->cnt==0)
    {
        *T=*p;
        free(p);
        return;
    }
    else if(T->right==NULL&&T->left==NULL)
    {
        if(T->value>a)
        {
            T->left=p;
            return;
        }
        else if(T->value==a)
        {
            T->cnt++;
            free(p);
            return;
        }
        else if (T->value<a)
        {
            T->right=p;
            return;
        }
        
    }
    else if(T->right==NULL)
    {
        if (T->value<a)
        {
            T->right=p;
            return;
        }
        else if(T->value==a)
        {
            T->cnt++;
            free(p);
            return;
        }
        else if(T->value>a){insert(T->left,a);}
    }
    else if(T->left==NULL)
    {
        if (T->value>a)
        {
            T->left=p;
            return;
        }
        else if(T->value==a)
        {
            T->cnt++;
            free(p);
            return;
        }
        else if(T->value<a){insert(T->right,a);}
    }
    else
    {
        if(T->value==a)
        {
            T->cnt++;
            free(p);
            return;
        }
        else if(T->value>a){insert(T->left,a);}
        else if((T)->value<a){insert(T->right,a);}
    }
}
void print(Node*T)
{
    if(T==NULL||T->cnt==0){return;}
    print(T->left);
    printf("%d出现了%d次。\n",T->value,T->cnt);
    print(T->right);
}
int findmax(Node*T)
{
	Node*trans=T;
	while(trans->right!=NULL){trans=trans->right;}
	return trans->value;
}
void del(Node*T,int a)
{
	if(T->value==a)
	{
		if(T->cnt>1)
		{
			T->cnt--;
			return;
		}
		if(T->left==NULL&&T->right==NULL)
		{
			free(T);
			return;
		}
		else if(T->right==NULL||T->right==NULL)
		{
			if(T->right!=NULL)
			{
				Node*trans=T->right;
				while(trans->left!=NULL){trans=trans->left;}
				T->cnt=trans->cnt;
				T->value=trans->value;
				free(trans);
				return;
			}
			if(T->left!=NULL)
			{
				Node*trans=T->left;
				while(trans->right!=NULL){trans=trans->right;}
				T->cnt=trans->cnt;
				T->value=trans->value;
				free(trans);
				return;
			}
		}
		else
		{
			Node*trans=T->left;
			while(trans->right!=NULL){trans=trans->right;}
			T->cnt=trans->cnt;
			T->value=trans->value;
			free(trans);
			return;
		}
	}
	else if(T->value>a){del(T->left,a);}
	else if(T->value<a){del(T->right,a);}
}
