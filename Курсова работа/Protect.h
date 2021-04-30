#pragma once
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void inputIntNumber(int& numb);//ввод только целочисленных значений
void inputPositiveNumber(int& numb);//ввод положительных целочисленных значений
void inputPositiveNumber(double& numb);//ввод положительных дробных значений
string inputStroky();//ввод строки без пробелов
void hidePass(string &);//преобразование вводимых символов в символ *
//функции для красивого вывода данных на экран
void littleLine();
void bigLine();
void changeScreen();