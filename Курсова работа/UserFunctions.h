#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Date.h"
#include "Protect.h"
#include "windows.h"
const string FILE_OF_PRODUCTS = "C://Университет//PRODUCTS.txt";//путь к файлу с БД продуктов
const int PRODUCT_ATTRIBUTES = 9;//максимальное количество аттрибутов продукта
using namespace std;
struct product
{
	string name;//наименование продукта
	int quantity;//количество продукта
	double price;//цена продукта
	date date;//дата внесения в базу
	//ФИО внёсшего товар в БД
	string userName;
	string userSurname;
	string userPatronymic;
};
void inputProduct(product& in_product);//ввод новго продукта
void inputDate(date& in_date);//ввод даты внесения продукта
void readProductsToArr(product* arr_products);//считывание продуктов в массив
void showProducts(product* arr_product, int counter);//отображение продуктов в порядке занесения в базу
void showOneProduct(product one_product, int numb);//отображение одного продукта
void writeProductsToFile(product* arr, int counter);//запись массива продуктов после работы с БД
product* deleteProduct(product* arr_products, int& counter);//удаление продукта
product* addProduct(product* arr, int& counter);//добавление продукта
void changeProduct(product* arr_products, int counter);//редактирование продукта
int countProducts();//подсч1т продуктов в БД
void showProductsInAlfavit(product* arr, int counter);//отображение продуктов в алффавитном порядке
void showProductsInPrice(product* arr, int counter);//сортировка продуктов по цене
void showProductsInUserSurname(product* arr, int counter);//сортировка продуктов по фамилии зарегистрировавшего его
void searchByName(product* arr, int counter);//поиск по наименованию продукта 
void searchBySurname(product* arr, int counter);//поиск по фамилии зарегистрировавшего продукт
void searchByMonth(product* arr, int counter);//поиск по месяце регистрации продукта в БД
void userMenu();//отображение меню пользователя
void sortProducts(product* arr, int counter);//выбор сортировки продуктов
void searchProducts(product* arr, int counter);//выбор способа поиска продуктов
void userActions(product* arr_of_products, int& counter);//действия пользователя
void showProductsStoredMaxMounthAndMinPrice(product* arr, int counter);//отображение продуктов, хранящиеся Y месяцев с X ценой в алфавитном порядке
void productHeader();//вывод заголовка отображения продуктов 
product* rewriteArr(product new_product, product* arr, int counter);//перезапись массива для добавления новой информации в него