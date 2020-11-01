FROM liquidforte/ant_farm/builder:latest
WORKDIR /app/build
RUN cmake ..