#include <iostream>
#include <queue>

using namespace std;

void showq(priority_queue <int> pq)
{
	while(!pq.empty())
	{
		cout<<"\t"<<pq.top();
		pq.pop();
	}
	cout<<"\n";
}

int main()
{
	priority_queue<int> pq;
	
	pq.push(3);
	pq.push(5);
	pq.push(6);
	pq.push(7);
	
	cout<<"Total elements: "<<pq.size()<<endl;
	
	if(pq.empty()) cout<<"The queue is empty!"<<endl;
	else cout<<"The queue is not empty!"<<endl;
	
	showq(pq);

	return 0;
}
