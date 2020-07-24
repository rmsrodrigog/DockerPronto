@echo off
FOR /F "tokens=*" %%A IN ('docker ps -a -q') DO docker rm -f  %%A
FOR /F "tokens=*" %%B IN ('docker images -a -q') DO docker rmi -f %%B

