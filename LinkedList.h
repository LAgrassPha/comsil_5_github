#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template <class T>
class Node{
	public:
		//데이터를 저장할 변수
		T data;
		//노드구조체 이용; 다음노드의 주소를 저장할 포인터
		Node *link;

		Node(T element){
		  data = element;
		  link = 0;
		}
	};

//LinkedList Class
template <class T>
class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first; // LinkedList의 첫 번째 원소의 주소를 저장할 Node 포인
		int current_size; // LinkedList의 크기
	public:
		//생성자, 초기화 
		LinkedList(){ // 생성자: LinkedList의 첫 번째 원소와 크기를 초기화
			first = 0;
			current_size = 0;
		};

		//노드 개수를 리턴
		int GetSize(){ // LinkedList의 크기 반환 함수
			return current_size;
		};

		//맨 앞에 원소를 삽입, LinkedList와 Stack 둘다 같다
		void Insert(T element); // 입력받은 원소를 LinkedList의 맨 앞에 추가
		
		//맨 뒤의 원소를 삭제, 제일 나중에 들어온 원소 삭제  - LinkedList
		virtual bool Delete(T &element); // LinkedList의 마지막 원소를 삭제하는 함수. 이때 삭제되는 원소는 element에 저장되며, 해당 클래스를 상속받는 Stack Class에서의 재정의를 위해 virtual로 선언한다.

		//리스트 출력
		void Print(); // LinkedList 내 원소를 첫 번째부터 순서대로 출력하는 함수
};


//새 노드를 맨 앞에 붙이고 값을 넣음
template <class T>
void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);

	//새 노드가 첫번째 노드를 가리킴
	//newnode는 포인터이기 때문에 -> 를 사용해 함수, 변수를 불러옴 newnode.link와 뜻은 같다
	newnode -> link = first;
	first = newnode;
	current_size++;
}

//마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
template <class T>
bool LinkedList<T>::Delete(T &element){

	if (first == 0)
		return false;
	
	Node<T> *current = first;
	Node<T> *previous = 0;
	
	//마지막 노드까지 찾아가는 반복문
	while(1){
		if (current->link == 0){  //마지막 노드를 찾는것
			if (previous)
				previous -> link = current -> link;
			else
				first = first -> link;
			break;
		}
		previous = current;
		current = current -> link;
	}
	element = current -> data;
	delete current;
	current_size--;

	return true;
}

//리스트를 출력하는 Print 함수
template <class T>
void LinkedList<T>::Print(){
	Node<T> *i;
	int index = 1;

	if (current_size != 0){
		// 마지막 노드까지 찾아가는 반복문
		for( i = first; i != NULL; i=i->link){
			if (index == current_size){ // 마지막 원소일 경우
				cout << "[" << index << "|";
				cout << i -> data <<"]";
			}
			
			else { // 마지막 원소가 아닐 경우
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}

}


#endif
