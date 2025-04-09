

//  Alternative approach: Using STL(Standard template library)
#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq; // Max Heap by default

    pq.push(40);
    pq.push(20);
    pq.push(30);
    pq.push(50);
    pq.push(10);

    cout << "Max Element: " << pq.top() << endl; // Get maximum

    pq.pop(); // Remove max element

    cout << "Priority Queue elements: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
   