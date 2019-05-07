//---------------------------------------------------------------------------


#pragma hdrstop   

#include "TLYellow.h"
#include "TLRed.h"

//---------------------------------------------------------------------------
TLYellow::TLYellow(TLNetTraffic* context): _context(context) {};

void TLYellow::Handle()
{
	printf("Yellow Light\n");
	_context->setState( new TLRed(_context) );
}
#pragma package(smart_init)
