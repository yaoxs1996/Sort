#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int> &list, int low, int high)
{
    int pivot = list[low];
    while(low < high)
    {
        while(low < high && list[high] >= pivot)
        {
            --high;
        }
        list[low] = list[high];

        while(low < high && list[low] <= pivot)
        {
            low++;
        }
        list[high] = list[low];
    }
    list[low] = pivot;
    return low;
}

void quickSort(vector<int> &list, int low, int high)
{
    if(low < high)
    {
        int pivotpos = partition(list, low, high);
        quickSort(list, low, pivotpos-1);
        quickSort(list, pivotpos+1, high);
    }
}

int main()
{
    vector<int> list {2, 1, 4, 9, 8, 10, 6, 20};
    int len = list.size();
    quickSort(list, 0, len-1);

    cout << "排序结果如下：" << endl;
    for_each(list.begin(), list.end(), [](int x){cout << x << " ";});
    cout << endl;

    system("pause");
    return 0;
}