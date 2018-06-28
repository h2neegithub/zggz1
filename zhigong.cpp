#include<iostream>            //基本的输入输出流函数包含在此
#include<fstream>             //基本的输入输出文件流包含在此                                                                                                                                                                                             j
#include<conio.h>             //getch()及getche()函数包含在此
#include<cstring>              //相关字符串函数包含在此
using namespace std;

  /*************************各函数的声明**************************/

struct zggz*read();                //从数据文件中读取职工工资数据
void write(struct zggz*first);     //写入职工工资记录
void find(struct zggz*first);      //查找职工工资记录
void modify(struct zggz*first);    //修改职工工资记录
struct zggz*add(struct zggz*first);//增加职工工资记录
struct zggz*del(struct zggz*first) ;//删除职工工资记录
float grsds(float m);              //计算个人所得税
void list(struct zggz*first);      //浏览职工工资记录

struct zggz                        //声明职工工资数据结构体
{	
	struct zggz*front;
	struct zggz*behind;
	char  gonghao[10];    //职工工号
	char  name[10];   //职工姓名
	float gwgz;        //岗位工资
	float xjgz;        //薪级工资
	float zwjt;        //职务津贴
	float jxgz;        //绩效工资
	float yfgz;        //应发工资
	float grsds;       //个人所得税
	float sfgz;        //实发工资

};

void main()
{	
	char ch;
	struct zggz*first;    //声明指向结构体的指针变量，记录链表的首地址
	first=read();         //从数据文件中读取职工工资数据并初始化职工工资结构体数组，即取得结构体数组的首地址
	while(true)
	{
		cout<<"请选择（1-7）"<<endl;
		cout<<endl;
		cout<<"1.查询职工工资记录"<<endl;
		cout<<"2.修改职工工资记录"<<endl;
		cout<<"3.添加职工工资记录"<<endl;
		cout<<"4.删除职工工资记录"<<endl;
		cout<<"5.保存职工工资记录"<<endl;
		cout<<"6.浏览职工工资记录"<<endl;
		cout<<"退出系统"<<endl;
		cout<<"您的选择是："<<endl;
		ch=getche();

		switch(ch)
		{
			case'1':
				find(first);           //查询
				break;

			case'2':
				modify(first);         //修改
				break;

			case'3':
				first=add(first);      //添加
				break;

			case'4':
				first=del(first);      //删除
				break;

			case'5':
				write(first);          //保存
				break;

			case'6':
				list(first);           //浏览
				break;

			case'7':
				return;                //退出

			default:
				cout<<"请按任意键返回重新选择（1-7）"<<endl;
			getch();
		
		}
	}

	return;

}

/**********从数据文件中gz.dat读取职工工资数据到结构数组zggz[]中***********/

struct zggz*read()
{
	FILE*file;                                //声明文件指针
	int n=0;                               //声明记录职工记录数的变量
	struct zggz*first,*readdate;            //记录首地址及新分配内存地址
	struct zggz*p ;                         //中间变量                      
	ifstream in("gz.dat",ios::binary);     //定义输入文件流对象in，打开二进制输入文件gz.dat
	if(!in)                                //如果文件打开失败，in返回0值
	{
		cout<<"职工工资数据文件打开失败，或为空"<<endl;
		cout<<"按任意键返回主菜单"<<endl;
		getch();
		return 0;
	}
	else                                  //文件打开成功时
	{
		readdate=(struct zggz*)malloc(sizeof(struct zggz));        //动态申请分配内存空间，并获得内存分配首地址
		while(fread(readdate,sizeof(struct zggz),1,file)==1)
		{
			if(n==0)                      //建立链表起始项
			{
				first=readdate;
				first->front=NULL;
				first->behind=NULL;
				p=readdate;
			
			}
			else                          //说明追加链表数据项
			{
				p->behind=readdate;
				readdate->front=p;
				readdate->behind=NULL;
				p=readdate;
			
			}
		
		  n++;                             //职工人数增加1
		  readdate=(struct zggz*)malloc(sizeof(struct zggz));
		
		}

		fclose(file);                        //关闭文件指针
		cout<<"职工工资数据读取完毕，共有："<<n<<"人"<<endl;
	}

