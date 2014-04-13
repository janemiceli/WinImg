/*
FORMAT.H

public:	
	bool setDrive(char source);
		pre:	source == c,d,e,f,g,h,0,1
		post:	sets the drive/disk that is to be formatted,
				return success
			
	void doFormat();
		pre:	run setDrive()
		post:	drive/disk selected is re-formated with its current format

private:
	void openDrive();
		useage:	called by doFormat to open a handle to the selected disk/drive
	LPCSTR driveSource;
	HANDLE hFile;
*/



#ifndef FORMAT_H
#define FORMAT_H

#include "stdafx.h"

class format : private utilities
{
public:	
	bool setDrive(char source);
	void doFormat();
private:
	void openDrive();
	LPCSTR driveSource;
	HANDLE hFile;
};
#endif