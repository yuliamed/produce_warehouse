#pragma once
#include <iostream>
#include <time.h>//���������� ������� ��� ���������� ������� ����
using namespace std;//����������� ���������� ����� � ������
struct date
{
	int day;//����
	int month;//�����
	int year;//���
};
date getDate();//���������� ������� ����
bool isDateCorrect(date entered_date);//�������� ���� �� ������������ 