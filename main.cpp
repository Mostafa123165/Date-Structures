
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

/*
 * ## content  :
 * 1-what is Heap ?
 * How Heaps Work ?
 * Heap Sort ?
 *
 * --------
 *
 * ## What is Heap ?
 *
 * -Heap is Date Structure We can View Binary Tree ( Complete Binary Tree , Full Binary Tree ),
 * -Each node in Binary Tree is Correspond to the Element in My Array ,
 * -Complete Binary Tree is Binary Tree is completely with elements except last level .
 * -Full Binary Tree is Binary Tree is completely with elements and last level .
 * -heap View by MaxHeap Or MinHeap , (MaxHeap Each Parent is greater than all child ) and MinHeap is Inverse MaxHeap
 * - is Emplace (This is mean do not need adding memory to doing operation (inverse merge Sort need  adding memory )).
 *
 * --------
 *
 * How Heaps Work ?
 * - In the first I have tow heap (max heap, min heap) ,
 * - How Max Heap work ? Compare Parent with Child if anyone child is greater than Parent I swap( parent , max between two child ) ,
 * - then do Recursive on same node (same node this mean max(parent , two child)).
 * - if Parent is Greater Tow Child I do return(stop).
 * - Time Complexity is O(lg n).a
 * - How Max Heap work ? Reverse Max Heap .
 *
 * --------
 * Heap Sort ? // Time O(n lgn)
 * - The Heapsort Algorithm start By Build_Heap So convert un order array to Max_Heap ,
 * - after this I have Max_Heap_Array and Max Element is Top Tree (A[0])
 *  Doing Operation ?
 *    // Repeat (1,2,3) on A.length() To 1
 *  1 : exchanging A[0] with a[n] (n number elements in array ). // a[n] is max element in Tree
 *  2 : n-=1 ( A.length() - 1 ) . // because i cut last element From Tree
 *  3 : we need do Max Heapify on 0 (0 Top Array )  ?  making  Max_Heap_Array .
 *
 *
*/
