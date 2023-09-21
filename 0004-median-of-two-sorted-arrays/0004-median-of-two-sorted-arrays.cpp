class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        double ans=0.0;
        int s1 = nums1.size(),s2 = nums2.size();
        if(!s1 && !s2) return 0.0;
        if(s1==0) 
        {
            if(s2%2==0) return  ((double)nums2[s2/2] + nums2[ ( s2/2 ) - 1]) / 2;
            else        return (double)nums2[s2/2];
        }
        else if(s2==0)
        {
            if(s1%2==0)    return  ((double)nums1[s1/2] + nums1[ ( s1/2 ) - 1]) / 2;
            else            return (double)nums1[s1/2];
        }

        if((s1+s2)%2==0)
        {
            int k = (s1+s2)/2,c=1,f,s,curr,i=0,j=0;
            while(i<s1 && j<s2)
            {
                if(nums1[i]<=nums2[j]) curr=nums1[i++];
                else curr=nums2[j++];
                if(c == k) f = curr;
                else if(c==k+1) {s = curr;}
                c++;
            }
            while(j<s2)
            {
                if(c==k) f = nums2[j];
                else if(c==k+1) s = nums2[j];
                j++;
                c++;
            }
            while(i<s1)
            {
                if(c==k) f = nums1[i];
                else if(c==k+1) s = nums1[i];
                i++;
                c++;
            }
            ans = ((double)f+s)/2;
        }   
        else
        {
            int k = ((s1+s2)/2),c=0,curr,i=0,j=0;
            while(i<s1 && j<s2)
            {
                if(nums1[i]<=nums2[j]) curr=nums1[i++];
                else curr=nums2[j++];
                if(c == k) {return (double)curr;}
                c++;
            }
            while(j<s2)
            {
                if(c==k) return (double) nums2[j];
                j++;
                c++;
            }
            while(i<s1)
            {
                if(c==k) return (double) nums1[i];
                i++;
                c++;
            }
        }
        return ans;
    }   
};