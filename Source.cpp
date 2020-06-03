#include<iostream>
#include "Stroka.h"
#include "IdentStroka.h"
#include "DesStroka.h"
using namespace std;
Stroka* input();

	int main() {
		setlocale(LC_ALL, "Russian");
		Stroka** a = new Stroka * [5];
		for (size_t i = 0; i < 5; i++)
		{
			a[i] = input();
		}
	}

	Stroka* input() {
		cout << "Выберите класс. Строка_идентификатор - введите \"1\"; Десятичная_строка - введите \"2\"" << endl << "Введите номер: ";
		int classNumber;
		cin >> classNumber;
		while ((classNumber != 1) && (classNumber != 2)) {
			cout << "Введён неверный номер. Введите номер ещё раз: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> classNumber;
			
		}
		if (classNumber == 1) {
			cout << "Введите идентификатор: ";
			string id;
			cin >> id;
			IdentStroka* obj = new IdentStroka(id.c_str());
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return obj;
		}
		else {
			cout << "Введите десятичное число: ";
			string number;
			cin >> number;
			DesStroka* obj = new DesStroka(number.c_str());
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return obj;
		}
	}