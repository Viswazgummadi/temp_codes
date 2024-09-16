#include <bits/stdc++.h>

using namespace std;
template <typename T>
void displayQueue(T q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

int main ()
{
    priority_queue<int> max_q;
    
    priority_queue<int, vector<int> , greater<int>> min_q;



    // functions
    // min_q.top()
    //min_q.pop()
    //min_q.push()
    //min_q.size()
    //min_q.empty()

    // Insert elements into the max-heap
    min_q.push(10);
    min_q.push(30);
    min_q.push(20);
    min_q.push(5);

    min_q.push(11);

    cout << "min-Heap: ";
    displayQueue(min_q);
    max_q.push(10);
    max_q.push(30);
    max_q.push(20);
    max_q.push(5);

    max_q.push(11);

    cout << "Max-Heap: ";
    displayQueue(max_q);



}