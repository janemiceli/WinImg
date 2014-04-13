// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <stdio.h>
#include <tchar.h>

// TODO: reference additional headers your program requires here
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//utilities
#include "utilities.h"

//image
#include <windows.h>
#include "image.h"

//disk
#include "disk.h"

//format
#include <winioctl.h>
// #include <diskio.h>
#include "Disk.h"
#include "format.h"

#include "dCompress.h"