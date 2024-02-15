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
bool append_arr(struct Arr* pArr, int val);	//׷��
bool insert_arr(struct Arr* pArr, int pos, int val);	//posֵ��1��ʼ
bool delete_arr(struct Arr* pArr, int pos, int* pVal);
int get();
bool is_empty(struct Arr* pArr);
bool is_full(struct Arr* pArr);
void sort_arr(struct Arr* pArr);
void show_arr(struct Arr* pArr);
void inversion_arr(struct Arr* pArr);		//����

int main(void) {
	struct Arr arr;
	int val;

	init_arr(&arr, 6);
	show_arr(&arr);
	append_arr(&arr, 1);
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	if (delete_arr(&arr, 5, &val)) {
		printf("ɾ���ɹ���\n");
		printf("��ɾ����Ԫ���ǣ�%d\n", val);
	}

	//append_arr(&arr, 2);
	//append_arr(&arr, 3);
	//append_arr(&arr, 4);
	//append_arr(&arr, 5);
	//insert_arr(&arr, 7, 99);

	//append_arr(&arr, 6);
	//if (append_arr(&arr, 7))
	//	printf("׷��ʧ�ܣ�\n");

	show_arr(&arr);
	inversion_arr(&arr);
	show_arr(&arr);
	sort_arr(&arr);
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

bool append_arr(struct Arr* pArr, int val) {
	if (is_full(pArr))
		return false;

	pArr->pBase[pArr->cnt++] = val;

	return true;
}

bool insert_arr(struct Arr* pArr, int pos, int val) {
	if (is_full(pArr)) {
		printf("����ʧ�ܣ�����������\n");
		return false;
	}
	if (pos - 1 < 0 || pos > pArr->cnt + 1) {
		printf("����ʧ�ܣ�����λ����Ч��\n");
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
		printf("����Ϊ�գ�\n");
		return false;
	}
	if (pos - 1 < 0 || pos > pArr->cnt) {
		printf("��Чλ�ã�\n");
		return false;
	}

	*pVal = pArr->pBase[pos - 1];
	for (int i = pos; i <= pArr->cnt; i++)
		pArr->pBase[i - 1] = pArr->pBase[i];
	pArr->cnt--;

	return true;
}

void inversion_arr(struct Arr* pArr) {
	int i = 0;
	int j = pArr->cnt - 1;
	int temp;

	while (i < j) {
		temp = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = temp;
		i++;
		j--;
	}
}

void sort_arr(struct Arr* pArr) {
	for (int i = 0; i < pArr->cnt; i++) {
		for (int j = i + 1; j < pArr->cnt; j++) {
			if (pArr->pBase[i] > pArr->pBase[j]) {
				int temp = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = temp;
			}
		}
	}
}
