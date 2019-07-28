#include <stdio.h>

/*
���Ա���ʽ�洢�ṹ
������
*/

typedef int DataType; // ����Ԫ������

// ������Ľṹ��
typedef struct node{
	DataType data; // ������Ԫ��
	struct node *next;  // ������Ԫ�غ��ָ��
}LNode, *LinkList;

// ��ʼ��
void Init(LinkList *L) {
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
	{
		printf("�ڴ����ʧ��");
		exit(-1);
	}
	(*L)->next = NULL;
}

// �жϴ�ͷ���ĵ������Ƿ�Ϊ��
int Empty(LinkList L) {
	if (L->next == NULL)
		return 1;
	else
		return 0;
}

// ��������
void Length(LinkList L, int *len) {
	LNode *p = L->next;
	int k = 0;
	while (p != NULL) {
		k++;
		p = p->next;
	}

	*len = k;
}

// ������Ų���Ԫ��
LNode * Locate_i(LinkList L, int i) {
	LNode *p = L;
	int k = 0;
	while (p->next != NULL && k<i) {
		k++;
		p = p->next;
	}

	if (k == i)
		return p;
	else
		return NULL;
}

// ����ֵ����Ԫ��
LNode * Locate_x(LinkList L, DataType x, int *k) {
	LNode *p = L->next;
	int j = 1;

	while (p != NULL && p->data != x) {
		j++;
		p = p->next;
	}

	if (p != NULL && p->data == x) {
		*k = j;
		return p;;
	}
	else
	{
		*k = -1;
		return NULL;
	}
}

// ����Ԫ��
// step1 �ж�i��λ�ò���Խ��
// step2 �ҵ�i-1�Ľ��
// step3 ����node���
// step4 ��ʼ�����㵽������
void Insert(LinkList L, int i, DataType x) {
	
	int length = 0;
	Length(L, &length);
	if (i < 1 || i > length + 1)
	{
		printf("����λ�ô���");
		return;
	}

	LNode *lNode;
	if ((i - 1) == 0) {
		lNode = L;
	}else{
		lNode = Locate_i(L, i - 1);
	}
	
	LNode *node = (LNode *)malloc(sizeof(LNode));
	if (node == NULL) {
		printf("�����ڴ�ʧ��");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;

	LNode *rNode = lNode->next;
	lNode->next = node;
	node->next = rNode;
}

// ɾ��Ԫ��
void LinkDelete(LinkList L, int i, DataType *x) {
	
	int ret = Empty(L);
	if (ret == 1) {
		printf("������Ϊ��");
		return;
	}

	int length = 0;
	Length(L, &length);
	if (i < 1 || i>length) {
		printf("λ�ô�����ɾ��");
		return;
	}

	LNode *rNode = Locate_i(L, i - 1);
	LNode *node = rNode->next;
	LNode *lNode = node->next;
	rNode->next = lNode;

	*x = node->data;
	free(node);
	node = NULL;
}

// ���������
void Display(LinkList L) {
	LNode *p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\r\n");
}

int main() {
	
	LinkList L;
	Init(&L);
	printf("�������ʼ���ɹ�\r\n");

	int ret = Empty(L);
	if (ret == 1) {
		printf("������Ϊ��\r\n");
	}

	Insert(L, 1, 11);
	Insert(L, 2, 22);
	Insert(L, 1, 33);

	Display(L);

	int k = 0;
	DataType value = 11;
	LNode * findNode = Locate_x(L, value, &k);
	if (findNode != NULL) {
		printf("ֵ%d���ڱ��е�������%d\r\n", value, k);
	}

	DataType deleteNode;
	LinkDelete(L, k, &deleteNode);
	printf("ɾ������%d,ֵΪ%d\r\n", k, deleteNode);

	Display(L);

	getchar();
	return 0;
}