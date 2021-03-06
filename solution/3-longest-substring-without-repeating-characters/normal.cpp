#include <string>
#include <array>
#include <algorithm>

using std::array;
using std::max;
using std::string;
using std::swap;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int end = s.size();
        switch (end)
        {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            break;
        }

        array<int, 127> record;
        record.fill(-1);

        auto anchor = 0;

        auto maximun = 0;

        for (auto i = 0; i != end; i++)
        {
            auto current = s[i];

            auto last = i;
            swap(last, record[current]);

            if (last != -1)
            {
                maximun = max(maximun, i - anchor);
                anchor = max(anchor, last + 1);
                if (end - anchor <= maximun)
                {
                    return maximun;
                }
            }
        }

        return end - anchor;
    }
};