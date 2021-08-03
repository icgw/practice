#! /bin/sh
#
# script.sh
# Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
#
# Distributed under terms of the Apache license.
#

awk '
{
    for (i = 1; i <= NF; i++) {
        if(NR == 1) {
            s[i] = $i;
        } else {
            s[i] = s[i] " " $i;
        }
    }
}
END {
    for (i = 1; s[i] != ""; i++) {
        print s[i];
    }
}' $1

