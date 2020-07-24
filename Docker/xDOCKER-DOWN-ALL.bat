@echo off
FOR /F "tokens=*" %%A IN ('docker ps -a -q') DO docker rm -f  %%A
