FROM liquidforte/ant_farm/build:latest

RUN rm -rf /app/scripts/

RUN mkdir /app/build/
RUN mkdir -p /app/bin

COPY CMakeLists.txt /app/
COPY cluster /app/cluster
COPY core /app/core
COPY generation /app/generation
COPY organism /app/organism
