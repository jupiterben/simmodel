#pragma once
#include "..\..\sim\Event.h"


NSBEGIN(Model)
NSBEGIN(Airport)

class TheModel : public Sim::Model
{
public:


};


NSBEGIN(Airside)
	//ground items
	class Runway 
	{
	public:
		class LogicRunway
		{

		};


	protected:
		LogicRunway* logic1;
		LogicRunway* logic2;
	};
	
	class Taxiway
	{
	public:


	};

	class Stand
	{
	public:
		class LeadLine
		{

		};
	};

	//
	class IntersectionNode
	{
	public:

	};

	class Ground
	{
	public:

	protected:


	};


	//airspace
	class AirFix
	{

	};

	class AirRoute
	{

	};

	class AirHold
	{

	};
	

	class Airspace
	{

	};



NSEND
NSEND
NSEND