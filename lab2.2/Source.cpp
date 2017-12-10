//Часть 2, лаба 2, вариант 2.
//Фамилия И.О., номер счета, сумма на счете, дата последнего изменения.
/*
1 - ввод элементов(полей) структуры +
2 - вывод +
3 - «очистка» структурированных переменных +
4 - поиск свободной структурированной переменной +
5 - поиск в массиве структуры и минимальным значением заданного поля
6 - поиск в массиве структур элемента с заданным значением поля или с наиболее близким к нему по значению +-
7 - удаление заданного элемента
8 - изменение(редактирование) заданного элемента
9 - сортировка массива структур в порядке возрастания заданного поля +
	(при сортировке можно использовать тот факт, что в Си++ разрешается присваивание структурированных переменных)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <windows.h>

typedef struct
{
	bool isEmpty;
	int id;
	int test;
	/*
	unsigned long long accNum;
	unsigned long fundSum;
	SYSTEMTIME lasEdited;
	
	char firstName[80];
	char lastName[80];
	char *patronymic[80];
	*/

} Account;

void fillAccs(Account *accounts, int arrSize)
{
	assert(accounts != NULL);
	assert(arrSize > 0);

	for (int i = 0; i < arrSize; i++)
	{
		(accounts + i)->id = i;
		(accounts + i)->isEmpty = false;
		(accounts + i)->test = 1 + rand() % 100;
	}
}

void printAccs(Account *accounts, int arrSize)
{
	assert(accounts != NULL);                                                                                     
	assert(arrSize > 0);

	printf("id	test\n\n");
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d	", (accounts + i)->id);
		printf("%d	", (accounts + i)->test);
		printf("\n");
	}
	printf("\n");
}

Account *scanAcc(Account *accounts, int arrSize, int id)
{
	assert(accounts != NULL);                                                                                     
	assert(arrSize > 0);

	for (int i = 0; i < arrSize; i++)
	{
		if ((accounts + i)->id == id)
		{
			printf("please enter a number:\n");
			scanf("%d", &((accounts + i)->test));
			return accounts + i;
		}
	}

	return NULL;
}

void printAcc(Account *accounts, int arrSize, int id)
{
	assert(accounts != NULL);                                                                                     
	assert(arrSize > 0);

	for (int i = 0; i < arrSize; i++)
	{
		if ((accounts + i)->id == id)
		{
			if ((accounts + i)->isEmpty == false)
				printf("%d \n", (accounts + i)->test);
		}
	}

	printf("account with this id doesent exist\n");
}

void clearAcc(Account *accounts, int arrSize, int id)
{
	assert(accounts != NULL);                                                                                     
	assert(arrSize > 0); 

	for (int i = 0; i < arrSize; i++)
	{
		if ((accounts + i)->id == id)
		{
			(accounts + id)->test = 0;
		}
	}
}

Account *searchEmptyAcc(Account **accounts, int *arrSize)
{
	int i;
	Account *mAccounts = *accounts;

	for (i = 0; i < *arrSize && (mAccounts + i)->isEmpty == false; i++);

	if (i >= *arrSize)
	{
		mAccounts = (Account *)realloc(mAccounts, (*arrSize + 1) * sizeof(Account));
		if (mAccounts)
		{
			(mAccounts + *arrSize)->id = *arrSize;                                                                 
			++*arrSize;                                                                                      
			*accounts = mAccounts;
			return (*accounts + i);
		}
		else
			return NULL;
	}
	else
		return (*accounts + i);
}

Account *searchMinValue(Account *accounts, int fieldShift, int fieldSize, int arrSize)
{
	assert(accounts != NULL);                                                                                     
	assert(arrSize > 0); 

	int index = 0;
	byte buffer[256];
	memset(buffer, 0xff, 256);
	void *min = buffer;
	
	for (int i = 0, ret = 0; i < arrSize; i++)
	{
		ret = memcmp(&(accounts + i)->isEmpty + fieldShift, min, fieldSize);
		if (ret < 0)
		{
			memcpy(min, &(accounts + i)->isEmpty + fieldShift, fieldSize);
			index = i;
		}
	}
	return (accounts + index);
}

Account *searchAcc(Account *accounts, char *acc, int arrSize)
{
	assert(accounts != NULL);                                                                                     
	assert(arrSize > 0); 

	long long a = atoll(acc);

	for (int i = 0, ret; i < arrSize; i++)
	{
		if (!(accounts + i)->isEmpty)
		{
			ret = memicmp(&(accounts + i)->test, &a, sizeof(int));
			if (ret == 0)
				return accounts + i;
		}
	}
}

void removeAcc(Account *accounts, int arrSize, int id)
{
	assert(accounts != NULL);                                                                                     
	assert(arrSize > 0);

	for (int i = 0; i < arrSize; i++)
		if ((accounts + i)->id == id)
			(accounts + i)->isEmpty = true;
}

void updateAcc(Account *accounts, int arrSize, Account *acc)
{
	assert(accounts != NULL);                                                                                     
	assert(arrSize > 0);

	for (int i = 0; i < arrSize; i++)
		if ((accounts + i)->id == acc->id)
			memcpy(accounts + i, acc, sizeof(Account));
}

void sortAccs(Account *accounts, int fieldShift, int fieldSize, int arrSize)
{
	assert(accounts != NULL);                                                                                     
	assert(arrSize > 0);   

	for (int i = 0; i < arrSize - 1; i++)      
	{
		for (int j = 0, ret = 0; j < arrSize - 1 - i; j++)
		{
			bool needSwap = false;
			ret = memcmp(&(accounts + j)->isEmpty + fieldShift, &(accounts + j + 1)->isEmpty + fieldShift, fieldSize);
			if (ret > 0)
				needSwap = true;

			if (needSwap)
			{
				Account temp;
				memcpy(&temp, accounts + j + 1, sizeof(Account));
				memcpy(accounts + j + 1, accounts + j, sizeof(Account));
				memcpy(accounts + j, &temp, sizeof(Account));
			}
		}
	}
}

int main(int argc, char **argv)
{
	int arrSize = 10;

	Account *accounts = (Account *)malloc(arrSize * sizeof(Account));

	char *acc;
	acc = "1";

	printf("Filling accounts ... ");
	fillAccs(accounts, arrSize);
	printf("Ok\n\n");
	printAccs(accounts, arrSize);

	printf("%d\n", searchAcc(accounts, acc, arrSize)->id);

	//printf("Searching empty account ... ");
	//Account *emptyAcc = searchEmptyAcc(&accounts, &arrSize);

	//if (emptyAcc == NULL)
	//{
	//	printf("Failed\n");
	//	return 1;
	//}

	//printf("Ok, new size is %d\n", arrSize);

	//emptyAcc->test = 999;
	//printAccs(accounts, arrSize);

	//printf("Updating test to %d in account with id %d ... ", 888, 0);
	//Account accToUpdate;
	//accToUpdate.id = 0;
	//accToUpdate.test = 888;
	//updateAcc(accounts, arrSize, &accToUpdate);
	//printf("Ok\n");
	//printAccs(accounts, arrSize);

	free(accounts);
}
