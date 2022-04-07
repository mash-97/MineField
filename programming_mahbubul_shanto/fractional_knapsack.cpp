#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef struct Item{
    int weight;
    int price;
} Item;

bool cmp(Item * a, Item * b){
    return a->price > b->price;
}

int main(){
    long long int a = 0;
    for(int i=0; i<1000000000; i++) a+=i;
    cout << "a: " << a <<endl;
    int n;
    cin >> n;
    vector<Item *> items;
    Item * item;
    cout << "&item: " << &item << endl;

    for(int i=0; i<n; i++){
        int weight, price;
        cin >> weight >> price;
        cout << "Before assignment &item: " << &item << endl;
        item = (Item *) malloc(sizeof(Item));
        item->weight = weight;
        item->price = price;
        cout << "After assignment &item: " << &item << endl ;
        items.push_back(item);
    }
    sort(items.begin(), items.end(), cmp);
    cout << "Items are: \n";
    for(auto item : items){
        cout << item->weight << " " << item->price << "&item: " << &item << endl;
    }
    cout << n << endl;
    return 0;
}
