#!/bin/bash

while true
do
    read -p ">"  cmd
    bash -c "$cmd"
done
