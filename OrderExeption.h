#pragma once
#ifndef __ORDEREXEPTION_H
#define __ORDEREXEPTION_H

#include<iostream>
#include"PizzeriaExeption.h"
using namespace std;

class OrderExeption : public PizzeriaExeption
{
public:
	virtual void print() const { cout << "Eror. order exeption." << endl; }
};

class NegativeNumberOfPizzaExpretion : public  OrderExeption
{
public:
	virtual void print() const { cout << "Number of pizza must be positive." << endl; }
};

#endif // !__ORDEREXEPTION_H
