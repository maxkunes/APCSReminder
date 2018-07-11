@echo off
if "%~1" equ ":FindFiles" goto :FindFiles

cd "C:\Users\admin\source\repos\APCSReminder\concatfolder"

:: Append newline to text files that are missing newline on last line
for /f "eol=: delims=" %%F in ('"%~f0" :FindFiles') do echo(>>"%%F"

:: Merge the text files and prefix each line with file name
findstr "^" *. >output.log

exit /b


:FindFiles
setlocal enableDelayedExpansion

:: Define LF to contain a newline character
set lf=^


:: The above 2 blank lines are critical - do not remove

:: List files that are missing newline on last line
findstr /vm "!lf!" *.cpp