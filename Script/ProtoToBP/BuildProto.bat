for /r %%i in (*.proto) do ( 
if not %%~ni == ssprotocol ( 
if not %%~ni == ssdefine ( 
protoc --cpp_out=./Code/ %%~nxi
)
)
)

cd ./Code
for /r %%i in (*.pb.cc) do ( 
copy %%~ni.cc %%~ni.cpp /y
)

del *.cc

for /r %%i in (*.pb.h) do ( 
..\Convert_pb_cc_to_ue4_cpp.exe %%~nxi
)