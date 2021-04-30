#include "AdminFunctions.h"
void adminMenu()
{
	bigLine();
	cout << setw(70) << "���� ��������������" << endl;
	bigLine();
	cout << "\t\t\t1 - �������� ���� �������������" << endl;
	cout << "\t\t\t2 - ��������� � ���������� ������ ������� � �������" << endl;
	cout << "\t\t\t3 - ��������� ��������" << endl;
	cout << "\t\t\t4 - ������ � ����������" << endl;
	cout << "\t\t\t5 - ���������� ������������" << endl;
	cout << "\t\t\t6 - �������� ��������" << endl;
	cout << "\t\t\t0 - ����� �� ����" << endl;
	cout << "\t\t�����: ";
}
void adminActions(user* arr_of_Users, int& counter, product* arr_of_products, int products_counter)
{
	int choise;
	do {
		adminMenu();
		inputPositiveNumber(choise);
		changeScreen();
		switch (choise)
		{
		case 1:
			showUsers(arr_of_Users, counter);
			break; 
		case 2:
			giveAccessToSystem(arr_of_Users, counter);
			break; 
		case 3: 
			deleteUser(arr_of_Users, counter); 
			break; 
		case 4: 
			userActions(arr_of_products, products_counter);
			break; 
		case 5: 
			banUser(arr_of_Users, counter); 
			break; 
		case 6:
			arr_of_Users= registerNewUser(arr_of_Users, counter);
			break;
		case 0: 
			writeUsersToFile(arr_of_Users, counter); 
			return;
		default: 
			cout << "������ �����!" << endl; 
			break; 
		}
		changeScreen();
	} while (choise != 0);
}
void showUsers(user* somebody, int counter)
{
	littleLine();
	cout << setw(71) << "������������ ���������" << endl;
	littleLine();
	cout << setw(5) << "�" << setw(15) << "�����" << setw(15) << "������" << setw(15) << "����" << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << setw(5) << i + 1;
		cout << setw(17) << somebody[i].login;
		if (somebody[i].access == 1)
			cout << setw(13) << "����";
		else cout << setw(12) << "���";
		if (somebody[i].role == 1)
			cout << setw(22) << "�������������";
		else cout << setw(23) << "������� ��������";
		cout << endl;
	}
}
void deleteUser(user* users, int& counter)
{
	bigLine();
	cout << setw(71) << "�������� ������������" << endl;
	int number;
	showUsers(users, counter);
	do {
		cout << "������� ����� ������������ ��� �������� ��� 0 ��� ������:";
		inputPositiveNumber(number);
	} while (number > counter);
	if (number != 0)
	{
		
		number--;
		if (users[number].role != 1)
		{ 
			int really;
			do {
				cout << "������������� ������ ������� ������������?\n\t1 - ��\n\t0 - ������\n\t�����: " << endl;
				inputPositiveNumber(really);
				if (really == 0)return;
			} while (really>1);
			for (int i = number; i < counter - 1; i++)
			{
				users[i] = users[i + 1];
			}
			counter--;
			cout << "\n������� ����� ����������" << endl;
		}
		else cout << "���������� ������� �������� �� ����! �� ��� ��� ������� :D" << endl;
	}
	else cout << "�������� ��������" << endl;
}
void banUser(user* users, int counter)
{
	bigLine();
	cout << setw(72) << "���������� ������������" << endl;
	bigLine();
	int number;
	showUsers(users, counter);
	do {
		cout << "������� ����� ������������ ��� 0 ��� ������:";
		inputPositiveNumber(number);
	} while (number > counter);
	if (number != 0)
	{   
	    number--;
		if (users[number].role != 1)
		{	
			int sure;
			do {
				cout << "������������� ������ ������������� ������������ "<< users[number].login<<"?"<<"\n\t1 - ��\n\t0 - ������\n�����: ";
				inputPositiveNumber(sure);
			} while (sure >2);
			if (sure == 0) return;
			users[number].access = 0;
			cout << "������������ " << users[number].login << " ������������" << endl;
		}
		else cout << endl << "���� ������������ �������������, �� �� ������ ��� �������������" << endl;
	}
	else cout << endl << "���������� ������������ ��������" << endl;
}
void giveAccessToSystem(user* somebody, int counter)
{
	bigLine();
	cout<<setw(68) << "��������� ������" << endl;
	bigLine();
	int users = 0;
	for (int i = 0; i < counter; i++)
	{
		if (somebody[i].access == 0)
		{
			int choise;
			littleLine();
			cout << "�����:" << somebody[i].login << "\n����:" << somebody[i].role << "\n������: ����������� " << endl;
			littleLine();
			do {
				cout << "����������� ������?\n\t1 - ��\n\t2 - ���\n\t0 - ����� �� �������������� ������� �������������" << endl << "�����: ";
				inputPositiveNumber(choise);
			} while (choise > 2);
			if (choise == 1)
				somebody[i].access = 1;
			if (choise == 0)
				return;
		}
		else users++;
	}
	if (users == counter)
	{
		littleLine();
		cout <<setw(68)<< "������ ���!" << endl;
		littleLine();
		return;
	}
}
user* registerNewUser(user* arr, int& counter)
{
	user new_user;
	inputNewUserInformation(new_user, arr, counter);
	int choice;
	do {
		cout << "�������� ������ ������ ������������?" << endl;
		cout << "\t1 - ��\n\t2 - ���\n�����: ";
		inputPositiveNumber(choice);
		if (choice == 1)
		{
			new_user.access = 1;
			break;
		}
		else if (choice == 2) break;
	} while (true);
	arr = rewriteArr(new_user, arr, counter);
	counter++;
	addUserToFile(new_user);
	return arr;
}