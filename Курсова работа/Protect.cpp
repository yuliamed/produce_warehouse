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
			cin.clear(); //Сбрасывает флаги ошибок
			cin.ignore(256, '\n');//чистится поток//cin.ignore(256, '\n'); //удаление максимального количества символов из потока до перевода курсора на сл строку
			cout << "Некоррректный ввод!\nПовторите ввод:";
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
			cin.clear(); //Сбрасывает флаги ошибок
			cin.ignore(256, '\n');//удаление максимального количества символов из потока до перевода курсора на сл строку
			cout << "Некоррректный ввод!\nПовторите ввод:";
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
			cin.clear(); //Сбрасывает флаги ошибок
			cin.ignore(256, '\n');//чистится поток//cin.ignore(256, '\n'); //удаление максимального количества символов из потока до перевода курсора на сл строку
			cout << "Некоррректный ввод!\nПовторите ввод:";
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
		cin >> word; //пользователь вводит слово
		if (cin.peek() != '\n') { //если при считке потока он заканчивается не переходом на новую строку
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//чистится поток
			cout << " Пожалуйста, введите без пробелов" << endl;
			continue; //повторяем ввод
		}
		else if (word.size() > 20) {
			cout << " Пожалуйста, введите слово меньшего размера" << endl;
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