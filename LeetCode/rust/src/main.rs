mod _0001_two_sum_;

fn main() {
  let ans = _0001_two_sum_::Solution::two_sum(vec![ 2, 7, 11, 15 ], 9);
  if ans.len() == 2 {
    println!("[{}, {}]", ans[0], ans[1]);
  }
}
