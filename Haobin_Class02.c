#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//������һ���������ͣ����������͵����ֽ���struct Arr��
//���������ͺ���������Ա���ֱ���pBase��len��cnt
struct Arr {
	int* pBase;	//�洢��������ĵ�һ��Ԫ�صĵ�ַ
	int len;			//�����������ɵ����Ԫ�صĸ���
	int cnt;			//��ǰ������ЧԪ�صĸ���
};

void init_arr(struct Arr* pArr, int len);
bool append_arr(struct Arr* pArr);	//׷��
bool insert_arr();
bool delete_arr();
int get();
bool is_empty(struct Arr* pArr);
bool is_full(struct Arr* pArr);
void sort_arr();
void show_arr(struct Arr* pArr);
void inversion_arr();		//����

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
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);	//��ֹ��������
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
		printf("����Ϊ�գ�\n");
	else {
		for (int i = 0; i < pArr->cnt; i++)
			printf("%d ", pArr->pBase[i]);
		printf("\n");
	}
}

bool append_arr(struct Arr* pArr) {

}
