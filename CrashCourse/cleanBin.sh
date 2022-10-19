#!/bin/bash
# cleanup

find ./ -depth -name bin -type d -exec rm -rf {} \;
