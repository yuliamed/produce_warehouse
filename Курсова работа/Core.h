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
bool enterance();//меню входа и последующие действия
void core();//система входа в программу
bool enterToAccount(user& user_in, user* array_of_users, int& counter);//проверка на вход в аккаунт