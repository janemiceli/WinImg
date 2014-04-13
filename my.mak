all : winimg.exe

winimg.exe : winimg.obj disk.obj utilities.obj image.obj format.obj stdafx.obj
   $(LINKER) $(GUIFLAGS) -OUT:winimg.exe winimg.obj disk.obj utilities.obj image.obj format.obj stdafx.obj

winimg.obj: winimg.cpp
   $(CC) $(MFCFLAGS) winimg.cpp /IC:\progra~1\micros~2\vc98\include

disk.obj: disk.cpp
   $(CC) $(MFCFLAGS) disk.cpp /IC:\progra~1\micros~2\vc98\include

utilities.obj: utilities.cpp
   $(CC) $(MFCFLAGS) utilities.cpp /IC:\progra~1\micros~2\vc98\include

image.obj: image.cpp
   $(CC) $(MFCFLAGS) image.cpp /IC:\progra~1\micros~2\vc98\include

format.obj: format.cpp
   $(CC) $(MFCFLAGS) format.cpp /IC:\progra~1\micros~2\vc98\include

stdafx.obj: stdafx.cpp
   $(CC) $(MFCFLAGS) stdafx.cpp /IC:\progra~1\micros~2\vc98\include
