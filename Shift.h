#ifndef __SHIFT_H
#define __SHIFT_H
#include"PizzeriaExeption.h"
#include "Worker.h"
#include "Order.h"
#include "SpecialTasks.h"

class Shift
{
public:

	enum eShiftType {MORNING , EVNING };

	Shift(eShiftType type); // Entering the rest of the detail in the c'tor
	~Shift();

	Worker getWorker()		const;
	eShiftType getType()	const;

	Order& getOrderByPhone(const char* phoneNumber)			const;
	SpecialTasks&  getSpesialTasks()						const{ return *sTask; }
	
	void addWorker(Worker& worker)			throw(WorkerExeption);
	void removeWorker(const char* id)		throw(NegetiveNumbersOfWorkerExpration);

	void showShift()			const;
	void showSpeicalTasks()		const;
	void showAllOrders()		const;
	void showOrdersToPrepare()	const;
	void showWorkers()			const;

	const Shift& operator+=(const Worker& worker);
	const Shift& operator+=(const Order& order);
	const Shift& operator+=(const SpecialTasks& sTasks);


	const Shift& operator-=(const Worker& worker);
	const Shift& operator-=(const Order& order);
	const Shift& operator-=(const SpecialTasks& sTasks);

	const Shift& operator=(const Shift& other);

	friend Shift& operator+(const Shift& shift ,const Worker& worker)		;
	friend Shift& operator+(const Shift& shift, const Order& order)			;
	friend Shift& operator+(const Shift& shift, const SpecialTasks& sTasks)	;

	friend Shift& operator+(const Worker& worker, const Shift& shift)			;
	friend Shift& operator+(const Order& order , const Shift& shift)			;
	friend Shift& operator+(const SpecialTasks& sTasksconst,const Shift& shift)	;

	friend ostream& operator<<(ostream& os, const  Shift shift);
	
private:

	//----- need to cheak arrys-------//
	const eShiftType type;
	Worker *workers;
	Order *orders;
	SpecialTasks* sTask;
};
#endif // !__SHIFT_Haw