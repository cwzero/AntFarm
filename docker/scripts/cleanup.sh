#!/bin/bash

apt-get autoremove --purge -y
apt-get autoclean -y
rm -rf /var/cache/apt/*