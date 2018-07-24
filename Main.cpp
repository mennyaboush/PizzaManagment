#include <iostream>
#include"Pizzeria.h"
#include "Person.h"

#define PIZZERIA_PHONE 02-9999999

using namespace std;

void newTerminate()
{
	cout << "\nEror.try to catch this exeption.\n";
	exit(1);
}

void main()
{
	set_terminate(newTerminate);//replace the terminate function.

	//---create pizzeria---//
	Person owner("052-123456789", "Yosi");
	Pizzeria myPizza("02-9999999",owner,20);
	
	myPizza.createWorkArragement();
	
	myPizza.show();
	//adding products
	for (int i = 0; i < 30; i++)
	{
		myPizza.getStock().addProduct();
	}

	cout << "After adding product.\n";
	myPizza.showStock();

	//---remove product product CocaCola until we need to order--//
	char* productName = "CocaCola" ;
	while(!myPizza.getStock().getProductByName(productName).getNeedToOrder)
		myPizza.getWorkerByName("Dan").takeProduct(productName); //finish with printing massege to Order CocaCola.

	myPizza.removeVehicle(123456);//add cehicle with license number '123456' in the c'tor

	cout << "\nMaintenance product in the stock .\n";
	myPizza.getStock().showProductByType(myPizza.getStock().MAINTENANCE_PRODUCTS);

	//add freezer with the id 1 in the c'tor.  & print massege for the damged frezzer.
	myPizza.getStock().getFreezer(1).setDamaged(true);

	myPizza.getWorkerByName("Dan").takerOrder();
	cout << "\nShow order Dan take.\n";
	myPizza.getWorkerByName("Dan").showOrders(false);
	myPizza.getWorkerByName("Dan").getOrderByPhone("050-999999999").orderSent();
	
	//create special order:
	myPizza.getWorkerByName("Dan").takeSpecialOrder();
	
	//create special task:
	myPizza.addSpecialTask();
	cout << "\nShow Dan's orders that has been sent .\n";
	myPizza.getWorkerByName("Dan").showOrders(true);
	cout << "\n show special tasks: \n";
	
	//show special tasks
	myPizza.showSpecialTasks();
	
	//take avilable shift for workers:
	Worker *workersArry = myPizza.getWorkers();
	int size = myPizza.getNumOfWorkers();
	for (int i = 0; i < size; i++) 
	{
		workersArry[i].takeAvailableShifts();
	}
	// show the current arragement 
	myPizza.showCurrentWorkArragement();

	//show myPizza with osteram (<<) operator.
	cout << myPizza;
}

