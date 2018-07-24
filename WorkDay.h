#ifndef __WORKDAY_H

#define __WORKDAY_H
#define OPEN_HOURES_FULL_DAY " 8:00 - 22:00 "
#define OPEN_HOURES_MORNING_ONLY " 8:00 - 17:00 "
#define OPEN_HOURES_EVNING_ONLY " 17:00 23:00 "

#include <time.h>
#include "Shift.h"

class WorkDay
{
private:
	time_t date;
	const char* openHours;
	bool fullDay ;
	char* notes;
	Shift *shifts;

public:
	WorkDay(time_t date, char* openHours = nullptr, char* notes = nullptr, bool fullDay = true) ;
	WorkDay(const WorkDay&& other);
	~WorkDay();

	const time_t getDate()		const { return date; }
	const char* getOpenHours()	const { return openHours; }
	bool  isFullDay()			const { return fullDay; }
	char* getNotes()			const { return notes; }

	void setNotes();

	void showWorkDay()			const;

	Shift& operator[](int index)		throw(NullPointerExeption); //To get shift morning/evning. by eShiftType or number.
	
	friend ostream& operator<<(ostream os, const WorkDay& workDay);
};

#endif // !__WORKDAY_H
