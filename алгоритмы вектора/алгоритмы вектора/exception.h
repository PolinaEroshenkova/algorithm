#include<exception>
#include<iostream>
#pragma once;


class MenuException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Неверный выбор";
	}
};

class InputException :public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Вы ввели недопустимый символ!";
	}
};