#ifndef _TREE_H_
#define _TREE_H_

#include"public.h"

#undef ElemType
#define ElemType char

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode*  leftChild;
	struct BinTreeNode*  rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode* root;
}BinTree;


//////////////////////////////////////////////////////////////////////
//链式队列
#define MY_PUEUE
#ifdef MY_PUEUE

typedef  struct trqueuenode
{
	BinTreeNode* base;
	struct trqueuenode *next;
}trqueuenode;

typedef  struct trqueue
{
	trqueuenode *qfront;
	trqueuenode *qrear;
}trqueue;

void trqueueInit(trqueue *psq);
void trqueueEnque(trqueue *psq, BinTreeNode* x);//入队
void trqueueDeque(trqueue *psq);//出队
struct trqueuenode* open_trnode(BinTreeNode* x);
void trqueueInit(trqueue *psq)
{
	
	psq->qfront = psq->qrear = NULL;
	
}
struct trqueuenode* open_trnode(BinTreeNode* x)
{
	trqueuenode *s = (trqueuenode*)malloc(sizeof(trqueuenode));
	assert(s != NULL);
	s->base = x;
	s->next = NULL;
	return s;
}

//入队
void trqueueEnque(trqueue *psq, BinTreeNode* x)
{
	assert(psq != NULL);
	trqueuenode *s = open_trnode(x);
	if (psq->qfront == NULL)
	{
		psq->qfront = psq->qrear = s;
	}
	else
	{
		psq->qrear->next = s;
		psq->qrear = s;
	}
}
//
//出队
void trqueueDeque(trqueue *psq)
{
	int i = 0;
	trqueuenode *p = (trqueuenode*)malloc(sizeof(trqueuenode));
	p = psq->qfront;
	psq->qfront = p->next;
	free(p);
}
//判空
bool empty(trqueue *psq)
{
	return psq->qfront ==NULL;
}
//取队头元素
BinTreeNode* trqueueTop(trqueue *psq)
{
	return psq->qfront->base;
}

#endif

////函数接口声明
void BintreeInIt(BinTree *bt);
void BinTreeCreate(BinTree* bt);
void BinTreeCreatestr(BinTree* bt,const char* s);
BinTreeNode* BinTreeCreatestr_1(const char* s, int* i);
void BinTreeCreate_1(BinTreeNode** bt);
void PreOrder(BinTree *bt);//先序遍历
void PreOrder_1(BinTreeNode* t);
void InOrder(BinTree *bt);//中序遍历
void IneOrder_1(BinTreeNode* t);
void PosOrder(BinTree *bt);//后序遍历
void PosOrder_1(BinTreeNode* t);
void LevelOrder(BinTree *bt);//层次遍历
void  LevelOrder_1(BinTreeNode* t);
void Wrapprint(BinTree *bt);//换行打印
void _Wrapprint(BinTreeNode *t);

////求二叉树的节点个数及高度
int BinTreeCount(BinTree *bt);
int BinTreeCount_1(BinTreeNode *t);
////求二叉树的高度
int BinTreeHeight(BinTree *bt);
int BinTreeHeight_1(BinTreeNode *t);

void  LevelOrder_1(BinTreeNode* t);
////查询
BinTreeNode* BinTreeFind(BinTree *bt,ElemType x);
BinTreeNode* BinTreeFind_1(BinTreeNode *t, ElemType x);
//查询父节点
BinTreeNode* BinTreeParent(BinTree *bt, ElemType x);
BinTreeNode* BinTreeParent_1(BinTreeNode *t, ElemType x);
////拷贝
BinTreeNode* BinTreeCopy(BinTree *bt1, BinTree *bt2);
BinTreeNode* _BinTreeCopy(BinTreeNode *t);

////判断是否相同
bool BinTreeEqual(BinTree *bt1, BinTree *bt2);
bool _BinTreeEqual(BinTreeNode *t1, BinTreeNode *t2);

////摧毁二叉树
void BinTreeDestroy(BinTree *bt);
void _BinTreeDestroy(BinTreeNode *t);




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////函数接口实现
void BinTreeInIt(BinTree *bt)
{
	bt->root = NULL;
}
void BinTreeCreate(BinTree* bt)
{
	BinTreeCreate_1(&bt->root);
}
void BinTreeCreate_1(BinTreeNode** t)
{
	ElemType bt;
	scanf("%c",&bt);
	if (bt == '#')
	{
		*t = NULL; 
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t!=NULL);
		(*t)->data = bt;
		BinTreeCreate_1(&(*t)->leftChild);
		BinTreeCreate_1(&(*t)->rightChild);
	}
	

}

