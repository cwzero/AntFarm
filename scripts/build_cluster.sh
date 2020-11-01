#!/bin/bash

docker build -t liquidforte/ant_farm/base:latest -f docker/core/base.Dockerfile .
docker build -t liquidforte/ant_farm/build:latest -f docker/core/build.Dockerfile .
docker build -t liquidforte/ant_farm/builder:latest -f docker/builder.Dockerfile .
docker build -t liquidforte/ant_farm/runner:latest -f docker/runner.Dockerfile .

docker build -t liquidforte/ant_farm/cluster:latest -f docker/modules/cluster.Dockerfile .