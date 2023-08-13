#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    vector<int> arr;
    int n;
    public:
    MaxHeap(){
        arr.push_back(-1);
        n = 0;
    }
    void heapify(int idx){
        int largest = idx;
        int child1 = largest*2;
        int child2 = largest*2 + 1;
        if(child1<=n and arr[largest] < arr[child1]){
            largest = child1;
        }
        if(child2 <=n and arr[largest] < arr[child2]){
            largest = child2;
        }
        if(largest != idx){
            swap(arr[idx], arr[largest]);
            heapify(largest);
        }
    }
    void push(int val){
        arr.push_back(val);
        n++;
        int idx = n;
        while(idx>1){
            int parent = idx/2;
            if(arr[idx] > arr[parent]){
                int temp = arr[parent];
                arr[parent] = arr[idx];
                arr[idx] = temp;
                idx /= 2;
            }
        }
    }
    void pop(){
        arr[1] = arr[n];
        arr.pop_back();
        n--;
        if(!n){
            return;
        }
        heapify(1);
    }
    int size(){
        return n;
    }
    int top(){
        return arr[1];
    }
};

class MinHeap{
    public:
    vector<int> arr;
    int n;
    MinHeap(){
        arr.push_back(-1);
        n = 0;
    }
    void heapify(int idx){
        int smallest = idx;
        int child1 = 2*smallest;
        int child2 = 2*smallest + 1;
        if(child1 <=n and arr[smallest] > arr[child1]){
            smallest = child1;
        }
        if(child2 <=n and arr[smallest] > arr[child2]){
            smallest = child2;
        }
        if(smallest != idx){
            swap(arr[smallest], arr[idx]);
            heapify(smallest);
        }
    }
    void push(int val){
        arr.push_back(val);
        n++;
        int idx = n;
        while(idx > 1){
            int parent = idx/2;
            if(arr[parent] > arr[idx]){
                swap(arr[parent], arr[idx]);
                idx /= 2;
            }
            else{
                break;
            }
        }
    }
    void pop(){
        arr[1] = arr[n];
        arr.pop_back();
        n--;
        heapify(1);
    }
    int size(){
        return n;
    }
    int top(){
        return arr[1];
    }
};
int main(){
    MinHeap pq;

}