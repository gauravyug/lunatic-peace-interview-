//---------------------------------------------------------------------------


#pragma hdrstop

#include "TLNetTraffic.h"
#include "TLRed.h"

//---------------------------------------------------------------------------

TLNetTraffic::TLNetTraffic()
{
	_state = new TLRed(this);
}

void TLNetTraffic::setState ( TLState* state )
{
	_state = state;
}

void TLNetTraffic::Handle ()
{
	_state->Handle();
}

#pragma package(smart_init)
