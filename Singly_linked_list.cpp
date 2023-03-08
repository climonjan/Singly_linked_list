#include <iostream>

using namespace std;

template<typename T>
class My_List
{
public:
	My_List();

	~My_List();

	void Push_Back(T data);

	void Push_Front(T data);

	int GetSize() { return size; }

	T& operator[](const int index);

	void Pop_Front();

	void Pop_Back();

	void Clear();

	void PrintElement(int index);

	void PrintList();

	void Insert(T value, int index);

	void RemoveAt(int index);

	int Find(T value);

private:
	//внутренний класс, описывающий эл-т списка
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

//конструктор класса
template<typename T>
My_List<T>::My_List()
{
	size = 0;
	head = nullptr;
}

//деструктор класса
template<typename T>
My_List<T>::~My_List()
{
	Clear();
}

//метод добавляет эл-т в конец списка
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

//перегрузка оператора квадратных скобок
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

//метод удаляет эл-т в начале списка
template<typename T>
void My_List<T>::Pop_Front()
{
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;

	size--;
}

//метод очищает список
template<typename T>
void My_List<T>::Clear()
{
	while (size)
	{
		Pop_Front();
	}
}

//метод добавляет эл-т в начало списка
template<typename T>
void My_List<T>::Push_Front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

//метод добавляет эл-т списка с определенным индексом
template<typename T>
void My_List<T>::Insert(T value, int index)
{
	if ((index > size) || index < 0)
	{
		cout << "Невозможно добавить эл-т с таким индексом!\n";

		return;
	}

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

//метод удаляет эл-т списка с определенным индексом
template<typename T>
void My_List<T>::RemoveAt(int index)
{
	if ((index >= size) || index < 0)
	{
		cout << "Нет эл-та с таким индексом!\n";

		return;
	}

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

//метод удаляет эл-т в конце списка
template<typename T>
void My_List<T>::Pop_Back()
{
	RemoveAt(size - 1);
}

//метод выводит эл-т списка с определенным индексом
template<typename T>
void My_List<T>::PrintElement(int index)
{
	if (size == 0)
	{
		cout << "Список пуст!\n";

		return;
	}

	if ((index >= size) || index < 0)
	{
		cout << "Такого эл-та в списке нет!\n";

		return;
	}

	Node<T>* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->pNext;
	}

	cout << current->data << endl;
}

//метод выводит весь список на экран
template<typename T>
void My_List<T>::PrintList()
{
	if (size == 0)
	{
		cout << "Список пуст!\n";

		return;
	}

	Node<T>* current = head;

	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->pNext;
	}

	cout << endl;
}

//метод возвращает индекс первого найденного эл-та с переданным значением
template<typename T>
int My_List<T>::Find(T value)
{
	int index = 0;
	Node<T>* current = head;

	while (current != nullptr)
	{
		if (current->data == value)
		{
			return index;
		}

		current = current->pNext;
		index++;
	}

	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//обьявление используемых в программе переменных
	My_List<int> list;
	int q = 0, value, index;

	//цикл, обеспечивающий возвращение в главное меню после каждой операции
	while (q != 7)
	{
		cout << "\nВыберите операцию с листом:\n1 - добавить эл-т\n2 - удалить эл-т";
		cout << "\n3 - вывести эл-т на экран\n4 - вывести список на экран\n5 - очистить список";
		cout << "\n6 - поиск эл-та по значению\n7 - выход из программы\nВаш выбор : "; cin >> q;

		if (q == 1)
		{
			if (list.GetSize() == 0)
			{
				cout << "\nВведите значение эл-та = "; cin >> value;

				list.Push_Front(value);
			}
			else
			{
				cout << "\nВведите значение эл-та = "; cin >> value;
				cout << "\nВведите индекс эл-та = "; cin >> index;

				list.Insert(value, index);
			}
		}

		if (q == 2)
		{
			if (list.GetSize() == 0)
			{
				list.PrintList();
			}
			else
			{
				cout << "\nВведите индекс эл-та = "; cin >> index;

				list.RemoveAt(index);
			}
		}

		if (q == 3)
		{
			if (list.GetSize() == 0)
			{
				list.PrintList();
			}
			else
			{
				cout << "\nВведите индекс эл-та = "; cin >> index;

				list.PrintElement(index);
			}
		}

		if (q == 4)
		{
			list.PrintList();
		}

		if (q == 5)
		{
			if (list.GetSize() == 0)
			{
				cout << "Список пуст!\n";
			}
			else
			{
				list.Clear();

				cout << "Список очищен!\n";
			}
		}

		if (q == 6)
		{
			if (list.GetSize() == 0)
			{
				cout << "Список пуст!\n";
			}
			else
			{
				cout << "\nВведите значение эл-та = "; cin >> value;

				index = list.Find(value);

				if (index == -1)
				{
					cout << "Такого эл-та нет!" << endl;
				}
				else
				{
					cout << "Индекс первого найденного эл-та = " << index << endl;
				}
			}
		}

		if (q == 7)
		{
			break;
		}

		if (q < 1 || q > 7)
		{
			cout << "Неправильный ввод!";
		}
	}

	return 0;
}
