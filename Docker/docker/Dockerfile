FROM centos:7
MAINTAINER Francisco Rodrigues

### CONFIG IMAGE VARS ##########################################################
ARG SSH_USER
ARG SSH_PASS
ARG CONTAINER_NAME
ARG NODE_ENV

RUN echo "America/Sao_Paulo" > /etc/timezone

RUN rpm -Uvh https://mirror.webtatic.com/yum/el7/epel-release.rpm
RUN rpm -Uvh https://mirror.webtatic.com/yum/el7/webtatic-release.rpm

RUN yum update -y && \
    yum install -y epel-release

RUN yum install -y \
    iproute hostname which jq vim \
    net-tools tcpdump supervisor \
    dos2unix nmap

#RUN rpm -iUvh https://download.postgresql.org/pub/repos/yum/9.3/redhat/rhel-7-x86_64/pgdg-centos93-9.3-3.noarch.rpm

### INSTALL NGINX/PHP ##########################################################

RUN yum install -y \
    composer \
    git \
    libmcrypt-devel \
    libxml2 \
    libxml2-devel \
    libxslt \ 
    libxslt-devel \
    mcrypt \
    nginx \
    php70w-bcmath \
    php70w-cli \
    php70w-common \
    php70w-devel \
    php70w-fpm \
    php70w-gd \
    php70w-intl \
    php70w-json \
    php70w-ldap \
    php70w-mbstring \
    php70w-mcrypt \
    php70w-mysql \
    php70w-opcache \
    php70w-pdo \
    php70w-pdo_dblib \
    php70w-pecl-xdebug \
    php70w-pgsql \
    php70w-process \
    php70w-recode \
    php70w-soap \
    php70w-xml \
    php70w-xmlrpc \
    postgresql \
    unzip \
    zip

RUN yum install -y plesk-php70-devel gcc libssh2-devel

#Install the extension:
RUN printf "\n" | pecl install ssh2-1.1.2

#Register extension in configuration file:
RUN echo "extension=ssh2.so" > /etc/php.d/ssh2.ini

#RUN  pear channel-update pear.php.net
#RUN pear upgrade
#RUN pear config-set preferred_state stable
RUN pear config-set preferred_state beta
RUN pear install --onlyreqdeps Spreadsheet_Excel_Writer
#RUN pear install -a OLE
#RUN pear install -a Spreadsheet_Excel_writer


RUN mkdir -p /var/lib/php/session
RUN chmod 777 /var/lib/php/session

ADD ./etc/nginx/nginx.conf /etc/nginx/
ADD ./etc/nginx/sites-available/default.conf /etc/nginx/sites-available/
COPY ./etc/nginx/certs/localhost.crt /usr/local/nginx/ssl/localhost.crt
COPY ./etc/nginx/certs/localhost.key /usr/local/nginx/ssl/localhost.key

RUN sed -i "s/^;date.timezone =*/date.timezone = America\/Sao_Paulo/" /etc/php.ini

RUN yum clean all

EXPOSE 80

################################################################################
COPY ./etc/supervisord.conf /etc/supervisord.conf
COPY ./etc/php.ini /etc/php.ini
COPY /etc/php.d/xdebug.ini /etc/php.d/xdebug.ini
COPY ./opt/start_script/init.sh /opt/start_script/init.sh
RUN dos2unix -q /opt/start_script/init.sh

CMD ["/usr/bin/supervisord"]