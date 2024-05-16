#include"parser.h"
#include"stack.h"
#include"queue.h"
#include"tree.h"

int w;
char kind[MAXLEN];
char tokenText0[MAXLEN];
int indent0 = 0;
queue<print> printList;

/***********************************************************
*�������ƣ�program
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ����
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status program(FILE * fp, CTree &T)
{
	CTree c;
	print elem = { indent0,num };
	printList.push(elem);
	w = gettoken(fp);
	if (!ExtDefList(fp, c)) return ERROR;
	T.n = 1; T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("����") + 1) * sizeof(char));		//����һ�������Ϊ�����ĸ�
	strcpy(T.nodes[0].data, "����");		//����һ�������Ϊ�����ĸ�
	T.nodes[0].indent = 0;
	T.nodes[0].firstchild = NULL;
	InsertChild(T, T.r, 1, c);
	return OK;
}

/***********************************************************
*�������ƣ�ExtDefList
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ�ⲿ��������
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status ExtDefList(FILE * fp, CTree &T)
{
	CTree c; Status p;
	if (w == EOF) return INFEASIBLE;
	T.n = 1;  T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("�ⲿ��������") + 1) * sizeof(char));
	strcpy(T.nodes[0].data, "�ⲿ��������");
	T.nodes[0].indent = 0;
	T.nodes[0].firstchild = NULL;
	if (!ExtDef(fp, c)) return ERROR;
	InsertChild(T, T.r, 1, c);
	p = ExtDefList(fp, c);
	if (p == OK) InsertChild(T, T.r, 2, c);
	if (!p) return ERROR;
	return OK;
}

/***********************************************************
*�������ƣ�ExtDef
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ�ⲿ����
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status ExtDef(FILE * fp, CTree &T)
{	
	Status p;
	if (w != INT && w != LONG && w != SHORT && w != SIGNED && w != UNSIGNED &&
		w != FLOAT && w != DOUBLE && w != CHAR) return ERROR;
	strcpy(kind, token_text);			//��������˵����
	w = gettoken(fp);
	if (w != IDENT) return ERROR;
	strcpy(tokenText0, token_text);		//�����һ����������������tokenText0
	w = gettoken(fp);
	if (w != LP) p = ExtVarDef(fp, T);	//�����ⲿ���������ӳ���
	else p = funcDef(fp, T);			//���ú��������ӳ���
	if (!p) return ERROR;
	return OK;
}

/***********************************************************
*�������ƣ�ExtVarDef
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ�ⲿ��������
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status ExtVarDef(FILE * fp, CTree & T)
{
	CTree c; CTree p;
	T.n = 1; T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("�ⲿ�������壺")+1)*sizeof(char));
	strcpy(T.nodes[0].data, "�ⲿ�������壺");
	T.nodes[0].indent = 1;
	T.nodes[0].firstchild = NULL;						//�����ⲿ����������
	c.n = 1; c.r = 0;
	c.nodes[0].data = (char *)malloc((strlen(kind)+strlen("���ͣ�") + 1) * sizeof(char));
	strcpy(c.nodes[0].data, "���ͣ�");
	strcat(c.nodes[0].data, kind);
	c.nodes[0].indent = 1;
	c.nodes[0].firstchild = NULL;						//�����ⲿ�������ͽ��
	if (!InsertChild(T, T.r, 1, c)) return ERROR;		//c��Ϊroot�ĵ�һ������
	if (!ExtVarList(fp, p)) return ERROR;
	if (!InsertChild(T, T.r, 2, p)) return ERROR;		//p��Ϊroot�ĵڶ�������
	return OK;
}

/***********************************************************
*�������ƣ�ExtVarList
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ�ⲿ��������
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status ExtVarList(FILE * fp, CTree & T)
{//��ʼʱ��tokenText0�����˵�һ��������
	CTree c; CTree t;
	T.n = 1; T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("�ⲿ��������") + 1) * sizeof(char));
	strcpy(T.nodes[0].data, "�ⲿ��������");
	T.nodes[0].indent = 0;
	T.nodes[0].firstchild = NULL;				//�����ⲿ�������н��
	if (w == LBT)
	{
		strcat(tokenText0, "[");
		if ((w = gettoken(fp)) == INT_CONST)
		{
			strcat(tokenText0, token_text);
			if ((w = gettoken(fp)) == RBT)
			{
				strcat(tokenText0, "]");
				c.n = 1; c.r = 0;
				c.nodes[0].data = (char *)malloc((strlen(tokenText0) + strlen("Array: ") + 1) * sizeof(char));
				strcpy(c.nodes[0].data, "Array: ");
				strcat(c.nodes[0].data, tokenText0);
				c.nodes[0].indent = 1;
				c.nodes[0].firstchild = NULL;
				w = gettoken(fp);
			}
			else return ERROR;
		}
		else return ERROR;
	}
	else
	{
		c.n = 1; c.r = 0;
		c.nodes[0].data = (char *)malloc((strlen(tokenText0) + strlen("ID: ") + 1) * sizeof(char));
		strcpy(c.nodes[0].data, "ID: ");
		strcat(c.nodes[0].data, tokenText0);
		c.nodes[0].indent = 1;
		c.nodes[0].firstchild = NULL;
	}
	if (!InsertChild(T, T.r, 1, c))	return ERROR;//tokenText0��Ϊroot�ĵ�һ������
	if (w != COMMA && w != SEMI) return ERROR;
	if (w == SEMI)								//�����ʶ�����Ƿֺţ�ֱ�ӽ���
	{
		w = gettoken(fp);
		return OK;
	}
	w = gettoken(fp);
	if (w != IDENT) return ERROR;
	//�������Ӧ�����Ǳ�ʶ��
	strcpy(tokenText0, token_text);
	w = gettoken(fp);
	if (!ExtVarList(fp, t)) return ERROR;
	if(!InsertChild(T,T.r,2,t)) return ERROR;
	return OK;
}

/***********************************************************
*�������ƣ�funcDef
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ��������
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status funcDef(FILE * fp, CTree & T)
{
	CTree c; CTree p; CTree q; CTree f; CTree s;
	T.n = 1; T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("�������壺") + 1) * sizeof(char));
	strcpy(T.nodes[0].data, "�������壺");
	T.nodes[0].indent = 1;
	T.nodes[0].firstchild = NULL;		//���ɺ���������root
	c.n = 1; c.r = 0;
	c.nodes[0].data = (char *)malloc((strlen(kind) + strlen("���ͣ�") + 1) * sizeof(char));
	strcpy(c.nodes[0].data, "���ͣ�");
	strcat(c.nodes[0].data, kind);
	c.nodes[0].indent = 1;
	c.nodes[0].firstchild = NULL;		//���ɷ���ֵ���ͽ��
	if (!InsertChild(T, T.r, 1, c)) return ERROR;
	w = gettoken(fp);
	//���������ڿ����޲�����������void�������ǲ�������
	//�����������
	if (w != RP && w != VOID && w != INT && w != LONG && w != SHORT &&
		w != SIGNED && w != UNSIGNED && w != FLOAT && w != DOUBLE && w != CHAR)
		return ERROR;
	p.n = 1; p.r = 0;
	p.nodes[0].data = (char *)malloc((strlen(tokenText0) + strlen("��������") + 1) * sizeof(char));
	strcpy(p.nodes[0].data, "��������");
	strcat(p.nodes[0].data, tokenText0);
	p.nodes[0].indent = 1;
	p.nodes[0].firstchild = NULL;		//���ɺ��������
	if (w == RP||w==VOID)
	{
		if (w == VOID)
		{
			w = gettoken(fp);
			if (w != RP) return ERROR;
		}
	}
	else
	{
		if (!ParameterList(fp, q)) return ERROR;
		if (!InsertChild(p, p.r, 1, q)) return ERROR;
	}
	if (!InsertChild(T, T.r, 2, p)) return ERROR;
	w = gettoken(fp);
	if (w != SEMI && w != LBS) return ERROR;
	f.n = 1; f.r = 0;
	f.nodes[0].data = (char *)malloc((strlen("�����壺") + 1) * sizeof(char));
	strcpy(f.nodes[0].data, "�����壺");
	f.nodes[0].indent = 1;
	f.nodes[0].firstchild = NULL;		//���ɺ�������
	if (w == LBS)
		if (!CompStat(fp, s)) return ERROR;
	if (!InsertChild(f, f.r, 1, s)) return ERROR;
	InsertChild(T, T.r, 3, f);
	return OK;
}

/***********************************************************
*�������ƣ�ParameterList
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ��������
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status ParameterList(FILE * fp, CTree & T)
{
	CTree c;
	T.n = 1; T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("�β�����") + 1) * sizeof(char));
	strcpy(T.nodes[0].data, "�β�����");
	T.nodes[0].indent = 0;
	T.nodes[0].firstchild = NULL;				//�����β����н��
	if (!FormParDef(fp, c)) return ERROR;
	if (!InsertChild(T, T.r, 1, c)) return ERROR;
	w = gettoken(fp);
	if (w != RP && w != COMMA) return ERROR;
	if (w == COMMA)
	{
		w = gettoken(fp);
		if (!ParameterList(fp, c)) return ERROR;
		InsertChild(T, T.r, 2, c);
	}
	return OK;
}

/***********************************************************
*�������ƣ�FormParDef
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ��ʽ���������ɵ���
������CTree T��
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status FormParDef(FILE * fp, CTree & T)
{
	CTree c;
	T.n = 1; T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("�βΣ�") + 1) * sizeof(char));
	strcpy(T.nodes[0].data, "�βΣ�");
	T.nodes[0].indent = 1;
	T.nodes[0].firstchild = NULL;		//�����βν��
	if (w != INT && w != LONG && w != SHORT && w != SIGNED && w != UNSIGNED &&
		w != FLOAT && w != DOUBLE && w != CHAR) return ERROR;
	c.n = 1; c.r = 0;
	c.nodes[0].data = (char *)malloc((strlen(token_text) + strlen("���ͣ�") + 1) * sizeof(char));
	strcpy(c.nodes[0].data, "���ͣ�");
	strcat(c.nodes[0].data, token_text);
	c.nodes[0].indent = 1;
	c.nodes[0].firstchild = NULL;		//�����β����ͽ��
	InsertChild(T, T.r, 1, c);
	w = gettoken(fp);
	if (w != IDENT) return ERROR;
	c.nodes[0].data = (char *)malloc((strlen(token_text) + strlen("ID: ") + 1) * sizeof(char));
	strcpy(c.nodes[0].data, "ID: ");
	strcat(c.nodes[0].data, token_text);
	c.nodes[0].indent = 1;
	c.nodes[0].firstchild = NULL;
	InsertChild(T, T.r, 2, c);
	return OK;
}

/***********************************************************
*�������ƣ�CompStat
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ�������
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status CompStat(FILE * fp, CTree & T)
{
	CTree c; CTree p;
	Status status;
	print elem;
	T.n = 1; T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("������䣺")+1)*sizeof(char));
	strcpy(T.nodes[0].data, "������䣺");
	T.nodes[0].indent = 1;
	T.nodes[0].firstchild = NULL;		//���ɸ��������
	//ע�����оֲ�����˵����������ж�����Ϊ��
	w = gettoken(fp);
	elem = { ++indent0,num };
	printList.push(elem);
	if (w == INT || w == LONG || w == SHORT || w == SIGNED || w == UNSIGNED
		|| w == FLOAT || w == DOUBLE || w == CHAR)
	{
		if (!LocVarList(fp, c)) return ERROR;
		if(!InsertChild(T,T.r,1,c)) return ERROR;
		status = StatList(fp, p);
		if (!status) return ERROR;
		if(status==OK)
			if (!InsertChild(T, T.r, 2, p)) return ERROR;
	}
	else
	{
		status = StatList(fp, p);
		if (!status) return ERROR;
		if (status == OK)
			if (!InsertChild(T, T.r, 1, p)) return ERROR;
	}
	elem = { --indent0,num };
	printList.push(elem);
	if (w != RBS) return ERROR;
	w = gettoken(fp);
	return OK;
}

/***********************************************************
*�������ƣ�LocVarList
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ�ֲ�������������
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status LocVarList(FILE * fp, CTree & T)
{
	CTree c; Status p;
	if (w != INT && w != LONG && w != SHORT && w != SIGNED && w != UNSIGNED &&
		w != FLOAT && w != DOUBLE && w != CHAR)
		return INFEASIBLE;						
	//�����ĺ�̵��ʲ�Ϊ����˵����ʱ�������������н���
	T.n = 1;  T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("�ֲ�������������") + 1) * sizeof(char));
	strcpy(T.nodes[0].data, "�ֲ�������������");
	T.nodes[0].indent = 0;
	T.nodes[0].firstchild = NULL;		//���ɾֲ������������н��
	if (!LocVarDef(fp, c)) return ERROR;
	if (!InsertChild(T, T.r, 1, c)) return ERROR;
	w = gettoken(fp);
	p = LocVarList(fp, c);
	if (p == OK) InsertChild(T, T.r, 2, c);
	if (!p) return ERROR;
	return OK;
}

/***********************************************************
*�������ƣ�LocVarDef
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ�ֲ�����
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status LocVarDef(FILE * fp, CTree & T)
{
	CTree c;  CTree t; int i = 1;
	CTree *Treeptr;
	if (w != INT && w != LONG && w != SHORT && w != SIGNED && w != UNSIGNED &&
		w != FLOAT && w != DOUBLE && w != CHAR) return ERROR;
	T.n = 1; T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("�ֲ��������壺") + 1) * sizeof(char));
	strcpy(T.nodes[0].data, "�ֲ��������壺");
	T.nodes[0].indent = 1;
	T.nodes[0].firstchild = NULL;			//���ɾֲ�����������
	c.n = 1; c.r = 0;
	c.nodes[0].data = (char *)malloc((strlen(token_text) + strlen("���ͣ�") + 1) * sizeof(char));
	strcpy(c.nodes[0].data, "���ͣ�");
	strcat(c.nodes[0].data, token_text);
	c.nodes[0].indent = 1;
	c.nodes[0].firstchild = NULL;			//���ɱ������ͽ��
	if (!InsertChild(T, T.r, 1, c)) return ERROR;
	t.n = 1; t.r = 0;
	t.nodes[0].data = (char *)malloc((strlen("����������") + 1) * sizeof(char));
	strcpy(t.nodes[0].data, "����������");
	t.nodes[0].indent = 0;
	t.nodes[0].firstchild = NULL;
	do
	{
		w = gettoken(fp); strcpy(tokenText0, token_text);
		if (w != IDENT) return ERROR;
		Treeptr = (CTree *)malloc(sizeof(CTree));
		if (!Treeptr) exit(OVERFLOW);
		w = gettoken(fp);
		if (w == LBT)
		{
			strcat(tokenText0, "[");
			if ((w = gettoken(fp)) == INT_CONST)
			{
				strcat(tokenText0, token_text);
				if ((w = gettoken(fp)) == RBT)
				{
					strcat(tokenText0, "]");
					Treeptr->n = 1; Treeptr->r = 0;
					Treeptr->nodes[0].data = (char *)malloc((strlen(tokenText0) + strlen("Array: ") + 1) * sizeof(char));
					strcpy(Treeptr->nodes[0].data, "Array: ");
					strcat(Treeptr->nodes[0].data, tokenText0);
					Treeptr->nodes[0].indent = 1;
					Treeptr->nodes[0].firstchild = NULL;
					w = gettoken(fp);
				}
				else return ERROR;
			}
			else return ERROR;
		}
		else
		{
			Treeptr->n = 1; Treeptr->r = 0;
			Treeptr->nodes[0].data = (char *)malloc((strlen(tokenText0) + strlen("ID: ") + 1) * sizeof(char));
			strcpy(Treeptr->nodes[0].data, "ID: ");
			strcat(Treeptr->nodes[0].data, tokenText0);
			Treeptr->nodes[0].indent = 1;
			Treeptr->nodes[0].firstchild = NULL;		//���ɱ��������
		}
		if (!InsertChild(t, t.r, i++, *Treeptr)) return ERROR;
	} while (w == COMMA);
	if (w != SEMI) return ERROR;
	if (!InsertChild(T, T.r, 2, t)) return ERROR;
	return OK;
}

/***********************************************************
*�������ƣ�StatList
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ�������
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status StatList(FILE * fp, CTree & T)
{
	Status status; CTree c, t;
	status = Statement(fp, c);
	if (status == INFEASIBLE) return INFEASIBLE;
	if (!status) return ERROR;
	else
	{
		T.n = 1; T.r = 0;
		T.nodes[0].data = (char *)malloc((strlen("�������") + 1) * sizeof(char));
		strcpy(T.nodes[0].data, "�������");
		T.nodes[0].indent = 0;
		T.nodes[0].firstchild = NULL;		//����������н��
		InsertChild(T, T.r, 1, c);
		status = StatList(fp, t);
		if (!status) return ERROR;
		if (status == OK)
			if (!InsertChild(T, T.r, 2, t))
				return ERROR;
	}
	return OK;
}

/***********************************************************
*�������ƣ�Statement
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ���
*���������Դ�ļ�ָ��fp,��CTree T
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status Statement(FILE * fp, CTree & T)
{
	CTree c; CTree p; CTree q; CTree k;
	print elem;
	switch (w)
	{
	case IF://�����������
		w = gettoken(fp);
		if (w != LP) return ERROR;
		w = gettoken(fp);
		if (w == RP) return ERROR;
		if (!exp(fp, p, RP)) return ERROR;
		c.n = 1; c.r = 0;
		c.nodes[0].data = (char *)malloc((strlen("������") + 1) * sizeof(char));
		strcpy(c.nodes[0].data, "������");
		c.nodes[0].indent = 1;
		c.nodes[0].firstchild = NULL;
		InsertChild(c, c.r, 1, p);
		w = gettoken(fp);
		if (w == LBS)
		{
			if (!CompStat(fp, q)) return ERROR;
		}
		else
		{
			elem = { ++indent0,num };
			printList.push(elem);
			if (!Statement(fp, q)) return ERROR;
			elem = { --indent0,num };
			printList.push(elem);
		}
		p.n = 1; p.r = 0;
		p.nodes[0].data = (char *)malloc((strlen("IF�Ӿ䣺") + 1) * sizeof(char));
		strcpy(p.nodes[0].data, "IF�Ӿ䣺");
		p.nodes[0].indent = 1;
		p.nodes[0].firstchild = NULL;
		InsertChild(p, p.r, 1, q);
		if (w == ELSE)
		{
			w = gettoken(fp);
			if (w == LBS)
			{
				if (!CompStat(fp, k)) return ERROR;
			}
			else
			{
				elem = { ++indent0,num };
				printList.push(elem);
				if (!Statement(fp, k)) return ERROR;
				elem = { --indent0,num };
				printList.push(elem);
			}
			q.n = 1; q.r = 0;
			q.nodes[0].data = (char *)malloc((strlen("ELSE�Ӿ䣺") + 1) * sizeof(char));
			strcpy(q.nodes[0].data, "ELSE�Ӿ䣺");
			q.nodes[0].indent = 1;
			q.nodes[0].firstchild = NULL;
			InsertChild(q, q.r, 1, k);
			T.n = 1; T.r = 0;
			T.nodes[0].data = (char *)malloc((strlen("if-else��䣺") + 1) * sizeof(char));
			strcpy(T.nodes[0].data, "if-else��䣺");
			T.nodes[0].indent = 1;
			T.nodes[0].firstchild = NULL;
			InsertChild(T, T.r, 1, c);
			InsertChild(T, T.r, 2, p);
			InsertChild(T, T.r, 3, q);
		}
		else
		{
			T.n = 1; T.r = 0;
			T.nodes[0].data = (char *)malloc((strlen("if��䣺") + 1) * sizeof(char));
			strcpy(T.nodes[0].data, "if��䣺");
			T.nodes[0].indent = 1;
			T.nodes[0].firstchild = NULL;
			InsertChild(T, T.r, 1, c);
			InsertChild(T, T.r, 2, p);
		}
		return OK;
	case LBS:
		if (!CompStat(fp, T)) return ERROR;
		return OK;
	case FOR:
		//����for���
		T.n = 1; T.r = 0;
		T.nodes[0].data = (char *)malloc((strlen("for��䣺") + 1) * sizeof(char));
		strcpy(T.nodes[0].data, "for��䣺");
		T.nodes[0].indent = 1;
		T.nodes[0].firstchild = NULL;
		c.n = 1; c.r = 0;
		c.nodes[0].data = (char *)malloc((strlen("��ʼ���ʽ��") + 1) * sizeof(char));
		strcpy(c.nodes[0].data, "��ʼ���ʽ��");
		c.nodes[0].indent = 1;
		c.nodes[0].firstchild = NULL;
		InsertChild(T, T.r, 1, c);
		c.n = 1; c.r = 0;
		c.nodes[0].data = (char *)malloc((strlen("��ֹ������") + 1) * sizeof(char));
		strcpy(c.nodes[0].data, "��ֹ������");
		c.nodes[0].indent = 1;
		c.nodes[0].firstchild = NULL;
		InsertChild(T, T.r, 2, c);
		c.n = 1; c.r = 0;
		c.nodes[0].data = (char *)malloc((strlen("ѭ�����ʽ��") + 1) * sizeof(char));
		strcpy(c.nodes[0].data, "ѭ�����ʽ��");
		c.nodes[0].indent = 1;
		c.nodes[0].firstchild = NULL;
		InsertChild(T, T.r, 3, c);
		c.n = 1; c.r = 0;
		c.nodes[0].data = (char *)malloc((strlen("for�Ӿ䣺") + 1) * sizeof(char));
		strcpy(c.nodes[0].data, "for�Ӿ䣺");
		c.nodes[0].indent = 1;
		c.nodes[0].firstchild = NULL;
		InsertChild(T, T.r, 4, c);
		w = gettoken(fp);
		if (w != LP) return ERROR;
		w = gettoken(fp);
		if (!exp(fp, c, SEMI)) return ERROR;
		InsertChild(T, T.nodes[0].firstchild->child, 1, c);
		w = gettoken(fp);
		if (w == SEMI) return ERROR;
		if (!exp(fp, c, SEMI)) return ERROR;
		InsertChild(T, T.nodes[0].firstchild->next->child, 1, c);
		w = gettoken(fp);
		if (!exp(fp, c, RP)) return ERROR;
		InsertChild(T, T.nodes[0].firstchild->next->next->child, 1, c);
		w = gettoken(fp);
		if (w == LBS)
		{
			if (!CompStat(fp, c)) return ERROR;
		}
		else
		{
			elem = { ++indent0,num };
			printList.push(elem);
			if (!Statement(fp, c)) return ERROR;
			elem = { --indent0,num };
			printList.push(elem);
		}
		InsertChild(T, T.nodes[0].firstchild->next->next->next->child, 1, c);
		return OK;
	case WHILE:
		w = gettoken(fp);
		if (w != LP) return ERROR;
		w = gettoken(fp);
		if (w == RP) return ERROR;
		if (!exp(fp, c, RP)) return ERROR;
		w = gettoken(fp);
		if (w == LBS)
		{
			if (!CompStat(fp, p)) return ERROR;
		}
		else
		{
			elem = { ++indent0,num };
			printList.push(elem);
			if (!Statement(fp, p)) return ERROR;
			elem = { --indent0,num };
			printList.push(elem);
		}
		T.n = 1; T.r = 0;
		T.nodes[0].data = (char *)malloc((strlen("while��䣺") + 1) * sizeof(char));
		strcpy(T.nodes[0].data, "while��䣺");
		T.nodes[0].indent = 1;
		T.nodes[0].firstchild = NULL;
		InsertChild(T, T.r, 1, c);
		InsertChild(T, T.r, 2, p);
		return OK;
	case DO:
		T.n = 1; T.r = 0;
		T.nodes[0].data = (char *)malloc((strlen("do-while��䣺") + 1) * sizeof(char));
		strcpy(T.nodes[0].data, "do-while��䣺");
		T.nodes[0].indent = 1;
		T.nodes[0].firstchild = NULL;
		w = gettoken(fp);
		if (w == LBS)
		{
			if (!CompStat(fp, c)) return ERROR;
		}
		else
		{
			elem = { ++indent0,num };
			printList.push(elem);
			if (!Statement(fp, c)) return ERROR;
			elem = { --indent0,num };
			printList.push(elem);
		}
		InsertChild(T, T.r, 1, c);
		if (w != WHILE) return ERROR;
		w = gettoken(fp);
		if (w != LP) return ERROR;
		w = gettoken(fp);
		if (w == RP) return ERROR;
		if (!exp(fp, c, RP)) return ERROR;
		InsertChild(T, T.r, 2, c);
		w = gettoken(fp);
		if (w != SEMI) return ERROR;
		w = gettoken(fp);
		return OK;
	case CONTINUE:
		T.n = 1; T.r = 0;
		T.nodes[0].data = (char *)malloc((strlen("continue��䣺") + 1) * sizeof(char));
		strcpy(T.nodes[0].data, "continue��䣺");
		T.nodes[0].indent = 1;
		T.nodes[0].firstchild = NULL;
		w = gettoken(fp);
		if (w != SEMI) return ERROR;
		w = gettoken(fp);
		return OK;
	case BREAK:
		T.n = 1; T.r = 0;
		T.nodes[0].data = (char *)malloc((strlen("break��䣺") + 1) * sizeof(char));
		strcpy(T.nodes[0].data, "break��䣺");
		T.nodes[0].indent = 1;
		T.nodes[0].firstchild = NULL;
		w = gettoken(fp);
		if (w != SEMI) return ERROR;
		w = gettoken(fp);
		return OK;
	case RETURN:
		T.n = 1; T.r = 0;
		T.nodes[0].data = (char *)malloc((strlen("return��䣺") + 1) * sizeof(char));
		strcpy(T.nodes[0].data, "return��䣺");
		T.nodes[0].indent = 1;
		T.nodes[0].firstchild = NULL;
		w = gettoken(fp);
		if (w == SEMI) return ERROR;
		if (!exp(fp, c, SEMI)) return ERROR;
		w = gettoken(fp);
		InsertChild(T, T.r, 1, c);
		return OK;
	case LP:
		if (!exp(fp, T, RP)) return ERROR;
		w = gettoken(fp);
		return OK;
	case IDENT:
	case INT_CONST:
	case UNSIGNED_CONST:
	case LONG_CONST:
	case UNSIGNED_LONG_CONST:
	case DOUBLE_CONST:
	case FLOAT_CONST:
	case LONG_DOUBLE_CONST:
	case CHAR_CONST:
		if (!exp(fp, T, SEMI)) return ERROR;
		w = gettoken(fp);
		return OK;
	case RBS:
		return INFEASIBLE;
	case SEMI: 
		T.n = 1; T.r = 0;
		T.nodes[0].data = (char *)malloc((strlen("�����") + 1) * sizeof(char));
		strcpy(T.nodes[0].data, "�����");
		T.nodes[0].indent = 1;
		T.nodes[0].firstchild = NULL;
		w = gettoken(fp);
		return OK;
	default:
		return ERROR;
	}
}

/***********************************************************
*�������ƣ�exp
*�������ܣ�������ǰ�﷨�ɷ��Ƿ�Ϊ���ʽ
*���������Դ�ļ�ָ��fp,��CTree T,���ʽ��������int endsym
*����ֵ�����غ���ִ��״̬
***********************************************************/
Status exp(FILE * fp, CTree & T, int endsym)
{
	//���ø��㷨ʱ���ڵ������Ѿ������˵�һ��������w��
	SqStack op;		//�����ջ
	SqStack opn;	//������ջ
	CTree * node = (CTree *)malloc(sizeof(CTree));
	CTree * child1 = (CTree *)malloc(sizeof(CTree));
	CTree * child2 = (CTree *)malloc(sizeof(CTree));
	T.n = 1; T.r = 0;
	T.nodes[0].data = (char *)malloc((strlen("���ʽ��䣺") + 1) * sizeof(char));
	strcpy(T.nodes[0].data, "���ʽ��䣺");
	T.nodes[0].indent = 1;
	T.nodes[0].firstchild = NULL;
	int error = 0;
	node->n = 1; node->r = 0;
	node->nodes[0].data = (char *)malloc((strlen("#") + 1) * sizeof(char));
	strcpy(node->nodes[0].data, "#");
	node->nodes[0].firstchild = NULL;
	InitStack(opn);  InitStack(op);  Push(op, node);		//��ʼ��������ֹ��#��ջ
	while ((w != BEGIN_END || strcmp(node->nodes[0].data, "#")) && !error)  //�������ջջ��������ֹ���ţ���û�д���ʱ
	{
		if (w == IDENT || w == INT_CONST || w == UNSIGNED_CONST || w == LONG_CONST
			|| w == UNSIGNED_LONG_CONST || w == DOUBLE_CONST || w == FLOAT_CONST
			|| w == LONG_DOUBLE_CONST || w == CHAR_CONST)
		{
			node = (CTree *)malloc(sizeof(CTree));
			node->n = 1; node->r = 0;
			node->nodes[0].data = (char *)malloc((strlen(token_text) + strlen("ID: ") + 1) * sizeof(char));
			strcpy(node->nodes[0].data, "ID: ");
			strcat(node->nodes[0].data, token_text);
			node->nodes[0].indent = 1;
			node->nodes[0].firstchild = NULL;
			Push(opn, node);								//����w����һ����㣬���ָ���ջopn
			w = gettoken(fp);
		}
		else if (w == PLUS || w == MINUS || w == MULTIPLY || w == DIVIDE ||
			w == MOD || w == LP || w == RP || w == COMPARISON || w == ASSIGN ||
			w == AND || w == OR || w == BEGIN_END)
		{
			node = (CTree *)malloc(sizeof(CTree));
			GetTop(op, node);
			if (w == BEGIN_END) strcpy(token_text, "#");
			switch (precede(node->nodes[0].data, token_text))
			{
			case '<':
				node = (CTree *)malloc(sizeof(CTree));
				node->nodes[0].data = (char *)malloc((strlen(token_text) + 1) * sizeof(char));
				strcpy(node->nodes[0].data, token_text);
				node->nodes[0].indent = 1;
				node->nodes[0].firstchild = NULL;
				node->n = 1; node->r = 0;
				Push(op, node);		//����w����һ����㣬���ָ���ջopn
				w = gettoken(fp);
				break;
			case '=':
				if (!Pop(op, node)) error++;
				w = gettoken(fp);
				break;   //ȥ����
			case '>':if (!Pop(opn, child2)) error++;
				if (!Pop(opn, child1)) error++;
				if (!Pop(op, node)) error++;
				//���������ջ��ջ�õ��������t�Ͳ������Ľ��ָ��t1��t2��
				//��ɽ�������һ��������Ľ�㣬���ָ���ջopn
				InsertChild(*node, node->r, 1, *child1);
				InsertChild(*node, node->r, 2, *child2);
				Push(opn, node);
				break;
			default:
				if (w == endsym) w = BEGIN_END; //����������ǣ���w���滻��#
				else error++;
			}
		}
		else if (w == endsym) w = BEGIN_END;//����������Ƿֺţ�w���滻��#
		else error = 1;
		GetTop(op, node);
	}
	if (error) return ERROR;
	GetTop(opn, node);
	InsertChild(T, T.r, 1, *node);
	return OK;
}


