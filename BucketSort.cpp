#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<double> arr {4.5, 0.84, 3.25, 2.18, 0.5};
    double max = *max_element(arr.begin(), arr.end());
    double min = *min_element(arr.begin(), arr.end());
    double d = max - min;
    int bucketNum = arr.size();

    //初始化桶，并向每个桶中插入合适的元素
    vector<vector<double>> bucketList (bucketNum);
    for(int i = 0; i< arr.size(); i++)
    {
        int num = (int)((arr[i] - min) * (bucketNum -1) / d);
        bucketList[num].push_back(arr[i]);
    }

    //对桶中的元素进行排序并输出
    for(int i = 0; i < arr.size(); i++)
    {
        sort(bucketList[i].begin(), bucketList[i].end());
        for_each(bucketList[i].begin(), bucketList[i].end(), [](double x) {cout << x << " ";});
    }

    cout << endl;

    system("pause");
}