#include<iostream>
#include "Stroka.h"
#include "IdentStroka.h"
#include "DesStroka.h"
#include <vector>
using namespace std;
Stroka* input();
bool Check(Stroka** allObjects);
static vector<string> objectType;

	int main() {
		setlocale(LC_ALL, "Russian");
		Stroka** allObjects = new Stroka*[5];
		for (size_t i = 0; i < 5; i++)
		{
			allObjects[i] = input();
		}
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "���������� ������� �������. ������ ��� ��������� ����������� ����� ����������� �������� ���� ������������� �������" << endl;	
		cout << "---------------------------------------------------------------------------" << endl;
		if (Check(allObjects)) {
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "�������� ������� ������ ��� ������. �� ���������� ���������� ����� ������ �� ���������� � ������� ������." << endl;
		}
		else {
			cout << "---------------------------------------------------------------------------" << endl;
			cout << "�� ����� �������� ������������� ������� ��������� ������. ����������� ������� ��� ����������." << endl;
		}
		DiagnosticPrint();
		cout << "������������ ���������." << endl;
	}

	Stroka* input() {
		cout << "------------------------------------------------------------" << endl;
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
		for (size_t i = 0; i < 5; i++)
		{
			if (objectType[i] == "IdentStroka") {
				try {
					cout << allObjects[i]->GetStr() << endl;
					cout << allObjects[i]->GetLen() << endl;
					IdentStroka tmp("itmo");
					*(allObjects[i]) = tmp;
					allObjects[i][3];
					IdentStroka tmp2("fbit");
					cout << (*(IdentStroka*)(allObjects[i]) + tmp2).GetStr() << endl;
					cout << (*(IdentStroka*)(allObjects[i]) + "hello world").GetStr() << endl;
					cout << ("My name is Alex " + *(IdentStroka*)(allObjects[i])).GetStr() << endl;
					allObjects[i]->Show();
				}
				catch(exception e){
					return false;
				}
				return true;
			}
			else {
				try {
					cout << allObjects[i]->GetStr() << endl;
					cout << allObjects[i]->GetLen() << endl;
					cout << ((DesStroka*)allObjects[i])->IsPositive() << endl;
					cout << ((DesStroka*)allObjects[i])->GetValue() << endl;
					DesStroka tmp("125");
					*(allObjects[i]) = tmp;
					cout << (*(DesStroka*)(allObjects[i]) + tmp).GetValue() << endl;
					cout << (*(DesStroka*)(allObjects[i]) + "228").GetValue() << endl;
					cout << ("1337" + *(DesStroka*)(allObjects[i])).GetValue() << endl;
					allObjects[i]->Show();
				}
				catch(exception e){
					return false;
				}
				return true;
			}
		}
	}

	void DiagnosticPrint() {
		cout << "---------------------------------------------------" << endl;
		cout << "���������� ��������� �������������:" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "����� Stroka:" << endl;
		Stroka::Diagnostic();
		cout << "---------------------------------------------------" << endl;
		cout << "����� DesStroka:" << endl;
		DesStroka::Diagnostic();
		cout << "---------------------------------------------------" << endl;
		cout << "����� IdentStroka:" << endl;
		IdentStroka::Diagnostic();
		cout << "---------------------------------------------------" << endl;
	}