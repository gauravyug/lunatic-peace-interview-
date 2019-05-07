//---------------------------------------------------------------------------

#ifndef VENDING_MACHINE_STOCK_H 
#define VENDING_MACHINE_STOCK_H
#include <iostream>
#include <stdio.h>
#include "VendingMachineState.h"
#include "FoodVendingMachine.h"
//---------------------------------------------------------------------------

class VendingMachineStock: public VendingMachineState
{
	private:
		FoodVendingMachine* _context;

	public:
		VendingMachineStock(FoodVendingMachine* context);
		void Handle();
};
#endif
