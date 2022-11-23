@echo off

rem proto 文件路径
set PROTO_SOURCE_PATH=E:\zizouqi\proto
echo Step 1/6 Copy proto files...
for /r %PROTO_SOURCE_PATH% %%i in (*.proto) do ( 
xcopy /Y  %%~i . 
)

echo Step 2/6 Build BP
call ./buildBP.bat

echo Step 3/6 Build Proto
call ./buildProto.bat

echo Step 4/6 replace
call ./replace.bat

echo Step 5/6 Process header
call ./process_header.bat

echo Step 5/6 -2 Process header
call ./psHearder.bat

echo Step 6/6 Copy Code to project
call ./CopyToProject.bat

echo Done.

pause