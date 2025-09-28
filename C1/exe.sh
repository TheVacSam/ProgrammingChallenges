#thanks davids
#!/bin/bash

if [ $# -eq 0 ]; then
  echo "USAGE: ./run file.cpp [optional input] [optional output]"
  exit 1
elif [ $# -eq 1 ]; then
  src=$1
  out=${src%.cpp}
  g++ "$src" -o "objects/$out" && ./objects/"$out"
elif [ $# -eq 2 ]; then
  src=$1
  out=${src%.cpp}
  g++ "$src" -o "objects/$out" && ./objects/"$out" <"$2"
elif [ $# -eq 3 ]; then
  src=$1
  out=${src%.cpp}
  g++ "$src" -o "objects/$out" && ./objects/"$out" <"$2" >"$3"
fi