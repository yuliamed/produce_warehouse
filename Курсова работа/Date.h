#pragma once
#include <iostream>
#include <time.h>//библиотека времени для считывания текущей даты
using namespace std;//возможность потокового ввода и вывода
struct date
{
	int day;//день
	int month;//месяц
	int year;//год
};
date getDate();//считывание текущей даты
bool isDateCorrect(date entered_date);//проверка даты на корректность 