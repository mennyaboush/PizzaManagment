#pragma once
#ifndef __SPECIALORDER_H
#define __SPECIALORDER_H

#include"SpecialTasks.h"
#include"Order.h"
#include<time.h>
class SpecialOrder:public SpecialTasks , public Order 
{
private:
	time_t estimatedTimeAndDate;
public:
	SpecialOrder();

	time_t getTimeDate()				const { return estimatedTimeAndDate; }
	time_t setTimeDate(time_t timeDate)	const throw(DateTypeExeption);

	friend ostream& operator<<(ostream& os, const SpecialOrder &order);
};
#endif // !__SPECIALORDER_H

