//
//  main.cpp
//  segement_tree
//
//  Created by Parvin ... on 23/09/17.
//  Copyright © 2017 Parvin ... All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;

class NumArray {
    unsigned long int seg_size;
    vector<int> seg;
    unsigned long int len;
    void build_tree(vector<int> num, int i)
    {
        unsigned long int k=0;
        unsigned long int x=0;
        for(x=len;x<seg_size;x++)
        {
            seg[x]=num[k++];
        }
        
        for(x=len-1;x>0;x--)
        {
            seg[x]=seg[2*x]+seg[2*x+1];
        }
        
    }
    
public:
    NumArray(vector<int> nums) {
        len=nums.size();
        if(len!=0)
        {
        seg_size=(2* len)+1;
        seg.resize(seg_size);
        build_tree(nums,1);
        }
    }
    
    void update(int i, int val) {
        
        int diff=val-seg[i+len];
        seg[i+len]=val;
        unsigned long int x=(i+len)/2;
        while(x>0)
        {
            seg[x]+=diff;
            x=x/2;
        }
    }
    
   int sumRange(int i, int j) {
       int sum=0;
       unsigned long int left=i+len;
       unsigned long int right=j+len;
       
       while(left<right && left >0 && right>0)
       {
           if(left &1)
           {
               sum+=seg[left];
               left++;
           }
           if(!(right&1))
           {
               sum+=seg[right];
               right--;
           }
           
           left=left/2;
           right=right/2;
       }
       if(left==right)
           return sum+seg[left];
       
       return sum;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums;
    int n;
    int st;
    int en;
    cout<<"input number of element in array"<<endl;
    cin>>n;
    cout<<"enter elements"<<endl;
    while(n--)
    {
        int a;
        cin>>a;
        nums.push_back(a);
    }
    NumArray*obj = new NumArray(nums);
    int k;
    cout<<"press\n 1: insert\n 2: upodate\n";
    cin>>k;
    switch(k)
    {
        case 1:
            cout<<"input range [0...."<<n-1<<"]"<<endl;
            cin>> st>>en;
            cout<<obj->sumRange(st,en)<<endl;
            break;
            
        case 2:
            cout<<"entern index [0...."<<n-1<<"] and new value"<<endl;
            cin>>st>>en;
            obj->update(st,en);
            break;
            
    }

    return 0;
}