void BinTreeCreatestr(BinTree* bt, const char* s)
{
	int i = 0;
	bt->root = BinTreeCreatestr_1(s,&i);
}
BinTreeNode* BinTreeCreatestr_1(const char* s,int *p)
{
	if (s[*p] == '#' || s[*p] == '\0')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		t->data = s[*p];
		(*p)++;
		t->leftChild = BinTreeCreatestr_1(s, p);
		(*p)++;
		t->rightChild = BinTreeCreatestr_1(s, p);
		return t;
	}
}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//递归遍历

//先序遍历

//void PreOrder(BinTree *bt)
//{
//	PreOrder_1(bt->root);
//}
//void PreOrder_1(BinTreeNode* t)
//{
//	if (t != NULL)
//	{
//		printf("%c ", t->data);
//		PreOrder_1(t->leftChild);
//		PreOrder_1(t->rightChild);
//	}
//	
//}

//中序遍历

//void InOrder(BinTree *bt)
//{
//	IneOrder_1(bt->root);
//}
//void IneOrder_1(BinTreeNode* t)
//{
//	if (t != NULL)
//	{
//		IneOrder_1(t->leftChild);
//		printf("%c ", t->data);
//		IneOrder_1(t->rightChild);
//	}
//}

//后序遍历

//void PosOrder(BinTree *bt)
//{
//	PosOrder_1(bt->root);
//}
//void PosOrder_1(BinTreeNode* t)
//{
//	if (t != NULL)
//	{
//		PosOrder_1(t->leftChild);
//		PosOrder_1(t->rightChild);
//		printf("%c ", t->data);
//	}
//}

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//非递归遍历

//先序遍历
void PreOrder(BinTree *bt)
{
	PreOrder_1(bt->root);
}
void PreOrder_1(BinTreeNode* t)
{
	if (t != NULL)
	{
		std::stack<BinTreeNode*> st;
		st.push(t);
		while (!st.empty())
		{
			BinTreeNode* top = st.top();
			st.pop();
			cout << top->data << " ";
			if (top->rightChild)
			{
				st.push(top->rightChild);
			}
			if(top->leftChild)
			{
				st.push(top->leftChild);
			}
		}
	}
}

//中序遍历
void InOrder(BinTree *bt)
{
	IneOrder_1(bt->root);
}
void IneOrder_1(BinTreeNode* t)
{
	if (t != NULL)
	{
		std::stack<BinTreeNode*> st;
		BinTreeNode* cur = t;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->leftChild;
			}
			BinTreeNode* top = st.top();
			st.pop();
			cout << top->data<<" ";

			cur = top->rightChild;
		}
	}
}

//后序遍历
void PosOrder(BinTree *bt)
{
	PosOrder_1(bt->root);
}
void PosOrder_1(BinTreeNode* t)
{
	
	if (t != NULL)
	{
		
		std::stack<BinTreeNode*> st;
		BinTreeNode* cur = t;
		BinTreeNode* prev = nullptr;//指向当前节点的前驱节点
		while (cur || !st.empty())
		{
			while(cur)
			{
				st.push(cur);
				cur = cur->leftChild;
			}

			BinTreeNode* top = st.top();
			if (top->rightChild == nullptr||top->rightChild == prev)
			{
				cout << top->data << " ";
				prev = top;
				st.pop();
			}
			else
			{
				cur = top->rightChild;
			}

		}
	}
}






//层次遍历
void LevelOrder(BinTree *bt)
{
	LevelOrder_1(bt->root);
}
void  LevelOrder_1(BinTreeNode* t)
{
	if (t != NULL)
	{
		trqueue q;
		trqueueInit(&q);
		trqueueEnque(&q,t);
		while (!empty(&q))
		{
			BinTreeNode *p = trqueueTop(&q);
			trqueueDeque(&q);
			printf("%c ",p->data);
			if (p->leftChild!=NULL)
				trqueueEnque(&q, p->leftChild);
			if (p->rightChild != NULL)
				trqueueEnque(&q, p->rightChild);
		}

	}
}

