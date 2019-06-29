#include "ezwin.h"
#include "bitmap.h"
#include "list.h"
#include "joeph.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

SimpleWindow game("Joeph",22,15,Position(0,0));
BitMap c(game);
BitMap mima(game);
BitMap chulie(game);
BitMap chuliehao(game);
BitMap over(game);
List<BitMap>tu;
List<BitMap>shu;
List<BitMap>people;

BitMap tu1(game);
BitMap tu2(game);
BitMap tu3(game);
BitMap tu4(game);
BitMap tu5(game);
BitMap tu6(game);
BitMap tu7(game);



BitMap shu1(game);
BitMap shu2(game);
BitMap shu3(game);
BitMap shu4(game);
BitMap shu5(game);
BitMap shu6(game);
BitMap shu7(game);

BitMap people1(game);
BitMap people2(game);
BitMap people3(game);
BitMap people4(game);
BitMap people5(game);
BitMap people6(game);
BitMap people7(game);


void Baoshu(int p,int s);
void Yizou(int p,int m);
void Code(int m);
void Jieshu();

int ApiMain(){

	c.SetPosition(Position(14,0));
	mima.SetPosition(Position(8,1));
	chulie.SetPosition(Position(17,13));
	chuliehao.SetPosition(Position(15,12.5));
	over.SetPosition(Position(0,0));

	mima.Load("tu\\mima.bmp");
	chulie.Load("tu\\chulie.bmp");
	over.Load("tu\\over.bmp");


	tu1.Load("tu\\3.bmp");
	tu2.Load("tu\\1.bmp");
	tu3.Load("tu\\7.bmp");
	tu4.Load("tu\\2.bmp");
	tu5.Load("tu\\4.bmp");
	tu6.Load("tu\\8.bmp");
	tu7.Load("tu\\4.bmp");
	
	tu1.SetPosition(Position(0,7));
	tu2.SetPosition(Position(3,7));
    tu3.SetPosition(Position(6,7));
	tu4.SetPosition(Position(9,7));
	tu5.SetPosition(Position(12,7));
	tu6.SetPosition(Position(15,7));
	tu7.SetPosition(Position(18,7));
	
	game.Open();
	Joeph_list<int> test_Joeph;


	tu.insert(0,tu1);
	tu.insert(1,tu2);
	tu.insert(2,tu3);
	tu.insert(3,tu4);
	tu.insert(4,tu5);
	tu.insert(5,tu6);
	tu.insert(6,tu7);

	
	shu1.SetPosition(Position(0,10));
	shu2.SetPosition(Position(3,10));
    shu3.SetPosition(Position(6,10));
	shu4.SetPosition(Position(9,10));
	shu5.SetPosition(Position(12,10));
	shu6.SetPosition(Position(15,10));
	shu7.SetPosition(Position(18,10));

	
	shu.insert(0,shu1);
	shu.insert(1,shu2);
	shu.insert(2,shu3);
	shu.insert(3,shu4);
	shu.insert(4,shu5);
	shu.insert(5,shu6);
	shu.insert(6,shu7);

	people1.SetPosition(Position(0,3));
	people2.SetPosition(Position(3,3));
    people3.SetPosition(Position(6,3));
	people4.SetPosition(Position(9,3));
	people5.SetPosition(Position(12,3));
	people6.SetPosition(Position(15,3));
	people7.SetPosition(Position(18,3));

	people1.Load("tu\\ren.bmp");
	people2.Load("tu\\ren.bmp");
	people3.Load("tu\\ren.bmp");
	people4.Load("tu\\ren.bmp");
	people5.Load("tu\\ren.bmp");
	people6.Load("tu\\ren.bmp");
	people7.Load("tu\\ren.bmp");

	people.insert(0,people1);
	people.insert(1,people2);
	people.insert(2,people3);
	people.insert(3,people4);
	people.insert(4,people5);
	people.insert(5,people6);
	people.insert(6,people7);

	for(int a=0;a<7;a++){
		
		BitMap bmpren(game);
		people.retrieve(a,bmpren);
		bmpren.Draw();

		BitMap bmptu(game);
		tu.retrieve(a,bmptu);
		bmptu.Draw();
	}
	

	int n=7;


	test_Joeph.insert(1,3,1);
	test_Joeph.insert(2,1,2);
	test_Joeph.insert(3,7,3);
	test_Joeph.insert(4,2,4);
	test_Joeph.insert(5,4,5);
	test_Joeph.insert(6,8,6);
	test_Joeph.insert(7,4,7);

   	cout << "Show the code you enter in: " << endl;

	for(int j=1; j<=n; j++){
		int scode, sposition;
		test_Joeph.retrieve(j, scode, sposition);
		cout<<"Person: "<<sposition<<" code: "<< scode<<endl;
	}
	cout << endl;




	cout<<endl<<endl<<endl<<test_Joeph.size()<<endl<<endl<<endl;
	int m=6;
	Code(m);
	int position =1;

	for(int r=1; r<=n; r++){    
		
		for(int s=1; s<m; s++){
			int x;int y;
			test_Joeph.retrieve(position,x,y);
			test_Joeph.baoshu(y,s);
			Baoshu(y,s);

			position++;
			if(position > test_Joeph.size()){
				position=1;
			}
			
		} 

		List_entry outcode, outposition;	
		test_Joeph.remove(position, outcode, outposition);
		if(position == test_Joeph.size()+1)             // 特殊情况判断，如果删除的是链表的最后一个节点，
			position =1; 
		Yizou(outposition,m);                           // 则将position值 置位表头位置
		m = outcode;                                // 将移出的人的密码 置位新的 m 值
		cout << outposition << " is moved out. Now begin the Joseph by the code : " << m << endl;
		Code(m);
		
	}
	Jieshu();

	return 0;
}




