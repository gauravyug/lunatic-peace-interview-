//---------------------------------------------------------------------------

#ifndef TLGreenH
#define TLGreenH
#include <iostream>
#include <stdio.h>
#include "VendingMachineState.h"
#include "FoodVendingMachine.h"
//---------------------------------------------------------------------------

class VendingMachineDeposit: public VendingMachineState
{
	private:
		FoodVendingMachine* _context;

	public:
		VendingMachineDeposit(FoodVendingMachine* context);
		void Handle();
};

#endif