		cout<<"按任意键进入主菜单"<<endl;
		getch();
		return first;
		
}


/**********向职工工资数据文件写入记录*************/

void write(struct zggz*first)
{
	FILE*file;                             //声明指针文件
	int n=0;                               //统计存入文件职工人数
	if(first==NULL)                        //内存中无工资记录
	{
		cout<<"没有数据可存！按任意键返回主菜单"<<endl;
		getch();
		return;
	
	}
	if((file=fopen("gz.dat","wb"))!=NULL)               //以二进制方式打开职工工资数据文件并进行判断是否失败
	{
	
		do
		{
			fwrite(first,sizeof(struct zggz),1,file);   //所有记录一次写入文件
			n++;
			first=first->behind;
		
		}while(first!=NULL);
		fclose(file);                      //关闭文件指针
		cout<<n<<"条职工记录保存完毕"<<endl;
	
	}
	else                                   //文件打开不成功时
		cout<<"无法打开职工工资数据文件"<<endl;
	getch();

}

/**********查询职工工资数据记录（依据工号）*************/

void find(struct zggz*first)
{

	char gonghao[10];                      //接收职工工号字符数组
	if(first==NULL)                        //说 明内存无工资记录
	{
		
		cout<<"当前还没有职工工资记录！按任意键返回主菜单";
		getch();
		return;

	}
	
	cout<<"请输入职工工号："<<endl;        //提示信息
	gets(gonghao);                         //从键盘读取字符串
  
	while(first!=NULL)                     //从链表开始向后查找
	{
		if(strcmp(first->gonghao,gonghao)==0)    //比较并找到
		{
			/*********显示该职工工资情况************/
			cout<<"该职工工资情况如下："<<endl;
			cout<<"工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资"<<endl;
			cout<<first->gonghao<<'\t'<<first->name<<'\t'<<first->gwgz<<'\t'<<first->xjgz<<'\t'<<first->zwjt<<'\t';
			cout<<first->jxgz<<'\t'<<first->yfgz<<'\t'<<first->grsds<<'\t'<<first->sfgz<<endl;
			cout<<"按任意键返回主菜单";
			getch();
			return;

		}

		first=first->behind;
	}

	//循环自动结束意味着未找到
	cout<<"您所输入的职工工号有误或不存在！按任意键返回主菜单"<<endl;
	getch();
	return;

}


/************浏览职工工资记录*************/

void list(struct zggz*first)
{
	system("cls");                       //清屏命令
	cout<<"全体职工工资情况如下："<<endl;
	cout<<endl;
	if(first!=NULL)                      //说明内存中链表存在
	{
		do
		{
			cout<<"工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资"<<endl;
			cout<<first->gonghao<<'\t'<<first->name<<'\t'<<first->gwgz<<'\t'<<first->xjgz<<'\t'<<first->zwjt<<'\t';
			cout<<first->jxgz<<'\t'<<first->yfgz<<'\t'<<first->grsds<<'\t'<<first->sfgz<<endl;
			first=first->behind;         //修正first指向链表中下一项结构数据
		
		}while(first!=NULL);             //不为空说明结构数据存在
	
	}

	cout<<"按任意键返回主菜单"<<endl;
	getch();
	return;

}

/************修改职工工资数据记录*************/

