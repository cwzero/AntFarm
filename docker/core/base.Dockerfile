FROM ubuntu:latest

RUN mkdir -p /app/scripts
RUN mkdir -p /app/lib
ENV LD_LIBRARY_PATH /app/lib
WORKDIR /app
CMD ["/bin/bash"]
ENV DEBIAN_FRONTEND noninteractive

COPY docker/scripts/cleanup.sh /app/scripts/
COPY docker/scripts/install.sh /app/scripts/
COPY docker/scripts/install_base.sh /app/scripts/
RUN scripts/install_base.sh
