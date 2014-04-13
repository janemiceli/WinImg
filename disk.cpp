#include "stdafx.h"

namespace nsDisk {
	LPCSTR drive0 = (LPCSTR) "\\\\.\\PhysicalDrive0";
	LPCSTR drive1 = (LPCSTR) "\\\\.\\PhysicalDrive1";
}

bool disk::driveGeometry()
{
	//open the specified disk, obtain all disk information,
	//this information is later available to the caller

	DISK_GEOMETRY * pdg = &geometry;
	HANDLE hDevice;							// handle to the drive to be examined 
//	bool bResult;							// results flag
	HRESULT hResult;
	DWORD junk;								// discard results

	if (driveNumber != NULL)
	{
		hDevice = CreateFile(driveNumber,			// drive to open
						0,							// no access to the drive
						FILE_SHARE_READ |			// share mode
						FILE_SHARE_WRITE, 
						NULL,						// default security attributes
						OPEN_EXISTING,				// disposition
						0,							// file attributes
						NULL);				   		// do not copy file attributes
	}
	else
	{ 
		Inform("Disk Number not specified...");
		return false;
	}

	if (hDevice == INVALID_HANDLE_VALUE) // cannot open the drive
	{
		Inform("Could Not Open Disk...");
		Inform(driveNumber);
		return (false);
	}

	hResult = DeviceIoControl(hDevice,						// device to be queried
							IOCTL_DISK_GET_DRIVE_GEOMETRY,	// operation to perform
                            NULL, 0,						// no input buffer
                            pdg, sizeof(*pdg),				// output buffer
                            &junk,							// # bytes returned
                            (LPOVERLAPPED) NULL);			// synchronous I/O
			
	CloseHandle(hDevice);
	return (hResult >= 0/*bResult*/);
}

bool disk::setDrive(int number)
{ 
	//set the disk that the user wants information for

	//the window header file uses type LPCSTR, i've had a lot of trouble
	//converting this (with user input) to a unified source string (won't accept cast)
	//....so for now an ugly switch statement will have to do
	switch (number)
	{
	case 0:
		driveNumber = nsDisk::drive0;		break;
	case 1:
		driveNumber = nsDisk::drive1;		break;
	default:
		return false;						break;
	}
	return true;
}


void disk::test() 
{
	//display number of bytes per sector
	DISK_GEOMETRY obj = getGeometry();
	cout << obj.BytesPerSector << endl;
}

DISK_GEOMETRY disk::getGeometry() const
{
	//standard accessor
	return geometry;
}
