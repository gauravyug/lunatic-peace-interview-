//---------------------------------------------------------------------------

#ifndef TLYellowH
#define TLYellowH
#include <iostream>
#include <stdio.h>
#include "TLState.h"
#include "TLNetTraffic.h"
//---------------------------------------------------------------------------
class TLYellow: public TLState
{
	private:
		TLNetTraffic* _context;

	public:
		TLYellow(TLNetTraffic* context);
		void Handle();
};
#endif
