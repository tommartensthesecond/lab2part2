/*���� 2, ����� 2, ������� 2. 
������� �.�., ����� �����, ����� �� �����, ���� ���������� ���������.*/
/*
1 - ���� ���������(�����) ��������� +
2 - ����� +
3 - �������� ����������������� ����������
4 - ����� ��������� ����������������� ����������
5 - ����� � ������� ��������� � ����������� ��������� ��������� ����
6 - ����� � ������� �������� �������� � �������� ��������� ���� ��� � �������� ������� � ���� �� ��������
7 - �������� ��������� ��������
8 - ���������(��������������) ��������� ��������
9 - ���������� ������� �������� � ������� ����������� ��������� ����
	(��� ���������� ����� ������������ ��� ����, ��� � ��++ ����������� ������������ ����������������� ����������)
10 - ���������� � ��������� � �������������� ���� ��������� ������� �� ��������� ������� � �������
	(��������, ����� ����� �� ���� ������) - ������ ������������� 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
//#include <windows.h>

//struct Date
//{
//	unsigned short day;
//	unsigned short month;
//	unsigned short year;
//};
//struct Name
//{
//	char first_name[80];
//	char last_name[80];
//	char *patronymic[80];
//};
//void time()
//{
//	SYSTEMTIME SystemTime;
//
//	GetSystemTime(&SystemTime);
//	printf("hours : %d\n", SystemTime.wHour);
//
//}
//int id;
//bool is_empty;
//unsigned long long account_id;
//long fund_sum;
//long last_edited;
//Date date;
//Name name;
//SYTEMTIME last_modified;
//void menu(Account *accounts, int *id)
//{
//	printf("\t please, write a number to select an option\n\n");
//	printf("\t 1. create new account\n\t 2. show account\n\n");
//	int in = 0;
//	printf("\t ");
//	scanf("%d\n", &in);
//
//	switch (in)
//	{
//	case 1:
//		scanData(accounts, id);
//		break;
//	case 2:
//		printData(accounts, id);
//		break;
//	}
//}
typedef struct Account 
{
	int test;
	
} Account;

void fillAcc(Account *accounts, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
		(accounts + i)->test = i;
}

void scanAcc(Account *accounts, int id)
{
	printf("please type a number:\n");
	scanf("%d", &(accounts+id)->test);
}

void printAcc(Account *accounts, int id, int arraySize)
{
	/*for (int i = 0; i < arraySize; i++)
		printf("  %d", (accounts + i)->test);*/
	if ((accounts + id)->test != 0)
		printf("%d \n", (accounts + id)->test);
}

void clearingAccVars(Account *accounts, int id, int arraySize)
{
	if (id < arraySize)
		(accounts + id)->test = 0;
}

void searchFreeVar(Account *accounts, int arraySize)
{
	for (int i = 0; i < arraySize, i++)
	{
		if ((accounts + i)->test == 0)
			//do actions
	}
}

void main()
{
	int arraySize = 100;
	int id = 0;
	Account *accounts = (Account *)malloc(arraySize * sizeof(Account));

	printf("enter id: \n");
	scanf("%d", &id);
	fillAcc(accounts, arraySize);
	printAcc(accounts, id, arraySize);

	free(accounts);
}
