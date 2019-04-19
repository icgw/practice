package main

import "fmt"

func twoSum(nums []int, target int) []int {
  lookup := make(map[int]int)
  for i, v := range nums {
    j, ok := lookup[-v]
    lookup[v - target] = i
    if ok {
      return []int { j, i }
    }
  }
  return []int {}
}

func main(){
  nums   := []int { 2, 7, 11, 15 }
  target := 9
  var ans []int
  ans = twoSum(nums, target)
  fmt.Println(ans)
}
