#ifndef __VEHICLE_H
#define __VEHICLE_H
#include <datetimeapi.h>
#include <time.h>
#include "PizzeriaExeption.h"

//-----------define for time unit ---------//
#define SECOND              1
#define MINUTE              60 * SECOND
#define HOUR                60 * MINUTE
#define DAY                 24 * HOUR
#define WEEK                7 * DAY
#define MONTH				4 * WEEK
#define YEAR				12 * MONTH

class Vehicle
{

public:

	enum eVehicleType{CAR , MOTORCYCLE };

	Vehicle(time_t validnsurance, time_t testdate, int licenseNumber, int capacity);

	const time_t getValidinsurance()	const { return validnsurance; }
	const time_t getTestdate()			const { return testdate; }
	eVehicleType getVehicleType()		const { return type; }
	int getLicenseNumber()				const { return licenseNumber; }
	int getCapacity()					const { return capacity; }

	void setCapacity(int capacity)		throw(VehicaleExeption);
	void setTestDate();	

	void showVehicle() const;
	//bool testDone(); -- unnecessary

	friend ostream&  operator<<(ostream os, const Vehicle vehicle);

private:
	time_t validnsurance;
	time_t testdate;
	const int licenseNumber;
	const int capacity;
	const eVehicleType type;

};
#endif // !__VEHICLE_H
#pragma once
