#pragma once
#ifndef __MAINTENANCETASK_H
#define __MAINTENANCETASK_H

#include"SpecialTasks.h"
class MaintenanceTask : public SpecialTasks
{
private:
	char* description;
public:
	MaintenanceTask();
	MaintenanceTask(const MaintenanceTask& other);
	~MaintenanceTask();

	char* getDescription() const;

	void setDescription(const char* description);

	friend ostream& operator<<(ostream& os, const MaintenanceTask &task); 
	friend istream& operator>>(istream is, MaintenanceTask &task);

};
#endif // !__MAINTENANCETASK_H

