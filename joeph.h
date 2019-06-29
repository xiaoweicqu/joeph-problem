#ifndef JOEPHLIST_H
#define JOEPHLIST_H
#include <cstddef>
#include <iostream>
#include "list.h"

using namespace std;

//enum Error_code{success, overflow, underflow, range_errord};
typedef int List_entry;

template <class List_entry>
struct Node{
	List_entry code;             // �洢ÿ��������    ����
	List_entry iposition;        // �洢ÿ����������  λ��
	Node<List_entry> *next;
	
	Node();
	Node(List_entry a, List_entry b, Node<List_entry> *link=NULL);
};


template <class List_entry>
class Joeph_list{
	public:
		Joeph_list();
		int size() const;
		bool empty() const;
		void clear();
		
		Error_code retrieve(int position, List_entry &x, List_entry &y) const;
		Error_code replace(int position, const List_entry &x, const List_entry &y);
		Error_code remove(int position, List_entry &x, List_entry &y);
		Error_code insert(int position, const List_entry &x, const List_entry &y);
		Error_code baoshu(int position,const List_entry &x);
		
		~Joeph_list();
	protected:
		int count;
		void Init();                              // ��ʼ�����Ա�
		Node<List_entry> *head;
		Node<List_entry> *set_position(int position) const;        // ����ָ���position������ָ��
};

Node<List_entry>::Node()

/*Ĭ�Ϲ��캯��*/

{         
	next = NULL;
}

template <class List_entry>
Node<List_entry>::Node(List_entry a, List_entry b, Node<List_entry> *link)
/*�趨 code   ���������Ϊ  a

 �趨 code    �����λ��Ϊ  b*/

{  
	code = a;                  
	iposition = b;             
	next = link;                
}
/* ******************************    Joseph_list ***************************** */
template <class List_entry>
Joeph_list<List_entry>::Joeph_list()

/*Ĭ�Ϲ��캯��*/

{    
	head = new Node<List_entry>;   // ����ͷָ��
	head->next=head;               // �� ѭ������ ��ͷ��� ָ�� ͷ��㱾��                   
} 
template <class List_entry>
int Joeph_list<List_entry>::size() const
/*��������Ĵ�С*/
{   
	int count=0;                                                            // ������
	for(Node<List_entry> *temp= head->next; temp != head; temp=temp->next)  // ��temp ����ָ��ÿ��Ԫ��
		count++;                                                            // �����Ա��ÿ��Ԫ�ؽ��м���
	return count;
}
template <class List_entry>
bool Joeph_list<List_entry>::empty() const
{
	return head->next==head;           // ��������ͷָ�� ָ��ͷָ�뱾������Ϊ�ա�
}
template <class List_entry>
void Joeph_list<List_entry>::clear()
{
	List_entry tempcode, tempposition; // ��ʱ��� code�� �� position ��Ԫ��
	while(size() >0)                   // ���Ա�ǿ�ʱ�� ��ɾ����һ��Ԫ��
		remove(1, tempcode,tempposition);
}


template <class List_entry>
Error_code Joeph_list<List_entry>::retrieve(int position, List_entry &x, List_entry &y) const
{
	if(position < 0 || position> size()) return range_errord;
	else{
		Node<List_entry> *temp;
		temp = set_position(position);
		x= temp->code;              // �õ���������
		y = temp->iposition;        // �õ�����λ��
	}
	
	return success;
}
template <class List_entry>
Error_code Joeph_list<List_entry>::replace(int position, const List_entry &x, const List_entry &y)
{
	if(position<1 || position> size()) return range_errord;
	else{
		Node<List_entry> *temp;
		temp = set_position(position);
		temp->code = x;                // �滻�������� Ϊ x
		temp->iposition = y;           // �滻����λ�� Ϊ y
		return success;
	}
}
template <class List_entry>
Error_code Joeph_list<List_entry>::remove(int position, List_entry &x, List_entry &y)
/*����Ӧλ�ýڵ�ɾ��*/
{
	if(position<1 || position> size()) return range_errord;
	else{
		Node<List_entry> *temp;
		temp = set_position(position-1);
		Node<List_entry> *new_temp= temp->next;
		temp->next = new_temp->next;
		x = new_temp->code;             // �Ƴ� �������� �� x
		y = new_temp->iposition;        // �Ƴ� ����λ�� �� y
		delete new_temp;
		return success;
	}
}
template <class List_entry>
Error_code Joeph_list<List_entry>::insert(int position, const List_entry &x, const List_entry &y)
/*�����µĽ��*/
{
	if(position <1 || position >size()+1) return range_errord;
	else{
		Node<List_entry> *temp;
		temp = set_position(position-1);
		Node<List_entry> *new_temp;
		new_temp = new Node<List_entry>(x, y, temp->next);  
		temp->next = new_temp;
		return success;
	}
}



template <class List_entry>
Node<List_entry> *Joeph_list<List_entry>::set_position(int position) const
/* �趨ָ���λ�ã� ����һ��ָ��ֵ*/
{  
	if(position == 0) return head;
	Node<List_entry> *temp = head->next;
	int curposition =1;
	while( temp != head && curposition < position){
		temp = temp->next;
		curposition++;
	}
	if(temp != head && curposition==position) return temp;
	else
		return NULL;
}
template <class List_entry>
Joeph_list<List_entry>::~Joeph_list()
/*�������� ���ÿ�����*/
{  
	clear();
	delete head;
}

template<class List_entry>
Error_code Joeph_list<List_entry>::baoshu(int position,const List_entry &x)
{
	cout<<position<<" Bao shu: "<<x<<endl;
	return success;
}
#endif
