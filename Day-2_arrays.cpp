#include<iostream>
#include<queue>
using namespace std;

//Q 3 > kth max/min
//A P 1> sort and return arr[k-1]
int kthMax(int arr[],int size,int k){
	sort(arr,arr+size);
	return arr[size-k];
}

//A P 2> using heaps
int kthMaxH(int arr[],int size,int k){
	priority_queue<int> g;
	for(int i=0;i<size;i++){
		g.push(arr[i]);
	}
	for(int j=1;j<k;j++){
		g.pop();
	}
	return g.top();
}



//Q 4 >  sort 0,1,2
//A P 1 >  count frequency and update values
void sort012(int arr[], int size){
    int z=0,o=0,t=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0)z++;
        if(arr[i]==1)o++;
        else{t++;}
    }
    int j=0;
    for(int i=0;i<z;i++){
        arr[j]=0;
        j++;
    }
    for(int k=z;k<z+o;k++){
        arr[j]=1;
        j++;
    }
    for(int l=o;l<size;l++){
        arr[j]=2;
        j++;
    }
}
//A P 2 > DNF algo
void DNFsort(int arr[],int size){
	int low=0,mid=0,high=size-1;
	while(mid<high){
		switch(arr[mid]){
			case 0:
						swap(arr[low],arr[mid]);
						low++;
						mid++;
			           break;
			case 1:
			    		mid++;
						break;
			case 2:
						swap(arr[mid],arr[high]);
						high--;
						break;					
		}
	}
}
int main(){
		//Q 3 driver code
		int w[9]={6,97,65,63,23,45,81,9,1};
		cout<<kthMaxH(w,9,4);
		
		


		//Q 4 driver code
        int a[7]={2,0,1,1,0,2,2};
        /*sort012(a,7);
        for(int k=0;k<7;k++){
            cout<<a[k]<<" ";
        }*/
        
        DNFsort(a,7);
      /*  for(int k=0;k<7;k++){
        	cout<<a[k]<<" ";
        }*/
       
}
