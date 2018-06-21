#include<iostream>            //基本的输入输出流函数包含在此
#include<fstream>             //基本的输入输出文件流包含在此                                                                                                                                                                                             j
#include<conio.h>             //*getch()及getch()函数包含在此
#include<string>              //相关字符串函数包含在此
using namespace std;

  /*************************各函数的声明**************************/

struct zggz*read();                //从数据文件中读取职工工资数据
void write(struct zggz*first);     //写入职工工资记录
void find(struct zggz*first);      //查找职工工资记录
void change(struct zggz*first);    //修改职工工资记录
struct zggz*add(struct zggz*first);//增加职工工资记录
float grsds(float m);              //计算个人所得税
void list(struct zggz*first);      //浏览职工工资记录

struct zggz
{	string num[10];    //职工工号
	string name[10];   //职工姓名
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
	read();
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
			case"1":
				find(first);           //查询
				break;

			case"2":
				change(first);         //修改
				break

			case"3":
				first=add(first);      //添加
				break;

			case"4":
				first=del(first);      //删除
				break;

			case"5":
				write(first);          //保存
				break;

			case"6":
				list(first);           //浏览
				break;

			case"7":
				return;                //退出

			default:
				cout<<"请按任意键返回重新选择（1-7）"<<endl;
			getche();
		
		}
	}

	return;

}

/**********从数据文件中gz.dat读取职工工资数据到结构数组zggz[]中***********/

struct zggz*read()
{
	FILE*fp                                //声明文件指针
	int n=0;                               //声明记录职工记录数的变量
	struct zggz*first,*readdat;            //记录首地址及新分配内存地址
	struct zggz*p                          //中间变量
	zggz zggz1[50];                        //定义职工工资结构体数组
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
		readdat=(struct zzgz*)malloc(sizeof(struct zggz));        //动态申请分配内存空间，并获得内存分配首地址
		while(fread(readdat,sizeof(struct zggz),1,fp)==1)
		{
			if(n==0)                      //建立链表起始项
			{
				first=readdat;
				first->front=NULL;
				first->behind=NULL;
				p=readdat;
			
			}
			else                         //说明追加链表数据项
			{
				p->behind=readdat;
				readdat->front=p;
				readdat->behind=NULL;
				p=readdat;
			
			}
		
		  n++;                          //职工人数增加1
		  readdat=(struct zggz*)malloc(sizeof(struct zggz));
		
		}

		fclose(fp);                    //关闭文件指针
		cout<<"职工工资数据读取完毕，共有："<<n<<"人"<<endl;
		cout<<"按任意键进入"



	
	
	
	
	}

	}




}

void input(struct Student stu[])
{
    int i;
    printf("请依次输入学生编号，姓名，三个科目成绩：\n");
    for (i=0;i<3;i++)
    {
        scanf("%d %s %f %f %f",&stu[i].num, &stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
        stu[i].aver = (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
    }
}

