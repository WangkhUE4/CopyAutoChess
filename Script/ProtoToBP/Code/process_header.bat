for /r %%i in (*.pb.h) do ( 
disable_warning.exe %%~nxi 4100 4125 4267 4668 4800 4456
)