#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	node(int Data) : data(Data), next(0) {}
} Node;

typedef struct queue
{
	Node *first;
	Node *last;
	queue(Node *F, Node *L) : first(F), last(L) {}
} Queue;

int empty(Queue *q)
{
	if (q->first)
		return (0);
	else
		return (1);
}

void push(Queue *q, int data)
{
	Node *node = new Node(data);
	if (empty(q))
	{
		q->first = node;
		q->last = node;
	}
	else
	{
		q->last->next = node;
		q->last = node;
	}
}

int pop(Queue *q)
{
	if (empty(q))
		return (-1);

	Node *node = q->first;
	int data = node->data;
	q->first = q->first->next;
	delete (node);
	return (data);
}

int size(Queue *q)
{
	Node *tmp = q->first;
	int size = 0;

	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

int front(Queue *q)
{
	if (empty(q))
		return (-1);
	return (q->first->data);
}

int back(Queue *q)
{
	if (empty(q))
		return (-1);
	return (q->last->data);
}

int main()
{
	int N;
	Queue q(0, 0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int i;
			cin >> i;
			push(&q, i);
		}
		else if (s == "pop")
		{
			cout << pop(&q) << '\n';
		}
		else if (s == "size")
		{
			cout << size(&q) << '\n';
		}
		else if (s == "empty")
		{
			cout << empty(&q) << '\n';
		}
		else if (s == "front")
		{
			cout << front(&q) << '\n';
		}
		else if (s == "back")
		{
			cout << back(&q) << '\n';
		}
	}
}