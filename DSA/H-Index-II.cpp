#include <iostream>
using namespace std;
// Brute force solution
// h index = v >= n-v
int hIndexBrute(vector<int> &citations)
{
    int n = citations.size();
    for (int i = 0; i < n; i++)
    {
        if (citations[i] == n - i)
        {
            return citations[i];
        }
    }
    return -1;
}

// Optimal solution
int hIndexOptimal(vector<int> &citations)
{
    int n = citations.size();
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (citations[mid] == (n - mid))
        {
            return citations[mid];
        }
        else if (citations[mid] > (n - mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return n - low;
}

int main()
{
    vector<int> citations = {0, 1, 3, 5, 6};
    cout << "h Index : " << hIndexBrute(citations) << endl;
    cout << "h Index : " << hIndexOptimal(citations) << endl;

    return 0;
}