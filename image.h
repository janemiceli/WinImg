/*
IMAGE.H

public:	
	bool setSourceDrive(char source);
		pre:	source == c,d,e,f,g,h,0,1
		post:	sets the source drive/disk that is to be imaged
				return true if a valid selection is made

	bool setDestinationDrive(char destination);
		pre:	source == c,d,e,f,g,h,0,1
		post:	sets the destination drive/disk that is to be imaged
				return true if a valid selection is made

	void setSectorSize(DWORD size);
		pre:	size should be obtained from a DISK_GEOMETRY class item
		post:	sets the size of the buffer to be used when imaging

	void createImage();
		pre:	calls to setSourceDrive(), setDestinationDrive(), 
				setSectorSize()
		post:	image is made to the destination drive

private:
	void openDrives();
		useage:	called by createImage() to open handles to disk(s)/drive(s)
	LPCSTR driveSource, driveDestination;
	DWORD bufferSize;
	HANDLE hFile[2];
*/



#ifndef IMAGE_H
#define IMAGE_H

#include "stdafx.h"

class image : private utilities
{
public:
	
	bool setCSourceDrive(char source);
	bool setCDestinationDrive(char destination);
	bool setRSourceDrive(char source);
	bool setRDestinationDrive(char destination);
	void setSectorSize(DWORD size);
	void createImage();
	void restoreImage();
private:
	void openCreateDrives();
	void openRestoreDrives();
	LPCSTR driveSource, driveDestination;
	DWORD bufferSize;
	HANDLE hFile[2];
};
#endif