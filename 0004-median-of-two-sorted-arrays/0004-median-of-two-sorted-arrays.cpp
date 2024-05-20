class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sumArray;
        vector<int>::iterator iter_1 = nums1.begin();
        vector<int>::iterator iter_2 = nums2.begin();
        double result;

        while(iter_1 != nums1.end() || iter_2 != nums2.end())
        {
            if (iter_1 == nums1.end())
            {
                for (; iter_2 != nums2.end(); ++iter_2)
                {
                    sumArray.push_back(*iter_2);
                }
                break;
            }
            if (iter_2 == nums2.end())
            {
                for (; iter_1 != nums1.end(); ++iter_1)
                {
                    sumArray.push_back(*iter_1);
                }
                break;
            }
            if (*iter_1 < *iter_2)
            {
                sumArray.push_back(*iter_1);
                ++iter_1;
            }
            else
            {
                sumArray.push_back(*iter_2);
                ++iter_2;
            }
        }

        if (sumArray.size() % 2 == 1)
        {
            result = sumArray[(sumArray.size() / 2)];
        }
        else
        {
            result = ((double)sumArray[(sumArray.size()/2)-1]+sumArray[sumArray.size()/2])/2;
        }

        return result;
    }
};