#include<iostream>
#include<vector>
using namespace std;

void PrintVector(vector<int>& a){
    for(vector<int>::iterator it=a.begin();it!=a.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}
//Introduce the basic knowledge of vector
void TestVector(){
    vector<int> v1;//default constrcuctor
    int arr[]={1,2,3,4};
    vector<int> v2(arr,arr+sizeof(arr)/sizeof(int));
    vector<int> v3(v2.begin(),v2.end());
    vector<int> v4(v3);
    //The four common initialized process
    PrintVector(v2);
    PrintVector(v3);
    PrintVector(v4);

    vector<int> v5;
    v5.assign(v4.begin(),v4.end());//assign operator is equal to v5=v4
    PrintVector(v5);
    
    for(int i=0;i<v5.size();i++) 
        v5[i]*=10;
    PrintVector(v5);
    v5.swap(v4);//swap operator(swap pointer)
    PrintVector(v4);
    PrintVector(v5);
    if(v1.empty())
        cout<<"v1 is empty!"<<endl;
    if(v2.empty())
        cout<<"v2 is empty!"<<endl;

    cout<<"Before resize:";
    PrintVector(v2);
    cout<<"After resize:";
    v2.resize(2);
    PrintVector(v2);

    v1.push_back(20);
    v1.push_back(30);
    v1.insert(v1.begin(),10);//low efficiency
    v1.insert(v1.end(),40);
    PrintVector(v1);

}
class Solution{
    public:
        vector<int> twoSum(vector<int>& nums,int target){
            map<int,int> m;
            for(int i=0;i<nums.size();i++){
                m[nums[i]]=i;
            


int main()
{
    TestVector();
    return 0;
}
