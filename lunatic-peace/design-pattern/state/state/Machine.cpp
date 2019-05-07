#include "Machine.h"

Machine::Machine(unsigned int inStockQuantity) { 
        mStockQuantity = inStockQuantity;
        if (inStockQuantity > 0) {
            mState = new Normal();
        }
        else {
            mState = new SoldOut();
        }
    }

Machine::~Machine() {
    delete mState;
}

void Machine::sell(unsigned int quantity) {
    mState->sell(*this, quantity);
}

void Machine::refill(unsigned int quantity) {
    mState->refill(*this, quantity);
}

unsigned int Machine::getCurrentStock() {
    return mStockQuantity;
}