#include "tree.h"
#include "stack.h"
using namespace std;

/**********************************************
*�������ƣ�InitTree
*�������ܣ��������г�ʼ��
*�����������CTree T
*����ֵ������ִ��״̬��ִ�гɹ�����OK��
**********************************************/
Status InitTree(CTree & T)
{
	T.n = 0; T.r = -1;		//������λ����Ϊ-1��˵����ǰ��û�и�
	return OK;
}

/**********************************************
*�������ƣ�InsertChild
*�������ܣ�ΪT��ĳ��������һ������
*�����������CTree T��int pָ��ĳ����㣬int i
��ʾ��i��������CTree c��Ҫ���������
*����ֵ������ִ��״̬��ִ�гɹ�����OK�����򷵻�
ERROR
**********************************************/
Status InsertChild(CTree & T, int p, int i, CTree c)
{
	if (p < 0 || p >= T.n) return ERROR;			//p��ָ��T��ĳ�����
	if (!c.n) return ERROR;							//Ҫ����������ǿ���
	int k = 0, j = T.n;
	ChildPtr prior = T.nodes[p].firstchild;			//�������ҵ�i������ǰһ�����
	ChildPtr cur = prior;							//�������ҵ�i�����
	ChildPtr t;
	while (k < c.n)
	{
		T.nodes[j] = c.nodes[k++];
		for (t = T.nodes[j].firstchild; t; t = t->next)
			t->child += T.n;
		j++;
	}
	t = (ChildPtr)malloc(sizeof(CTNode));
	if (!t) exit(OVERFLOW);
	t->child = T.n + c.r;							//��������λ��
	t->next = NULL;
	T.n += c.n;
	if (i == 1)
	{
		if (prior)
		{
			t->next = prior;
			prior = t;
		}
		else prior = t;
		T.nodes[p].firstchild = prior;
	}
	else if (i < 1) return ERROR;					//���i����Ƿ�������ERROR
	else
	{
		k = 1;											//k��ʾ��ǰ�ǵڼ�������
		while (k < i&&cur)
		{
			k++;
			prior = cur;
			cur = cur->next;
		}
		if (cur)
		{
			prior->next = t;
			t->next = cur;
		}
		else if (k == i)
		{
			prior->next = t;
			t->next = NULL;
		}
		else return ERROR;
	}
	return OK;
}

Status GetParent(CTree T, int child, int & parent)
{
	ChildPtr t; int i = 0;
	if (child >= T.n) return ERROR;
	for (; i < T.n; i++)
	{
		t = T.nodes[i].firstchild;
		while (t&&t->child != child)
			t = t->next;
		if (t&&t->child == child)
		{
			parent = i;
			return OK;
		}
	}
	return INFEASIBLE;
}

/****************************************************
*�������ƣ�TraverseTree
*�������ܣ�����T�����ȸ�����
*�����������CTree T���Խ�������Ӧ�ú���visit()
*����ֵ������ִ��״̬��
*****************************************************/
Status TraverseTree(CTree T, Status(*visit)(TElemType, int))
{
	stack<int> stack;
	int status = 0;							//������־�Ƿ����к��Ӷ������ʹ�
	int i; int j;
	int indent = 0;							//������
	int parent;
	ChildPtr t;
	int visited[MAX_TREE_SIZE] = { 0 };		//���ʱ�־�����ʼ��
	if (!T.n) return OK;					//��Ϊ��ֱ�ӽ���
	for (i = 0; i < T.n; i++)
	{
		indent = 0;
		if (!visited[i])					//����δ���ʵĽ����з���
		{
			stack.push(i);
			visited[i] = 1;
			if (GetParent(T, i, parent) == OK)
				indent += T.nodes[parent].indent;
			if (T.nodes[i].indent)
				visit(T.nodes[i].data, indent);
			t = T.nodes[i].firstchild;
			while (t && !status)									//����ý���к���
			{
				while (visited[t->child] && t->next)	//Ѱ��δ�����ʹ��ĺ���
					t = t->next;
				if (!visited[t->child])
				{
					visited[t->child] = 1;
					if(T.nodes[t->child].firstchild)
						stack.push(t->child);
					GetParent(T, t->child, parent);
					indent += T.nodes[parent].indent;
					if (T.nodes[t->child].indent)
						visit(T.nodes[t->child].data, indent);
					t = T.nodes[t->child].firstchild;
					status = 0;
				}
				else status = 1;
			}
		}
		while (!stack.empty())						//ѭ����ջΪ��
		{
			j = stack.top();
			indent -= T.nodes[j].indent;
			t = T.nodes[j].firstchild;
			status = 0;
			while (t && !status)							//����ý���к���
			{
				while (visited[t->child] && t->next)	//Ѱ��δ�����ʹ��ĺ���
					t = t->next;
				if (!visited[t->child])
				{
					visited[t->child] = 1;
					if(T.nodes[t->child].firstchild)
						stack.push(t->child);
					GetParent(T, t->child, parent);
					indent += T.nodes[parent].indent;
					if (T.nodes[t->child].indent)
						visit(T.nodes[t->child].data, indent);
					t = T.nodes[t->child].firstchild;
					status = 0;
				}
				else status = 1;
			}
			if (t) stack.pop();
		}
	}
	return OK;
}