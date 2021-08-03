#! /bin/sh
#
# script.sh
# Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
#
# Distributed under terms of the Apache license.
#

cat $1 | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1 }'

