# engine.io.poc
Testbed for V2.0 DSA protocol

Notes

This is a message broker test bed to explore broker performance. It supports an IO adapter that provides a simple echo-back
service at 127.0.0.1 by default on port 8888 at this time. 

Building on Linux and Windows
------------------------------

use the provided cmake to build.
It appears as:
bin/engine_io on linux 
bin/Debug/engine_io.exe on windows

Running the binary
------------------
linux: bin/run.sh
windows: bin\run.bat
