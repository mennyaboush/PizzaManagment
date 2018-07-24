#pragma once
#ifndef __DOUOGHPREPARATION_H
#define __DOUOGHPREPARATION_H

#include"SpecialTasks.h"

class DoughPreparation :public SpecialTasks
{
private:
	int numberToMade;

public:

	DoughPreparation(int numberToMade = 400)	throw(NegativeNumberOfDoughts);

	int getNumberToMade()						const { return numberToMade; }

	void setNumberToMade(int numberToMade)		throw(NegativeNumberOfDoughts);
	
	friend ostream operator<<(ostream os, const DoughPreparation &dp);
	friend istream operator>>(istream is, DoughPreparation &dp);
};
#endif // !__DOUOGHPREPARATION_H

