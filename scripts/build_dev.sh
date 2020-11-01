#!/bin/bash
docker build -t liquidforte/ant_farm/base:latest -f docker/core/base.Dockerfile .
docker build -t liquidforte/ant_farm/build:latest -f docker/core/build.Dockerfile .
docker build -t liquidforte/ant_farm/dev:latest -f docker/dev.Dockerfile .