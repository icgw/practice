/*
 * solution.go
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */

package main

import (
  "fmt"
  "strings"
)

func toLowerCase(str string) string {
  return strings.ToLower(str)
}

func main() {
  fmt.Println(toLowerCase("LOVELY"))
}
