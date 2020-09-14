#ifndef _CONTACT_H_
#define _CONTACT_H_

#include<stdio.h>
#include<assert.h>
#include<string.h>


//定义操作选项
typedef enum
{
	QUIT,
	ADD,
	DEL,
	FIND,
	MODIFY,
	SHOW,
	CLEAR,
	SORT
}OPER_ENUM;

//#define MAX_CONTACT_SIZE 1000
#define DEFAULT_CONTACT_SIZE 2
#define MAX_NAME_SIZE 20
#define MAX_ADDR_SIZE 256

//定义人员信息结构
typedef struct PersonInfo
{
	char  name[MAX_NAME_SIZE];
	char  sex[3];
	char  tel[12];
	char  addr[MAX_ADDR_SIZE];
	int age;
}personinfo;

//定义通讯录结构
typedef struct contact
{
	//personinfo data[MAX_CONTACT_SIZE];
	personinfo *data;
	size_t     size;
	size_t     capacity;
}contact;

///////////////////////////////////////////////////////////////
//函数申明
void InitContact(contact *pct);
void AddContact(contact *pct);
void ShowContact(contact *pct);
void FindContact(contact *pct);
void DelContact(contact *pct);
void ModifyContact(contact *pct);
void ClearContact(contact *pct);
void SortContact(contact *pct);
void DestroyContact(contact *pct);

void LoadContact(contact *pct);
void SaveContact(contact *pct);

#endif /* _CONTACT_H_ */ 