FROM liquidforte/ant_farm/base:latest

COPY docker/scripts/install_runner.sh /app/scripts/
RUN scripts/install_runner.sh
RUN rm -rf /app/scripts/