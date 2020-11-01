FROM liquidforte/ant_farm/base:latest

COPY docker/scripts/install_build.sh /app/scripts/
RUN scripts/install_build.sh

RUN cp -L /usr/lib/x86_64-linux-gnu/libcurl.so /app/lib/libcurl.so