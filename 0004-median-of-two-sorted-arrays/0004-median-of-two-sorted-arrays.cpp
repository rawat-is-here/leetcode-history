class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0,j = 0,k = 0;
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums3(m+n);
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
            nums3[k] = nums1[i];
            i++;k++;
            }

            else
            {
            nums3[k] = nums2[j];
            k++;j++;
            }
        }
        while(i<m)
        {
            nums3[k] = nums1[i];
            k++;
            i++;
        }
        while(j<n)
        {
            nums3[k] = nums2[j];
            k++;
            j++;
        }
        //nums 3 is now there
        if((m+n)%2==0)
        return (nums3[(m+n)/2] + nums3[(m+n)/2-1])/2.0;
        else
        return nums3[(n+m)/2];
    }
};