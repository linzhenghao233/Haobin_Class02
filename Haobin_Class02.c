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
bool append_arr(struct Arr* pArr);	//追加
bool insert_arr();
bool delete_arr();
int get();
bool is_empty(struct Arr* pArr);
bool is_full(struct Arr* pArr);
void sort_arr();
void show_arr(struct Arr* pArr);
void inversion_arr();		//倒置

int main(void) {
	struct Arr arr;

	init_arr(&arr, 6);
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

bool append_arr(struct Arr* pArr) {

}
