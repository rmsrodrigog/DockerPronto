@echo off
echo #############################################################
echo #                                                           #
echo #  CUIDADO! Ja vi que nao sabe o que esta fazendo hehehe!   #
echo #  Melhor parar agora, antes que seja tarde!                #
echo #                                                           #
echo #############################################################
pause
exit

apt install postgresql-pltcl-9.5
psql -U postgres -c 'CREATE EXTENSION pltcl' dev

apt install postgresql-plperl-9.5
psql -U postgres -c 'CREATE EXTENSION plperl' dev
psql -U postgres -c 'CREATE LANGUAGE plperlu' dev

"C:\Program Files (x86)\pgAdmin 4\v4\runtime\pg_restore.exe" --host "localhost" --port "5432" --username "postgres" --dbname "dev" --no-owner --no-privileges --no-tablespaces --disable-triggers --verbose "D:\\NEWFOL~1\\teste.sql"  >output.txt 2>&1