cd /d %~dp0

for /r %%i in (*.pb.h) do ( 
AddStrWrapSection.exe %%~nxi "#if PLATFORM_WINDOWS\n" "#endif\n" "#pragma warning*"
)
