class Solution {
    private:
        int digitSquareSum(int n) {
            int sum = 0;
            while (n != 0) {
                int tmp = n % 10;
                sum += tmp * tmp;
                n /= 10;
            }
            return sum;
        }

    public:
        bool isHappy(int n) {
            int slow = n, fast = n;
            do {
                slow = digitSquareSum(slow);
                fast = digitSquareSum(fast);
                fast = digitSquareSum(fast);
            } while (slow != fast);
            return slow == 1;
        }
};
