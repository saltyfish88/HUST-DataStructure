//
// Print_CFile.h
//
// Description
// ��������������Դ�����ļ�

#pragma once

#ifndef _PRINT_CFILE_H
#include<stdio.h>
#include<string.h>
#include"parser.h"
#define ERROR 0
#define OK 1
typedef int Status;
Status Print_CFile(FILE * fp);
#endif // !_PRINT_CFILE_H
