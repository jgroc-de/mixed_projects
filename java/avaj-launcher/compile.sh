#!/bin/bash

find . -name "*.java" > sources.txt && javac -sourcepath . @sources.txt
java src/Application scenario.txt
