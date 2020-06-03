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
		cout << "�������� �����. ������_������������� - ������� \"1\"; ����������_������ - ������� \"2\"" << endl << "������� �����: ";
		int classNumber;
		cin >> classNumber;
		while ((classNumber != 1) && (classNumber != 2)) {
			cout << "����� �������� �����. ������� ����� ��� ���: ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> classNumber;
			
		}
		if (classNumber == 1) {
			cout << "������� �������������: ";
			string id;
			cin >> id;
			IdentStroka* obj = new IdentStroka(id.c_str());
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return obj;
		}
		else {
			cout << "������� ���������� �����: ";
			string number;
			cin >> number;
			DesStroka* obj = new DesStroka(number.c_str());
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return obj;
		}
	}