#include<exception>
#include<iostream>
#pragma once;


class MenuException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "�������� �����";
	}
};

class InputException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "�� ����� ������������ ������!";
	}
};