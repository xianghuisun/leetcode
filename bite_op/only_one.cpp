#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
       int singleNumbers_one(vector<int>& nums){
            int single_number=0;
            for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
                single_number=single_number^(*it);
            }
            return single_number;
        }
       vector<int> singleNumbers_two(vector<int>& nums){
           int total_ox=0;
           for(vector<int>::iterator it=nums.begin();it!=nums.end();it++)
               total_ox=total_ox^(*it);
           int res1=0,res2=0;
           int pos=total_ox&(-total_ox);
           for(int i=0;i<nums.size();i++)
           {
               if(nums[i]&pos==pos)
                   res1^=nums[i];
               else
                   res2^=nums[i];
           }
           vector<int> res;
           res.push_back(res1);
           res.push_back(res2);
           return res;
       }

};




int main()
{
    /*cout<<"Please input the number of vector : ";
    int n;
    cin>>n;
    cout<<"Please sequentially input the element of vector :"<<endl;
    int placeholder;
    for(int i=0;i<n;i++)
    {
        cin>>placeholder;
        nums.push_back(placeholder);
    }
    cout<<endl;
    Solution s=Solution();
    int single_number=s.singleNumbers_one(nums);
    cout<<single_number<<endl;*/
    Solution s=Solution();
    int a[]={1,2,4,4,5,5,6,6};
    vector<int> nums;
    for(int i=0;i<8;i++)
        nums.push_back(a[i]);
    vector<int> res=s.singleNumbers_two(nums);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
