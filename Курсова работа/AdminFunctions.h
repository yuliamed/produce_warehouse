#pragma once
#include "Authentication.h"//������������� ��������� � ��������� �������
#include "Protect.h"//���������� �������������� �������� ����� ������
#include "UserFunctions.h"//����������� ������ � ����� ������ ���������

using namespace std;
void adminMenu();//����� ���� �������������
void adminActions(user* arr_of_Users, int& counter, product* arr_of_products, int products_counter);//����������� �������� �������������
void showUsers(user* somebody, int counter);//����� ������������� 
void banUser(user* users, int counter);//���������� ������������
void deleteUser(user* users, int& counter);//�������� ������������
void giveAccessToSystem(user* somebody, int counter);//��������� ��� ��������� ������ ������� 
user* registerNewUser(user* arr, int& counter);//�������� �������� 