#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertion(int *arr,int n){
    int key;
    cin>>key;
    int idx=-1;
    int s=0,e=n-1;
    int mid;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]>=key){
            idx=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    int i;
    for(i=n-1;i>=idx;i--){
        arr[i+1]=arr[i];
    }
    arr[i+1]=key;  
}

void delet(int *arr,int n){
    int index=-1;
    int ele;
    cin>>ele;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            index=i;
            break;
        }
    }

    if(index == -1)
        return ;
        
    for(int i=index;i<=n-2;i++){
        arr[i]=arr[i+1];
    }
   
}

void update(int *arr,int n){
    int ix;
    cin>>ix;
    int ele3;
    cin>>ele3;
    arr[ix]=ele3;
    sort(arr,arr+n);    
}

int givemax(int *arr,int n){
    return arr[n-1];
   
}

int givemin(int *arr,int n){
    return arr[0];
}

int find(int *arr,int n){
    int targ;
    cin>>targ;
    int s1=0,e1=n-1;
    int mid1;
    while(s1<=e1){
        mid1=s1+(e1-s1)/2;
        if(arr[mid1]==targ){
            return mid1;
        }
        else if(arr[mid1]>targ){
            e1=mid1-1;
        }
        else{
            s1=mid1+1;
        }
    }
    return -1;
   
}

void display(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
   
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int k;
    cin>>k;
    int num;
    for(int i=1;i<=k;i++){
        cin>>num;
        switch(num){
            case 1:
                insertion(arr,n);
                n++;
                //cout<<endl;
                break;
            case 2:
                delet(arr,n);
                n--;
                //cout<<endl;
                break;
            case 3:
                update(arr,n);
                break;
            case 4:
                display(arr,n);
                cout<<endl;
                break;
            case 5:
                cout<<givemax(arr,n)<<endl;
                break;
            case 6:
                cout<<givemin(arr,n)<<endl;
                break;
            case 7:
                cout<<find(arr,n)<<endl;
                break;
            default:
                cout<<"enter another choice";
        }
    }

    return 0;
}