#pragma once
#include "..\..\sim\cpputil.h"
#include "..\..\sim\unit.h"
#include "..\..\sim\quantity.hpp"


NSBEGIN(Model)
NSBEGIN(Airport)




class Flight
{
public:
	struct Perform
	{
		Quantity<SI::Speed> touchDownSpeed;
		Quantity<SI::Speed> taxiSpeed;
		
	};




};



NSEND
NSEND
