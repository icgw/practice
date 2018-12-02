import java.util.Arrays;
import java.util.HashMap;

public class Solution {
	public int[] twoSum(int[] nums, int target){
		HashMap<Integer, Integer> m = new HashMap<>();
		for (int i = 0; i < nums.length; ++i){
			if (m.containsKey(nums[i])) return new int[] {m.get(nums[i]), i};
			m.put(target - nums[i], i);
		}
		throw new IllegalArgumentException("No two sum solution");
	}

	public static void main(String[] args){
		Solution s = new Solution();
		int[] nums = {2, 7, 11, 15};
		System.out.println(Arrays.toString(s.twoSum(nums, 9)));
	}
}
