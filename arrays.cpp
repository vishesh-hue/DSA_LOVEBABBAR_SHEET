#include<iostream>
#include<utility>
#include<limits.h>
using namespace std;


//  Q.1>    reverse array
// AP 1 => iterative way
void reverseArrayIter(int arr[], int size){
    int s=0;
    int e=size-1;
    while(e>s){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}
//AP 2 => recursive way
void reverseArrayRecur(int arr[], int start , int end){
    if(start>=end)return;
    
    swap(arr[start],arr[end]);
    reverseArrayRecur(arr, start+1, end-1);
}

//  Q.2>    find max/min in array
//AP 1 => linear search
pair<int,int> maxMin1(int arr[], int size){
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return make_pair(max,min);
}
//AP 2 => comparison in pairs
/*pair<int,int> maxMin2(int arr[], int size){
    int max,min,i;
    if(size%2==0){
        //first two mai se compare krke assign kro
        if(arr[0]>arr[1]){
            max=arr[0];
            min=arr[1];
        }
        else{
             max=arr[1];
             min=arr[0];
        }
        i=2;//aage ke comparisons yha se shuru kro
    }
    else{
        //pehla dono ko assign kro
        max=arr[0];
        min=arr[0];
        i=1;
    }

    while(i<size){
        if(arr[i]>arr[i+1]){
            if(arr[i]>max)max=arr[i];
            else if(arr[i+1]<min)min=arr[i+1];
        }
        if(arr[i]<arr[i+1]){
            if(arr[i+1]>max)max=arr[i+1];
            else if(arr[i]<min)min=arr[i];
        }
    }
    return make_pair(max,min);
}*/
//AP 3 => tournament method (recursive way)
pair<int,int> maxMin3(int arr[],int s, int e){
    // base cases
    if(s==e)return make_pair(arr[s],arr[s]);

    if(s+1==e){
        if(arr[s+1]>arr[s])return make_pair(arr[s+1],arr[s]);
        else{
            return make_pair(arr[s],arr[s+1]);
        }
    }

    //main logic
    int m=(s+e)/2;
    pair<int,int> left;
    pair<int,int> right;

    //store answers of broken subarrays
    left=maxMin3(arr,s,m);
    right=maxMin3(arr,m,e);

    // compare for both parts and return ans
    pair<int , int> ans;
    if(left.first>right.first)ans.first=left.first;
    else{ans.first=right.first;}

    if(left.second<right.second)ans.second=left.second;
    else{ans.second=right.second;}

    return ans;


}
int main(){
    int a[6]={1,2,3,5,7,9};

    //Q 1 driver code
   /* for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    // reverseArrayIter(a,5);
    // reverseArrayRecur(a,0,4);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    */

   //Q 2 driver code
   //cout<<"MAX:"<<maxMin1(a,5).first<<" "<<"MIN:"<<maxMin1(a,5).second;
//    cout<<"MAX:"<<maxMin2(a,5).first<<" "<<"MIN:"<<maxMin2(a,5).second;
   cout<<"MAX:"<<maxMin3(a,0,5).first<<" "<<"MIN:"<<maxMin3(a,0,4).second;//not working for odd size array
}











/*
struct Pair getMinMax(int arr[], int low, int high)
{
    struct Pair minmax, mml, mmr;
    int mid;
 
    // If there is only one element
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }
 
    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }
 
    // If there are more than 2 elements
    mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);
 
    // Compare minimums of two parts
    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;
 
    // Compare maximums of two parts
    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;
 
    return minmax;
}
 
// Driver code
int main()
{
    int arr[] = { 1000, 11, 445, 1, */