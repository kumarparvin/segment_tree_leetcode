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

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */


int main(int argc, const char * argv[]) {
    // insert code here...
   //std::cout << "Hello, World!\n";
    vector<int> nums={1,6,7,3,9};
    NumArray*obj = new NumArray(nums);
    obj->update(4,55);
    int param_2 = obj->sumRange(0,2);
    cout<<param_2<<endl;

    return 0;
}
