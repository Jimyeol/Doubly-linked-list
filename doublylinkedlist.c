#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef struct DlistNode {
	int data;
	struct DlistNode *llink;
	struct DlistNode *rlink;

} DlistNode;

void init( DlistNode* pHead);
void dinsert_node( DlistNode* before, int data);
void display(DlistNode *pHead);
void remove_link(DlistNode *pHead_Node, DlistNode *remove);
void down_nember(DlistNode *pHead);
void up_nember(DlistNode *pHead);

int main()
{
	DlistNode pHead_Node;
	int n = 0;

	init(&pHead_Node);

	for( ;; )
	{
		printf(" 입력(-1은 종료) : ");
		scanf("%d", &n);
		
		if( n == -1 )
			break;

		dinsert_node( &pHead_Node, n);
	}
	display(&pHead_Node);

	printf("\n 오름차순 \n");
	up_nember(&pHead_Node);
	display(&pHead_Node);

	printf("\n 내림차순 \n");
	down_nember(&pHead_Node);
	display(&pHead_Node);


	return 0;
}

void init( DlistNode* pHead)
{
	pHead->llink = pHead;
	pHead->rlink = pHead;
}

void dinsert_node( DlistNode* before, int data)
{
	DlistNode *new_node = NULL;

	if( new_node == NULL)
	{
		new_node = (DlistNode*)malloc(sizeof(DlistNode));
		new_node->data = data;
	}

	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
	
}

void display(DlistNode *pHead)
{
	DlistNode *p;
	for( p = pHead->rlink; p != pHead; p = p->rlink )
	{
		printf(" %x %d %x \n", p->llink, p->data, p->rlink );
	}
}

void remove_link(DlistNode *pHead_Node, DlistNode *remove)
{
	if ( remove == pHead_Node ) return;
	remove->llink->rlink = remove->rlink;
	remove->rlink->llink = remove->llink;
	free(remove);
}
void up_nember(DlistNode *pHead) 
{

	DlistNode* temphead = NULL; 
	DlistNode* temp = NULL;
	int n;

	for(temphead = pHead->rlink; temphead != pHead; temphead = temphead->rlink)
	{
		for(temp = temphead->rlink; temp != pHead; temp = temp->rlink)
		{
			if(temphead->data < temp->data)
			{
				n = temp->data;
				temp->data = temphead->data;
				temphead->data = n;
			}
		}
	}
}
void down_nember(DlistNode *pHead) 
{

	DlistNode* temphead = NULL;
	DlistNode* temp = NULL;
	int n;

	for(temphead = pHead->rlink; temphead != pHead; temphead = temphead->rlink)
	{
		for(temp = temphead->rlink; temp != pHead; temp = temp->rlink)
		{
			if(temphead->data > temp->data)
			{
				n = temp->data;
				temp->data = temphead->data;
				temphead->data = n;
			}
		}
	}
}