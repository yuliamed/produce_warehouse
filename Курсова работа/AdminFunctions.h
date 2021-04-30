#pragma once
#include "Authentication.h"//использование структуры и некоторых функций
#include "Protect.h"//проработка исключительных ситуаций ввода данных
#include "UserFunctions.h"//возможность работы с базой данных продуктов

using namespace std;
void adminMenu();//вывод меню админитратора
void adminActions(user* arr_of_Users, int& counter, product* arr_of_products, int products_counter);//оргаризовка действий админитратора
void showUsers(user* somebody, int counter);//вывод пользователей 
void banUser(user* users, int counter);//блокировка пользователя
void deleteUser(user* users, int& counter);//удаление пользователя
void giveAccessToSystem(user* somebody, int counter);//одобрение или отлонение заявок доступа 
user* registerNewUser(user* arr, int& counter);//создание аккаунта 