//
// lexical.h
//

//#pragma once

#ifndef _LEXER_H
#define _LEXER_H
//��ֹ�ظ�������ͷ�ļ�

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define MAXLEN 100
enum token_kind
{
	ERROR_TOKEN, AUTO, BREAK, CASE, CHAR, CONST, CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN,
	FLOAT, FOR, GOTO, IF, INLINE, INT, LONG, REGISTER, RESTRICT, RETURN, SHORT, SIGNED, SIZEOF,
	STATIC, STRUCT, SWITCH, TYPEDEF, UNION, UNSIGNED, VOID, VOLATILE, WHILE, _ALIGNAS, _ALIGNOF,
	_ATOMIC, _BOOL, _COMPLEX, _GENERIC, _IMAGINARY, _NORETURN, _STATIC_ASSERT, _THREAD_LOCAL, IDENT,
	INT_CONST, UNSIGNED_CONST, LONG_CONST, UNSIGNED_LONG_CONST, DOUBLE_CONST, FLOAT_CONST,
	LONG_DOUBLE_CONST, CHAR_CONST, STRING_CONST, ASSIGN, PLUS, PLUSPLUS, MINUS, MINUSMINUS,
	MULTIPLY, DIVIDE, MOD, COMPARISON, AND, OR, LP, RP, LBT, RBT, LBS, RBS, SEMI, COMMA
};
struct keyword
{
	char key[15];
	enum token_kind c;
};
//Hash�������Ԫ��

//����ö�����ͣ�ʹ��ͬ���͵ĵ��ʵõ�Ψһ�ı�ʶ��

extern int num;						//��������������¼��ǰ�ѷ�����Դ����ĵڼ���
extern char token_text[MAXLEN];		//��ŵ���ֵ���ַ���
extern keyword HashKey[25][11];		//��Źؼ��ּ����ʶ���Hash��

int gettoken(FILE * fp);

#endif // !_LEXER_H
