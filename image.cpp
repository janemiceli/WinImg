#include "stdafx.h"

namespace nsImage {
	LPCSTR driveC = (LPCSTR) "\\\\.\\C:";;
	LPCSTR driveD = (LPCSTR) "\\\\.\\D:";
	LPCSTR driveE = (LPCSTR) "\\\\.\\E:";
	LPCSTR driveF = (LPCSTR) "\\\\.\\F:";
	LPCSTR driveG = (LPCSTR) "\\\\.\\G:";
	LPCSTR driveH = (LPCSTR) "\\\\.\\H:";
	LPCSTR drive0 = (LPCSTR) "\\\\.\\PhysicalDrive0";
	LPCSTR drive1 = (LPCSTR) "\\\\.\\PhysicalDrive1";

}

bool image::setCSourceDrive(char source)
{ 
	//set the disk that the will be copied
	//the window header file uses type LPCSTR, i've had a lot of trouble
	//converting this (with user input) to a unified source string (won't accept cast)
	//....so for now an ugly switch statement will have to do
	switch (source)
	{
	case 'c': case 'C' :
		driveSource =  (LPCSTR) "\\\\.\\C:";		break;
	case 'd': case 'D' :
		driveSource =  (LPCSTR) "\\\\.\\D:";		break;
	case 'e': case 'E' :
		driveSource =  (LPCSTR) "\\\\.\\E:";		break;
	case 'f': case 'F' :
		driveSource =  (LPCSTR) "\\\\.\\F:";		break;
	case 'g': case 'G' :
		driveSource =  (LPCSTR) "\\\\.\\G:";		break;
	case 'h': case 'H' :
		driveSource =  (LPCSTR) "\\\\.\\H:";		break;	
	case '0':
		driveSource = (LPCSTR) "\\\\.\\PhysicalDrive0";		break;
	case '1':
		driveSource = (LPCSTR) "\\\\.\\PhysicalDrive1";		break;
	default:
		return false;						break;
	}
	return true;
}

bool image::setCDestinationDrive(char destination)
{ 
	//set the disk where the image will be copied to

	//the window header file uses type LPCSTR, i've had a lot of trouble
	//converting this (with user input) to a unified source string (won't accept cast)
	//....so for now an ugly switch statement will have to do
	
	switch (destination)
	{
	case 'c': case 'C' :
		driveDestination = (LPCSTR) "\\\\.\\C:\\\\image.img";		break;
	case 'd': case 'D' :
		driveDestination = (LPCSTR) "\\\\.\\D:\\\\image.img";		break;
	case 'e': case 'E' :
		driveDestination = (LPCSTR) "\\\\.\\E:\\\\image.img";		break;
	case 'f': case 'F' :
		driveDestination = (LPCSTR) "\\\\.\\F:\\\\image.img";		break;
	case 'g': case 'G' :
		driveDestination = (LPCSTR) "\\\\.\\G:\\\\image.img";		break;
	case 'h': case 'H' :
		driveDestination = (LPCSTR) "\\\\.\\H:\\\\image.img";		break;		
	case '0':
		driveDestination = (LPCSTR) "\\\\.\\PhysicalDrive0";		break;
	//case '1':
	//	driveDestination = (LPCSTR) "\\\\.\\PhysicalDrive1";		break;
	default:
		return false;							break;
	}
	return true;
}

bool image::setRSourceDrive(char source)
{ 
	//set the disk that the will be copied

	//the window header file uses type LPCSTR, i've had a lot of trouble
	//converting this (with user input) to a unified source string (won't accept cast)
	//....so for now an ugly switch statement will have to do
	switch (source)
	{
	case 'c': case 'C' :
		driveSource =  (LPCSTR) "\\\\.\\C:\\\\image.img";		break;
	case 'd': case 'D' :
		driveSource =  (LPCSTR) "\\\\.\\D:\\\\image.img";		break;
	case 'e': case 'E' :
		driveSource =  (LPCSTR) "\\\\.\\E:\\\\image.img";		break;
	case 'f': case 'F' :
		driveSource =  (LPCSTR) "\\\\.\\F:\\\\image.img";		break;
	case 'g': case 'G' :
		driveSource =  (LPCSTR) "\\\\.\\G:\\\\image.img";		break;
	case 'h': case 'H' :
		driveSource =  (LPCSTR) "\\\\.\\H:\\\\image.img";		break;	
	case '0':
		driveSource = (LPCSTR) "\\\\.\\PhysicalDrive0";		break;
	case '1':
		driveSource = (LPCSTR) "\\\\.\\PhysicalDrive1";		break;
	default:
		return false;						break;
	}
	return true;
}

