#!/bin/bash

docker build -t liquidforte/ant_farm/base:latest -f docker/core/base.Dockerfile .
docker build -t liquidforte/ant_farm/build:latest -f docker/core/build.Dockerfile .
docker build -t liquidforte/ant_farm/builder:latest -f docker/builder.Dockerfile .
docker build -t liquidforte/ant_farm/runner:latest -f docker/runner.Dockerfile .

docker build -t liquidforte/ant_farm/ant_farm:latest -f docker/modules/ant_farm.Dockerfile .
docker build -t liquidforte/ant_farm/cluster:latest -f docker/modules/cluster.Dockerfile .
docker build -t liquidforte/ant_farm/core:latest -f docker/modules/core.Dockerfile .
docker build -t liquidforte/ant_farm/generation:latest -f docker/modules/generation.Dockerfile .
docker build -t liquidforte/ant_farm/organism:latest -f docker/modules/organism.Dockerfile .