char precede(char * a, char * b)
{
	int i, j;		//ָʾ�������Ӧ�ı��
	//����һ����ά���飬���ڴ�����ȼ�
	char precede[MAX_OP][MAX_OP]=
	{//				+		-		*		/		%		��		��		=		>��<		==��!=		#		&&		||
	/* + */			'>',	'>',	'<',	'<',	'<',	'<',	'>',	'?',	'>',		'>',		'>',	'>',	'>',
	/* - */			'>',	'>',	'<',	'<',	'<',	'<',	'>',	'?',	'>',		'>',		'>',	'>',	'>',
	/* * */			'>',	'>',	'>',	'>',	'>',	'<',	'>',	'?',	'>',		'>',		'>',	'>',	'>',
	/* / */			'>',	'>',	'>',	'>',	'>',	'<',	'>',	'?',	'>',		'>',		'>',	'>',	'>',
	/* % */			'>',	'>',	'<',	'<',	'<',	'<',	'>',	'?',	'>',		'>',		'>',	'>',	'>',
	/* ( */			'<',	'<',	'<',	'<',	'<',	'<',	'=',	'?',	'<',		'<',		'>',	'<',	'<',
	/* ) */			'>',	'>',	'>',	'>',	'>',	'>',	'?',	'?',	'>',		'>',		'>',	'>',	'>',
	/* = */			'<',	'<',	'<',	'<',	'<',	'<',	'?',	'<',	'<',		'<',		'>',	'<',	'<',
	/* >��< */		'<',	'<',	'<',	'<',	'<',	'<',	'>',	'?',	'>',		'>',		'>',	'>',	'>',
	/* ==��!= */	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'?',	'<',		'>',		'>',	'>',	'>',
	/* # */			'<',	'<',	'<',	'<',	'<',	'<',	'?',	'<',	'<',		'<',		'=',	'<',	'<',
	/* && */		'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'<',		'<',		'>',	'>',	'>',
	/* || */		'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'<',		'<',		'>',	'>',	'>'
	};
	switch (a[0])
	{
	case '+':
		i = 0; break;
	case '-':
		i = 1; break;
	case '*':
		i = 2; break;
	case '/':
		i = 3; break;
	case '%':
		i = 4; break;
	case '(':
		i = 5; break;
	case ')':
		i = 6; break;
	case '=':
		if (a[1] == '=') i = 9;
		else i = 7;
		break;
	case '>':
	case '<':
		i = 8; break;
	case '!':
		if (a[1] == '=') i = 9;
		else return '?';
		break;
	case '#':
		i = 10;
		break;
	case '&':
		if (a[1] == '&') i = 11;
		else return '?';
		break;
	case '|':
		if (a[1] == '|') i = 12;
		else return '?';
		break;
	default:
		return '?';
	}
	switch (b[0])
	{
	case '+':
		j = 0; break;
	case '-':
		j = 1; break;
	case '*':
		j = 2; break;
	case '/':
		j = 3; break;
	case '%':
		j = 4; break;
	case '(':
		j = 5; break;
	case ')':
		j = 6; break;
	case '=':
		if (b[1] == '=') j = 9;
		else j = 7;
		break;
	case '>':
	case '<':
		j = 8; break;
	case '!':
		if (b[1] == '=') j = 9;
		else return '?';
		break;
	case '#':
		j = 10;
		break;
	case '&':
		if (b[1] == '&') j = 11;
		else return '?';
		break;
	case '|':
		if (b[1] == '|') j = 12;
		else return '?';
		break;
	default:
		return '?';
	}
	return precede[i][j];
}

Status PrintTree(TElemType data, int indent)
{
	int i;
	for (i = 0; i < indent; i++)
		printf("\t");
	printf("%s\n", data);
	return OK;
}
