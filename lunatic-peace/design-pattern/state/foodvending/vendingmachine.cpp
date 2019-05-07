#include <iostream>
#include "food-vending-machine.h"

int main()
{
    FoodVendingMachine machine(10);
    machine.coinInsert();
   // machine.dispense();
    cout << machine.getcurrentstock();
    return 0;
}