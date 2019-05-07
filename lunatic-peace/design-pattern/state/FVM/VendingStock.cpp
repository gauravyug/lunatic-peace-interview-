//---------------------------------------------------------------------------


#pragma hdrstop

#include "VendingStock.h"
#include "VendingDeposit.h"

//---------------------------------------------------------------------------
VendingMachineStock(FoodVendingMachine* context): _context(context) {};

void VendingMachineStock::Handle()
{
	printf("Vending Machine Stock t\n");
	_context->setState( new vendingDepositState(_context) );
}

#pragma package(smart_init)
