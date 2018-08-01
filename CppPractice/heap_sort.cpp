//
// Created by Anant Agarwal on 8/1/18.
//

#include "iostream"
#include "vector"

using namespace std;




struct PriorityQueue {
private:
    // vector to store heap elements
    vector<int> A;

    // return parent of A[i]
    // don't call this function if it is already a root node
    int PARENT(int i) {
        return (i - 1) / 2;
    }

    // return left child of A[i]
    int LEFT(int i) {
        return (2 * i + 1);
    }

    // return right child of A[i]
    int RIGHT(int i) {
        return (2 * i + 2);
    }

    // Recursive Heapify-down algorithm
    // the node at index i and its two direct children
    // violates the heap property
    void heapify_down(int i , int N) {
        // get left and right child of node at index i
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        // compare A[i] with its left and right child
        // and find largest value
        if (left < N && A[left] > A[i])
            largest = left;

        if (right < N && A[right] > A[largest])
            largest = right;

        // swap with child having greater value and
        // call heapify-down on the child
        if (largest != i) {
            swap(A[i], A[largest]);
            heapify_down(largest, N);

        }
    }

    void heapify_up(int i)
    {
        // check if node at index i and its parent violates
        // the heap property
        if (i && A[PARENT(i)] < A[i])
        {
            // swap the two if heap property is violated
            swap(A[i], A[PARENT(i)]);

            // call Heapify-up on the parent
            heapify_up(PARENT(i));
        }
    }

public:
    // return size of the heap
    unsigned int size()
    {
        return A.size();
    }

    void sort()
    {
        int N = size();
        for (int i = N/2 ; i >=0 ; i--) {
            heapify_down(i,N);
        }
        while(N >1)
        {
            //cout<<"swap"<<endl;
            swap(A[0],A[N]);
            heapify_down(0, --N);
        }
    }
    void push(int key)
    {
        // insert the new element to the end of the vector
        A.push_back(key);

        // get element index and call heapify-up procedure
        int index = size() - 1;
        heapify_up(index);
    }

    void view()
    {
        for (int i = 0; i < size(); ++i) {
            cout<<A.at(i)<<endl;

        }
    }


};


int main()
{

    PriorityQueue pq;

    // Note - Priority is decided by element's value

    pq.push(3);
    pq.push(2);
    pq.push(15);
    pq.push(5);
    pq.push(4);
    pq.push(45);
    pq.view();
    cout<<"******************"<<endl;
    pq.sort();
    pq.view();

    return 0;
}

