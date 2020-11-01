#!/bin/bash

readonly DEBIAN_PACKAGES="${1}"

apt-get update
apt-get install -y ${DEBIAN_PACKAGES}

scripts/cleanup.sh