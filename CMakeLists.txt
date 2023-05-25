cmake_minimum_required (VERSION 2.8)
project (etools)
aux_source_directory(./src DIR_SRCS)
add_executable(etools ${DIR_SRCS})