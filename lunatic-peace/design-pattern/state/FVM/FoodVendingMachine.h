//---------------------------------------------------------------------------

#ifndef FOOD_VENDING_MACHINE_H
#define FOOD_VENDING_MACHINE_H

#include "VendingMachineState.h"
//---------------------------------------------------------------------------
class FoodVendingMachine
{
	private:
		VendingMachineState* _state;
	public:
		FoodVendingMachine();
		void setState ( VendingMachineState* state );
		void Handle();
};
#endif