void modify(struct zggz*first)
{
	char gonghao[10];                   //接收职工工号字符数组
	if(first==NULL)                     //说明内存无工资记录
	{
		cout<<"当前没有职工工资记录！按任意键返回主菜单"<<endl;
		getch();
		return;
	}

	cout<<"请输入职工工号："<<endl;      //提示信息
	gets(gonghao);                       //从键盘读取字符串
	while(first!=NULL)                   //从链表开始向后查找
	{
			if(strcmp(first->gonghao,gonghao)==0)    //比较并找到
		{
			/*********显示该职工工资情况************/
			cout<<"该职工工资情况如下："<<endl;
			cout<<"工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资"<<endl;
			cout<<first->gonghao<<'\t'<<first->name<<'\t'<<first->gwgz<<'\t'<<first->xjgz<<'\t'<<first->zwjt<<'\t';
			cout<<first->jxgz<<'\t'<<first->yfgz<<'\t'<<first->grsds<<'\t'<<first->sfgz<<endl;

			/**********接收该职员新的工资数据***********/
			cout<<"请输入该职员新的岗位工资：";
			cin>>first->gwgz;
			cout<<"请输入该职员新的薪级工资：";
			cin>>first->xjgz;
			cout<<"请输入该职员新的绩效工资：";
			cin>>first->jxgz;

			/*********计算应发工资，个人所得税，实发工资***********/
			first->yfgz=(first->gwgz)+(first->xjgz)+(first->zwjt)+(first->jxgz);
			first->grsds=grsds(first->yfgz);
			first->sfgz=(first->yfgz)-(first->grsds);

			/**********显示计算结果***********/
			cout<<"该职工的应发工资为："<<first->yfgz<<endl;
			cout<<"该职工的个人所得税为："<<first->grsds<<endl;
			cout<<"该职工的实发工资为："<<first->sfgz<<endl;
			cout<<"该职工工资数据修改成功！按任意键返回主菜单"<<endl;
			getch();
			return;
			
		}
		first=first->behind;
	}

	//循环自动结束意味着未找到
	cout<<"您所输入的职工工号有误或不存在！按任意键返回主菜单"<<endl;
	getch();
	return;

}

/**********向职工工资数据文件增加记录***********/

struct zggz*add(struct zggz*first)
{
	struct zggz*adddate;              //记录首地址及新分配内存地址
	struct zggz*p;                    //中间变量
	adddate=(struct zggz*)malloc(sizeof(struct zggz));       //申请动态内存空间，并获得首地址
	if(first==NULL)                   //说明需要创建工资数据链表
	{
		first=adddate;
		first->front=NULL;
		first->behind=NULL;
		
	}
	else                              //说明需要找到链表结束位置
	{
		p=first;
		while(p->behind!=NULL)
		{
			p=p->behind ;
		}
	//建立链表追加项指针指向关系
		p->behind=adddate;
		adddate->front=p;
		adddate->behind=NULL;
	}
	//无论是创建第一条还是追加工资记录，均只对adddate添加数据
		cout<<"请输入职工工号：";
		fflush(stdin);                 //清楚键盘缓冲区
		gets(adddate->gonghao);
		cout<<"请输入职工姓名：";      
		fflush(stdin);                 //清楚键盘缓冲区 
		gets(adddate->name);
		cout<<"请输入该职工新的岗位工资：";
		cin>>adddate->gwgz;
		cout<<"请输入该职工新的薪级工资：";
		cin>>adddate->xjgz;
		cout<<"请输入该职工新的职务津贴：";
		cin>>adddate->zwjt;
		cout<<"请输入该职工新的绩效工资：";
		cin>>adddate->jxgz;

	 /*********计算应发工资，个人所得税，实发工资***********/
		first->yfgz=(first->gwgz)+(first->xjgz)+(first->zwjt)+(first->jxgz);
		first->grsds=grsds(first->yfgz);
		first->sfgz=(first->yfgz)-(first->grsds);

	 /**********输出以上计算结果***********/
		cout<<"该职工的应发工资为："<<first->yfgz<<endl;
		cout<<"该职工的个人所得税为："<<first->grsds<<endl;
		cout<<"该职工的实发工资为："<<first->sfgz<<endl;
		cout<<"按任意键返回主菜单"<<endl;
		getch();
		return first;                //返回链表首地址

}

/**********从职工工资数据文件删除记录***********/

