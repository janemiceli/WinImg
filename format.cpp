#include "stdafx.h"

namespace nsFormat {
	LPCSTR driveC = (LPCSTR) "\\\\.\\C:";
	LPCSTR driveD = (LPCSTR) "\\\\.\\D:";
	LPCSTR driveE = (LPCSTR) "\\\\.\\E:";
	LPCSTR driveF = (LPCSTR) "\\\\.\\F:";
	LPCSTR driveG = (LPCSTR) "\\\\.\\G:";
	LPCSTR driveH = (LPCSTR) "\\\\.\\H:";
	LPCSTR drive0 = (LPCSTR) "\\\\.\\PhysicalDrive0";
	LPCSTR drive1 = (LPCSTR) "\\\\.\\PhysicalDrive1";
}

bool format::setDrive(char source)
{ 
	//set the disk that the user wants to format

	//the window header file uses type LPCSTR, i've had a lot of trouble
	//converting this (with user input) to a unified source string (won't accept cast)
	//....so for now an ugly switch statement will have to do
	switch (source)
	{
	case 'c': case 'C' :
		driveSource = nsFormat::driveC;		break;
	case 'd': case 'D' :
		driveSource = nsFormat::driveD;		break;
	case 'e': case 'E' :
		driveSource = nsFormat::driveE;		break;
	case 'f': case 'F' :
		driveSource = nsFormat::driveF;		break;
	case 'g': case 'G' :
		driveSource = nsFormat::driveG;		break;
	case 'h': case 'H' :
		driveSource = nsFormat::driveH;		break;	
	case '0':
		driveSource = nsFormat::drive0;		break;
	case '1':
		driveSource = nsFormat::drive1;		break;
	default:
		return false;						break;
	}
	return true;
}

void format::doFormat() 
{
	//check the syntax on this...it's a little different than the other functions
	//re-format the specified drive
	openDrive();
//	DeviceIoControl(hFile,IOCTL_DISK_FORMAT_VOLUME,NULL,0,NULL,0,NULL,NULL);
	CloseHandle(hFile); 
	Inform("Disk/Drive closed...");
} 

void format::openDrive()
{
	//open a handle to the area to be formatted
	//the handle is stored as a class variable

	hFile = CreateFile(driveSource,
						GENERIC_READ|GENERIC_WRITE,
						0,
						NULL,
						OPEN_EXISTING,
						0,
						NULL);
	
	if (hFile == INVALID_HANDLE_VALUE) 
	{ 
			Inform("Drive to be formatted could not be opened...    "  );	//may not exist 
			Inform(driveSource);
			//Inform(GetLastError());										//returns error code
	}
	else
			Inform("Disk/Drive opened for formatting...");
}