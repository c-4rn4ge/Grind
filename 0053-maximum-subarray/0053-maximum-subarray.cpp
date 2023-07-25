class Solution {
public:
    int maxSubArray(vector<int>& arr) 
    {
        int maxS= INT_MIN,sum=0,i,s=0,start=0,end=0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum = sum + arr[i];
            if (sum < arr[i])
            {
                sum = arr[i];
                s = i;
            }
            if (maxS < sum)
            {
                maxS = sum;
                start = s;
                end = i;
            }
        }
        for(i=start;i<=end;i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        return maxS;
    }
};