#!/bin/bash
DIR=/opt
DIR_PUBLIC=$DIR/www
DIR_GIT=$DIR_PUBLIC
DIR_GIT_VENDOR=$DIR_GIT/vendor
DIR_GIT_API=$DIR_PUBLIC/portal/servicos/api
DIR_GIT_API_VENDOR=$DIR_GIT_API/vendor

NGINX_CONF=/etc/nginx/sites-available/default.conf

if [ ! -d "/opt/www_init" ]; then
    mkdir -p /opt/www_init
fi
echo "<head>" > /opt/www_init/index.html
echo "  <meta http-equiv='refresh' content='5'>" >> /opt/www_init/index.html
echo "</head>" >> /opt/www_init/index.html
echo "<pre>" >> /opt/www_init/index.html
echo "INI: DOCKER" >> /opt/www_init/index.html
sed -i "s|root /opt/www_localhost;|root /opt/www_init; #LOCALHOST#|" $NGINX_CONF
sed -i "s|root /opt/www/portal/polos;|root /opt/www_init; #POLOS#|" $NGINX_CONF
sed -i "s|root /opt/www;|root /opt/www_init; #SIGA#|" $NGINX_CONF
sed -i "s|root /opt/www/portal/servicos/api/src;|root /opt/www_init; #API#|" $NGINX_CONF
nginx -s reload

cd $DIR

echo "> Desativando http.sslVerify do git" >> /opt/www_init/index.html
git config --global http.sslVerify "false"

if [ ! "$(ls -A $DIR_GIT)" ]; then
    echo "> INI: Clonando SIGA do git" >> /opt/www_init/index.html
    git clone https://areiabranca.uniritter.edu.br/dti_sistemas_ead/SIGA-EAD.git $DIR_GIT
    echo "> END: Clonando SIGA do git" >> /opt/www_init/index.html
fi

if [ "$(ls -A $DIR_GIT)" ]; then
    cd $DIR_GIT
    if [ ! "$(ls -A $DIR_GIT_VENDOR)" ]; then
        echo "> INI: Composer SIGA" >> /opt/www_init/index.html
        composer require phpoffice/phpspreadsheet
        composer install


        echo "> END: Composer SIGA" >> /opt/www_init/index.html
    else
        echo "$DIR_GIT_VENDOR exists"
    fi
    if [ ! "$(ls -A $DIR_GIT_API)" ]; then
        echo "> INI: Clonando API SIGA do git" >> /opt/www_init/index.html
        git clone --recurse-submodules https://areiabranca.uniritter.edu.br/dti_sistemas_ead/SIGA-API-CORE-EAD.git $DIR_GIT_API
        echo "> END: Clonando API SIGA do git" >> /opt/www_init/index.html
    fi
    if [ "$(ls -A $DIR_GIT_API)" ]; then
        cd $DIR_GIT_API
        if [ ! "$(ls -A $DIR_GIT_API_VENDOR)" ]; then
            echo "> INI: Composer SIGA-API" >> /opt/www_init/index.html
            composer install
            echo "> END: Composer SIGA-API" >> /opt/www_init/index.html
        else
            echo "$DIR_GIT_API_VENDOR exists"
        fi
    fi
fi
echo "> END: DOCKER" >> /opt/www_init/index.html
echo "</pre>" >> /opt/www_init/index.html
sed -i "s|root /opt/www_init; #LOCALHOST#|root /opt/www_localhost;|" $NGINX_CONF
sed -i "s|root /opt/www_init; #POLOS#|root /opt/www/portal/polos;|" $NGINX_CONF
sed -i "s|root /opt/www_init; #SIGA#|root /opt/www;|" $NGINX_CONF
sed -i "s|root /opt/www_init; #API#|root /opt/www/portal/servicos/api/src;|" $NGINX_CONF
nginx -s reload