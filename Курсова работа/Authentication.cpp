#include "Authentication.h"

void inputNewUserInformation(user& new_user, user* array_of_users, int counter)
{
	bigLine();
	cout <<setw(65)<< "Регистрация" << endl;
	bigLine();
	do {
		cout << "\tВведите логин: ";
		new_user.login=inputStroky();
		if (isLoginFree(new_user, array_of_users, counter))
		{
			do {
				string password;
				cout << "\tВведите пароль: ";
				hidePass(new_user.password);
				cout << endl;
				if (new_user.password.length() < MIN_LENGHT_OF_PASSWORD)
				{
					littleLine();
					cout << "Слишком короткий пароль! " << endl;
					littleLine();
					continue;
				}
				cout << "\tПодтвердите пароль: ";
				hidePass(password);
				cout << endl;
				if (password != new_user.password)
				{
					cout << "Ошибка ввода пароля!!" << endl;
					continue;
				}
				
				else break;
			} while (true);
			break;
		}
	} while (true);
	int choise;
	do {
		cout<<"Создать аккаунт пользователя или администратора? \n\t1 - Пользователь\n\t2 - Администратор\nВыбор: "<<endl;
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
	cout << setw(83) << "Ваш аккаунт ждёт подтвержения администратора" << endl;
	littleLine();
	addUserToFile(new_user);
	return arr;
}
void creatAdminAccount(user& admin, user* arr, int counter)
{
	littleLine();
	cout << "\tВ базе данных отсутствуют записи об администраторе.\n\tНеобходимо создать аккаунт администора для работы программы." << endl;
	littleLine();
	do {
		cout << "Введите логин: ";
		 admin.login=inputStroky();
		if (isLoginFree(admin, arr, counter))
		{
			do {
				string password;
				cout << "Введите пароль: ";
				hidePass(admin.password);
				cout << endl;
				if (admin.password.length() < MIN_LENGHT_OF_PASSWORD)
				{
					cout << "Слишком короткий пароль! " << endl;
					continue;
				}
				cout << "Подтвердите пароль: ";
				hidePass(password);
				cout << endl;
				if (password != admin.password)
				{
					cout << "Ошибка ввода пароля" << endl;
					continue;
				}
				else break;
			} while (true);
			break;
		}else
			cout << "Аккаунт с таким логином уже зарегистрирован!" << endl << endl;
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
	cout << "\tВведите логин: ";
	cin >> in_user.login;
	cout << "\tВведите пароль: ";
	hidePass(in_user.password);
	cout << endl;
}
bool isLoginFree(user new_user, user* arr_of_users, int counter)
{
	for (int i = 0; i < counter; i++)
	{
		if (new_user.login == arr_of_users[i].login)
		{
			cout << "Пользователь с таким логином уже зарегистрирован!" << endl;
			return false;
		}
	}
	return true;
}
void addUserToFile(user new_user)
{
	ofstream fadd(FILE_OF_USERS, ios::app);
	if (!fadd.is_open())
		cout << "Указанный файл не существует!" << endl;
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
	cout <<setw(67)<< "Вход в систему" << endl;
	bigLine();
	cout << "\t\t1 - Регистрация" << endl;
	cout << "\t\t2 - Вход" << endl;
	cout << "\t\t0 - Выход из программы" << endl;
	cout << "\tВыбор: ";
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
				cout << "Ваш аккаунт пока не подтверждён администратором." << endl;
				littleLine();
				return false;
			}
		}
	}
	littleLine();
	cout << "Перепроверьте введёные логин и пароль." << endl;
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
		cout << "Указанный файл не существует" << endl;
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