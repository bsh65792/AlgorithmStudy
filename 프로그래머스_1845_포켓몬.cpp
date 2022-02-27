#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> map;

int solution(vector<int> nums)
{
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (map[nums[i]] == 0) {
            answer++;
            map[nums[i]]++;
        }
    }

    if (nums.size() / 2 < answer) {
        answer = nums.size() / 2;
    }

    return answer;
}