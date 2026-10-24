#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    // Helper function to convert "MM-DD" to day of the year (1 to 365)
    int calculateDayOfYear(std::string date) {
        std::vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));
        
        int totalDays = day;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysInMonths[i];
        }
        
        return totalDays;
    }

    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, 
                          std::string arriveBob, std::string leaveBob) {
        int aliceArrival = calculateDayOfYear(arriveAlice);
        int aliceLeaving = calculateDayOfYear(leaveAlice);
        int bobArrival = calculateDayOfYear(arriveBob);
        int bobLeaving = calculateDayOfYear(leaveBob);
        
        // Find the latest arrival and earliest departure
        int start = std::max(aliceArrival, bobArrival);
        int end = std::min(aliceLeaving, bobLeaving);
        
        // Calculate overlapping days
        if (start <= end) {
            return end - start + 1;
        }
        
        return 0;
    }
};