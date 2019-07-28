#include <stdio.h>

#define MAXSIZE 20

// 线性表顺序存储结构
typedef int ElemType;
typedef struct {
	ElemType *data;
	int length;
}SeqList;

// 初始化顺序表
void init(SeqList *L, int n) {
	L->data = (ElemType *)malloc(n * sizeof(ElemType));
	if (L->data == NULL) {
		printf("\n 内存分配失败");
		exit(-1);
	}
	L->length = 0;
}

// 在i位置插入x，成功返回1，失败返回-1
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

// 删除元素
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

// 查找元素  从1开始
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

// 表长度
int length(SeqList *L, int *length) {
	*length = L->length;
}

// 打印表
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
//		printf("元素%d,在表中的位置是:%d\r\n", value, index);
//	}
//	else {
//		printf("元素%d,在表中不存在\r\n", value);
//	}
//
//	ElemType e;
//	Delete(&L, 2, &e);
//	display(&L);
//	printf("被删除的值为:%d", e);
//
//	getchar();
//	return 0;
//}