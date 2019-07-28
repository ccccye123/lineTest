#include <stdio.h>

/*
线性表链式存储结构
单链表
*/

typedef int DataType; // 定义元素类型

// 单链表的结构体
typedef struct node{
	DataType data; // 单链表元素
	struct node *next;  // 单链表元素后继指针
}LNode, *LinkList;

// 初始化
void Init(LinkList *L) {
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
	{
		printf("内存分配失败");
		exit(-1);
	}
	(*L)->next = NULL;
}

// 判断带头结点的单链表是否为空
int Empty(LinkList L) {
	if (L->next == NULL)
		return 1;
	else
		return 0;
}

// 单链表长度
void Length(LinkList L, int *len) {
	LNode *p = L->next;
	int k = 0;
	while (p != NULL) {
		k++;
		p = p->next;
	}

	*len = k;
}

// 根据序号查找元素
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

// 根据值查找元素
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

// 插入元素
// step1 判断i的位置不能越界
// step2 找到i-1的结点
// step3 创建node结点
// step4 开始插入结点到链表中
void Insert(LinkList L, int i, DataType x) {
	
	int length = 0;
	Length(L, &length);
	if (i < 1 || i > length + 1)
	{
		printf("插入位置错误");
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
		printf("分配内存失败");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;

	LNode *rNode = lNode->next;
	lNode->next = node;
	node->next = rNode;
}

// 删除元素
void LinkDelete(LinkList L, int i, DataType *x) {
	
	int ret = Empty(L);
	if (ret == 1) {
		printf("单链表为空");
		return;
	}

	int length = 0;
	Length(L, &length);
	if (i < 1 || i>length) {
		printf("位置错误不能删除");
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

// 输出单链表
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
	printf("单链表初始化成功\r\n");

	int ret = Empty(L);
	if (ret == 1) {
		printf("单链表为空\r\n");
	}

	Insert(L, 1, 11);
	Insert(L, 2, 22);
	Insert(L, 1, 33);

	Display(L);

	int k = 0;
	DataType value = 11;
	LNode * findNode = Locate_x(L, value, &k);
	if (findNode != NULL) {
		printf("值%d，在表中的索引是%d\r\n", value, k);
	}

	DataType deleteNode;
	LinkDelete(L, k, &deleteNode);
	printf("删除索引%d,值为%d\r\n", k, deleteNode);

	Display(L);

	getchar();
	return 0;
}