/*
UTILITIES.H

public:
	void Inform(string info) const;
		pre:	none
		post:	program output is directed through this function,
				can be set to standard display or a log file
*/


#ifndef UTILITIES_H
#define UTILITIES_H

#include "stdafx.h"

class utilities
{
public:
	void Inform(string info) const;
};
#endif