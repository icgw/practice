mod _0905_sort_array_by_parity_;

fn main() {
  let a = vec![ 3, 1, 2, 4 ];
  let ans = _0905_sort_array_by_parity_::Solution::sort_array_by_parity(a);
  for x in ans {
    println!("{}", x);
  }
}
