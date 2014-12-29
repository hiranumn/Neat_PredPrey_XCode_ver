#!/bin/bash

###############################################################################
# Changes the output file directory in all parameter files for the specified
# OS to the given absolute path.
#
# Usage: ./dir.sh mac|linux absolute_path_to_output_dir
#
# Written by Alby Himelick, 7/30/13
###############################################################################

# modify output directory of $1 to be $3/$2/
function fixdir {
    sed "$ s|.*|filedist $3/$2/generation_%i|" $1 > tmp
    sed "$ s|//|/|" tmp > $1
    rm tmp
}

# cd to directory where script is running
cd "$(dirname "${BASH_SOURCE[0]}")"

# command-line argument handling
if [ $# -ne 1 ]; then
    #echo "Usage: $0 mac|linux absolute_path_to_output_dir" 1>&2
    echo "Usage: $0 absolute_path_to_output_dir" 1>&2
    exit 1
fi

# command-line arguments
#os=$1
path=$1

# modify output directory
for i in {1..14}; do
    fixdir commparams$i.ne commtest$i $path
done