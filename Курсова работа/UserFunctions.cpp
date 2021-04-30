#include "UserFunctions.h"
void productHeader()
{
	littleLine();
	cout << setw(5) << "№" << setw(23) << "Наименование" << setw(15) << "Количество" << setw(10) << "Цена";
	cout << setw(25) << "Дата поступления" << setw(20) << "ФИО внёсшего" << endl;
	littleLine();
}
void inputProduct(product& in_product)
{
	bigLine();
	cout <<setw(72)<< "Добавление нового товара" << endl;
	bigLine();
	cout << "Наименование: ";
	in_product.name=inputStroky();
	cout << "Количество: ";
	inputPositiveNumber(in_product.quantity);
	cout << "Цена на одну единицу в BYN: ";
	inputPositiveNumber(in_product.price);
	inputDate(in_product.date);
	littleLine();
	cout <<setw(71)<< "Данные о регистрирующем" << endl;
	littleLine();
	cout << "Фамилия: ";
	cin >> in_product.userSurname;
	cout << "Имя: ";
	cin>> in_product.userName;
	cout << "Отчество: ";
	cin>>in_product.userPatronymic;
	bigLine();
}
void inputDate(date &in_date)
{
	int choise;
	date now_date;
	now_date = getDate();
	do {
		cout << "Внести товар под сегодняшней датой?\n\t1 - Да\n\t2 - Ввести дату" << endl << "Выбор: ";
		inputPositiveNumber(choise);
	} while (choise < 1 || choise > 2);
	if (choise == 1) in_date = now_date;
	else
	{
		littleLine();
		cout << setw(72) << "Данные о дате регистрации" << endl;
		littleLine();
		do {
			cout << "Введите день поступления: ";
			inputPositiveNumber(in_date.day);
			cout << "Введите месяц поступления: ";
			inputPositiveNumber(in_date.month);
			cout << "Введите год поступления: ";
			inputPositiveNumber(in_date.year);
		} while (!isDateCorrect(in_date));
	}
}
void readProductsToArr(product* arr_products)
{
	ifstream fread(FILE_OF_PRODUCTS, ios::in);
	if (!fread.is_open())
		cout << "Указанный файл не существует" << endl;
	else
	{
		int i = 0;
		while(!fread.eof())
		{
			fread >> arr_products[i].name >> arr_products[i].quantity >> arr_products[i].price;
			fread >> arr_products[i].date.day >> arr_products[i].date.month >> arr_products[i].date.year;
			fread >> arr_products[i].userSurname >>arr_products[i].userName >> arr_products[i].userPatronymic;
			i++;
		}
	}
	fread.close();
}
void showProducts(product* arr_product, int counter)
{
	if (counter == 0)
	{
		cout<<setw(71) << "Продуктов на базе нет" << endl;
	}
	else {
	productHeader();
	for (int i = 0; i < counter; i++)
		showOneProduct(arr_product[i], i);
	cout << endl;
	}
}
void showOneProduct(product one_product, int numb)
{
	numb++;
	cout << setw(5) << numb << ")" <<setw(22)/*<<setw(5)<< ' '<<setw(one_product.name.length())*/ 
		<< one_product.name /*<<setw(20- one_product.name.length())*/<< setw(12) << one_product.quantity << setw(13) << one_product.price;
	cout << setw(14)  << one_product.date.day << '.' << one_product.date.month << '.' << one_product.date.year;
	cout << setw(15) << one_product.userSurname<< ' ' <<  one_product.userName << ' ' << one_product.userPatronymic << endl;
}
void writeProductsToFile(product* arr, int counter)
{
	ofstream fout(FILE_OF_PRODUCTS, ios::out);
	for (int i = 0; i < counter; i++)
	{
		fout << arr[i].name << " " << arr[i].quantity << " " << arr[i].price << " ";
		fout << arr[i].date.day <<" "<< arr[i].date.month << " " << arr[i].date.year << " ";
		fout << arr[i].userSurname << " " <<  arr[i].userName<< " " << arr[i].userPatronymic;
		if (i != counter - 1)fout<< endl;
	}
	fout.close();
}
product* deleteProduct(product* arr_products, int& counter)
{
	bigLine();
	cout << setw(68) << "Удаление товара" << endl;
	bigLine();
	int choice;
	showProducts(arr_products, counter);
	do {
		cout << "Введите номер продукта для удаления или 0 для выхода: ";
		inputPositiveNumber(choice);
	} while (choice > counter);
	if (choice == 0) return arr_products;
	
	choice--;
	counter--;int sure;
	do {
		cout << "Действительно удалить товар " << arr_products[choice].name << "?\n\t1 - Да\n\t0 - Отмена\n\tВыбор:" << endl;
		inputPositiveNumber(sure);
	} while (sure>2);
	product* temp = new product[counter];
	for (int i = 0; i < choice; i++)
		{
		temp[i] = arr_products[i];
		}
	for (int i = choice; i < counter; i++)
		{
		temp[i] = arr_products[i + 1];
		}
	delete[] arr_products;
	littleLine();
	cout << "\n\tЕдиница товара удалена\n" << endl;
	littleLine();
	return temp;
}
product* addProduct(product* arr, int &counter)
{
	product new_product;
	inputProduct(new_product);
	arr=rewriteArr(new_product, arr, counter);
	++counter;
	littleLine();
	cout<<endl<<setw(20) << "Новый продукт успешно добавлен в базу" << endl;
	littleLine();
	return arr;
}
void changeProduct(product* arr_products, int counter)
{
	bigLine();
	cout << setw(70) << "Редактирование продукта" << endl;
	bigLine();
	int number;
	showProducts(arr_products, counter);
	do {
		cout << "Введите номер продукта для редактирования или 0 для выхода: ";
		inputPositiveNumber(number);
	} while (number >= (counter+1));
	if (number == 0)
	{
		littleLine();
		cout << "Отмена редактирования" << endl;
		littleLine();
		return;
	}
	number--;
	int choise;
	littleLine();
	cout << "Вы выбрали продукт:" << endl;
	productHeader();
	showOneProduct(arr_products[number], number);
	littleLine();
	cout << "Что необходимо изменить?\n\t 1 - Наименование\n\t 2 - Количество\n\t 3 - Цена\n\t 4 - Дата поступления\n\t 5 - ФИО зарегистрировавшего\n\t 0 - Выход\nВыбор: ";
	inputPositiveNumber(choise);
	switch (choise)
	{
		case 1:
			cout << "Введите новое наименование: ";
			cin>>arr_products[number].name;
			break;
		case 2:
			cout << "Введите новое количество: ";
			inputPositiveNumber(arr_products[number].quantity);
			break;
		case 3:
			cout << "Введите новую цену: ";
			inputPositiveNumber( arr_products[number].price);
			break;
		case 4:
			inputDate(arr_products[number].date);
			break;
		case 5:
			cout << "Введите новую фамилию: ";
			cin >> arr_products[number].userSurname;
			cout << "Введите новое имя: ";
			cin>> arr_products[number].userName;
			cout << "Введите новое отчество: ";
			cin>> arr_products[number].userPatronymic;
			break;
		case 0: return;
		default: cout << "Ошибка действия" << endl;
	}
	littleLine();
	cout << "Продукт "<<number+1<<" изменён"<< endl;
	littleLine();
}
int countProducts()
{
	string s;
	int counter=0;
	fstream fread(FILE_OF_PRODUCTS, ios::in);
	while (!fread.eof())
	{
		fread >> s;
		counter++;
	}
	fread.close();
	counter /= PRODUCT_ATTRIBUTES;
	return counter;
}
void showProductsInAlfavit(product *arr, int counter)
{
	for (int i = 0; i < counter - 1; i++)
		for (int j = i + 1; j < counter; j++)
			if (arr[i].name > arr[j].name) 
				swap(arr[i], arr[j]);
	showProducts(arr, counter);
}
void showProductsInPrice(product* arr, int counter)
{
	for (int i = 0; i < counter - 1; i++)
		for (int j = i + 1; j < counter; j++)
			if (arr[i].price > arr[j].price) swap(arr[i], arr[j]);
	showProducts(arr, counter);
}
void showProductsInUserSurname(product* arr, int counter)
{
	for (int i = 0; i < counter - 1; i++)
		for (int j = i + 1; j < counter; j++)
			if (arr[i].userSurname > arr[j].userSurname) swap(arr[i], arr[j]);
	showProducts(arr, counter);
}
void searchByName(product* arr, int counter)
{
	string name;
	bool work = false;
	cout << "Введите наименование продукта для поиска: ";
	cin>> name;
	for(int i=0;i<counter; i++)
		if (name == arr[i].name)
		{
			if (!work) productHeader();
			showOneProduct(arr[i], i);
			work = true;
		}
	if (work == false) cout << endl << "По данному запросу ничего не найдено" << endl;
}
void searchBySurname(product* arr, int counter)
{
	string surname;
	bool work = false;
	cout << "Введите фамилию пользователя для поиска: ";
	cin>> surname;
	for (int i = 0; i < counter; i++)
		if (surname == arr[i].userSurname)
		{
			if (!work) productHeader();
			showOneProduct(arr[i], i);
			work = true;
		}
	if (work == false) cout << endl << "По данному запросу ничего не найдено" << endl;
}
void searchByMonth(product* arr, int counter)
{
	int month;
	bool work = false;
	cout << "Введите месяц внесения продукта в базу: ";
	inputPositiveNumber(month);
	for (int i = 0; i < counter; i++)
		if (month == arr[i].date.month)
		{
			if (!work) productHeader();
			showOneProduct(arr[i], i);
			work = true;
		}
	if (work == false) cout << endl << "По данному запросу ничего не найдено" << endl;
}
void userMenu()
{
	bigLine();
	cout <<setw(68)<< "Меню пользователя" << endl;
	bigLine();
	cout << "\t\t\t\t1 - Добавление продукта\n\t\t\t\t2 - Редактирование продукта\n\t\t\t\t3 - Удаление продукта" << endl;
	cout << "\t\t\t\t4 - Просмотреть продукты в порядке занесения\n\t\t\t\t5 - Просмотреть продукты используя сортировку\n\t\t\t\t6 - Поиск необходимого товара" << endl;
	cout << "\t\t\t\t7 - Продукты, которые хранятся более n месяцев и стоят более х\n\t\t\t\t0 - Выход из меню " << endl;
	cout << "\n\t\tВыбор: " ;
}
void sortProducts(product* arr, int counter)
{
	int choiсe;
	bigLine();
	cout << setw(69) << "Сортировка продуктов" << endl;
	bigLine();
	cout << "Как отсортировать продукты?\n\t 1 - По наименованию\n\t 2 - По цене\n\t 3 - По фамилии пользователя\n\tДругое - Выход\nВыбор: " ;
	inputPositiveNumber(choiсe);
	switch (choiсe)
	{
	case 1:
		showProductsInAlfavit(arr, counter);
		break;
	case 2:
		showProductsInPrice(arr, counter);
		break;
	case 3:
		showProductsInUserSurname(arr, counter);
		break;
	default: 
		cout << "Ошибка ввода, сортировка отменена" << endl;
		break;
	}
}
void searchProducts(product* arr, int counter)
{
	int choiсe;
	bigLine();
	cout << setw(67) << "Поиск продукта" << endl;
	bigLine();
	cout << "\tКак искать продукт?\n\t1 - По наименованию\n\t2 - По месяцу\n\t3 - По фамилии пользователя\n\tДругое - Выход" << endl;
	inputPositiveNumber(choiсe);
	switch (choiсe)
	{
	case 1:
		searchByName(arr, counter);
		break;
	case 2:
		searchByMonth(arr, counter);
		break;
	case 3:
		searchBySurname(arr, counter);
		break;
	default:
		cout << "Ошибка ввода, поиск отменён" << endl;
		break;
	}
}
void userActions(product* arr_of_products, int& counter)
{
	int choise;
	do {
		userMenu();
		inputPositiveNumber(choise);
		changeScreen();
		switch (choise)
		{
			case 1:
				arr_of_products = addProduct(arr_of_products, counter);//добавление ногово продукта 
				break;
			case 2:
				changeProduct(arr_of_products, counter);
				break;
			case 3:
				arr_of_products=deleteProduct(arr_of_products, counter);
				break;
			case 4:
				showProducts(arr_of_products, counter);
				break;
			case 5:
				sortProducts(arr_of_products, counter);
				break;
			case 6:
				searchProducts(arr_of_products, counter);
				break;
			case 7:
				showProductsStoredMaxMounthAndMinPrice(arr_of_products, counter);
				break;
			case 0:
				writeProductsToFile(arr_of_products, counter);
				return;
			default: 
				cout << endl<< "Ошибка ввода!" << endl;
				break;
		}
		changeScreen();
	} while (choise != 0);
}
void showProductsStoredMaxMounthAndMinPrice(product* arr, int counter)
{
	bigLine();
	cout <<setw(86)<< "Вывод продуктов с огничением по цене и времени хранения" << endl;
	bigLine();
	product* temp = new product[counter];
	int months, price, years=0;
	cout <<"Введите минимальное число месяцев, сколько хранится товар: " ;
	inputPositiveNumber(months);
	cout << "Введите минимальную стоимость товара: ";
	inputPositiveNumber(price);
	date now=getDate();
	int j = 0;
	if (months > 12)
	{
		years = months / 12;
		months -= years * 12;
		for (int i = 0; i < counter; i++)
			arr[i].date.year -= years;
		now.year -= years;
	}
	for (int i = 0; i < counter; i++)
	{
		if (arr[i].date.year == now.year && arr[i].price >= price && now.month-arr[i].date.month>=months)
		{
			temp[j] = arr[i];
			j++;
			continue;
		}
		if (now.year - arr[i].date.month == 1 && arr[i].price >= price)
		{
			if (12 + now.month - arr[i].date.month >= months)
			{
				temp[j] = arr[i];
				j++;
				continue;
			}
		}
		if (now.year - arr[i].date.year > 1 && arr[i].price >= price)
		{
			temp[j] = arr[i];
			j++;
			continue;
		}
	}
	if (j == 0)
	{
		littleLine();
		cout << "Продукты с такими параметрами не найдены" << endl;
		littleLine();
	}
	else showProductsInAlfavit(temp, j);
	for (int i = 0; i < counter; i++)
		arr[i].date.year += years;
	delete[] temp;
}
product* rewriteArr(product new_product, product* arr, int counter)
{
	product* temp = new product[counter + 1];
	for (int i = 0; i < counter; i++)
	{
		temp[i] = arr[i];
	}
	temp[counter] = new_product;
	return temp;
}