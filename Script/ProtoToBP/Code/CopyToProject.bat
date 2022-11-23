set project_pb_path=..\..\..\Source\CopyAutoChess\Network\Protobuf
set fcfilename=tmpfcstr.txt
set fcfilename_linenum=tmpfcstr_linenum.txt
set fcfilename_lastline=tmpfcstr_lastline.txt
set fcfilename_alllastline=tmpfcstr_alllastline.txt

::----------------------对比文件
::----------------------对比结果保存在tmpfcstr_alllastline.txt
::----------------------不需要拷贝的：
::----------------------文件名,FC: no differences encountered 
::----------------------其他为需要拷贝的(对比结果行数大于100行或最后一行是*****、文件不存在)
type nul > %fcfilename_alllastline%
for /r %%i in (*.h *.cpp) do ( 
if exist "%project_pb_path%\%%~nxi" (


fc /N %%~nxi %project_pb_path%\%%~nxi > %fcfilename%
type %fcfilename%|find /c /v "" > %fcfilename_linenum%
for /f "delims=" %%k in (%fcfilename_linenum%) do ( 
if %%k gtr 100 ( 
echo %%~nxi,******linenum gtr 100 >> %fcfilename_alllastline%

) else (
fc /N %%~nxi %project_pb_path%\%%~nxi > %fcfilename%
for /f "delims=" %%j in (%fcfilename%) do ( 
echo %%~nxi,%%j > %fcfilename_lastline%
)
type %fcfilename_lastline% >> %fcfilename_alllastline%
)
)


) else (
echo %%~nxi,******not exist >> %fcfilename_alllastline%
)
)



::----------------------拷贝文件
for /f "tokens=1,2 delims=," %%i in (%fcfilename_alllastline%) do ( 
if not "%%j" == "FC: no differences encountered " ( 
copy /Y %%i %project_pb_path%\%%i
)
)

del %fcfilename%
del %fcfilename_linenum%
del %fcfilename_lastline%
del %fcfilename_alllastline%