@echo off
FOR /F "tokens=1-4 delims=- " %%i IN ('date /t') DO SET yyyymmdd=%%i%%j%%k

echo # git add .
git add .
echo.

echo # git commit -m "%yyyymmdd%"
git commit -m "%yyyymmdd%"
echo.

echo # git push origin master 
git push origin master 
echo.

echo # end
pause>nul
