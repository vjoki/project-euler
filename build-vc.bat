call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\vcvars32.bat"
cd build
cmake ..
nmake
nmake test
pause