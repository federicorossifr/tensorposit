#!/bin/bash
docker run -it  -v/home/federico/cppWorkspace/cppposit_private:/cppposit_private -v $PWD/tensorflow:/tensorposit -e HOST_PERMS="$(id -u):$(id -g)" tensorflow/tensorflow:devel bash




