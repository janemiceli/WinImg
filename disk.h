/*
DISK.H

public:
	bool driveGeometry();
		pre:	select disk to obtain information from using
				setDrive() function
		post:	available information about the drive is stored
				in geometry variable, and is available with
				getGeometry(), return success

	bool setDrive(int number);
		pre:	number == 0 or 1
		post:	select the disk that will be queried, return success

	DISK_GEOMETRY getGeometry() const;
		pre:	driveGeometry() must be run to first obtain
				the information.
		post:	returns a DISK_GEOMETRY class item that
				contains information about the disk

	void test();
		pre:	run driveGeometry();
		post:	this is only a debug function written for testing,
				it prints the number of bytes/sector to the screen,
				this function can safely be removed
private:
	DISK_GEOMETRY geometry;
	LPCSTR driveNumber;
*/


#ifndef DISK_H
#define DISK_H

#include "winioctl.h"
#include "stdafx.h"

class disk : private utilities
{
public:
	bool driveGeometry();
	bool setDrive(int number);
	DISK_GEOMETRY getGeometry() const;
	void test();
private:
	DISK_GEOMETRY geometry;
	LPCSTR driveNumber;
};

#endif