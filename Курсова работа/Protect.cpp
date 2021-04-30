#include "Protect.h"

using namespace std;

void inputIntNumber(int& numb)
{
	int a;
	do
	{
		cin >> a;
		if ((cin.get() != '\n') )
		{
			cin.clear(); //���������� ����� ������
			cin.ignore(256, '\n');//�������� �����//cin.ignore(256, '\n'); //�������� ������������� ���������� �������� �� ������ �� �������� ������� �� �� ������
			cout << "������������� ����!\n��������� ����:";
			continue;
		}
		else break;
	} while (true);
	numb = a;

}
void inputPositiveNumber(int& numb)
{
	int a;
	do
	{
		cin >> a;
		if ((cin.get()!='\n') || a < 0)
		{
			cin.clear(); //���������� ����� ������
			cin.ignore(256, '\n');//�������� ������������� ���������� �������� �� ������ �� �������� ������� �� �� ������
			cout << "������������� ����!\n��������� ����:";
			continue;
		}
		else break;
	} while (true);
	numb = a;
	
}
void inputPositiveNumber(double& numb)
{
	double a;
	do
	{
		cin >> a;
		if ((cin.get() != '\n') || a < 0)
		{
			cin.clear(); //���������� ����� ������
			cin.ignore(256, '\n');//�������� �����//cin.ignore(256, '\n'); //�������� ������������� ���������� �������� �� ������ �� �������� ������� �� �� ������
			cout << "������������� ����!\n��������� ����:";
			continue;
		}
		else break;
	} while (true);
	numb = a;

}
void bigLine()
{
	cout<< "=======================================================================================================================" << endl;
}
void littleLine()
{
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
}
string inputStroky() {
	string word;
	while (1) {
		cin >> word; //������������ ������ �����
		if (cin.peek() != '\n') { //���� ��� ������ ������ �� ������������� �� ��������� �� ����� ������
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//�������� �����
			cout << " ����������, ������� ��� ��������" << endl;
			continue; //��������� ����
		}
		else if (word.size() > 20) {
			cout << " ����������, ������� ����� �������� �������" << endl;
			continue;
		}
		else return word;
	}
}
void hidePass(string& password)
{
	int ch = 0;
	string t;

	while (true)
	{
		ch = _getch();
		if (ch == 13) break;
		else
		{
			cout << "*";
			t += (char)ch;
		}
	}
	password = t;
}
void changeScreen()
{
	system("pause");
	system("cls");
}