void Baoshu(int p,int s)
{
	BitMap ren;
	
	shu.retrieve(p-1,ren);
	string sname;
	switch(s){
	case 1:
		sname="tu\\1.bmp";
		break;
	case 2:
		sname="tu\\2.bmp";
		break;
	case 3:
		sname="tu\\3.bmp";
		break;
	case 4:
		sname="tu\\4.bmp";
		break;
	case 5:
		sname="tu\\5.bmp";
		break;
	case 6:
		sname="tu\\6.bmp";
		break;
	case 7:
		sname="tu\\7.bmp";
		break;
	}

	ren.Load(sname);
	ren.Draw();

	Sleep(500);

	ren.Erase();

}

void Yizou(int p,int m)
{

	Baoshu(p,m);
	BitMap yiren;
	BitMap rencode;
	people.retrieve(p-1,yiren);
	tu.retrieve(p-1,rencode);
	
	Sleep(500);
	yiren.Erase();
	rencode.Erase();

	string sname;
	switch(p){
	case 1:
		sname="tu\\1.bmp";
		break;
	case 2:
		sname="tu\\2.bmp";
		break;
	case 3:
		sname="tu\\3.bmp";
		break;
	case 4:
		sname="tu\\4.bmp";
		break;
	case 5:
		sname="tu\\5.bmp";
		break;
	case 6:
		sname="tu\\6.bmp";
		break;
	case 7:
		sname="tu\\7.bmp";
		break;
	}
	chuliehao.Load(sname);
	chulie.Draw();
	chuliehao.Draw();

}

void Code(int m)
{
	string sname;
	switch(m){
	case 1:
		sname="tu\\1.bmp";
		break;
	case 2:
		sname="tu\\2.bmp";
		break;
	case 3:
		sname="tu\\3.bmp";
		break;
	case 4:
		sname="tu\\4.bmp";
		break;
	case 5:
		sname="tu\\5.bmp";
		break;
	case 6:
		sname="tu\\6.bmp";
		break;
	case 7:
		sname="tu\\7.bmp";
		break;
	}
	c.Load(sname);
	c.Draw();
	mima.Draw();
	
}

void Jieshu()
{
	chulie.Erase();
	chuliehao.Erase();
	mima.Erase();
	c.Erase();
	over.Draw();
}