#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<stdio.h>
#pragma once;

using namespace std;
#pragma once
class storage
{
	string name;
	int amount;
	int cost;
	int number;
public:
	storage();
	~storage();
	storage& operator=(const storage&);
	bool operator<(storage);
	bool operator==(int);
	void operator=(int);
	bool operator!=(int);
	int operator+=(int);
	void SetName(string);
	void SetAmount(int);
	void SetCost(int);
	void SetNumber(int);
	string GetName();
	int GetAmount();
	int GetCost();
	int GetNumber();
	friend ostream& operator<<(ostream&, storage);
	friend ofstream& operator<<(ofstream&, storage);
};