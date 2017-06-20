#include <iostream>

#define ERR "WRONG OPERATION"

using namespace std;

class Nodo{
	private:
		int num;
	public:
		Nodo *next;
		
		Nodo(void){
			next = NULL;
		}
		Nodo(int num){
			this->num = num;
			next = NULL;
		}
		Nodo(int num, Nodo *next){
			this->num = num;
			this->next = next;
		}
		int getValue(Nodo *nodo){
			return nodo->num;
		}
};

class linkedList{
	private:
		Nodo *head;
		Nodo *tail;
	public:
		linkedList(void){
			head = tail = NULL;
		}
		bool empty(){
			return head == NULL;
		}
		void addElement(int num){
			Nodo *temp = new Nodo(num);
			if(empty()){
				head = tail = temp;
			}else{
				tail->next = temp;
				tail = temp;
			}
		}
		void removeFirst();
		void printList();
};

void linkedList::removeFirst(){
	if(empty()){
		cout << ERR;
		return;
	}else{
		Nodo *curr = head;
		head = head->next;
		delete(curr);
	}
}

void linkedList::printList(){
	Nodo *curr;
	while(!empty()){
		cout << head->getValue(head) << endl;
		head = head->next;
	}
	
}

int main(){
	linkedList myList;
	int number;
	
	cout << "Give me some Cool Integers: ";
	for(;;){
		if(cin >> number && number != 0) 
			myList.addElement(number);
		else
			break;
	}
	 
	myList.removeFirst();
	
	myList.printList();
	
	return 0;
}
