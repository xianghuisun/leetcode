#include<iostream>
#include<vector>
using namespace std;

class MountainArray{
    public:
        int get(int index){return this->v[index];}
        int length(){return this->v.size();}
        MountainArray(int a[],int n);
    private:
        vector<int> v;
};
MountainArray::MountainArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        this->v.push_back(a[i]);
}

class Solution{
    public:
        int findMountainPeakPos(MountainArray& mountainArr,int left,int right);
        int findsortedMountain(MountainArray& mountainArr,int left,int right,int target);
        int findReversedMountain(MountainArray& mountainArr,int left,int right,int target);
        int findInMountainArray(int target,MountainArray& mountainArr){
            int peak_pos=findMountainPeakPos(mountainArr,0,mountainArr.length()-1);
            if(mountainArr.get(peak_pos)==target)
                return peak_pos;
            int a=findsortedMountain(mountainArr,0,peak_pos,target);
            if(a!=-1)
                return a;
            return findReversedMountain(mountainArr,peak_pos,mountainArr.length()-1,target);
        }
};

int Solution::findMountainPeakPos(MountainArray& mountainArr,int left,int right)
{
    //find the peak position mountainArr.get(peak_pos) should be the biggest value of mountain array
    while(left<right)
    {
        int middle=left+(right-left)/2;//向下取整
        //first sorted by ascending and after is descending sort
        if(mountainArr.get(middle)<mountainArr.get(middle+1))
            left=middle+1;
        else
            right=middle;
    }
    return left;
}
int Solution::findsortedMountain(MountainArray& mountainArr,int left,int right,int target)
{
    while(left<right)
    {
        int middle=left+(right-left)/2;
        if(mountainArr.get(middle)==target)
            return middle;
        if(mountainArr.get(middle)<target)
            left=middle+1;
        if(mountainArr.get(middle)>target)
            right=middle-1;
    }
    if(mountainArr.get(left)==target)
    {
        cout<<left<<"=="<<right<<endl;
        return left;
    }
    return -1;
}
int Solution::findReversedMountain(MountainArray& mountainArr,int left,int right,int target)
{
    while(left<right)
    {
        int middle=left+(right-left)/2;
        if(mountainArr.get(middle)==target)
            return middle;
        if(mountainArr.get(middle)<target)
            right=middle-1;
        if(mountainArr.get(middle)>target)
            left=middle+1;
    }
    if(mountainArr.get(left)==target)
    {
        cout<<left<<"=="<<right<<endl;
        return left;
    }
    return -1;
}
int main()
{
    int a[]={1,2,3,4,5,6,7,3,1};
    MountainArray mountainArr=MountainArray(a,7);
    Solution s=Solution();
    cout<<s.findInMountainArray(7,mountainArr)<<endl;
    return 0;
}
    
