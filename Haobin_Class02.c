#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//定义了一个数据类型，该数据类型的名字叫做struct Arr，
//该数据类型含有三个成员，分别是pBase，len，cnt
struct Arr {
	int* pBase;	//存储的是数组的第一个元素的地址
	int len;			//数组所能容纳的最大元素的个数
	int cnt;			//当前数组有效元素的个数
};

void init_arr(struct Arr* pArr, int len);
bool append_arr(struct Arr* pArr, int val);	//追加
bool insert_arr(struct Arr* pArr, int pos, int val);	//pos值从1开始
bool delete_arr(struct Arr* pArr, int pos, int* pVal);
int get();
bool is_empty(struct Arr* pArr);
bool is_full(struct Arr* pArr);
void sort_arr();
void show_arr(struct Arr* pArr);
void inversion_arr();		//倒置

int main(void) {
	struct Arr arr;
	int val;

	init_arr(&arr, 6);
	show_arr(&arr);
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	if (delete_arr(&arr, 1, &val)) {
		printf("删除成功！\n");
		printf("您删除的元素是：%d\n", val);
	}

	//append_arr(&arr, 2);
	//append_arr(&arr, 3);
	//append_arr(&arr, 4);
	//append_arr(&arr, 5);
	//insert_arr(&arr, 7, 99);

	//append_arr(&arr, 6);
	//if (append_arr(&arr, 7))
	//	printf("追加失败！\n");
	show_arr(&arr);
	//printf("%d\n", arr.len);

	return 0;
}

void init_arr(struct Arr* pArr, int len) {
	pArr->pBase = (int*)malloc(sizeof(int) * len);
	if (pArr->pBase == NULL) {
		printf("动态内存分配失败！\n");
		exit(-1);	//终止整个程序
	}
	else {
		pArr->len = len;
		pArr->cnt = 0;
	}
	return;
}

bool is_empty(struct Arr* pArr) {
	if (pArr->cnt== 0)
		return true;
	else
		return false;
}

bool is_full(struct Arr* pArr) {
	if (pArr->cnt > pArr->len)
		return true;
	else
		return false;
}

void show_arr(struct Arr* pArr) {
	if (is_empty(pArr) == true)
		printf("数组为空！\n");
	else {
		for (int i = 0; i < pArr->cnt; i++)
			printf("%d ", pArr->pBase[i]);
		printf("\n");
	}
}

bool append_arr(struct Arr* pArr, int val) {
	if (is_full(pArr))
		return false;

	pArr->pBase[pArr->cnt++] = val;

	return true;
}

bool insert_arr(struct Arr* pArr, int pos, int val) {
	if (is_full(pArr)) {
		printf("插入失败，数组已满！\n");
		return false;
	}
	if (pos - 1 < 0 || pos > pArr->cnt + 1) {
		printf("插入失败，插入位置无效！\n");
		return false;
	}

	for (int i = pArr->cnt - 1; i > pos - 2; i--) {
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val;
	pArr->cnt++;

	return true;
}

bool delete_arr(struct Arr* pArr, int pos, int* pVal) {
	if (is_empty(pArr)) {
		printf("数组为空！");
		return false;
	}
	if (pos - 1 < 0 || pos > pArr->cnt + 1) {
		printf("无效位置！");
		return false;
	}

	*pVal = pArr->pBase[pos - 1];
	for (int i = pos; i <= pArr->cnt; i++)
		pArr->pBase[i - 1] = pArr->pBase[i];
	pArr->cnt--;

	return true;
}
