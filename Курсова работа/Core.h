#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "Protect.h"
#include "Authentication.h"
#include "AdminFunctions.h"
#include "UserFunctions.h"
#include <Windows.h>

using namespace std;
void systemWork();
bool enterance();//���� ����� � ����������� ��������
void core();//������� ����� � ���������
bool enterToAccount(user& user_in, user* array_of_users, int& counter);//�������� �� ���� � �������