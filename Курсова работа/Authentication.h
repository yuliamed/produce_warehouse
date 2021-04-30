#pragma once
#include <fstream>//для работы с файлом
#include <string>
#include <iomanip>
#include "Protect.h"//проработка исключительных ситуаций ввода данных
#include "UserFunctions.h"

using namespace std;//возможность потового ввода и вывода
const string FILE_OF_USERS = "C://Университет//USERS.txt";//файл хранения данных о пользователях
const int USER_ATTRIBUTES = 4;//количество атрибутов пользователя
const int MIN_LENGHT_OF_PASSWORD = 6;//минимальное количество символов пароля пользователя
struct user
{
	string login;//логин
	string password;//пароль
	bool role;//роль пользователя
	bool access;//возможность доступа к системе
};
void writeUsersToFile(user* arr_of_users, int counter);//запись пользователей в файл
bool isLoginFree(user new_user, user* arr_of_users, int);//проверка на совпадение логина 
bool checkUser(user& incoming_user, user* arr_of_users, int);//проверка логина и пароля при входе в систему
void inputNewUserInformation(user& new_user, user* array_of_users, int);//ввод нового пользователя
void addUserToFile(user new_user);//добавление нового пользователя в файл
void inputLoginAndPass(user& in_user); //ввод пароля и логина при входе
void showMenuEntrance();//меню входа
user* rewriteArr(user new_user, user* arr, int counter);//расширение массива
user* registration(user& new_user, user* arr, int& counter);//регистрация и добавление нового пользователя
void readUsersToArr(user* arr_of_users, int counter);//считывание зарегистрированных пользователей из файла в массив
int countUsers();//считает количество зарегистрированных пользователей
void creatAdminAccount(user& admin, user* arr, int counter);//создание аккаунта администратора в случае его отсутствия 
user* checkAdmin(user* arr, int& counter);//проверка БД на наличие аккаунта администратора