#pragma once
#include "cpputil.h"
#include "unit.hpp"

NSBEGIN(SI)
	//dimension define
	NSBEGIN(Dim)
		//7 si units dimensions
		typedef dimension<1,0,0> length;
		typedef dimension<0,1,0> mass;
		typedef dimension<0,0,1> time;
		typedef dimension<0,0,0,1> electric_current;
		typedef dimension<0,0,0,0,1> thermodynamic_temperature;
		typedef dimension<0,0,0,0,0,1> amount_of_substance;
		typedef dimension<0,0,0,0,0,0,1> luminous_intensity;

		//si derived units dimension
		typedef dimension<2,0,0>	area;
		typedef dimension<3,0,0>	volume;
		typedef dimension<1,0,-1>	velocity;
		typedef velocity			speed;

		typedef dimension<0,0,-1>	frequency;
		typedef dimension<1,0,-2>	acceleration;
		typedef dimension<1,1,-1>	momentum;
		typedef dimension<1,1,-2>	force;

		typedef dimension<0,0,0>	scale;
	NSEND

//base units
UNIT_DEFINE_BASE(Meter,		Dim::length,						"meter",		"m"	);

UNIT_DEFINE_BASE(Kilogram,	Dim::mass,							"kilogram",		"kg");
UNIT_DEFINE_BASE(Second,	Dim::time,							"second",		"s"	);
UNIT_DEFINE_BASE(Ampere,	Dim::electric_current,				"ampere",		"A"	);
UNIT_DEFINE_BASE(Kelvin,	Dim::thermodynamic_temperature,		"kelvin",		"K"	);
UNIT_DEFINE_BASE(Mole,		Dim::amount_of_substance,			"mole",			"mol");
UNIT_DEFINE_BASE(Candela,	Dim::luminous_intensity,			"candela",		"cd");

//drived unit
UNIT_DEFINE_BASE(Newton,					Dim::force,			"newton",						"N");	
UNIT_DEFINE_BASE(MeterPerSecond,			Dim::speed,			"meter per second",				"m/s");
UNIT_DEFINE_BASE(MeterPerSecondSquared,		Dim::acceleration,	"meter per second squared",		"m/s2");
UNIT_DEFINE_BASE(SquareMeter,				Dim::area,			"square meter",					"m2");

typedef MeterPerSecond			Speed;
typedef Meter					Length;
typedef Second					Time;
typedef Newton					Force;
typedef MeterPerSecondSquared	Acceleration;
typedef SquareMeter				Area;
//other units
//mass
UNIT_DEFINE(Gram,			Dim::mass,			0.001,			"gram",				"g");
UNIT_DEFINE(Pound,			Dim::mass,			0.45359237,		"pound",			"lb");
UNIT_DEFINE(Tonne,			Dim::mass,			1000,			"tonne",			"t");
UNIT_DEFINE(OunceUS,		Dim::mass,			0.028,			"ounce",			"oz");

//length
UNIT_DEFINE(Foot,			Dim::length,		0.30480,		"feet",				"ft");
UNIT_DEFINE(Mile,			Dim::length,		1609.344,		"mile",				"mi");
UNIT_DEFINE(NauticalMile,	Dim::length,		1852.0,			"nautical mile",	"NM");
UNIT_DEFINE(Yard,			Dim::length,		0.9144,			"yard",				"yd");
UNIT_DEFINE(Inch,			Dim::length,		0.254,			"inch",				"in");
UNIT_DEFINE(Nanometer,		Dim::length,		1.0e-9,			"nanometer",		"nm");
UNIT_DEFINE(Centimeter,		Dim::length,		0.01,			"centimeter",		"cm");

//time
UNIT_DEFINE(Minute,			Dim::time,			60.0000,		"minute",			"min");
UNIT_DEFINE(Hour,			Dim::time,			3600.00,		"hour",				"h");
UNIT_DEFINE(Day,			Dim::time,			86400.0,		"day",				"d");

//speed
UNIT_DEFINE(Knot,			Dim::speed,			4.63/9.0,		"knot",				"kn");
UNIT_DEFINE(MilePerHour,	Dim::speed,			0.44704,		"mile per hour",	"mph");
UNIT_DEFINE(KilometerPerHour, Dim::speed,		1.0/3.6,		"kilometer per hour",	"km/h"	);



NSEND