bool image::setRDestinationDrive(char destination)
{ 
	//set the disk where the image will be copied to

	//the window header file uses type LPCSTR, i've had a lot of trouble
	//converting this (with user input) to a unified source string (won't accept cast)
	//....so for now an ugly switch statement will have to do
	
	switch (destination)
	{
	case 'c': case 'C' :
		driveDestination = (LPCSTR) "\\\\.\\C:";		break;
	case 'd': case 'D' :
		driveDestination = (LPCSTR) "\\\\.\\D:";		break;
	case 'e': case 'E' :
		driveDestination = (LPCSTR) "\\\\.\\E:";		break;
	case 'f': case 'F' :
		driveDestination = (LPCSTR) "\\\\.\\F:";		break;
	case 'g': case 'G' :
		driveDestination = (LPCSTR) "\\\\.\\G:";		break;
	case 'h': case 'H' :
		driveDestination = (LPCSTR) "\\\\.\\H:";		break;		
	case '0':
		driveDestination = (LPCSTR) "\\\\.\\PhysicalDrive0";		break;
	//case '1':
	//	driveDestination = (LPCSTR) "\\\\.\\PhysicalDrive1";		break;
	default:
		return false;							break;
	}
	return true;
}

void image::setSectorSize(DWORD size)
{
	bufferSize = size;
}

void image::createImage() 
{
	//open the two disk(s)/drive(s),
	//create a buffer the size of a single sector
	//and copy all the appropriate information
	//Inform() is used to return any status from the program

	openCreateDrives();

	//BYTE a[512];
	//LPVOID buffer = a;
	//this line can be replaced with the above two lines
	BYTE* buffer = new BYTE[bufferSize];

	LPDWORD bytesRead = new DWORD();
	*bytesRead = bufferSize;

	//i'll leave this code in for future developers
	//this is another way to run the loop....you could
	//just run one for loop for the # of sectors
	////copy the drive here (outer loop contains number of GB of info)
	////for (int i1(0); i1 < 2; ++i1) //number of 10Gb/Gb
	////	for (int i2(0); i2 < 1024; ++i2) //number of iterations GB/MB
	//	for (int i2(0); i2 < 256; ++i2)
	//		for (int i3(0); i3 < 1024; ++i3) //number of iterations MB/KB
	//					for (int i4(0); i4 < 2; ++i4) //number of iterations per KB/512B
	//					{
	//								ReadFile(hFile[0],buffer,bufferSize,bytesRead,NULL);								
	//												//for (int i(0); i < 512; ++i)
	//												//	cout << a[i];
	//								WriteFile(hFile[1],buffer,bufferSize,bytesRead,NULL);
	//					}
	
	dCompress* comp; 
	comp= new dCompress();
	BYTE* outbuff;
	int outbuffersize;

	while (*bytesRead != 0)
	{
		ReadFile(hFile[0],buffer,bufferSize,bytesRead,NULL);
		//compress it
		comp->cData(((BYTE*)buffer),*bytesRead, &outbuff, &outbuffersize); 
		*bytesRead = outbuffersize; 
		WriteFile(hFile[1],outbuff,outbuffersize,bytesRead,NULL);
		//as long as bytesRead==sectorSize the commands
		//completed successfully
	}
	delete bytesRead;
	delete [] buffer;
	CloseHandle(hFile[0]); Inform ("Source File Closed   ");
	CloseHandle(hFile[1]); Inform ("Destination File Closed   ");
}



