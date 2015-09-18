#!/bin/bash - 
# argument is root directory with websites / directories with websites
set -o nounset                              # Treat unset variables as an error
find $1  -type f -name '*.xml' 

