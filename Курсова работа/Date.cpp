#include "Date.h"

date getDate()
{
	struct tm localtime;
	time_t now = time(NULL);
	date now_date;
	localtime_s(&localtime, &now);

	now_date.day = localtime.tm_mday;
	now_date.month = 1 + localtime.tm_mon;
	now_date.year = 1900 + localtime.tm_year;

	return now_date;
}
bool isDateCorrect(date entered_date)
{
	date now = getDate();
	if (entered_date.year > now.year)
	{
		cout << endl << "�� ����� ������� ���. ��� ���������� (��, ��������� �� ����� � ������ �������)" << endl;
		return false;
	}
	if (entered_date.year == now.year && entered_date.month > now.month)
	{
		cout << endl << "�� ����� ������� �����. ��� ���������� (��, ��������� �� ����� � ������ �������)" << endl;
		return false;
	}
	if (entered_date.year == now.year && entered_date.month == now.month && entered_date.day > now.day)
	{
		cout << endl << "�� ����� ������� ����. ��� ���������� (��, ��������� �� ����� � ������ �������)" << endl;
			return false;
	}
	if (entered_date.year == 0 || entered_date.month == 0 || entered_date.day == 0)
	{
		cout << endl << "�� ����� ������� ����, ��� ����������!" << endl;
		return false;
	}
	if(entered_date.day>31||entered_date.month>12||entered_date.year<1900)
	{
		cout << endl << "�� ����� ���������� ����! �� � ��������� ��������� � �������� ������� ����" << endl;
		return false;
	}
	return true;
}