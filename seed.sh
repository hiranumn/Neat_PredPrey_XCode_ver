#!/bin/bash

###############################################################################
# Changes the random seed in all parameter files for the specified OS using the
# bash $RANDOM random number generator.
#
# Usage: ./dir.sh mac|linux
#
# Written by Alby Himelick, 7/30/13
###############################################################################

# modify random seed using bash $RANDOM random number generator
function fixseed {
    sed "35 s/[0-9][0-9]*/$RANDOM/" $1 > tmp
    mv tmp $1
}

# cd to directory where script is running
cd "$(dirname "${BASH_SOURCE[0]}")"

# command-line argument handling
if [ $# -ne 0 ]; then
    echo "Usage: $0 mac|linux" 1>&2
    exit 1
fi


# modify random seed
for i in {1..14}; do
    fixseed commparams$i.ne
done