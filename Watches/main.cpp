#pragma once

#include <iostream>

#include "PWatch.h"
#include "ABracelet.h"
#include "ABody.h"
#include "AClasp.h"
#include "AGlass.h"
#include "MDouble.h"

using namespace std;

int main()
{
	/*
		TESTING THE MECHANISMS
	*/
	
	MAnalogue Analogue(312., 20200314);
	MDigital Digital(32., "11:45", "7:00");
	MDouble Double(543., "8:20", 20200312, "6:30");

	cout << Analogue << endl << Digital << endl << Double << endl;

	/*
		TESTING THE WATCH
	*/

	PWatch Watch(new MDouble(468.00, "9:15", 20200315, "7:00"));

	// adding some accessories
	Watch += new ABracelet("leather", 54.);
	Watch += new AClasp("steel", 12.5);
	Watch += new ABody("steel", 36.6);
	Watch += new AGlass("quartz", 44.8);

	cout << "PWatch Watch:" << endl;
	cout << Watch << endl;

	// copy constructor is called
	PWatch Watch2(Watch);
	cout << "PWatch Watch2:" << endl;
	cout << Watch2 << endl;

	// operator= is called
	PWatch Watch3 = Watch2;
	cout << "PWatch Watch3:" << endl;
	cout << Watch3 << endl;

	return 0;
}