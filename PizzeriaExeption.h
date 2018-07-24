#ifndef PIZZERIAEXEPTION_H
#define PIZZERIAEXEPTION_H

#include <iostream>

using namespace std;

class PizzeriaExeption
{
public:
	virtual void print()const { cout << "PizzeriaExeption.\n"; }
};
class NegativeNumberExeption : public PizzeriaExeption
{
public:
	virtual void print()const { cout << "Negative Number Exeption.\n"; }

};
class SeatsExeption : public NegativeNumberExeption
{
public:
	virtual void print() const
	{
		cout << "Invalid number of sets (must be positive).\n";
	}
};

class WorkDayExeption : public PizzeriaExeption
{
public:
	virtual void print()const { cout << "Eror. workDatExpration.\n"; }
};

class WorkerExeption : public PizzeriaExeption
{
public:
	virtual void print()const { cout << "Eror. WorkerExpration.\n"; }
};
class NegetiveNumbersOfVehiacleExpration :public NegativeNumberExeption
{
public:
	virtual void print() const { cout << "vehiacle numbers can't be negtive." << endl; }
};

class NegetiveNumbersOfWorkerExpration : public NegativeNumberExeption
{
public:
	virtual void print() const { cout << "Workers numbers can't be negtive." << endl; }
};
class NullPointerExeption:public PizzeriaExeption , public WorkDayExeption
{
public:
	virtual void print() const { cout << "The index outside the array boundaries." << endl; }
};

class DateTypeExeption :public PizzeriaExeption , public WorkerExeption
{
public:
	virtual void print() const { cout << "Eror.enter value frome type \"time_t\"." << endl; }
};


class ProductExeption: public PizzeriaExeption
{
public:
	virtual void print() const { cout << "Product exeption." << endl; }
};

class NegativePriceExeption : public ProductExeption, public NegativeNumberExeption
{
public:
	virtual void print() const { cout << "Price must be positive." << endl; }
};

class PersonExeption : public PizzeriaExeption
{
public:
	virtual void print() const { cout << "PersonExeption.\n"; }
};


class NameExeption : public PersonExeption
{
public:
	virtual void print()
	{
		std::cout << "Name must countain letters only.";
	}
};

class phoneNumberExeption : public PizzeriaExeption, public PersonExeption 
{
public:
	virtual void print() const
	{
		cout << "Phone number problem .\n";
	}
};
class phoneNumberSizeExeption : public phoneNumberExeption
{
	virtual void print() const
	{
		cout << "Phone number must be between 9-10 numbers.\n";
	}
};
class phoneNumberDigitExeption : public phoneNumberExeption
{
	virtual void print() const
	{
		cout << "Phone number must be numbers only!.\n";
	}
};


class FreezerExeption : public PizzeriaExeption
{
public:
	virtual void print() const { cout << "Eror. freezer exeption." << endl; }
};


class DoghExeptoin : public FreezerExeption
{
public:
	virtual void print() const { cout << "Freezer can contain only doughs." << endl; }
};
class NegativeNumberOfDoughts : public FreezerExeption, public NegativeNumberExeption
{
	public:
		virtual void print() const { cout << "Number of doughts must be positive.\n"; }
};


class OrderExeption : public PizzeriaExeption
{
public:
	virtual void print() const { cout << "Eror. order exeption." << endl; }
};

class NegativeNumberOfPizzaExpretion : public  OrderExeption,public NegativeNumberExeption
{
public:
	virtual void print() const { cout << "Number of pizza must be positive." << endl; }
};


class VehicaleExeption :public PizzeriaExeption
{
public:
	virtual void print() const { cout << "Eror. problem with vwhicale details." << endl; }
};

class NegativeCapacityExeption : public FreezerExeption, public NegativeNumberExeption, public VehicaleExeption
{
public:
	virtual void print() const { cout << "Capacity must be positive." << endl; }
};

class NegativeSalaryExeption : public WorkerExeption, public NegativeNumberExeption
{
public:
	virtual void print()const { cout << "Salary must be positive.\n"; }
};
class JobExeption : public WorkerExeption
{
public:
	virtual void print()const { cout << "JobExeption - Jub didn't exist.\n"; }
};

class StockExeption : public PizzeriaExeption
{
public:
	virtual void print() const { cout << "Eror. StockExeption.\n"; }
};

class ProductDoesNotExistExeption : public StockExeption
{
public:
	virtual void print() const { cout << "Product does not exist.\n"; }
};
class FreezerDoesNotExistExeption : public StockExeption
{
public:
	virtual void print() const { cout << "Freezer does not exist.\n"; }
};
#endif // !PIZZERIAEXEPTION_H
