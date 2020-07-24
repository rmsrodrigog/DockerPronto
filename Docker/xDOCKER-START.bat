@echo off

docker network create mynet > nul 2> nul

if exist docker-compose.yml (
    docker-compose down
    docker-compose up -d --build
)else (
    echo docker-compose.yml NAO ENCONTRADO
)
if NOT ["%errorlevel%"]==["0"] pause