mod _0709_to_lower_case_;

fn main() {
  let hello = String::from("Hello");
  let ans = _0709_to_lower_case_::Solution::to_lower_case(hello);
  println!("{}", ans);
}
