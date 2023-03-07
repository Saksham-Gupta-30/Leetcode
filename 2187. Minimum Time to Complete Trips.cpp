class Solution {
public:
    long long overallTrips(vector<int>& time, long long givenTime) {
        long long count = 0;
        for (auto &it: time) {
            long long num = it;
            count += (givenTime / num);
        }
        return count;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lowestTime = 1;
        long long highestTime = 1e14;
        while (highestTime > lowestTime) {
            long long mid = lowestTime + (highestTime - lowestTime) / 2;
            if (overallTrips(time, mid) >= totalTrips)
                highestTime = mid;
            else
                lowestTime = mid + 1;
        }
        return lowestTime;
    }
};
