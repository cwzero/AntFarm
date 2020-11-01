FROM liquidforte/ant_farm/build:latest

COPY docker/scripts/install_dev.sh /app/scripts/
RUN scripts/install_dev.sh
RUN rm -rf /app/scripts/

RUN mkdir -p /var/run/sshd

RUN echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config && \ 
   ssh-keygen -A 

# expose port 22 
EXPOSE 22

RUN useradd -m -d /home/eric -s /bin/bash -G sudo eric

CMD ["/bin/bash", "-i", "<<<", "'service start ssh; exec </dev/tty'"]