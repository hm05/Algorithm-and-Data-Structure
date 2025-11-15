
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class sorting
{
private:
    vector<int> merge_array (vector<int> a, vector<int> b){
        int n = a.size(), m = b.size();
        vector<int> sorted_array;
        int i = 0, j = 0;
        while(i < n && j < m){
            if (a[i] < b[j]){
                sorted_array.push_back(a[i++]);
            }
            else{
                sorted_array.push_back(b[j++]);
            }
        }
        while (i < n) sorted_array.push_back(a[i++]);
        while (j < m) sorted_array.push_back(b[j++]);
        return sorted_array;
    }
public:
    vector<int> insertion_sort (vector<int> arr){
    // This is a Program demonstrating the insertion sort.
    // The complexity of this algorithm is O(n^2).
    /* The pseducode of this algorithm is
     *
     * insertion_sort(arr):
     *     for i = 0...n-1:
     *         j = i
     *         while j > 0 and arr(j) < arr(j-1):
     *             swap(arr(j), arr(j-1))
     *             j--
     *     return arr;
     */
    
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int j = i;
            while (j > 0 && arr[j-1] > arr[j]){
                swap(arr[j-1], arr[j]);
                j--;
            }
        }
        return arr;
    }

    vector<int> merge_sort (vector<int> arr){
    // This is a Program demonstrating the merge sort.
    // The complexity of this algorithm is O(n logn).
    /* The pseducode of this algorithm is 
     * 
     * merge(a, b):
     *     n = len(a)
     *     m = len(b)
     *     arr [n + m]
     *     i = 0, j = 0, k = 0
     *     while i < n or j < m:
     *         if j = m or (i < n and a[i] < b[j]):
     *             arr(k++) = a(i++)
     *         else
     *             arr(k++) = b(j++)
     *         return arr
     * 
     * sort(arr):
     *     if len(arr) < 2 : return arr
     *     a = arr (0...n/2-1)
     *     b = arr (n/2...n-1)
     *     a = sort (a)
     *     b = sort (b)
     *     return merge(a, b)
     */
        if (arr.size() < 2)
        {
            return arr;
        }
        vector<int> a, b;
        int n = arr.size();
        a.insert(a.begin(), arr.begin(), arr.begin() + n/2);
        b.insert(b.begin(), arr.begin() + n/2, arr.end());
        a = merge_sort(a);
        b = merge_sort(b);
        return merge_array(a, b);
    }
    void print_array(vector<int> arr){
        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main(){
    int choice;
    cout << "Which sorting algorithm would you like to use?" << endl << "1. Insertion Sort (Time complexity: n^2)" << endl << "2. Merge Sort (Time complexity: n logn)" << endl;
    cin >> choice;

    sorting call;

    vector<int> arr;
    
    cout << "Please enter the numbers: ";
    
    int x;

    while (cin >> x) {
        arr.push_back(x);
        if (cin.peek() == '\n') break;
    }
    
    switch (choice)
    {
    case 1:
        // cout << "Insertion sort selected" << endl;
        arr = call.insertion_sort(arr);
        call.print_array(arr);
        break;
    case 2:
        // cout << "Merge sort selected" << endl;
        arr = call.merge_sort(arr);
        call.print_array(arr);
        break;
    default:
        cout << "Thank you for using the program" << endl;
        break;
    }
    return 0;
}