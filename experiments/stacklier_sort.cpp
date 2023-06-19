#include <iostream>
#include <stack>
#include <vector>


using namespace std;


pair<vector<int>, int> stacklier_sort(vector<int> array) {
	stack<int> sorted_stack;
	stack<int> buffer_stack;
	
	sorted_stack.push(array[0]);
	int steps = 0;
	
	for(int i=1; i<(int)array.size(); i++) {
		while(sorted_stack.size() > 0 && sorted_stack.top() > array[i]) {
			buffer_stack.push(sorted_stack.top());
			sorted_stack.pop();
			steps += 1;
		}
			
		sorted_stack.push(array[i]);
		
		while(buffer_stack.size() > 0) {
			sorted_stack.push(buffer_stack.top());
			buffer_stack.pop();
			steps += 1;
		}
	}
	vector<int> sorted_array;
	while(sorted_stack.size() > 0) {
		sorted_array.push_back(sorted_stack.top());
		sorted_stack.pop();
	}
	return make_pair(sorted_array, steps);
}


pair<vector<int>, int> insertion_sort(vector<int> array) {
	int steps = 0;
	
	for(int i=1; i<(int)array.size(); i++) {
		int j=i-1;
		while(j>=0 && array[j] > array[j+1]) {
			int temp = array[j];
			array[j] = array[j+1];
			array[j+1] = temp;
			j -= 1;
			steps += 1;
		}
	}
	vector<int> sorted_array;
	for(auto x: array)
		sorted_array.push_back(x);
	return make_pair(sorted_array, steps);
}
		
int main() {
	cout << "enter array size: ";
	int array_size;
	cin >> array_size;
	cout << "enter array elements: ";
	vector<int> array;
	int temp;
	for(int i=0; i<array_size; i++)
	{
		cin >> temp;
		array.push_back(temp);
	}
	
	pair<vector<int>, int> ss = stacklier_sort(array);
	vector<int>::iterator vit = ss.first.begin();
	cout << "stacklier_sort: ";
	while(vit != ss.first.end()) {
		cout << *vit << " ";
		vit+=1;
	}
	cout << ", steps: " << ss.second << endl;
	
	pair<vector<int>, int> is = insertion_sort(array);
	vit = is.first.begin();
	cout << "insertion_sort: ";
	while(vit != is.first.end()) {
		cout << *vit << " ";
		vit+=1;
	}
	cout << ", steps: " << is.second << endl;
	
	return 0;
}
