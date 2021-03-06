// ConsoleApplication48.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include<fstream>
#include <string>
#include <deque>

using namespace std;

template<class T>
T vvod() {
	for (;;) {
		try {
			T n = NULL;
			if (!(cin >> n)) throw 1;
			return n;
		}
		catch (int) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка! Введено не целое число!" << endl;
		}
	}
}

template<class T>
T vvod(T i, T j) {
	for (;;) {
		try {
			T n = vvod <int>();
			if (n < i || n > j) throw 1.5;
			return n;

		}
		catch (double) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка! Число должно быть в диапозоне от " << i << " до " << j << endl;
		}
	}
}

class Products {
private:
	char Name[100];
	int Count;
	int Number;
public:
	Products() {};
	void in(char NAME[100], int COUNT, int NUMBER);
	friend ostream& operator<< (ostream &out, const Products &prod);
	bool operator <(Products &prod);
	bool operator >(Products &prod);
	void operator =(Products &prod);
	friend bool operator==(const Products &st, char* &gr);
	char* getName();
	int getCount();
	int getNumber();;
};


void Products::in(char NAME[100], int COUNT, int NUMBER)
{
	strcpy_s(this->Name, NAME);
	this->Count = COUNT;
	this->Number = NUMBER;
}
char* Products::getName()
{
	return Name;
}

int Products::getCount()
{
	return Count;
}

int Products::getNumber()
{
	return Number;
}

bool Products::operator<(Products &pr)
{
	char f[100];
	strcpy_s(f, pr.getName());
	if ((int)Name[0] < (int)f[0])
		return true;
	else return false;
}

bool Products::operator>(Products &pr)
{
	char f[100];
	strcpy_s(f, pr.getName());
	if ((int)Name[0] > (int)f[0])
		return true;
	else return false;
}

void Products::operator=(Products &pr)
{
	strcpy_s(this->Name, pr.getName());
	this->Count = pr.getCount();
	this->Number = pr.getNumber();
}

bool operator==(const Products &prod, char* &gr) {
	if (strcmp(prod.Name, gr) == 0)
		return true;
	else return false;
}

ostream& operator<< (ostream &out, const Products &prod)
{
	out << "Наименование:" << endl;
	out << prod.Name << endl;
	out << "Количество:" << endl;
	out << prod.Count << endl;
	out << "Номер цеха:" << endl;
	out << prod.Number << " ";
	return out;
}

//template <class T>
//void quickSort(int left, int right, deque<T> &itr);
//
//template <class T>
//void find(deque<T> &deq, char* group);
//
//template <class T>
//void del(deque<T> &deq, char* group);

class Algoritm
{
public:
	Algoritm();
	~Algoritm();
	template <class T>
	void quickSort(int left, int right, deque<T> &deq) {
		int l = left, r = right;
		T mid = deq[(r + l) / 2], help;
		while (l < r) {
			while (deq[l] < mid)
			{
				l++;
			}
			while (deq[r] > mid)
			{
				r--;
			}
			if (l <= r) {
				help = deq[l];
				deq[l] = deq[r];
				deq[r] = help;
				l++; r--;
			}
		}
		if (left < r)
			quickSort(left, r, deq);
		if (l < right)
			quickSort(l, right, deq);
	}
	//Алгоритм: функция нахождения первого элемента, который
	//удовлетворяет заданным критериям.
	template <class T>
	void find(deque<T> &deq, char* group) {
		deque<Products>::const_iterator itr_b = deq.begin();
		deque<Products>::const_iterator itr_e = deq.end();
		bool fl = true;
		while (itr_b != itr_e) {
			if (*itr_b == group)
			{
				cout << *itr_b << endl;
				fl = false;
				break;
			}
			itr_b++;
		}
		if (fl) throw 1;
	}
	//Алгоритм: функция, которая удаляет элементы,
	//удовлетворяющие условию.
	template <class T>
	void del(deque<T> &deq, char* group) {
		deque<Products>::iterator itr_b = deq.begin();
		deque<Products>::iterator itr;

		bool fl = true;
		while (itr_b != deq.end()) {
			if (*itr_b == group)
			{
				for (itr = itr_b; itr != deq.end() - 1; itr++) {
					*itr = *(itr + 1);
				}
				deq.pop_back();
			}
			itr_b++;
		}
	}

};

Algoritm::Algoritm()
{
}

Algoritm::~Algoritm()
{
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество Продукции:" << endl;
	int n = vvod<int>();
	deque<Products> deq;
	Products prod;
	char Name[100];
	int Count;
	int Number;
	Algoritm al;
	for (int i = 0; i < n; i++) {
		cout << "Введите наименование: " << endl;
		cin.ignore();
		cin.getline(Name, 100);
		cout << "Введите количество: " << endl;
		Count = vvod<int>();
		cout << "Введите номер цеха: " << endl;
		Number = vvod<int>();
		prod.in(Name, Count, Number);
		deq.push_back(prod);
	}
	int ch = 0;
	while (ch != 7)
	{
		cout << "1. Вывести список продукции" << endl;
		cout << "2. Вывести список продукции в обратном порядке" << endl;
		cout << "3. Сортировать список продукции" << endl;
		cout << "4. Просмотреть информацию о продукции" << endl;
		cout << "5. Найти продукцию" << endl;
		cout << "6. Удалить продукцию" << endl;
		cout << "7. Выход" << endl;
		cout << "Выбор меню:" << endl;
		ch = vvod<int>(1, 7);
		switch (ch)
		{
		case 1:
		{
			deque<Products>::const_iterator pt;
			if (deq.empty()) {
				cout << "Список пуст" << endl;
			}
			cout << "Количество продукции: " << deq.size() << endl;
			for (pt = deq.begin(); pt != deq.end(); pt++)
				cout << *pt << endl;
		}
		break;
		case 2:
		{
			deque<Products>::reverse_iterator pt;
			if (deq.empty()) {
				cout << "Список пуст" << endl;
			}
			cout << "Количество продукции: " << deq.size() << endl;
			for (pt = deq.rbegin(); pt != deq.rend(); pt++)
				cout << *pt << endl;
		}
		break;
		case 3:
		{
			al.quickSort(0, deq.size() - 1, deq);
			cout << "   Отсортировано!" << endl;
		}
		break;
		case 4:
		{
			cout << "Введите порядковый продукции:" << endl;
			int num = vvod<int>() - 1;
			cout << deq[num] << endl;
		}
		break;
		case 5:
		{
			cout << "  Демонстракия алгоритма find. Поиск продукции по наименованию" << endl;
			try
			{
				cout << "Введите наименование: " << endl;
				cin.ignore();
				cin.getline(Name, 100);
				al.find(deq, Name);
			}
			catch (int)
			{
				cout << "Совпадений не найдено" << endl;
			}
		}
		case 6:
		{
			cout << "  Демонстракия алгоритма del. Удаление продукции по наименованию" << endl;
			cout << "Введите наименование: " << endl;
			cin.ignore();
			cin.getline(Name, 10);
			al.del(deq, Name);
			cout << "  Сделано!" << endl;
		}
		case 7:
			break;
		default:
			cout << "Неккоректный ввод" << endl;
			break;
		}
	}
	return 0;
}

//Алгоритм: быстрая сортировка
