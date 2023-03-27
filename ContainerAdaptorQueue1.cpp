/**
 * @file ContainerAdaptorQueue1.cpp
 * @author Md. Yousuf Ali (yousuf.cse17@gmail.com)
 * @brief Standard Template Library Stack [FIFO]
 * @version 0.1
 * @date 2023-03-27
 * @since MonDay; 08:55 AM
 * @copyright Copyright (c) 2023
 * @institute: Dept. of CSE, Varendra University, Rajshahi, Bangladesh
 */
/*Theory: QUEUE
    -> First in Frist out [FIFO] data structure
    -> Implemented as an adapter over othe STL container,
        Can be implemented as a list or deque
    -> Elements are pushed at the back and poped from the front
    -> No iterators are supported
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#pragma pack(1)
using namespace std;

void headerSection(const char *const header){
	cout<<setw(10)<<right<<setfill('-')<<":Start "<<header<<":"<<setw(49)<<right<<""<<endl;
	cout<<setfill(' ');
}

void footerSection(const char *const footer){
	cout<<setw(56)<<right<<setfill('-')<<":End "<<footer<<":"<<setw(4)<<right<<"\n"<<endl;
	cout<<setfill(' ');
}

/*By repeatedly removing elements from the front*/
/*Note that the QUEUE is passed in the value so we
  Don't affect pass in QUEUE*/

template <typename var>
void display(queue <var> myQueue){
	cout<<"[ ";
	while(!myQueue.empty()){
		cout<<myQueue.front()<<" ";
		myQueue.pop();  
	}
	cout<<"]"<<endl;
}


int main(int argc, const char *const argv[]){
    system("cls");
	headerSection("Queue");
	queue <int> q1{};
	
	for(const int &element: {1, 2, 3, 4, 5}){
		q1.push(element);
	}

	display(q1);
	cout<<endl;
	
	cout<<"Front of q1: "<<q1.front()<<endl;
	cout<<"Back of q1: "<<q1.back()<<endl;
	cout<<endl;
	
	q1.push(100);
	display(q1);
	cout<<endl;
	
	q1.pop();
	q1.pop();
	display(q1);
	cout<<endl;
	
	while(!q1.empty()){
		q1.pop();
	}
	display(q1);
	cout<<endl;
	
	cout<<"Size of q1: "<<q1.size()<<"\tIsEmpty?: "<<boolalpha<<q1.empty()<<endl;
	cout<<endl;
	
	q1.push(10);
	q1.push(100);
	q1.push(1000);
	cout<<"Front of q1: "<<q1.front()<<endl;
	cout<<"Back of q1: "<<q1.back()<<endl;
	cout<<endl;
	
	q1.front() = 5;
	q1.back() = 5000;
	display(q1);
	cout<<endl;
	
	cout<<"Front of q1: "<<q1.front()<<endl;
	cout<<"Back of q1: "<<q1.back()<<endl;
	
	footerSection("Queue");
	
	constexpr char smilee{2};
	cout<<setw(50)<<setfill(smilee)<<right<<"HappyEnding...!"<<endl;
	system("pause>0");
};