#include <iostream>
#include <ctime>
#include <random> 

using namespace std;

void fillArr(int ran[], int n){
    mt19937 mt(time(nullptr));
    for(int i=0; i<n; i++){
        ran[i]=mt();
    }
}

void retArr(int ran[], int n){
    for(int i=0; i<n; i++){
        std::cout<<ran[i]<<" ";
    }
    std::cout<<std::endl;
}

unsigned long long insertionSort(int arr[], int n)
{
    int i, key, j;
    unsigned long long b=0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        b+=1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            b+=2;
        }
        arr[j + 1] = key;
        b+=2;
    }
    return b;
}
 


int partition(int vec[], int n, int low, int high, int  option, unsigned long long &count) {

    // Selecting last element as the pivot
    int pivot{0};
    switch(option){
        case 0:  pivot = vec[high]; break;
        case 1:  pivot = vec[(high-low)/2]; break;
        case 2:  pivot = (vec[high]+vec[(high-low)/2]+vec[low])/2; break;
        case 3:  pivot = std::min(vec[low],vec[high]); break;
        case 4:  pivot = std::max(vec[low],vec[high]); break;
    }
    count+=1;
    count+=1;

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (low - 1);
    count+=2;

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
            count+=3;
        }
        count+=1;
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);
    count+=3;

    // Return the point of partition
    return (i + 1);
}

void quickSort(int vec[], int n, int low, int high, int option, unsigned long long &count) {

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {
        count+=1;

        // pi is Partitioning Index, arr[p] is now at
        // right place
        int pi = partition(vec ,n, low, high, option, count );

        // Separately sort elements before and after the
        // Partition Index pi
        quickSort(vec,n, low, pi - 1, option, count);
        quickSort(vec,n, pi + 1, high, option, count);
    }
    
}

int main()
{

    int n=10000;
    int ran[10000];
    mt19937 mt(time(nullptr));
    fillArr(ran, n);
    
    unsigned long long count1=0;
    quickSort(ran, n, 0, n, 0, count1);
    std::cout<<count1<<std::endl;
    
    int ran2[10000];
    fillArr(ran, n);
    unsigned long long count2=insertionSort(ran, n);
    std::cout<<count2<<std::endl;
    
    srand(time(NULL));
    //mt19937 mt;
    std::cout<<mt()<<std::endl;
    std::cout<<mt();


    return 0;
}