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
	List_entry code;             // 存储每个人手中    密码
	List_entry iposition;        // 存储每个人所处的  位置
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
		void Init();                              // 初始化线性表
		Node<List_entry> *head;
		Node<List_entry> *set_position(int position) const;        // 返回指向第position个结点的指针
};

Node<List_entry>::Node()

/*默认构造函数*/

{         
	next = NULL;
}

template <class List_entry>
Node<List_entry>::Node(List_entry a, List_entry b, Node<List_entry> *link)
/*设定 code   即结点密码为  a

 设定 code    即结点位置为  b*/

{  
	code = a;                  
	iposition = b;             
	next = link;                
}
/* ******************************    Joseph_list ***************************** */
template <class List_entry>
Joeph_list<List_entry>::Joeph_list()

/*默认构造函数*/

{    
	head = new Node<List_entry>;   // 构造头指针
	head->next=head;               // 空 循环链表 的头结点 指向 头结点本身                   
} 
template <class List_entry>
int Joeph_list<List_entry>::size() const
/*返回链表的大小*/
{   
	int count=0;                                                            // 计数器
	for(Node<List_entry> *temp= head->next; temp != head; temp=temp->next)  // 用temp 依次指向每个元素
		count++;                                                            // 对线性表的每个元素进行计数
	return count;
}
template <class List_entry>
bool Joeph_list<List_entry>::empty() const
{
	return head->next==head;           // 如果链表的头指针 指向头指针本身，则视为空。
}
template <class List_entry>
void Joeph_list<List_entry>::clear()
{
	List_entry tempcode, tempposition; // 临时存放 code， 和 position 的元素
	while(size() >0)                   // 线性表非空时， 则删除第一个元素
		remove(1, tempcode,tempposition);
}


template <class List_entry>
Error_code Joeph_list<List_entry>::retrieve(int position, List_entry &x, List_entry &y) const
{
	if(position < 0 || position> size()) return range_errord;
	else{
		Node<List_entry> *temp;
		temp = set_position(position);
		x= temp->code;              // 得到结点的密码
		y = temp->iposition;        // 得到结点的位置
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
		temp->code = x;                // 替换结点的密码 为 x
		temp->iposition = y;           // 替换结点的位置 为 y
		return success;
	}
}
template <class List_entry>
Error_code Joeph_list<List_entry>::remove(int position, List_entry &x, List_entry &y)
/*将相应位置节点删除*/
{
	if(position<1 || position> size()) return range_errord;
	else{
		Node<List_entry> *temp;
		temp = set_position(position-1);
		Node<List_entry> *new_temp= temp->next;
		temp->next = new_temp->next;
		x = new_temp->code;             // 移除 结点的密码 到 x
		y = new_temp->iposition;        // 移除 结点的位置 到 y
		delete new_temp;
		return success;
	}
}
template <class List_entry>
Error_code Joeph_list<List_entry>::insert(int position, const List_entry &x, const List_entry &y)
/*插入新的结点*/
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
/* 设定指针的位置， 返回一个指针值*/
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
/*析构函数 清楚每个结点*/
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
