
// Chapter 6 in Introduction In Algorithms // HeapSort #include <bits/stdc++.h> using namespace std; // Lift , Right and Parent Node to Current Node int Lift(int pos){ return pos * 2 + 1 ; }

int Right(int pos){ return pos * 2 + 2 ; }

int Lift(int pos){ return pos * 2 + 1 ; }

int Parent(int pos){ return (pos) / 2 -1 ; } // Time complexity lg(n) = height // Time complexity Max_Heapif O(lg n) void Max_Heapify(vector &heap, int n ,int pos) {

int greater = pos ;

if(Lift(pos) < n && heap[greater] < heap[Lift(pos)]) // check if lift node is greater than parent { greater = Lift(pos) ; }

if(Right(pos) < n && heap[greater] < heap[Right(pos)]) // check if right node is greater than max(Parent ,Lift Node) // max(Parent ,Lift Node) = greater { greater = Right(pos) ; }

if(pos!=greater){ // If Was Difference Between Current Pos And Greater This Mean I Get Element Greater Than Parent swap(heap[pos],heap[greater]) ; Max_Heapify(heap,n,greater) ; }

}

void BuildHeap(vector &heap , int n ){ //o(n)

    for(int pos =n/2-1 ; pos>=0 ;pos--){
        Max_Heapify(heap,n,pos) ;
    }
}

void HeapSort(vector &heap, int n ){ // O(n lgn) BuildHeap(heap , n ) ;

    for(int pos = n-1 ;pos>0 ; pos--){
        swap(heap[0] , heap[pos] ) ;
        Max_Heapify(heap,pos,0);
    }
}

int main() {

    vector<int>heap = { 4, 1, 3, 2, 16, 9,10,14,8,7};
    int n = heap.size();
    BuildHeap(heap, n);
    cout << "Sorted array is \n";

    for(int i =0 ; i<heap.size() ;i++)cout<<heap[i]<<" ";
    cout<<'\n' ;
}