//换行打印
void Wrapprint(BinTree *bt)
{
	_Wrapprint(bt->root);
}
void _Wrapprint(BinTreeNode *t)
{
	if (t != NULL)
	{
		int count_next = 0;
		int count_self = 1;
		trqueue q;
		trqueueInit(&q);
		trqueueEnque(&q, t);
		while (!empty(&q))
		{
			BinTreeNode *p = trqueueTop(&q);
			trqueueDeque(&q);
			if (p->leftChild != NULL)
			{
				count_next++;
				trqueueEnque(&q, p->leftChild);
			}
				
			if (p->rightChild != NULL)
			{
				count_next++;
				trqueueEnque(&q, p->rightChild);
			}
				
			printf("%c ", p->data);
			--count_self;
			if (count_self == 0)
			{
				printf("\n");
				count_self = count_next;
				count_next = 0;
			}
		}
	}
}


////求二叉树的节点个数
int BinTreeCount(BinTree *bt)
{
	return BinTreeCount_1(bt->root);
}
int BinTreeCount_1(BinTreeNode *t)
{
	if (NULL == t)
		return 0;
	else
	{
		return BinTreeCount_1(t->leftChild) + BinTreeCount_1(t->rightChild)+1;
	}
}

////求二叉树的高度
int BinTreeHeight(BinTree *bt)
{
	return BinTreeHeight_1(bt->root);
}
int BinTreeHeight_1(BinTreeNode *t)
{
	if (NULL == t)
	{
		return 0;
	}
	else
	{
		int a = BinTreeHeight_1(t->leftChild);
		int b = BinTreeHeight_1(t->rightChild);
		return (a > b ? a : b) + 1;
	}
}

////查询
BinTreeNode* BinTreeFind(BinTree *bt, ElemType x)
{
	return  BinTreeFind_1(bt->root,x);
}
BinTreeNode* BinTreeFind_1(BinTreeNode *t, ElemType x)
{
	if (NULL == t||x==t->data)
		return t;
	else
	{
		BinTreeNode* p=BinTreeFind_1(t->leftChild,x);
		if (NULL != p)
			return p;
		else
		return BinTreeFind_1(t->rightChild, x);
	}
	
}
////查询父节点
BinTreeNode* BinTreeParent(BinTree *bt, ElemType x)
{
	return  BinTreeParent_1(bt->root, x);
}
BinTreeNode* BinTreeParent_1(BinTreeNode *t, ElemType x)
{
	BinTreeNode* p;
	if (NULL == t || x == t->data)
		return NULL;
    if ((t->leftChild != NULL && x == t->leftChild->data) ||( t->rightChild != NULL && x == t->rightChild->data))
		return t;
	p = BinTreeParent_1(t->leftChild, x);
	if (p != NULL)
		return p;
	return  BinTreeParent_1(t->rightChild, x);
}

////拷贝
BinTreeNode* BinTreeCopy(BinTree *bt1, BinTree *bt2)
{
	return bt2->root = _BinTreeCopy(bt1->root);
}
BinTreeNode* _BinTreeCopy(BinTreeNode *t)
{
	if (NULL == t)
		return NULL;
	else
	{
		BinTreeNode* tmp = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(tmp!=NULL);
		tmp->data = t->data;
		tmp->leftChild = _BinTreeCopy(t->leftChild);
		tmp->rightChild= _BinTreeCopy(t->rightChild);
		return tmp;
	}
}

////判断是否相同
bool BinTreeEqual(BinTree *bt1, BinTree *bt2)
{
	return  _BinTreeEqual(bt1->root,bt2->root);
}
bool _BinTreeEqual(BinTreeNode *t1, BinTreeNode *t2)
{
	if (NULL == t1 && NULL == t2)
		return true;
	if (t2 == NULL || t1 == NULL)
		return false;
	if (t1->data == t2->data
		&&_BinTreeEqual(t1->leftChild, t2->leftChild)
		&& _BinTreeEqual(t1->rightChild, t2->rightChild)
		)
		return true;
	else
		return false;
}

////摧毁二叉树
void BinTreeDestroy(BinTree *bt)
{
	_BinTreeDestroy(bt->root);
}

void _BinTreeDestroy(BinTreeNode *t)
{
	if (t == nullptr)
		return;
	_BinTreeDestroy(t->leftChild);
	_BinTreeDestroy(t->rightChild);

	free(t);

}










#endif /* _TREE_H_*/