void dumpbyte(BYTE* buff, int buffSize)
{
	for (int i = 0; i < buffSize; i++)
	{
		printf("%3d  0x%02X (\'%c\')\n",i,buff[i],buff[i]);
	}
	printf("\n");
}



void image::restoreImage() 
{
	openRestoreDrives();

	BYTE* buffer = new BYTE[bufferSize];
	LPDWORD bytesRead = new DWORD();
		
	*bytesRead = bufferSize;
	dCompress* comp; 
	comp= new dCompress();
	BYTE* outbuff;
	int outbuffersize;//  = 10000;
	int returnread = 0;
	int returnwrite = 0;
	char message[200];
	int tValue;

	long readSize = 0;
	long writeSize = 0;

	//DWORD *written = 0;
	while (*bytesRead != 0)
	{
		returnread = ReadFile(hFile[0],buffer,bufferSize,bytesRead,NULL);
		//cout << "return read: " << returnread << endl;
		//FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,NULL,GetLastError(),0, message,200,NULL);
		//cout << "Message: " << message << endl;

		if (buffer [*bytesRead - 1] == (0xFF))
		{
			if ((buffer [*bytesRead -2] == (0xFE)) && (buffer [*bytesRead-3 ] == 0xFF))
			{
				SetFilePointer(hFile[0],-3,NULL,FILE_CURRENT);
				*bytesRead -= 3;			
			}	
			else
			{
				SetFilePointer(hFile[0],-1,NULL,FILE_CURRENT);
				*bytesRead -= 1;
			}		
		}
			
		if	(buffer [*bytesRead - 2] == (0xFF))
		{
			SetFilePointer(hFile[0],-2,NULL,FILE_CURRENT);
			*bytesRead -= 2;
		}
		
		comp-> uData(((BYTE*)buffer),*bytesRead, &outbuff, &outbuffersize); 
		cout << "ResoreImage, Initial: " << *bytesRead << " Final: " << outbuffersize << " ";

		readSize += *bytesRead;
		writeSize += outbuffersize;

		tValue = outbuffersize - 500;
		while (tValue > 0)
		{
			cout << "*";
			tValue -= 100;
		}

		cout << endl;

		 *bytesRead = outbuffersize; //this was here 
		//returnwrite = WriteFile(hFile[1],outbuff,outbuffersize,bytesRead,NULL);//this is the correct one
	    //returnwrite = WriteFile(hFile[1],buffer,bufferSize,bytesRead,NULL);//origial code
		//returnwrite = WriteFile(hFile[1],buffer,outbuffersize,bytesRead,NULL);//fails to read		
		 //cout << "Buffer size: " << outbuffersize << endl;
		cout <<"Read in : "<< *bytesRead<< endl;

/*			cout << "File: " << hFile[1] << endl
				 << "Buffer: \"" << outbuff << "\"" << endl
				 << "oBuffSize: " << outbuffersize << endl;
//				 << "bytesWritten: " << *bytesRead << endl;*/
		returnwrite = WriteFile(hFile[1],outbuff,outbuffersize,bytesRead,NULL);//this is correct!!
		cout <<"Read in after Write: "<< *bytesRead<< endl;
		cout << "return write: " << returnwrite << "  bytesRead: " << *bytesRead << endl;
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,NULL,GetLastError(),0, message,200,NULL);
		cout << "Error Message : " << message << endl;

		//if (false == returnwrite)
		//{
//			cout << "File: " << hFile[1] << endl
				// << "Buffer: \"" << outbuff << "\"" << endl
//				 << "oBuffSize: " << outbuffersize << endl
//				 << "bytesWritten: " << *bytesRead << endl;
		//}

		//dumpbyte(outbuff,10);
		//dumpbyte(outbuff+(outbuffersize-10),10);

		delete[] outbuff;

		//as long as bytesRead==sectorSize the commands
		//completed successfully
	}	
	delete bytesRead;
	delete [] buffer;

	cout << readSize << " bytes read from image file" << endl;
	cout << writeSize << " bytes written to drive" << endl;
	cout << "Compression: " << (readSize/(double)writeSize)*100 << "%" << endl;

	CloseHandle(hFile[0]); Inform ("Source File Closed   ");
	CloseHandle(hFile[1]); Inform ("Destination File Closed   ");
}

