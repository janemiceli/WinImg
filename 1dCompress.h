// dCompress.h: interface for the dCompress class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCOMPRESS_H__D2236FD1_BDCA_4FB8_A1B7_8F8405C58F04__INCLUDED_)
#define AFX_DCOMPRESS_H__D2236FD1_BDCA_4FB8_A1B7_8F8405C58F04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"

class dCompress  
{
public:
	dCompress();
	virtual ~dCompress();

	bool cData(BYTE* iBuff, int iBuffSize, BYTE** oBuff, int* oBuffSize);
	bool uData(BYTE* iBuff, int iBuffSize, BYTE** oBuff, int* oBuffSize);

};

#endif // !defined(AFX_DCOMPRESS_H__D2236FD1_BDCA_4FB8_A1B7_8F8405C58F04__INCLUDED_)
