#include"storage.h"

const string successful = "Выполнено успешно";
const string TYPE = "Введите ";
const string NAME = "Наименование изделия";
const string SUM = "Количество";
const string COST = "Стоимость";
const string NUMBER = "Идентификационный номер";
const string PRODUCT = "Изделия";

storage::storage()
{
	name = "";
	cost = 0;
	number = 0;
	amount = 0;
}
storage::~storage(){}
void storage::SetName(string temp)
{
	name = temp;
}
void storage::SetAmount(int temp)
{
	amount = temp;
}
void storage::SetCost(int temp)
{
	cost = temp;
}
void storage::SetNumber(int temp)
{
	number = temp;
}
string storage::GetName()
{
	return name;
}
int storage::GetAmount()
{
	return amount;
}
int storage::GetCost()
{
	return cost;
}
int storage::GetNumber()
{
	return number;
}
ostream& operator<<(ostream& cout, storage store)
{
	cout << endl << NAME << ": " << store.GetName() << endl;
	cout << "Общее " << SUM << ": " << store.GetAmount() << endl;
	cout << COST << " за штуку: " << store.GetCost() << endl;
	cout << NUMBER << ": " << store.GetNumber();
	return cout;
}
storage& storage::operator=(const storage&obj)
{
	name = obj.name;
	amount = obj.amount;
	cost = obj.cost;
	number = obj.number;
	return *this;
}
ofstream& operator<<(ofstream& f, storage store){
	cout << endl << NAME << ": " << store.GetName() << endl;
	cout << "Общее " << SUM << ": " << store.GetAmount() << endl;
	cout << COST << " за штуку: " << store.GetCost() << endl;
	cout << NUMBER << ": " << store.GetNumber();
	return f;
}
bool storage::operator<(storage tmp)
{
	return cost < tmp.cost;
}
bool storage::operator==(int number)
{
	return this->number == number;
}
void storage::operator=(int N)
{
	amount = N;
}
bool storage::operator!=(int number)
{
	return this->number != number;
}

