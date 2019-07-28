#include <stdio.h>

#define MAXSIZE 20

// ���Ա�˳��洢�ṹ
typedef int ElemType;
typedef struct {
	ElemType *data;
	int length;
}SeqList;

// ��ʼ��˳���
void init(SeqList *L, int n) {
	L->data = (ElemType *)malloc(n * sizeof(ElemType));
	if (L->data == NULL) {
		printf("\n �ڴ����ʧ��");
		exit(-1);
	}
	L->length = 0;
}

// ��iλ�ò���x���ɹ�����1��ʧ�ܷ���-1
int insert(SeqList *L, int i, ElemType x) {
	if (L->length == MAXSIZE)
		return -1;
	if (i < 1 || i > L->length + 1)
		return -1;
	for (int j = L->length; j > i - 1; j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = x;
	L->length++;
	return 1;
}

// ɾ��Ԫ��
int Delete(SeqList *L, int i, ElemType *e) {
	if (L->length == 0)
		return -1;
	if (i < 1 || i > L->length)
		return -1;
	*e = L->data[i - 1];
	for (int j = i - 1; j < L->length - 1; j++) {
		L->data[j] = L->data[j + 1];
	}
	L->data[L->length - 1] = NULL;
	L->length--;
	return 1;
}

// ����Ԫ��  ��1��ʼ
void Locate(SeqList *L, ElemType x, int *index) {
	ElemType *p;
	int i = 0;
	p = L->data;
	while (i <= L->length-1 && *p != x) {
		i++;
		p++;
	}

	if (i <= L->length - 1)
		*index = i + 1;
}

// ����
int length(SeqList *L, int *length) {
	*length = L->length;
}

// ��ӡ��
void display(SeqList *L) {
	for (int i = 0; i < L->length; i++) {
		printf("%d", L->data[i]);
	}
	printf("\r\n");
}

//int main(){
//	SeqList L;
//	init(&L, MAXSIZE);
//
//	insert(&L, 1, 9);
//	insert(&L, 1, 7);
//	insert(&L, 2, 33);
//
//	display(&L);
//
//	int index = -1;
//	ElemType value = 11;
//	Locate(&L, value, &index);
//	if (index > 0) {
//		printf("Ԫ��%d,�ڱ��е�λ����:%d\r\n", value, index);
//	}
//	else {
//		printf("Ԫ��%d,�ڱ��в�����\r\n", value);
//	}
//
//	ElemType e;
//	Delete(&L, 2, &e);
//	display(&L);
//	printf("��ɾ����ֵΪ:%d", e);
//
//	getchar();
//	return 0;
//}