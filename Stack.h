#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (int &element){
			//first가 0이면 false반환
			if(this->first == NULL){
				return false;
			}
			element = this->first->data; // Stack class의 data를 element에 저장 (LinkedList Class의 원소와 구분하기 위해 this 포인터 사용)
			Node<T> *t = this->first; // t에 Stack의 첫 번째 원소 저장
			this->first = this->first->link; // Stack의 첫 번째 원소 변경(다음 원소로)
			delete t; // 첫 번째 원소 삭제
			this->current_size--; // Stack의 크기 1 감

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제

			return true;
			}
};
