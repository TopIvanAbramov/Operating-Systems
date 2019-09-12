#!/bin/bash

read -p "Enter Your command: "  cmd
echo "Execute programm $cmd"

bash -c "$cmd"
