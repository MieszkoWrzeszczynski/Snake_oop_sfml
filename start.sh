#!/bin/bash
g++ -c  -std=c++11  *.cpp
g++ *.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
./sfml-app 
