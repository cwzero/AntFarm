#!/bin/bash
if [ "$1" == "1" ]
then
    scripts/build_cluster.sh
fi
docker run --rm -it -v /var/run/docker.sock:/var/run/docker.sock liquidforte/ant_farm/cluster:latest