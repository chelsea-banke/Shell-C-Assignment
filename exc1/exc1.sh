#!/bin/bash


echo "enter file path: "
read path

chmod u+x $path
if ([ $? -eq 0 ])
then
  if ([ $path == *.c ])
  then
    gcc $path
    ./a.out
  else
    echo "not a c file"
  fi
else
  echo "invalid input, not a file"
fi
