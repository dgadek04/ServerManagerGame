#!/bin/bash

# Set the output file name
output_file="game"

# List all the source files to be compiled
source_files=(
    "src/main.cpp"
    "src/player.cpp"
    "src/game.cpp"
    # Add more source files as needed
)

# Compile the source files
g++ -o "$output_file" "${source_files[@]}"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
else
    echo "Compilation failed."
fi