void image::openCreateDrives()
{
	//create a handle to the disk(s)/drive(s)
	//test to see if valid
	
	//HANDLE source
	if (driveSource != NULL)
	{
		hFile[0] = CreateFile(driveSource,
						GENERIC_READ,              // open for reading 
						FILE_SHARE_READ,           // share for reading 
						NULL,                      // no security 
						OPEN_EXISTING,             // existing file only 
						FILE_ATTRIBUTE_NORMAL,     // normal file 
						NULL);                     // no attr. template 
	}
	else
	{
		Inform("Source not specified...");
		return;
	}
 
	if (hFile[0] == INVALID_HANDLE_VALUE) 
	{ 
		Inform("Image Source Could Not Be Opened...    "  );	//may not exist 
		Inform(driveSource);
		//Inform(GetLastError());								//returns error code
		return;
	}
	else
			Inform("Image Source Opened   ");


	//HANDLE destination;
	if (driveDestination != NULL)
	{
		hFile[1] = CreateFile(driveDestination, 
						GENERIC_WRITE,             // open for writing 
						FILE_SHARE_WRITE,          // share for writing 
						NULL,                      // no security 
						OPEN_EXISTING,             // existing file only 
						FILE_ATTRIBUTE_NORMAL,     // normal file 
						NULL);                     // no attr. template 
	}
	else
	{
		Inform("Destination not specified...");
		return;
	}


	if (hFile[1] == INVALID_HANDLE_VALUE) 
	{ 
		Inform("Image Destination Could Not Be Opened...    "  );	//may not exist 
		Inform(driveDestination);
		//Inform(GetLastError());									//returns error code
		return;
	}
	else
			Inform("Image Destination Opened   ");
}

void image::openRestoreDrives()
{
	//create a handle to the disk(s)/drive(s)
	//test to see if valid
	cout<<"openRestoreDrives()"<<endl;
	cout<<"source: drive"<<driveSource<<endl;
	cout<<"destination Drive: "<<driveDestination<<endl<<endl;
	//HANDLE source
	if (driveSource != NULL)
	{
		hFile[0] = CreateFile(driveSource,
						GENERIC_READ,              // open for reading 
						FILE_SHARE_READ,           // share for reading 
						NULL,                      // no security 
						OPEN_EXISTING,             // existing file only 
						FILE_ATTRIBUTE_NORMAL,     // normal file 
						NULL);                     // no attr. template 
	}
	else
	{
		Inform("Source not specified...");
		return;
	}
 
	if (hFile[0] == INVALID_HANDLE_VALUE) 
	{ 
		Inform("Image Source Could Not Be Opened...    "  );	//may not exist 
		Inform(driveSource);
		//Inform(GetLastError());								//returns error code
		return;
	}
	else
			Inform("Image Source Opened   ");

	//HANDLE destination;
	if (driveDestination != NULL)
	{
		hFile[1] = CreateFile(driveDestination, 
						GENERIC_WRITE,             // open for writing 
						FILE_SHARE_WRITE,          // share for writing 
						NULL,                      // no security 
						OPEN_EXISTING,             // existing file only 
						FILE_ATTRIBUTE_NORMAL,     // normal file 
						NULL);                     // no attr. template 
	}
	else
	{
		Inform("Destination not specified...");
		return;
	}

	if (hFile[1] == INVALID_HANDLE_VALUE) 
	{ 
		Inform("Image Destination Could Not Be Opened...    "  );	//may not exist 
		Inform(driveDestination);
		//Inform(GetLastError());									//returns error code
		return;
	}
	else
			Inform("Image Destination Opened   ");
}