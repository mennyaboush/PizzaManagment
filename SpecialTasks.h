#pragma once
#ifndef __SPECIALTASKS_H
#define __SPECIALTASKS_H

#include "PizzeriaExeption.h"

class SpecialTasks
{
private:
	int numberOfWorkerRequired;
	SpecialTasks(int numberOfWorkerRequired = 1)	throw(NegetiveNumbersOfWorkerExpration);
public:
	
	const int getNumberOfWorkerRequired()			const{ return numberOfWorkerRequired; }
	void setNumberOfWorkerRequired(int numOfWorkers)const throw(NegetiveNumbersOfWorkerExpration);

	void show() const;

	virtual void toOs()						const;

	friend ostream& operator<<(ostream& os, const  SpecialTasks& task);
	friend istream& operator>>(istream& is, SpecialTasks& task);
};
#endif // !__SPECIALTASKS_H

