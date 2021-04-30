#include "Authentication.h"

void inputNewUserInformation(user& new_user, user* array_of_users, int counter)
{
	bigLine();
	cout <<setw(65)<< "�����������" << endl;
	bigLine();
	do {
		cout << "\t������� �����: ";
		new_user.login=inputStroky();
		if (isLoginFree(new_user, array_of_users, counter))
		{
			do {
				string password;
				cout << "\t������� ������: ";
				hidePass(new_user.password);
				cout << endl;
				if (new_user.password.length() < MIN_LENGHT_OF_PASSWORD)
				{
					littleLine();
					cout << "������� �������� ������! " << endl;
					littleLine();
					continue;
				}
				cout << "\t����������� ������: ";
				hidePass(password);
				cout << endl;
				if (password != new_user.password)
				{
					cout << "������ ����� ������!!" << endl;
					continue;
				}
				
				else break;
			} while (true);
			break;
		}
	} while (true);
	int choise;
	do {
		cout<<"������� ������� ������������ ��� ��������������? \n\t1 - ������������\n\t2 - �������������\n�����: "<<endl;
		inputPositiveNumber(choise);
	} while (choise>=3); 
	if(choise==1 )new_user.role = 0;
	else new_user.role = 1;
	new_user.access = 0;
}
user* registration(user& new_user, user* arr, int& counter)
{
	changeScreen();
	inputNewUserInformation(new_user, arr, counter);
	arr = rewriteArr(new_user, arr, counter);
	counter++;
	littleLine();
	cout << setw(83) << "��� ������� ��� ������������ ��������������" << endl;
	littleLine();
	addUserToFile(new_user);
	return arr;
}
void creatAdminAccount(user& admin, user* arr, int counter)
{
	littleLine();
	cout << "\t� ���� ������ ����������� ������ �� ��������������.\n\t���������� ������� ������� ����������� ��� ������ ���������." << endl;
	littleLine();
	do {
		cout << "������� �����: ";
		 admin.login=inputStroky();
		if (isLoginFree(admin, arr, counter))
		{
			do {
				string password;
				cout << "������� ������: ";
				hidePass(admin.password);
				cout << endl;
				if (admin.password.length() < MIN_LENGHT_OF_PASSWORD)
				{
					cout << "������� �������� ������! " << endl;
					continue;
				}
				cout << "����������� ������: ";
				hidePass(password);
				cout << endl;
				if (password != admin.password)
				{
					cout << "������ ����� ������" << endl;
					continue;
				}
				else break;
			} while (true);
			break;
		}else
			cout << "������� � ����� ������� ��� ���������������!" << endl << endl;
	} while (true);
	admin.role = 1;
	admin.access = 1;
	counter++;
}
user* checkAdmin(user* array_of_users, int& counter)
{
	for (int i = 0; i < counter; i++)
	{
		if (array_of_users[i].role == 0) continue;
		else if(array_of_users[i].access == 1) return array_of_users;
	}
	user admin;
	creatAdminAccount(admin, array_of_users, counter);
	array_of_users = rewriteArr(admin, array_of_users, counter);
	//addUserToFile(admin);
	counter++;
	writeUsersToFile(array_of_users, counter);
	return array_of_users;
}
void inputLoginAndPass(user& in_user)
{
	littleLine();
	cout << "\t������� �����: ";
	cin >> in_user.login;
	cout << "\t������� ������: ";
	hidePass(in_user.password);
	cout << endl;
}
bool isLoginFree(user new_user, user* arr_of_users, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		if (new_user.login == arr_of_users[i].login)
		{
			cout << "������������ � ����� ������� ��� ���������������!" << endl;
			return false;
		}
	}
	return true;
}
void addUserToFile(user new_user)
{
	ofstream fadd(FILE_OF_USERS, ios::app);
	if (!fadd.is_open())
		cout << "��������� ���� �� ����������!" << endl;
	else
	{
		fadd << endl;
		fadd << new_user.login << " " << new_user.password << " ";
		fadd << new_user.role << " " << new_user.access;
		fadd.close();
	}
}
void showMenuEntrance()
{
	bigLine();
	cout <<setw(67)<< "���� � �������" << endl;
	bigLine();
	cout << "\t\t1 - �����������" << endl;
	cout << "\t\t2 - ����" << endl;
	cout << "\t\t0 - ����� �� ���������" << endl;
	cout << "\t�����: ";
}
bool checkUser(user& incoming_user, user* arr_of_users, int counter)
{
	for (int i = 0; i <counter; i++)
	{
		if (incoming_user.login == arr_of_users[i].login && incoming_user.password == arr_of_users[i].password)
		{
			if (arr_of_users[i].access == 1)
			{
				incoming_user.role = arr_of_users[i].role;
				incoming_user.access = arr_of_users[i].access;
				return true;
			}
			else
			{
				littleLine();
				cout << "��� ������� ���� �� ���������� ���������������." << endl;
				littleLine();
				return false;
			}
		}
	}
	littleLine();
	cout << "������������� ������� ����� � ������." << endl;
	littleLine();
	return false;
}
void writeUsersToFile(user* arr_of_users, int counter)
{

	ofstream fout(FILE_OF_USERS, ios::out);
	for (int i = 0; i < counter; i++)
	{
		fout << endl;
		fout << arr_of_users[i].login << " " << arr_of_users[i].password << " ";
		fout << arr_of_users[i].role << " " << arr_of_users[i].access;
	}
	fout.close();
}
user* rewriteArr(user new_user, user* arr, int counter)
{
	user* temp = new user[counter + 1];
	for (int i = 0; i < counter; i++)
	{
		temp[i] = arr[i];
	}
	temp[counter] = new_user;
	return temp;
}
void readUsersToArr(user* arr_of_users, int counter)
{
	ifstream fread(FILE_OF_USERS, ios::in);
	if (!fread.is_open())
		cout << "��������� ���� �� ����������" << endl;
	else
	{
		int i = 0;
		while (i < counter)
		{
			fread >> arr_of_users[i].login >> arr_of_users[i].password;
			fread >> arr_of_users[i].role >> arr_of_users[i].access;
			i++;
		}
	}
	fread.close();
}
int countUsers()
{
	string s;
	int counter = 0;
	ifstream fread(FILE_OF_USERS, ios::in);
	while (!fread.eof())
	{
		fread >> s;
		counter++;
	}
	counter /= USER_ATTRIBUTES;
	fread.close();
	return counter;
}