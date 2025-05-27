#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a;
    vector<int> b(5);
    vector<int> c(3, 7);
    vector<int> d = {1, 2, 3};

    cout << "\nConstructed vectors:\n";
    cout << "b: "; for (int x : b) cout << x << " "; cout << endl;
    cout << "c: "; for (int x : c) cout << x << " "; cout << endl;
    cout << "d: "; for (int x : d) cout << x << " "; cout << endl;

    cout << "\nElement access:\n";
    cout << "d[1] = " << d[1] << endl;
    cout << "d.at(2) = " << d.at(2) << endl;
    cout << "Front: " << d.front() << ", Back: " << d.back() << endl;
    cout << "Data pointer: " << d.data() << endl;

    cout << "\nCapacity and size:\n";
    cout << "Size: " << d.size() << ", Capacity: " << d.capacity() << endl;
    d.reserve(10);
    cout << "After reserve(10), Capacity: " << d.capacity() << endl;
    d.shrink_to_fit();
    cout << "After shrink_to_fit(), Capacity: " << d.capacity() << endl;

    cout << "\nModifiers:\n";
    d.push_back(4);
    cout << "After push_back(4): "; for (int x : d) cout << x << " "; cout << endl;
    d.pop_back();
    cout << "After pop_back(): "; for (int x : d) cout << x << " "; cout << endl;
    d.insert(d.begin() + 1, 10);
    cout << "After insert at index 1: "; for (int x : d) cout << x << " "; cout << endl;
    d.erase(d.begin());
    cout << "After erase index 0: "; for (int x : d) cout << x << " "; cout << endl;
    d.resize(5);
    cout << "After resize(5): "; for (int x : d) cout << x << " "; cout << endl;
    vector<int> e = {9, 8};
    d.swap(e);
    cout << "After swap with {9, 8}: "; for (int x : d) cout << x << " "; cout << endl;
    cout << "\nIterators:\n";
    cout << "Forward: ";
    for (auto it = d.begin(); it != d.end(); ++it) cout << *it << " ";
    cout << "\nReverse: ";
    for (auto rit = d.rbegin(); rit != d.rend(); ++rit) cout << *rit << " ";
    cout << endl;

    d.clear();
    cout << "\nAfter clear(), is empty? " << boolalpha << d.empty() << endl;
    
    return 0;
}
