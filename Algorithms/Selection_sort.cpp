#include <iostream>
using namespace std;

int main() {
    int nums[]={6, 5, 2, 8, 9, 4};
    int size=sizeof(nums)/sizeof(nums[0]);
    int temp=0,minIndex=-1;

    cout<<"Before Sorting"<< endl;
    for (int num:nums) {
        cout << num << " ";
    }
    cout << endl;

    for (int i=0;i<size-1;i++) {
        minIndex=i;
        for (int j=i + 1;j < size;j++) {
            if (nums[minIndex]>nums[j]) {
                minIndex = j;
            }
        }

        temp=nums[minIndex];
        nums[minIndex]=nums[i];
        nums[i]=temp;

        for (int num:nums) {
            cout<< num << " ";
        }
        cout << endl;
    }

    cout << endl<< "After Sorting" << endl;
    for (int num:nums) {
        cout << num << " ";
    }

    return 0;
}
