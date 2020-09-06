#include <iostream>
#include <string>
using namespace std;
struct Node //описание узла списка
{
	string data; //информационное поле
	Node* next; //указатель на следующий элемент
};
struct Queue //описание очереди
{
	int size; //счетчик размера очереди
	Node* first; //указатель на начало очереди
	Node* last; //указатель на конец очереди
};
void Creation(Queue* Q) //создание очереди
{
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
	Q->size = 0;
}
bool IsEmpty(Queue* Q) //проверка очереди на пустоту
{
	if (Q->first == Q->last) return true;
	else return false;
}
string Top(Queue* Q) //вывод начального элемента
{
	return Q->first->next->data;
}
void Add(Queue* Q) //добавление элемента
{
	string value;
	cout << "\nЗначение > "; cin >> value;
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = value; //добавление элемента в конец
	Q->last->next = NULL; //обнуление указателя на следующий элемент
	Q->size++;
	cout << "\nЭлемент добавлен\n\n";
}
void Delete(Queue* Q) //удаление элемента
{
	Q->first = Q->first->next; //смещение указателя
	Q->size--;
	cout << "\nЭлемент удален\n\n";
}
void main() //главная функция
{
	setlocale(LC_ALL, "Rus");
	Queue Q;
	Creation(&Q);
	char number;
	do
	{
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Вывести верхний элемент" << endl;
		cout << "4. Узнать, пуста ли очередь" << endl;
		cout << "0. Выйти\n\n";
		cout << "Номер команды > "; cin >> number;
		switch (number)
		{
		case '1': Add(&Q);
			break;
			//-----------------------------------------------
		case '2':
			if (IsEmpty(&Q)) cout << endl << "Очередь пуста\n\n";
			else Delete(&Q);
			break;
			//-----------------------------------------------
		case '3':
			if (IsEmpty(&Q)) cout << endl << "Очередь пуста\n\n";
			else { cout << "\nНачальный элемент: " << Top(&Q) << "\n\n"; }
			break;
			//-----------------------------------------------
		case '4':
			if (IsEmpty(&Q)) cout << endl << "Очередь пуста\n\n";
			else cout << "\nОчередь не пуста" << "\n\n";
			break;
			//-----------------------------------------------
		case '0': break;
		default: cout << endl << "Команда не определена\n\n";
			break;
		}
	} while (number != '0');
	system("pause");
}