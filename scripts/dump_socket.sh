#!/bin/bash

# Parameters
socket="/var/run/docker.sock"
dump="capture.pcap"

# Extract repetition
port=80
source_socket="$(dirname "${socket}")/$(basename "${socket}").orig"

# Move socket files
mv "${socket}" "${source_socket}"
trap "{ rm '${socket}'; mv '${source_socket}' '${socket}'; }" EXIT

# Setup pipe over TCP that we can tap into
socat -t100 "TCP-LISTEN:${port},reuseaddr,fork" "UNIX-CONNECT:${source_socket}" &
socat -t100 "UNIX-LISTEN:${socket},mode=777,reuseaddr,fork" "TCP:localhost:${port}" &

# Record traffic
tshark -i lo -w "${dump}" -F pcapng "dst port ${port} or src port ${port}"