#include<iostream>
#include "Stroka.h"
#include "IdentStroka.h"
#include "DesStroka.h"
#include <vector>
using namespace std;
Stroka* input();
static vector<string> objectType;

	int main() {
		setlocale(LC_ALL, "Russian");
		Stroka** allObjects = new Stroka*[5];
		for (size_t i = 0; i < 5; i++)
		{
			allObjects[i] = input();
		}
		cout << "���������� ������� �������. ������ ��� ��������� ����������� ����� ����������� �������� ���� ������������� �������" << endl;	
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
			objectType.push_back("IdentStroka");
			return obj;
		}
		else {
			cout << "������� ���������� �����: ";
			string number;
			cin >> number;
			DesStroka* obj = new DesStroka(number.c_str());
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			objectType.push_back("DesStroka");
			return obj;
		}
	}

	bool Check(Stroka** allObjects) {
		int objectsCount = 1;
		for (size_t i = 0; i < 5; i++)
		{
			if (objectType[i] == "IdentStroka") {
				cout << allObjects[i]->GetStr() << endl;
				cout << allObjects[i]->GetLen() << endl;
				allObjects[i]->Show();
				IdentStroka* tmp = new IdentStroka("itmo");
				allObjects[i] = tmp;
				allObjects[i][3];
				IdentStroka tmp2("fbit");
				IdentStroka tmp3(" top faculty");
				cout << (tmp3 + tmp2).GetStr << endl;
				cout << ((IdentStroka)*(allObjects[i]) + tmp2).GetStr();
			}
			else {

			}
		}
	}