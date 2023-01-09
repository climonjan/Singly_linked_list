#include <iostream>

using namespace std;

template<typename T>
class My_List
{
public:
	My_List();

	~My_List();

	void Push_Back(T data);

	int GetSize() { return size; }

	T& operator[](const int index);

	void Pop_Front();

	void Clear();

	void Push_Front(T data);

	void Insert(T value, int index);

	void RemoveAt(int index);

	void Pop_Back();

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;

		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;

			this->pNext = pNext;
		}
	};

	Node<T>* head;

	int size;
};

template<typename T>
My_List<T>::My_List()
{
	size = 0;

	head = nullptr;
}

template<typename T>
My_List<T>::~My_List()
{
	Clear();
}

template<typename T>
void My_List<T>::Push_Back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}

		current->pNext = new Node<T>(data);
	}

	size++;
}

template<typename T>
T& My_List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}

		current = current->pNext;

		counter++;
	}
}

template<typename T>
void My_List<T>::Pop_Front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	size--;
}

template<typename T>
void My_List<T>::Clear()
{
	while (size)
	{
		Pop_Front();
	}
}

template<typename T>
void My_List<T>::Push_Front(T data)
{
	head = new Node<T>(data, head);

	size++;
}

template<typename T>
void My_List<T>::Insert(T value, int index)
{
	if (index == 0)
	{
		Push_Front(value);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(value, previous->pNext);

		previous->pNext = newNode;

		size++;
	}
}

template<typename T>
void My_List<T>::RemoveAt(int index)
{
	if (index == 0)
	{
		Pop_Front();
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		size--;
	}
}

template<typename T>
void My_List<T>::Pop_Back()
{
	RemoveAt(size - 1);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	return 0;
}