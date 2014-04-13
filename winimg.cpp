// winimg.cpp : Defines the entry point for the console application.

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//this driver file is still in development, and will
	//change as the program takes modifications,
	//it will also determine syntax for command line parameters
	//see appropriate documentation

	unsigned char Flags = 0;
	char *sDrive = ""; //Source Drive
	char *dDrive = "";	//Destination Drive
	image obj;
	bool create = false;
	bool restore = false;

	//This is for debugging purposes.
	/*printf ("ARGC: %d\n",argc);
	for (int j = 0; j < argc; j++)
	{
		printf("[%2d]: \"%s\"\n",j,argv[j]);
	}*/
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			switch (argv[i][1])
			{
				case 'c':  // We're creating an image
					Flags |= 1;
					printf("Creating a file\n");
					create=true;
					break;
				case 'r':  // We're restoring an image
					Flags |= 1;
					printf("Restoring a file\n");
					restore= true;
					break;
				//case 'z':  // We're also compressing/decompressing the image
				//	printf("Compressing/Decompressing the file\n");
				//	break;
				case 's':  // the "source" is next
					Flags |= 2;
					printf("Source: ");
					if (argc > (i+1) && argv[i+1][0] != '-')
					{
						// argv[i+1] is our source location
						printf("\"%s\"\n",argv[i+1]);
						sDrive = argv[i+1];
						++i;
					}
					else
					{
						// Use a default source
						printf("default\n");
					}
					break;
				case 'd': // the "destination" is next
					Flags |= 4;
					printf("Destination: ");
					if (argc > (i+1) && argv[i+1][0] != '-')
					{
					 //argv[i+1] is our destination location
						printf("\"%s\"\n",argv[i+1]);
						dDrive=argv[i+1];
						++i;
					}
					else
					{
						// Use a default destination
						printf("default\n");
					}
					break;
				default:
					printf("\"%s\" is an unknown command\n",argv[i]);
			}
		}
		else
		{
			printf("\"%s\" is an unknown command, should it be \"-%s\"?",argv[i],argv[i]);
		}
	}
	
	if (Flags == 7)
	{
		printf("\n\n Everything is A-OK!!\n\n");
	}
	else
	{
		printf("Please specify:\n   \"-c\" Create or \"-r\" Restore\n   \"-s\" Source\n   \"-d\" Destination");
		return 1;
	}
	
	if (create)
	{
		FILE* imgfile = fopen("f:\\image.img","w+");
		fprintf(imgfile,"");
		fclose(imgfile);
		
		cout << obj.setCSourceDrive(*sDrive);
		cout << obj.setCDestinationDrive(*dDrive);
		obj.setSectorSize(512);
		obj.createImage();
	}

	if (restore)
	{
		FILE* imgfile = fopen("e:\\","w+");
		//fprintf(imgfile,"");
		fclose(imgfile);

		cout << obj.setRSourceDrive(*sDrive);
		cout << obj.setRDestinationDrive(*dDrive);
		obj.setSectorSize(512);
		obj.restoreImage();
	}
	
	return 0;
}

