
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int low1 = 0;
        int low2 = 0;

        int vi = 1;
        int elm1 = 0, elm2 = 0;
        int i1, i2;

        if ((n + m) % 2 == 0) {
            i1 = (n + m) / 2;
            i2 = i1 + 1;
        } else {
            i1 = (n + m + 1) / 2;
            i2 = i1;
        }

        while (low1 < n && low2 < m) {
            if (nums1[low1] <= nums2[low2]) {
                if (vi == i1) elm1 = nums1[low1];
                if (vi == i2) elm2 = nums1[low1];
                low1++;
            } else {
                if (vi == i1) elm1 = nums2[low2];
                if (vi == i2) elm2 = nums2[low2];
                low2++;
            }
            vi++;
        }

        while (low1 < n) {
            if (vi == i1) elm1 = nums1[low1];
            if (vi == i2) elm2 = nums1[low1];
            low1++;
            vi++;
        }

        while (low2 < m) {
            if (vi == i1) elm1 = nums2[low2];
            if (vi == i2) elm2 = nums2[low2];
            low2++;
            vi++;
        }

        double ans = ((double)elm1 + elm2) / 2;
        return ans;
    }
};
