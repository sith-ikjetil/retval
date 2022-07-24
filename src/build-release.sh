#!/bin/bash
#: Title       : build-release.sh
#: Date        : 2022-07-23
#: Author      : Kjetil Kristoffer Solberg <post@ikjetil.no>
#: Version     : 1.0
#: Description : Builds retval.
echo "Building fib ..."
echo "> using release build < "

g++ retval.cpp --std=c++17 -o retval
if [[ $? -eq 0 ]]
then
    echo "> retval build ok"
else
    echo "> retval build error"
fi

echo "> build process complete <"