struct zggz*del(struct zggz*first)
{
	char gonghao[10];                 //接收职工工号字符数组
	char d='N';                       //接收确认删除字符：y/n
	struct zggz*p;                    //中间变量
	p=first;
	if(p==NULL)                       //说明内存无工资记录
	{
		cout<<"当前还没有职工工资记录，无法执行删除！"<<endl;
		cout<<"按任意键返回主菜单"<<endl;
		getch();
		return first;
	
	}
	cout<<"请输入待删除职工工号：";
	gets(gonghao);
	while(p!=NULL)                    //从链表开始处进行查找
	{
		if(strcmp(first->gonghao,gonghao)==0)      //比较并找到
		{
			/*********显示该职工工资情况************/
			cout<<"该职工工资情况如下："<<endl;
			cout<<"工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资"<<endl;
			cout<<first->gonghao<<'\t'<<first->name<<'\t'<<first->gwgz<<'\t'<<first->xjgz<<'\t'<<first->zwjt<<'\t';
			cout<<first->jxgz<<'\t'<<first->yfgz<<'\t'<<first->grsds<<'\t'<<first->sfgz<<endl;
			cout<<"你确定要删除该职工工资信息吗"<<endl;
			d=getch();
			if(d=='y'||d=='Y')                     //确认删除
			{
				//以下代码实现重建链表关系
				if(p->front==NULL&&p->behind==NULL)   //当只有一条记录时
				{
					first=NULL;
				
				}
				else if(p->front==NULL)            //删除的是第一条记录
				{
					first=p->behind;
					first->front=NULL;
				
				}
				else if(p->behind==NULL)           //删除的事最后一条记录
				{
					(p->front)->behind=NULL;
				}
				else                               //删除非第一条记录
				{
					(p->front)->behind=p->behind;
					(p->behind)->front=p->front;
				
				}
				free(p);                           //释放被删除数据所占内存
				cout<<"该职工记录成功被删除，按任意键返回主菜单"<<endl;
				getch();
				return first;                      //返回工资链表起始地址

			}
			else                //未确认删除记录
			{
			
			cout<<"你选择了不删除该职工记录，按任意键返回主菜单"<<endl;
			getch();
			return first;
			
			}

			p=p->behind ;           //指向下一项结构数据

		}

	if(d=='n'||d=='N')             //该值反映未删除过记录的状态
	{
		cout<<"本单位无此工号，按任意键返回主菜单"<<endl;
		getch();
		return first;
	
	}
}

}

/*********计算个人所得税*************/
float grsds(float m)
{
	float x;                  //当月应纳税所得额
	float y=0;                //当月应纳税额
	int n;
	x=m-2000;
	if(x>0)
	{	if(x<500) n=1;
		else if(x<2000) n=2;
		else if(x<5000) n=3;
		else if(x<20000) n=4;                    
		else if(x<40000) n=5;
		else if(x<60000) n=6;
		else if(x<80000) n=7;
		else if(x<100000) n=8;
		else n=9;
	}

	switch(n)                 
	{ 
		         
		case 9:y=(x-100000)*0.45;          
									  //超过100000元的部分45%			                       
					x=100000;
		case 8:y+=(x-80000)*0.40;
									  //超过80000元至100000的部分40%
					x=80000; 
		case 7:y+=(x-60000)*0.35;
									  //超过60000元至80000的部分35%
					x=60000;
		case 6:y+=(x-40000)*0.30;
									  //超过40000元至60000的部分30%
					x=40000; 			     
		case 5:y+=(x-20000)*0.25; 
									  //超过20000元至40000的部分25%
					x=20000;
		case 4:y+=(x-5000)*0.20;
									  //超过5000元至20000的部分20%
					x=5000;
		case 3:y+=(x-2000)*0.15;
									  //超过2000元至5000的部分15%
					x=2000;
		case 2:y+=(x-500)*0.10;
									  //超过500元至2000的部分10%
					x=500;
		case 1:y+=x*0.05;                     
									 //不超过500元的5%
		}

	return y;
}
