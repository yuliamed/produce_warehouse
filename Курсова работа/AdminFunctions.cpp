#include "AdminFunctions.h"
void adminMenu()
{
	bigLine();
	cout << setw(70) << "Меню администратора" << endl;
	bigLine();
	cout << "\t\t\t1 - Показать всех пользователей" << endl;
	cout << "\t\t\t2 - Одобрение и отклонение заявок доступа к системе" << endl;
	cout << "\t\t\t3 - Удалаение аккаунта" << endl;
	cout << "\t\t\t4 - Работа с продуктами" << endl;
	cout << "\t\t\t5 - Блокировка пользователя" << endl;
	cout << "\t\t\t6 - Создание аккаунта" << endl;
	cout << "\t\t\t0 - Выход из меню" << endl;
	cout << "\t\tВыбор: ";
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
			cout << "Ошибка ввода!" << endl; 
			break; 
		}
		changeScreen();
	} while (choise != 0);
}
void showUsers(user* somebody, int counter)
{
	littleLine();
	cout << setw(71) << "Пользователи программы" << endl;
	littleLine();
	cout << setw(5) << "№" << setw(15) << "Логин" << setw(15) << "Доступ" << setw(15) << "Роль" << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << setw(5) << i + 1;
		cout << setw(17) << somebody[i].login;
		if (somebody[i].access == 1)
			cout << setw(13) << "Есть";
		else cout << setw(12) << "Нет";
		if (somebody[i].role == 1)
			cout << setw(22) << "Администратор";
		else cout << setw(23) << "Простой смертный";
		cout << endl;
	}
}
void deleteUser(user* users, int& counter)
{
	bigLine();
	cout << setw(71) << "Удаление пользователя" << endl;
	int number;
	showUsers(users, counter);
	do {
		cout << "Введите номер пользователя для удаления или 0 для выхода:";
		inputPositiveNumber(number);
	} while (number > counter);
	if (number != 0)
	{
		
		number--;
		if (users[number].role != 1)
		{ 
			int really;
			do {
				cout << "Действительно хотите удалить пользователя?\n\t1 - да\n\t0 - отмена\n\tВыбор: " << endl;
				inputPositiveNumber(really);
				if (really == 0)return;
			} while (really>1);
			for (int i = number; i < counter - 1; i++)
			{
				users[i] = users[i + 1];
			}
			counter--;
			cout << "\nУспешно удалён несчастный" << endl;
		}
		else cout << "Невозможно удалить колллегу по цеху! Ты его сам одобрил :D" << endl;
	}
	else cout << "Действие отменено" << endl;
}
void banUser(user* users, int counter)
{
	bigLine();
	cout << setw(72) << "Блокировка пользователя" << endl;
	bigLine();
	int number;
	showUsers(users, counter);
	do {
		cout << "Введите номер пользователя или 0 для выхода:";
		inputPositiveNumber(number);
	} while (number > counter);
	if (number != 0)
	{   
	    number--;
		if (users[number].role != 1)
		{	
			int sure;
			do {
				cout << "Действительно хотите заблокировать пользователя "<< users[number].login<<"?"<<"\n\t1 - да\n\t0 - отмена\nВыбор: ";
				inputPositiveNumber(sure);
			} while (sure >2);
			if (sure == 0) return;
			users[number].access = 0;
			cout << "Пользователь " << users[number].login << " заблокирован" << endl;
		}
		else cout << endl << "Этот пользователь администратор, вы не можете его заблокировать" << endl;
	}
	else cout << endl << "Блокировка пользователа отменена" << endl;
}
void giveAccessToSystem(user* somebody, int counter)
{
	bigLine();
	cout<<setw(68) << "Обработка заявок" << endl;
	bigLine();
	int users = 0;
	for (int i = 0; i < counter; i++)
	{
		if (somebody[i].access == 0)
		{
			int choise;
			littleLine();
			cout << "Логин:" << somebody[i].login << "\nРоль:" << somebody[i].role << "\nДоступ: отсутствует " << endl;
			littleLine();
			do {
				cout << "Подтвердить доступ?\n\t1 - Да\n\t2 - Нет\n\t0 - Выйти из редактирования доступа пользователей" << endl << "Выбор: ";
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
		cout <<setw(68)<< "Заявок нет!" << endl;
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
		cout << "Одобрить доступ новому пользователю?" << endl;
		cout << "\t1 - да\n\t2 - нет\nВыбор: ";
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