class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {
        
        auto solve = [](const vector<int>& firstStart,
                        const vector<int>& firstDur,
                        const vector<int>& secondStart,
                        const vector<int>& secondDur) -> long long {
            
            int m = secondStart.size();

            vector<pair<int, int>> rides;
            rides.reserve(m);

            for (int i = 0; i < m; i++) {
                rides.push_back({secondStart[i], secondDur[i]});
            }

            sort(rides.begin(), rides.end());

            vector<int> starts(m);
            vector<long long> prefMinDur(m);
            vector<long long> suffMinStartPlusDur(m);

            for (int i = 0; i < m; i++) {
                starts[i] = rides[i].first;

                if (i == 0)
                    prefMinDur[i] = rides[i].second;
                else
                    prefMinDur[i] = min(prefMinDur[i - 1],
                                        (long long)rides[i].second);
            }

            for (int i = m - 1; i >= 0; i--) {
                long long val = (long long)rides[i].first + rides[i].second;

                if (i == m - 1)
                    suffMinStartPlusDur[i] = val;
                else
                    suffMinStartPlusDur[i] =
                        min(suffMinStartPlusDur[i + 1], val);
            }

            long long ans = LLONG_MAX;

            for (int i = 0; i < (int)firstStart.size(); i++) {
                long long finishFirst =
                    (long long)firstStart[i] + firstDur[i];

                int idx = upper_bound(starts.begin(), starts.end(),
                                      finishFirst) - starts.begin();

                long long best = LLONG_MAX;

                // Second ride already open.
                if (idx > 0) {
                    best = min(best,
                               finishFirst + prefMinDur[idx - 1]);
                }

                // Wait for a future second ride to open.
                if (idx < m) {
                    best = min(best,
                               suffMinStartPlusDur[idx]);
                }

                ans = min(ans, best);
            }

            return ans;
        };

        long long landThenWater =
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration);

        long long waterThenLand =
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration);

        return min(landThenWater, waterThenLand);
    }
};