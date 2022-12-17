class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;
        while (target != 1) {
            if (maxDoubles == 0) {
                count += target - 1;
                target = 1;
            }
            else {
                if (target % 2 == 0) {
                    maxDoubles--;
                    target /= 2;
                    count += 1;
                }
                else {
                    target--;
                    count++;
                }
            }
        }
        return count;
    }
};
