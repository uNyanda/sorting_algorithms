#!/bin/bash

# Get the latest *-main.c file
latest_main=$(ls -t *-main.c | head -n 1)

# Get list of functions called in the latest main.c
functions=$(grep -o '[a-zA-Z_][a-zA-Z_0-9]*(' $latest_main | tr -d '(')

# Initialize gcc_files with the latest main.c file
gcc_files=$latest_main

# For each function
for func in $functions; do
    # Find the file that defines the function (excluding all *-main.c files except the latest one)
    file=$(grep -l "$func" *.c | grep -v -E '.*-main\.c' | grep -v $latest_main)

    # Print the name of the file that defines it
    echo $file
done
