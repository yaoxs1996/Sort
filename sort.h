#pragma once
#include<vector>
#include<algorithm>

//双向冒泡升序排序
void bubble_sort_2(vector<int> &a)
{
    int n = a.size();
    int change = 1, low = 0, high = n-1;
    while(low <= high && change == 1)
    {
        change = 0;        //假设不发生交换
        for(int i = low; i<high; i++)        //由左向右冒泡
            if(a[i] > a[i+1]
            {
                swap(a[i], a[i+1]);
                change = 1;
            }
        high--;        //修改上界
        
        for(int i = high; i>low; i--)        //由右向左冒泡
            if(a[i]<a[i-1]
            {
                swap(a[i], a[i+1]);
                change = 1;
            }
        low++;        //修改下界
    }
}
