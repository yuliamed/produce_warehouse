#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Date.h"
#include "Protect.h"
#include "windows.h"
const string FILE_OF_PRODUCTS = "C://�����������//PRODUCTS.txt";//���� � ����� � �� ���������
const int PRODUCT_ATTRIBUTES = 9;//������������ ���������� ���������� ��������
using namespace std;
struct product
{
	string name;//������������ ��������
	int quantity;//���������� ��������
	double price;//���� ��������
	date date;//���� �������� � ����
	//��� ������� ����� � ��
	string userName;
	string userSurname;
	string userPatronymic;
};
void inputProduct(product& in_product);//���� ����� ��������
void inputDate(date& in_date);//���� ���� �������� ��������
void readProductsToArr(product* arr_products);//���������� ��������� � ������
void showProducts(product* arr_product, int counter);//����������� ��������� � ������� ��������� � ����
void showOneProduct(product one_product, int numb);//����������� ������ ��������
void writeProductsToFile(product* arr, int counter);//������ ������� ��������� ����� ������ � ��
product* deleteProduct(product* arr_products, int& counter);//�������� ��������
product* addProduct(product* arr, int& counter);//���������� ��������
void changeProduct(product* arr_products, int counter);//�������������� ��������
int countProducts();//�����1� ��������� � ��
void showProductsInAlfavit(product* arr, int counter);//����������� ��������� � ����������� �������
void showProductsInPrice(product* arr, int counter);//���������� ��������� �� ����
void showProductsInUserSurname(product* arr, int counter);//���������� ��������� �� ������� ������������������� ���
void searchByName(product* arr, int counter);//����� �� ������������ �������� 
void searchBySurname(product* arr, int counter);//����� �� ������� ������������������� �������
void searchByMonth(product* arr, int counter);//����� �� ������ ����������� �������� � ��
void userMenu();//����������� ���� ������������
void sortProducts(product* arr, int counter);//����� ���������� ���������
void searchProducts(product* arr, int counter);//����� ������� ������ ���������
void userActions(product* arr_of_products, int& counter);//�������� ������������
void showProductsStoredMaxMounthAndMinPrice(product* arr, int counter);//����������� ���������, ���������� Y ������� � X ����� � ���������� �������
void productHeader();//����� ��������� ����������� ��������� 
product* rewriteArr(product new_product, product* arr, int counter);//���������� ������� ��� ���������� ����� ���������� � ����