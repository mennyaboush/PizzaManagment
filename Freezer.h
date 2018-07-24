#pragma once
#ifndef __FREEZER_H
#define __FREEZER_H

#include"Product.h"
#include "Person.h"

class Freezer
{
private:
	int id;
	bool damaged;
	int capacity;
	int maxCapacity;
	Product* doughs;

public:
	Freezer(int capacity, int maxCapacity, bool damaged = false);
	Freezer(const Freezer& other);
	Freezer(const Freezer&& other);
	~Freezer();

	int getId()				const { return id; }
	bool getDamaged()		const { return damaged; }
	int getCapacity()		const { return capacity; }
	int getMaxCapacity()	const { return maxCapacity; }

	void setDamaged(bool isDamaged);
	void setCapacity(int capacity)	throw (NegativeCapacityExeption);

	const Freezer& operator=(const Freezer& other);

	const Freezer& operator+=(Product dough) throw (DoghExeptoin);
	const Freezer& operator-=(Product dough) throw (DoghExeptoin);

	friend ostream& operator<<(ostream os, const Person& owner);
};
#endif // !__FREEZER_H
