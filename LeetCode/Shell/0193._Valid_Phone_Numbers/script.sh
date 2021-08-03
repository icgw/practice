#! /bin/sh
#
# script.sh
# Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
#
# Distributed under terms of the Apache license.
#


cat $1 | egrep "^((\([0-9]{3}\) )|([0-9]{3}-))[0-9]{3}-[0-9]{4}$"
