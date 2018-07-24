#ifndef __OWNER_H
#define __OWNER_H

#include"PizzeriaExeption.h"

class Person
{
private:
	char* phoneNumber;
	char* name;

public:
	Person(char* phoneNumber, const char* name);
	Person(const Person& other) = delete;
	~Person();

	const char* getName()			const { return name; }
	const char* getPhoneNumber ()	const{ return phoneNumber; }

	void setName(const char* name)					throw (NameExeption);
	void setPhoneNumber(const char *phoneNumber)	throw (phoneNumberExeption); 

	friend ostream& operator<<(ostream os, const Person& owner);
	friend istream& operator>>(istream in, Person& owner) throw (NameExeption , phoneNumberExeption);
};
#endif // !__OWNER_H
