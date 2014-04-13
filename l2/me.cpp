// l2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dCompress.h"

void dumpbyte(BYTE* buff, int buffSize)
{
	for (int i = 0; i < buffSize; i++)
	{
		printf("0x%02X (\'%c\')\n",buff[i],buff[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[])
{	
	BYTE inbuff[] = {"bMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMc" };
	BYTE* outbuff;
	BYTE* outbuff2;
	int inbuffsize = sizeof(inbuff);
	int outbuffsize;
	int outbuff2size;
	printf("Hello World!\n");
	dCompress* myComp;
	myComp= new dCompress();
	
	printf("First:\n");
	dumpbyte(inbuff,inbuffsize);

	myComp->cData(inbuff,inbuffsize, &outbuff, &outbuffsize);

	printf("Second:\n");
	dumpbyte(outbuff,outbuffsize);

	myComp->uData(outbuff,outbuffsize,&outbuff2,&outbuff2size);

	printf("Third:\n");
	dumpbyte(outbuff2,outbuff2size);

	return 0;
}

