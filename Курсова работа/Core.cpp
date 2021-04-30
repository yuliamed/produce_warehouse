#include "Core.h"
void systemWork()
{
	SetConsoleOutputCP(1251);//������� ��������� ��� ����� ������� �������� � �������
	SetConsoleCP(1251);//������� ��������� ��� ������ ������� �������� � �������
	system("color 70");//���� ������� � ������
	bigLine();
	littleLine();
	cout <<setw(77)<< "��������� ����� ������� �� ������" << endl;
	littleLine();
	bigLine();
}
void core()
{
	systemWork();
	enterance();
}
bool enterance()
{
	int choise;
	changeScreen();
		do {
			user user_in;int counter = countUsers();
			int counter_products = countProducts(); 
			user* array_of_users = new user[counter];//������ ��� ������ � ������
			product* arr_of_products = new product[counter_products];
			readUsersToArr(array_of_users, counter);
			readProductsToArr(arr_of_products);
			array_of_users=checkAdmin(array_of_users, counter);
			showMenuEntrance();
			inputPositiveNumber(choise);
			switch (choise)
			{
			case 1://�����������
				array_of_users = registration(user_in, array_of_users, counter);
				changeScreen();
				break;
			case 2://���� � �������
				if (enterToAccount(user_in, array_of_users, counter))
				{
					changeScreen();
					if (user_in.role == 1)
					{	
						adminActions(array_of_users, counter, arr_of_products, counter_products);
					}
					else
					{
						userActions(arr_of_products, counter_products);
					}
				}
				break;
			case 0://����� �� ��������� 
				delete[] arr_of_products;
				delete[] array_of_users;
				return 0;
			default:
				cout << "������ �����!" << endl;
				break;
			}
			//writeUsersToFile(array_of_users, counter);
			delete[] arr_of_products;
			delete[] array_of_users;
		} while (true);
}
bool enterToAccount(user& user_in, user* array_of_users, int& counter)
{
	while (true)
	{
		inputLoginAndPass(user_in);
		if (checkUser(user_in, array_of_users, counter))
			return true;
		else
		{
			int choise;
			cout << "\t��������� ����?\n\t1 - ��\n\t2 - ���\n�����:";
			cin >> choise;
			if (choise == 2)return false;
		}
	}
}