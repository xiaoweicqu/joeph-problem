#ifndef CONTIGUOUSLIST_H
#define CONTIGUOUSLIST_H

enum Error_code{success,underflow,overflow,error_range,range_errord};
const int max_list=10;

template<class List_entry>
class List
{
public:
	List();
	int size()const;
	void clear();
	bool empty()const;
	bool full()const;
	void traverse(void(*visit)(List_entry&));
	Error_code retrieve(int position,List_entry &x)const;
	Error_code replace(int position,const List_entry &x);
	Error_code remove(int position,List_entry &x);
	Error_code insert(int position,const List_entry &x);
protected:
	int count;
	List_entry entry[max_list];
};



template<class List_entry>
List<List_entry>::List()
{
	count=0;
}

template<class List_entry>
int List<List_entry>::size() const
{
	return count;
}

template<class List_entry>
void List<List_entry>::clear()
{
	count=0;
}

template<class List_entry>
void List<List_entry>::traverse(void(*visit)(List_entry &))
{
	for(int i=0;i<count;i++)
		(*visit)(entry[i]);
}
template<class List_entry>
bool List<List_entry>::empty() const
{
	return count==0;
}
template<class List_entry>
bool List<List_entry>::full() const
{
	return count==max_list;
}

template<class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
{
	if(position<0||position>count-1)
		return error_range;
	x=entry[position];
	return success;
}

template<class List_entry>
Error_code List<List_entry>::replace(int position,const List_entry &x)
{
	if(empty())
		return underflow;
	if(position<0||position>count-1)
		return error_range;
	entry[position]=x;
	return success;
}

template<class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
	if(empty())
		return underflow;
	if(position<0||position>count-1)
		return error_range;
	for(int i=position;i<count;i++)
		entry[i]=entry[i+1];
	count--;
	return success;
}

template<class List_entry>
Error_code List<List_entry>::insert(int position,const List_entry &x)
{
	if(full())
		return overflow;
	if(position<0||position>count)
		return error_range;
	for(int i=count-1;i>=position;i--)//notice here,you can use a i++ way,as the upper one change
		                             // the result will show the last ones are the same;
		entry[i+1]=entry[i];
	entry[position]=x;
	count++;
	return success;
}

#endif




