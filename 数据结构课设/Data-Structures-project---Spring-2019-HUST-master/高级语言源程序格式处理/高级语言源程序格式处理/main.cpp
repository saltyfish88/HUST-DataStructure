#include"lexer.h"
#include"parser.h"
#include"queue.h"
#include"tree.h"
#include"Print_CFile.h"
#include"pre_process.h"

//�Զ������õ�visit()�������ж���
Status PrintElement(QElemType e)
{
	int i = 1;					//��Ǵ������
	printf("	%d		%d\n", i++, e);
	return OK;
}

int main(void)
{
	char filename[30]; FILE * fp, * fp1;
	int status; int ch = 1;
	LinkQueue Q;				//����һ�����У����ڴ�Ŵ�����
	CTree T;
	InitQueue(Q);
ChooseFilename:
	system("cls");
	printf("�����ļ�����");
	scanf("%s", filename, 30);
	while (ch)
	{
		if (fopen(filename, "r"))
		{
			printf("�ļ���ʧ�ܣ�\n");
			printf("�����������...");
			getchar(); getchar();
			goto ChooseFilename;
		}
		system("cls");
		printf("�ļ�����%s\n\n", filename);
		printf("�߼�����Դ�����ʽ����˵�\n");
		printf("1. �ʷ�����\n");
		printf("2. �﷨����\n");
		printf("3. ��ʽ��Դ�ļ�\n");
		printf("4. ����ѡ���ļ�\n");
		printf("0. �˳�����\n");
		printf("\n");
		printf("�����ѡ��");
		scanf("%d", &ch);
		system("cls");
		switch (ch)
		{
		case 1:
			printf("����Ԥ�����ļ�...\n");
			if (fp = pre_process(fp))
			{
				printf("Ԥ����ɹ��������м��ļ�mid_cpp\n");
				printf("�����������...\n");
				getchar(); getchar();
			}
			else
			{
				printf("Ԥ����ʧ�ܣ��������\n");
				printf("�����������...");
				getchar(); getchar();
				return 0;
			}
			fp = fopen("mid_cpp", "r");
			system("cls");
			printf("\n");
			printf("	�������				����ֵ\n");
			while (!feof(fp))
			{
				status = gettoken(fp);
				if (status >= AUTO && status <= _THREAD_LOCAL)
					printf("	�ؼ���					%s\n", token_text);
				switch (status)
				{
				case IDENT:
					printf("	��ʶ��					%s\n", token_text);
					break;
				case INT_CONST:
					printf("	���ͳ���				%s\n", token_text);
					break;
				case UNSIGNED_CONST:
					printf("	�޷������ͳ���				%s\n", token_text);
					break;
				case LONG_CONST:
					printf("	�����ͳ���				%s\n", token_text);
					break;
				case UNSIGNED_LONG_CONST:
					printf("	�޷��ų����ͳ���			%s\n", token_text);
					break;
				case DOUBLE_CONST:
					printf("	˫���ȸ����ͳ���			%s\n", token_text);
					break;
				case FLOAT_CONST:
					printf("	�����ͳ���				%s\n", token_text);
					break;
				case LONG_DOUBLE_CONST:
					printf("	��˫���ȸ����ͳ���			%s\n", token_text);
					break;
				case CHAR_CONST:
					printf("	�ַ��ͳ���				%s\n", token_text);
					break;
				case STRING_CONST:
					printf("	�ַ�������				%s\n", token_text);
					break;
				case ASSIGN:
					printf("	��ֵ�����				=\n");
					break;
				case PLUS:
					printf("	�ӷ������				+\n");
					break;
				case PLUSPLUS:
					printf("	���������				++\n");
					break;
				case MINUS:
					printf("	���������				-\n");
					break;
				case MINUSMINUS:
					printf("	�Լ������				--\n");
					break;
				case MULTIPLY:
					printf("	�˷������				*\n");
					break;
				case DIVIDE:
					printf("	���������				/\n");
					break;
				case MOD:
					printf("	ȡģ�����				%%\n");
					break;
				case COMPARISON:
					printf("	��ϵ�����				%s\n", token_text);
					break;
				case AND:
					printf("	�߼���					&&\n");
					break;
				case OR:
					printf("	�߼���					||\n");
					break;
				case LP:
					printf("	��С����				(\n");
					break;
				case RP:
					printf("	��С����				)\n");
					break;
				case LBT:
					printf("	��������				[\n");
					break;
				case RBT:
					printf("	��������				]\n");
					break;
				case LBS:
					printf("	�������				{\n");
					break;
				case RBS:
					printf("	�Ҵ�����				}\n");
					break;
				case SEMI:
					printf("	�ֺ�					;\n");
					break;
				case COMMA:
					printf("	����					,\n");
					break;
				case ERROR_TOKEN:
					EnQueue(Q, num);
					break;
				}
			}
			printf("\n");
			printf("�����б� %d\n", QueueLength(Q));
			if (QueueLength(Q))
			{
				printf("\n");
				printf("	���		��\n");
				QueueTraverse(Q, PrintElement);
			}
			fclose(fp);
			printf("\n�����������...");
			getchar();
			num = 1;
			break;
		case 2:
			printf("����Ԥ�����ļ�...\n");
			if (fp = pre_process(fp))
			{
				printf("Ԥ����ɹ��������м��ļ�mid_cpp\n");
				printf("�����������...\n");
				getchar(); getchar();
			}
			else
			{
				printf("Ԥ����ʧ�ܣ��������\n");
				printf("�����������...");
				getchar(); getchar();
				return 0;
			}
			fp = fopen("mid_cpp", "r");
			system("cls");
			if (!program(fp, T))
			{
				printf("�������ɴ��󣡴����кţ�%d\n", num);
				printf("�����������...\n");
				getchar(); num = 1;
				break;
			}
			TraverseTree(T, PrintTree);
			printf("\n�����������...\n");
			getchar();
			num = 1;
			break;
		case 3:
			if (!pre_process(fp))
			{
				printf("����Ԥ����ʧ�ܣ�\n");
				printf("�����������...");
				getchar(); getchar();
				goto ChooseFilename;
			}
			if (!(fp1 = fopen("mid_cpp", "r")))
			{
				printf("�޷����м��ļ���\n");
				printf("�����������...");
				getchar(); getchar();
				goto ChooseFilename;
			}
			if (!program(fp1, T))
			{
				printf("��������﷨�����޷�������ӡ��\n");
				printf("�����������...");
				getchar(); getchar();
				goto ChooseFilename;
			}
			if (!(fp = freopen(filename, "r+", fp)))
			{
				printf("�ļ���ʧ�ܣ�\n");
				printf("�����������...");
				getchar(); getchar();
				goto ChooseFilename;
			}
			Print_CFile(fp);
			printf("���ɳɹ�������Դ�ļ��в鿴��\n");
			printf("�����������...\n");
			getchar(); getchar();
			break;
		case 4:
			goto ChooseFilename;
		default:
			return 0;
		}
	}
	return 1;
}
