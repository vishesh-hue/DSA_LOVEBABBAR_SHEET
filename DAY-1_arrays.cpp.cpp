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
pair<int,int> maxMin2(int arr[], int size){
    int max,min,i;
    if(size%2!=0){
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
        i+=2;
    }
    return make_pair(max,min);
}
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
   for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    reverseArrayIter(a,6);
     for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    reverseArrayRecur(a,0,5);
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
   

   //Q 2 driver code
    cout<<"MAX:"<<maxMin1(a,6).first<<" "<<"MIN:"<<maxMin1(a,6).second<<endl;
    cout<<"MAX:"<<maxMin2(a,6).first<<" "<<"MIN:"<<maxMin2(a,6).second<<endl;
    cout<<"MAX:"<<maxMin3(a,0,5).first<<" "<<"MIN:"<<maxMin3(a,0,5).second;
}

