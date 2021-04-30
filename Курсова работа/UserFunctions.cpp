#include "UserFunctions.h"
void productHeader()
{
	littleLine();
	cout << setw(5) << "�" << setw(23) << "������������" << setw(15) << "����������" << setw(10) << "����";
	cout << setw(25) << "���� �����������" << setw(20) << "��� �������" << endl;
	littleLine();
}
void inputProduct(product& in_product)
{
	bigLine();
	cout <<setw(72)<< "���������� ������ ������" << endl;
	bigLine();
	cout << "������������: ";
	in_product.name=inputStroky();
	cout << "����������: ";
	inputPositiveNumber(in_product.quantity);
	cout << "���� �� ���� ������� � BYN: ";
	inputPositiveNumber(in_product.price);
	inputDate(in_product.date);
	littleLine();
	cout <<setw(71)<< "������ � ��������������" << endl;
	littleLine();
	cout << "�������: ";
	cin >> in_product.userSurname;
	cout << "���: ";
	cin>> in_product.userName;
	cout << "��������: ";
	cin>>in_product.userPatronymic;
	bigLine();
}
void inputDate(date &in_date)
{
	int choise;
	date now_date;
	now_date = getDate();
	do {
		cout << "������ ����� ��� ����������� �����?\n\t1 - ��\n\t2 - ������ ����" << endl << "�����: ";
		inputPositiveNumber(choise);
	} while (choise < 1 || choise > 2);
	if (choise == 1) in_date = now_date;
	else
	{
		littleLine();
		cout << setw(72) << "������ � ���� �����������" << endl;
		littleLine();
		do {
			cout << "������� ���� �����������: ";
			inputPositiveNumber(in_date.day);
			cout << "������� ����� �����������: ";
			inputPositiveNumber(in_date.month);
			cout << "������� ��� �����������: ";
			inputPositiveNumber(in_date.year);
		} while (!isDateCorrect(in_date));
	}
}
void readProductsToArr(product* arr_products)
{
	ifstream fread(FILE_OF_PRODUCTS, ios::in);
	if (!fread.is_open())
		cout << "��������� ���� �� ����������" << endl;
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
		cout<<setw(71) << "��������� �� ���� ���" << endl;
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
	cout << setw(68) << "�������� ������" << endl;
	bigLine();
	int choice;
	showProducts(arr_products, counter);
	do {
		cout << "������� ����� �������� ��� �������� ��� 0 ��� ������: ";
		inputPositiveNumber(choice);
	} while (choice > counter);
	if (choice == 0) return arr_products;
	
	choice--;
	counter--;int sure;
	do {
		cout << "������������� ������� ����� " << arr_products[choice].name << "?\n\t1 - ��\n\t0 - ������\n\t�����:" << endl;
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
	cout << "\n\t������� ������ �������\n" << endl;
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
	cout<<endl<<setw(20) << "����� ������� ������� �������� � ����" << endl;
	littleLine();
	return arr;
}
void changeProduct(product* arr_products, int counter)
{
	bigLine();
	cout << setw(70) << "�������������� ��������" << endl;
	bigLine();
	int number;
	showProducts(arr_products, counter);
	do {
		cout << "������� ����� �������� ��� �������������� ��� 0 ��� ������: ";
		inputPositiveNumber(number);
	} while (number >= (counter+1));
	if (number == 0)
	{
		littleLine();
		cout << "������ ��������������" << endl;
		littleLine();
		return;
	}
	number--;
	int choise;
	littleLine();
	cout << "�� ������� �������:" << endl;
	productHeader();
	showOneProduct(arr_products[number], number);
	littleLine();
	cout << "��� ���������� ��������?\n\t 1 - ������������\n\t 2 - ����������\n\t 3 - ����\n\t 4 - ���� �����������\n\t 5 - ��� �������������������\n\t 0 - �����\n�����: ";
	inputPositiveNumber(choise);
	switch (choise)
	{
		case 1:
			cout << "������� ����� ������������: ";
			cin>>arr_products[number].name;
			break;
		case 2:
			cout << "������� ����� ����������: ";
			inputPositiveNumber(arr_products[number].quantity);
			break;
		case 3:
			cout << "������� ����� ����: ";
			inputPositiveNumber( arr_products[number].price);
			break;
		case 4:
			inputDate(arr_products[number].date);
			break;
		case 5:
			cout << "������� ����� �������: ";
			cin >> arr_products[number].userSurname;
			cout << "������� ����� ���: ";
			cin>> arr_products[number].userName;
			cout << "������� ����� ��������: ";
			cin>> arr_products[number].userPatronymic;
			break;
		case 0: return;
		default: cout << "������ ��������" << endl;
	}
	littleLine();
	cout << "������� "<<number+1<<" ������"<< endl;
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
	cout << "������� ������������ �������� ��� ������: ";
	cin>> name;
	for(int i=0;i<counter; i++)
		if (name == arr[i].name)
		{
			if (!work) productHeader();
			showOneProduct(arr[i], i);
			work = true;
		}
	if (work == false) cout << endl << "�� ������� ������� ������ �� �������" << endl;
}
void searchBySurname(product* arr, int counter)
{
	string surname;
	bool work = false;
	cout << "������� ������� ������������ ��� ������: ";
	cin>> surname;
	for (int i = 0; i < counter; i++)
		if (surname == arr[i].userSurname)
		{
			if (!work) productHeader();
			showOneProduct(arr[i], i);
			work = true;
		}
	if (work == false) cout << endl << "�� ������� ������� ������ �� �������" << endl;
}
void searchByMonth(product* arr, int counter)
{
	int month;
	bool work = false;
	cout << "������� ����� �������� �������� � ����: ";
	inputPositiveNumber(month);
	for (int i = 0; i < counter; i++)
		if (month == arr[i].date.month)
		{
			if (!work) productHeader();
			showOneProduct(arr[i], i);
			work = true;
		}
	if (work == false) cout << endl << "�� ������� ������� ������ �� �������" << endl;
}
void userMenu()
{
	bigLine();
	cout <<setw(68)<< "���� ������������" << endl;
	bigLine();
	cout << "\t\t\t\t1 - ���������� ��������\n\t\t\t\t2 - �������������� ��������\n\t\t\t\t3 - �������� ��������" << endl;
	cout << "\t\t\t\t4 - ����������� �������� � ������� ���������\n\t\t\t\t5 - ����������� �������� ��������� ����������\n\t\t\t\t6 - ����� ������������ ������" << endl;
	cout << "\t\t\t\t7 - ��������, ������� �������� ����� n ������� � ����� ����� �\n\t\t\t\t0 - ����� �� ���� " << endl;
	cout << "\n\t\t�����: " ;
}
void sortProducts(product* arr, int counter)
{
	int choi�e;
	bigLine();
	cout << setw(69) << "���������� ���������" << endl;
	bigLine();
	cout << "��� ������������� ��������?\n\t 1 - �� ������������\n\t 2 - �� ����\n\t 3 - �� ������� ������������\n\t������ - �����\n�����: " ;
	inputPositiveNumber(choi�e);
	switch (choi�e)
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
		cout << "������ �����, ���������� ��������" << endl;
		break;
	}
}
void searchProducts(product* arr, int counter)
{
	int choi�e;
	bigLine();
	cout << setw(67) << "����� ��������" << endl;
	bigLine();
	cout << "\t��� ������ �������?\n\t1 - �� ������������\n\t2 - �� ������\n\t3 - �� ������� ������������\n\t������ - �����" << endl;
	inputPositiveNumber(choi�e);
	switch (choi�e)
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
		cout << "������ �����, ����� ������" << endl;
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
				arr_of_products = addProduct(arr_of_products, counter);//���������� ������ �������� 
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
				cout << endl<< "������ �����!" << endl;
				break;
		}
		changeScreen();
	} while (choise != 0);
}
void showProductsStoredMaxMounthAndMinPrice(product* arr, int counter)
{
	bigLine();
	cout <<setw(86)<< "����� ��������� � ���������� �� ���� � ������� ��������" << endl;
	bigLine();
	product* temp = new product[counter];
	int months, price, years=0;
	cout <<"������� ����������� ����� �������, ������� �������� �����: " ;
	inputPositiveNumber(months);
	cout << "������� ����������� ��������� ������: ";
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
		cout << "�������� � ������ ����������� �� �������" << endl;
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