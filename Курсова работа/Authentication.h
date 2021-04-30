#pragma once
#include <fstream>//��� ������ � ������
#include <string>
#include <iomanip>
#include "Protect.h"//���������� �������������� �������� ����� ������
#include "UserFunctions.h"

using namespace std;//����������� �������� ����� � ������
const string FILE_OF_USERS = "C://�����������//USERS.txt";//���� �������� ������ � �������������
const int USER_ATTRIBUTES = 4;//���������� ��������� ������������
const int MIN_LENGHT_OF_PASSWORD = 6;//����������� ���������� �������� ������ ������������
struct user
{
	string login;//�����
	string password;//������
	bool role;//���� ������������
	bool access;//����������� ������� � �������
};
void writeUsersToFile(user* arr_of_users, int counter);//������ ������������� � ����
bool isLoginFree(user new_user, user* arr_of_users, int);//�������� �� ���������� ������ 
bool checkUser(user& incoming_user, user* arr_of_users, int);//�������� ������ � ������ ��� ����� � �������
void inputNewUserInformation(user& new_user, user* array_of_users, int);//���� ������ ������������
void addUserToFile(user new_user);//���������� ������ ������������ � ����
void inputLoginAndPass(user& in_user); //���� ������ � ������ ��� �����
void showMenuEntrance();//���� �����
user* rewriteArr(user new_user, user* arr, int counter);//���������� �������
user* registration(user& new_user, user* arr, int& counter);//����������� � ���������� ������ ������������
void readUsersToArr(user* arr_of_users, int counter);//���������� ������������������ ������������� �� ����� � ������
int countUsers();//������� ���������� ������������������ �������������
void creatAdminAccount(user& admin, user* arr, int counter);//�������� �������� �������������� � ������ ��� ���������� 
user* checkAdmin(user* arr, int& counter);//�������� �� �� ������� �������� ��������������