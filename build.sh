#!/bin/bash

cmake --build build

echo 'Copying binary to web/index.cgi'
cp build/index web/index.cgi
