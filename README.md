DOUBLY-LINKED-LIST
===
### Date: 2014-04~
#### university programming assignments.
-------------
이번에 구현한 자료구조는 이중연결리스트입니다. 이중연결리스트는 단순연결리스트를 심화한 리스트입니다. 각 노드들의 양쪽들은 서로 이어져있는 구조를 말합니다. 장점은 2각각 노드마다 2개의 링크가 있기 때문에 특정 노드의 다음 노드뿐 아니라 이전 노드에도 직접 접근할 수 있습니다. 
이중 연결리스트 노드의 구조를 그림으로 그리면 
이런 노드의 형식을 가지고 있습니다.

## 구조체 선언
<pre><code>typedef struct DlistNode {
	int data;
	struct DlistNode *llink;
	struct DlistNode *rlink;

} DlistNode;
</pre></code>
이중연결리스트를 하기 위해서 먼저 구조체에 들어갈 자료형 int로 값을 넣었고 양쪽을 이어주기 위해서 link 포인터와 rlink포인터를 선언 하였습니다.

## 초기화함수
<pre><code>void init( DlistNode* pHead)
{
	pHead->llink = pHead;
	pHead->rlink = pHead;
}</pre></code>
선언된 이중연결리스트 구조체에 초기화를 해줍니다. 아직 노드가 한 개밖에 선언이 안 되였기에 왼쪽 링크와 오른쪽 링크를 자기 자신에게 연결해줍니다.

## 삽입 함수
<pre><code>void dinsert_node( DlistNode* before, int data)
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
	
}</pre></code>
먼저 이중연결리스트와 자료의 인자값을 받습니다. 
그리고 new_node라는 새로 집어넣을 노드를 생성하고 그 노드에
자료들을 넣고 리스트에 삽입을 합니다. 삽입의 순서를 그림으로 그리면

- 첫 번째 new_node->llink = before;
- 두 번째 new_node->rlink = before->rlink;
- 세 번째 before->rlink->llink = new_node;
- 네 번째 before->rlink = new_node;
전에 있던 각 노드의 연결들을 끊고 새로운 노드들의 연결을 이어줍니다.

## 삭제 함수
<pre><code>void remove_link(DlistNode *pHead_Node, DlistNode *remove)
{
	if ( remove == pHead_Node ) return;
	remove->llink->rlink = remove->rlink;
	remove->rlink->llink = remove->llink;
	free(remove);
}</pre></code>
삭제 함수는 삭제할 함수의 링크를 끊고 그 다음 링크로 연결을 해줍니다.

## 디스플레이 함수
<pre><code>void display(DlistNode *pHead)
{
	DlistNode *p;
	for( p = pHead->rlink; p != pHead; p = p->rlink )
	{
		printf(" %x %d %x \n", p->llink, p->data, p->rlink );
	}
}</pre></code>
디스플레이 함수는 각 노드의 번지수와 자료들을 보여줍니다. 이때 for문으로
반복을 하는데 먼저 구조체 포인터 p를 만들고 그 p에다가 pHead의 다음번 링크를 넣어줍니다. 그런후 그 p가 pHead와 똑같을때까지 반복을 하여줍니다. 연산문에는 p = p->rlink를 하여 계속 다음 링크로 이동을 합니다. 
만약 p가 pHead를 만난다면 반복문은 빠져 나오게 됩니다.

## 오름차순 내림차순 함수
<pre><code>void up_nember(DlistNode *pHead) 
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
}</pre></code>
오름차순 함수는 선택정렬을 이용하였습니다. 먼저 for문으로 비교할 노드를 선택하고 그 노드로 다시 포문을 돌아서 모든 노드들과 비교를 합니다. 선택된 노드가 크면 오름차순 작으면 내림차순입니다. 만약 크다면 swap을 이용해서 서로 교환을 하게 됩니다. temphead->data가 temphead에 다음번째인 수부터 계속 검사를 하게 됩니다. 그림으로 그리면 
수가 다 끝날때까지 비교하게되고 비교가 다 되면 함수를 빠져 나오게 됩니다.
