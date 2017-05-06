#include"storage.h"
#include"validation.h"
#include<iterator>
#include<vector>

const string successful = "Выполнено успешно";
const string TYPE = "Введите ";
const string NAME = "Наименование изделия";
const string SUM = "Количество";
const string COST = "Стоимость";
const string NUMBER = "Идентификационный номер";
const string PRODUCT = "Изделия";


template<class T,class U>
class algorithm{
public:
	storage add();
	void sort(typename vector<T>::iterator,typename vector<T>::iterator);
	typename vector<T>::iterator find(typename vector<T>::iterator, typename vector<T>::iterator, int);
	void generate(typename vector<T>::iterator, typename vector<T>::iterator, int (*f)());
	//template<class U>
	bool equal(typename vector<T>::iterator, typename vector<T>::iterator, typename vector<U>::iterator);
	int count(typename vector<T>::iterator, typename vector<T>::iterator);
	typename vector<T>::iterator set_union(typename vector<T>::iterator, typename vector<T>::iterator, typename vector<T>::iterator, typename vector<T>::iterator, typename vector<T>::iterator&);
};

int Lucas_numbers()
{
	static int a = 2;
	static int b = 1;
	static int c;
	c = a + b;
	a = b;
	b = c;
	return a;
}

int operator+=(int& sum,storage store)
{
	sum =sum+ store.GetAmount()*store.GetCost();
	return sum;
}


template<class T,class U>
storage algorithm<T,U>::add(){
	string name;
	int amount;
	int cost;
	int number;
storage store;
InputValidation validation;
cout << TYPE << NAME << ": ";
cin.sync();
getline(cin, name);
try{
	cout << TYPE << "общее " << SUM << " изделий: ";
	cin >> amount;
	validation.CheckNumber(amount);
	cout << TYPE << COST << " одного " << PRODUCT << ": ";
	cin >> cost;
	validation.CheckNumber(cost);
	cout << TYPE << NUMBER << " " << PRODUCT << ": ";
	cin >> number;
	validation.CheckNumber(number);
}
catch (InputException e)
{
	cout << e.what() << endl;
	return store;
}
store.SetName(name);
store.SetAmount(amount);
store.SetCost(cost);
store.SetNumber(number);
return store;
}

template<class T, class U>
void algorithm<T,U>::sort(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
	vector<T>::iterator tmp1;
	vector<T>::iterator tmp2;
	if (!(begin < end))
		return;
	for (tmp1 = begin + 1; tmp1 != end; tmp1++)
	{
		for (tmp2 = tmp1; tmp2 != begin && *tmp2 < *(tmp2 - 1); tmp2--)
			iter_swap(tmp2 - 1, tmp2);
	}
}

template<class T, class U>
typename vector<T>::iterator algorithm<T,U>::find(typename vector<T>::iterator begin, typename vector<T>::iterator end, int number){
	for (begin; begin != end; begin++)
	{
		if (*begin == number)
			return begin;
	}
	return begin;
}

template<class T, class U>
void algorithm<T,U>::generate(typename vector<T>::iterator begin, typename vector<T>::iterator end, int(*f)())
{
	for (begin; begin != end; begin++)
	{
		*begin = f();
	}
}

template<class T, class U>
//template<class U>
bool algorithm<T,U>::equal(typename vector<T>::iterator begin, typename vector<T>::iterator end,typename vector<U>::iterator begin_int)
{
	for (begin; begin != end; begin++, begin_int++)
	{
		if (*begin != *begin_int)
			return false;
	}
	return true;
}

template<class T, class U>
int algorithm<T,U>::count(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
	int sum = 0;
	for (begin; begin != end; begin++)
	{
		sum += *begin;
	}
	return sum;
}

template<class T, class U>
typename vector<T>::iterator algorithm<T,U>::set_union(typename vector<T>::iterator begin1, typename vector<T>::iterator end1, typename vector<T>::iterator begin2, typename vector<T>::iterator end2, typename vector<T>::iterator &result)
{

	for (begin1; begin1 != end1; begin1++)
	{
		cout << "1";
		*result++ = *begin1;
		cout << "2";
	}
	for (begin2; begin2 != end2; begin2++)
	{
		cout << "3";
		*result++ = *begin2;
		cout << "4";
	}
	return result;
}
