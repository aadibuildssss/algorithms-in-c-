#include<stack>
#include<iostream>
#include<string>
using namespace std;


void sortedInsert(stack<int>&s, int element){
    //base case 
    if(s.empty() || (!s.empty() && s.top() < element)){
        s.push(element);
        return ;
    }

    int n = s.top();
    s.pop();

    //recursive call
    sortedInsert(s,element);
    
    s.push(n);
}
void sortStack(stack<int> &inputStack){
    if(inputStack.empty()){
        return ;
    }

    int num = inputStack.top();
    inputStack.pop();

    sortStack(inputStack);

    //sorted insert 
    sortedInsert(inputStack, num);
}