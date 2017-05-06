#include"algorithm.h"�
#include"storage.h"
#include"exception.h"
#include<iterator>
#include<string>
#include<algorithm>

int main(){
	setlocale(LC_ALL, "RUS");
	system("chcp 1251");
	int choice;
	int flags;
	int number;
	char error;
	bool result;
	int N;
	char ch;
	vector<storage> store;
	vector<storage> store2;
	vector<storage> store3(20);
	vector<int> buffer;
	vector<int>::iterator begin_int;
	algorithm<storage,int> function;
	vector<storage>::iterator begin;
	vector<storage>::iterator end;
	vector<storage>::iterator temp;
	while (1)
	{
		cout << "1. ������ ������" << endl;
		cout << "2. ������� �� �����" << endl;
		cout << "3. ������������� ������" << endl;
		cout << "4. ����� �� �������" << endl;
		cout << "5. ��������� ������" << endl;
		cout << "6. �������� ������" << endl;
		cout << "7. ����� ����� ��������� ������ �� ������" << endl;
		cout << "8. ���������� ��� ������" << endl;
		cout << "9. �����" << endl;
		cout << "��� �����: ";
		try{
			cin >> choice;
			flags = cin.rdstate();
			if (flags & ios::failbit)
			{
				cin.clear(0);
				cin >> error;
				throw MenuException();
			}
		}
		catch (MenuException &e)
		{
			cout << e.what() << endl;
			break;
		}

		switch (choice)
		{
		case 1:
			system("cls");
			store.push_back(function.add());
			cout << "��������� �������" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			for (begin = store.begin(); begin != store.end(); begin++)
			{
				cout << *begin << endl;
			}
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			begin = store.begin();
			end = store.end();
			function.sort(begin, end);
			cout << "��������� �������" << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "������� ����������������� �����: ";
			try{
				cin >> N;
				flags = cin.rdstate();
				if (flags & ios::failbit)
				{
					cin.clear(0);
					cin >> error;
					throw MenuException();
				}
			}
			catch (MenuException &e)
			{
				cout << e.what() << endl;
				break;
			}
			temp = function.find(store.begin(),store.end(), N);
			if (temp != store.end())
			{
				cout << *temp << endl;
			}
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			function.generate(store.begin(), store.end(), &Lucas_numbers);
			cout << "��������� �������" << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			cout << "������� ����������������� ������ ��� ��������" << endl;
			for (begin = store.begin(); begin != store.end(); begin++)
			{
				cin >> number;
				buffer.push_back(number);
			}
			result = function.equal(store.begin(), store.end(), buffer.begin());
			if (result) cout << "����������������� ������ ���������" << endl;
			else cout << "�������" << endl;
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			cout << "����� ����� �����: ";
			cout << function.count(store.begin(), store.end()) << endl;
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			cout << "������� ������: " << endl;
			do{
				store2.push_back(function.add());
				cout << "�����? (y/n)";
				cin >> ch;
			} while (ch != 110);
			end=function.set_union(store.begin(), store.end(), store2.begin(), store2.end(), store3.begin());
			N = end - store3.begin();
			store3.resize(N);
			store.clear();
			store.resize(N);
			copy(store3.begin(), store3.end(), store.begin());
			cout << "��������� �������" << endl;
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			return 0;
		default:
			cout << "��� ������ ����" << endl;
		}
	}

}