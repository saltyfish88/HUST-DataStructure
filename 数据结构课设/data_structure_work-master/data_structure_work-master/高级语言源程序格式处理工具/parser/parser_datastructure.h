#ifndef __PARSER_DATASTRUCTURE__
#define __PARSER_DATASTRUCTURE__
typedef struct TOKEN//定义token. 
{
	int type;
	char value[MAXLEN_OF_CONTENT];
	int loc;
}Token;
enum Tag//词法记号标签。 
{
	ERR,//错误。 
	END,//文件结束。 
	ID,//标识符。 
	INT,CHAR,FLOAT,DOUBLE,VOID,EXTERN,//数据类型。 
	NUM,//数字常量。 
	CH,//字符常量。 
	STR,//字符串。 
	NOT,LEA,//！& 
	ADD,SUB,MUL,DIV,MOD,//+-*/% 
	INC,DEC,//++--
	GT,GE,LT,LE,EQU,NEQU,//>>=<<==!=
	AND,OR,//&&|| 
	LPAREN,RPAREN,//（） 
	LBRACK,RBRACK,//【】 
	LBRACE,RBRACE,//｛｝ 
	COMMA,COLON,SEMICON,//，：； 
	ASSIGN,//= 
	IF,ELSE,SWITCH,CASE,DEFAULT,WHILE,DO,FOR,BREAK,CONTINUE,RETURN,//关键字。
	MAC//宏。 
};
enum synerror///语法错误标签。 
{
	TYPELOST,TYPEWRONG,//类型 
	IDLOST,IDWRONG,//标识符 
	NUMLOST,NUMWRONG,//数组的长度 
	LITERALLOST,LITERALWRONG,//常量 
	COMMALOST,COMMAWRONG,//, 
	SEMICONLOST,SEMICONWRONG,//;
	ASSIGNLOST,ASSIGNWRONG,//=
	COLONLOST,COLONWRONG,//:
	STATEMENTLOST,STATEMENTWRONG,//语句
	LPARENLOST,LPARENWRONG,//(
	RPARENLOST,RPARENWRONG,//)
	LBRACKLOST,LBRACKWRONG,//[
	RBRACKLOST,PBRACKWRONG,//]
	LBRACELOST,LBRACEWRONG,//{
	RBRACELOST,RBRACEWRONG//}
};
#endif
