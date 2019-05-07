#pragma once

#include "MachineStates.h"

class AbstractState;
class Machine {
    friend class AbstractState;
    public:
        Machine(unsigned int inStockQuantity);
        void sell(unsigned int quantity);
        void refill(unsigned int quantity);
        unsigned int getCurrentStock();
        ~Machine();
    private:
        unsigned int mStockQuantity;
        AbstractState* mState;
};