class Solution {
    public:
        int hammingDistance(int x, int y){
            int dist = 0, n = x ^ y;
            while (n){
                ++dist;
                n &= n - 1;
            }
            return dist;
        }

        //int hammingDistance(int x, int y){
            //int dist = 0;
            //for (int i = 0; i != 31; ++i, x >>= 1, y >>= 1){
                //if ((x & 1) ^ (y & 1)) ++dist;
            //}
            //return dist;
        //}
};
