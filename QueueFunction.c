#include"D:\VSProgram\Test\ListQueue\LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL)return;	
	Q->front = Q->rear = head;
	Q->front->next = NULL;
	printf("��ʼ���ɹ�!\n");
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
Status DestoryLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	while (Q->front!=NULL)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return TRUE;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front->next==NULL)
	{
		return TRUE;
	}
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	void* temp = Q->front->next->data;
	LPrint(temp);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q)==TRUE)return 0;
	Node* temp = Q->front;
	int count = 0;
	while (temp->next!=NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* Q, void* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)return FALSE;
	Node* temp = Q->front;

	newNode->data = data;
	newNode->next = NULL;

	if (IsEmptyLQueue(Q) == TRUE) {
		temp->next = newNode;
		Q->rear = newNode;
		return TRUE;
	}
	/*while (temp->next!=NULL)
	{
		temp = temp->next;
	}*/
	Node* behind = temp->next;
	temp->next = newNode;
	newNode->next = behind;
	Q->rear = newNode;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	Node* temp = Q->front->next;
	void* ptr = temp->data;
	LPrint(ptr);
	Q->front->next = temp->next;
	if (Q->rear = temp)Q->rear = temp;
	free(temp);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
Status ClearLQueue(LQueue* Q) {
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	Q->rear = Q->front;
	return TRUE;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	if (IsEmptyLQueue(Q) == TRUE)return FALSE;
	Node* temp = Q->front;
	while (temp->next!=NULL)
	{
		temp = temp->next;
		foo(temp->data);
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void* q) {
	char* ptr = (char*)q;
	printf("%s\n",ptr);
}

//�˵���
void menu() {
	printf("1.�ж϶����Ƿ�Ϊ��\n");
	printf("2.���\n");
	printf("3.����\n");
	printf("4.��ȡ��ͷԪ��\n");
	printf("5.��ȡ���г���\n");
	printf("6.��ն���\n");
	printf("7.���ٶ���\n");
	printf("8.��ӡ����\n");
	printf("9.�˳�\n");
}