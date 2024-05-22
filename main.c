#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef  int  QDataType;

//定义队列节点结构
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;


//定义队列结构
typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;


//创建队列并初始化
Queue* createQueue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}


//入队列
void enqueue(Queue* queue, QDataType data)
{
	QueueNode* newNode = (QueueNode *)malloc(sizeof(QueueNode));
	newNode->data = data;
	newNode->next = NULL;
	if (queue->front == NULL)
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}

}

//出队列
QDataType dequeue(Queue* queue)
{
	if (queue->front == NULL)
	{
		return NULL;
	}
	QueueNode* temp = queue->front;
	QDataType data = temp->data;
	queue->front = queue->front->next;
	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}
	free(temp);

	return data;
}


//判断队列是否为空
bool isQueueEmpty(Queue* queue)
{
	return queue->front == NULL;
}



//销毁队列
void destroyQueue(Queue* queue)
{
	while (!isQueueEmpty(queue))
	{
		dequeue(queue);
	}
	free(queue);
}



int main() {
	Queue* queue = createQueue();

	// 示例：将整数加入队列
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);

	// 出队并打印数据
	while (!isQueueEmpty(queue)) {
		QDataType data = dequeue(queue);
		printf("%d ",data);
	}
	printf("\n");

	destroyQueue(queue);

	return 0;
}
