#!/bin/bash
scripts/build_dev.sh
docker run -it --rm -p 5000:22 liquidforte/antfarm-dev /bin/bash