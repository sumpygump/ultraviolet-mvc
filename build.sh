#!/bin/bash

cmake --build build

echo 'Copying binary index to web/index.cgi'
cp build/index web/index.cgi

echo 'Copying binary info to web/info.cgi'
cp build/info web/info.cgi
