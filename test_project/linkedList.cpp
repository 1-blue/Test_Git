#include <iostream>
#include <array>

using namespace std;

#define Element int

typedef struct LinkedList
{
	Element item;
	LinkedList* nextLink;
}Node;

Node* head = nullptr;
Node* ptr = nullptr;
Node* tail = nullptr;

void Print()
{
	ptr = head;
	while (ptr != tail)
	{
		cout << ptr->item << endl;
		ptr = ptr->nextLink;
	}

	cout << ptr->item << endl;		//tail출력
}

void Push(Element e)
{
	//Node* node = (Node*)malloc(sizeof(Node));
	Node* node = new Node();
	node->item = e;

	if (nullptr == head)
	{
		node->nextLink = nullptr;
		head = node;
		tail = node;
	}
	else
	{
		ptr = head;

		while (ptr != tail)
			ptr = ptr->nextLink;

		ptr->nextLink = node;
		tail = node;
	}
}

void Delete(int idx)
{
	Node* tempPtr = nullptr;

	if (1 == idx)
	{
		ptr = head->nextLink;
		delete head;
		head = ptr;
	}
	else
	{
		ptr = head;

		for (int i = 1; i < idx; i++)
		{
			if (2 == idx)			//두번째노드삭제
				tempPtr = ptr;
			else if (i == idx - 1)
				tempPtr = ptr;		//삭제할노드 전노드
				
			ptr = ptr->nextLink;

			//마지막노드삭제
			if (ptr->nextLink == nullptr)
			{
				tempPtr->nextLink = nullptr;
				tail = tempPtr;
				delete ptr;
				return;
			}
		}
			
		tempPtr->nextLink = ptr->nextLink;		//이전노드가 다다음노드가르키게
		delete ptr;
	}
}

void Insert(int idx, Element e)
{
	Node* tempPtr = nullptr;
	Node* node = new Node();
	node->item = e;
	ptr = head;

	if (idx == 1)
	{
		head = node;
		node->nextLink = ptr;
		return;
	}

	for (int i = 1; i < idx; i++)
	{
		if(idx == 2)
			tempPtr = ptr;
		if (i == idx - 1)
			tempPtr = ptr;

		ptr = ptr->nextLink;

		if (ptr->nextLink == tail && i == idx-1)
		{
			tail->nextLink = node;
			node->nextLink = nullptr;
			tail = node;
		}
	}

	tempPtr->nextLink = node;
	node->nextLink = ptr;

}

int Find(Element e)
{
	int count = 0;

	ptr = head;

	while (ptr != tail)
	{
		count++;
		if(ptr->item == e)
			return count;
		ptr = ptr->nextLink;

	}
	if (ptr->item == e)
		return ++count;

	return -1;
}

void Replace(int idx, Element e)
{
	ptr = head;

	for (int i = 1; i < idx; i++)
	{
		ptr = ptr->nextLink;
	}

	ptr->item = e;
}

int Size()
{
	ptr = head;
	int length = 0;

	while (ptr != tail)
	{
		length++;
		ptr = ptr->nextLink;
	}
	
	return ++length;
}

Element GetEntry(int idx)
{
	ptr = head;

	for (int i = 1; i < idx; i++)
	{
		ptr = ptr->nextLink;
	}

	return ptr->item;
}

int main(void)
{



	system("pause");
	return 0;
}
