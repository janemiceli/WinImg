//////////////////////////////////////////////////////////////////////
//
// dCompress.cpp: implementation of the dCompress class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "dCompress.h"

#define ESCAPE_BYTE 0xFF
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

dCompress::dCompress()
{

}

dCompress::~dCompress()
{

}


// Things to do to this function:

// If the count for repeats is > 254, make multiple escape character
// sequences for each group of 254 (remember, the count can't be 0xff (the escape byte)

bool dCompress::cData(BYTE* iBuff, int iBuffSize, BYTE** oBuff, int* oBuffSize)
{
	//what this should do:
	//   Loop through inBuff, searching for duplicate values
	//   if three or more are found in a row, replace them with:
	//   ESCAPE_BYTE, <Number of duplicates>, <duplicated byte>
	//
	//   Note that if there are _more_ than 254 duplicated bytes
	//   make multiple ESCAPE_BYTE sequences.
	//
	//   If the current byte of inBuff is ESCAPE_BYTE,
	//   Replace it with _TWO_ ESCAPE BYTES
	//   Note that if there are multiple escape bytes in a row in
	//   inBuff, you can use the initial system in the first paragraph here.
	
	int count = 1;
	int compareto = 0;
	int outbuffindex = 0;

	*oBuff = new BYTE[iBuffSize*2];


	for  (count=1; count <= iBuffSize; count++)
	{
		//*inBuff     == inBuff[0]
		//*(inBuff+1) == inBuff[1]
		if (iBuff[count] != iBuff[compareto])
		{
			if (count - compareto > 3/* && count - compareto < 254*/) //do something about more then 254 byte copies here 
			{
				int itemcount = ((count-1) - compareto);
				// compress it
				//  the first instance of the repeating byte is at: inBuff[compareto]
				//  the last instance of the repeating byte is at: inBuff[count - 1]
				while (itemcount > 254 )
				{
					(*oBuff)[outbuffindex++] = ESCAPE_BYTE;
					(*oBuff)[outbuffindex++] = 254;
					(*oBuff)[outbuffindex++] = iBuff[compareto];
					itemcount -= 255;
				}
				(*oBuff)[outbuffindex++] = ESCAPE_BYTE;
				(*oBuff)[outbuffindex++] = itemcount;
				(*oBuff)[outbuffindex++] = iBuff[compareto];
				compareto = count;
			}
			while (compareto < count)
			{
				// const == variable
				//	because if you miss an "=" you'll get a compiler error since you 
				//  cannot assign a variable to a const value
				//  and won't mess up the logic of your programming!!
				if (ESCAPE_BYTE == iBuff[compareto])
				{
					(*oBuff)[outbuffindex++] = ESCAPE_BYTE;
				}
				(*oBuff)[outbuffindex++] = iBuff[compareto++];
			}
		}
	}	
	


	*oBuffSize = outbuffindex;
	return true;
}

// Things to do to this function
//
//  Make sure your size stuff is correct.
//  Initialize the output buffer
//  loop through and process all of the bytes, follow along with the comments
//  inside the function to see how to decode things.

bool dCompress::uData(BYTE* iBuff, int iBuffSize, BYTE** oBuff, int* oBuffSize)
{
	// What this should do:
	//    Copy bytes from inBuff to oBuff, if an ESCAPE_BYTE character is
	//    found, process it.
	//
	//    How to process it:
	//       if ESCAPE_BYTE is found check the second byte:
	//           ESCAPE_BYTE - replace both with a single ESCAPE_BYTE
	//
	//           other byte - This is a count, check the third byte,
	//                        the third byte is the byte that should be
	//                        copied to the oBuffer count times.'
	//   That's it, Ta Da!

	int count=0;
	int bytesneed=0;
	

	//This counts how big the output buffer needs
	for (count=0; count < iBuffSize; count++)
	{
		if (ESCAPE_BYTE == iBuff[count])
		{
			if ((count +1) < iBuffSize && iBuff[count+1] != ESCAPE_BYTE)
			{
				bytesneed = bytesneed + iBuff[count+1];
			}
		}
		bytesneed++;
	}
	
	*oBuff = new BYTE[bytesneed];
	int obuffloc = 0;

	//cout<<"bytesneed: " << bytesneed << endl;	
	// second loop will be similar to first.
	// uncompresses and writes out to the buffer
	for (count=0; count < iBuffSize; count++)
	{
		if (ESCAPE_BYTE == iBuff[count])
		{
			if ((count +1) < iBuffSize && iBuff[count+1] != ESCAPE_BYTE)
			{
				for (int count1=0;count1<=iBuff[count+1];count1++)
				{
					(*oBuff)[obuffloc++]=iBuff[count+2];
				}
				count += 2;
			}
			else
			{
				(*oBuff)[obuffloc++] = iBuff[count++];
			}
		}
		else
		{
			(*oBuff)[obuffloc++] = iBuff[count];
		}
	}
	
	*oBuffSize = obuffloc;	

	return true;
}

	
