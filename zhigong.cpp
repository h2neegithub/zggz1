#include<iostream>            //������������������������ڴ�
#include<fstream>             //��������������ļ��������ڴ�                                                                                                                                                                                             j
#include<conio.h>             //*getch()��getch()���������ڴ�
#include<string>              //����ַ������������ڴ�
using namespace std;

  /*************************������������**************************/

struct zggz*read();                //�������ļ��ж�ȡְ����������
void write(struct zggz*first);     //д��ְ�����ʼ�¼
void find(struct zggz*first);      //����ְ�����ʼ�¼
void change(struct zggz*first);    //�޸�ְ�����ʼ�¼
struct zggz*add(struct zggz*first);//����ְ�����ʼ�¼
float grsds(float m);              //�����������˰
void list(struct zggz*first);      //���ְ�����ʼ�¼

struct zggz
{	string num[10];    //ְ������
	string name[10];   //ְ������
	float gwgz;        //��λ����
	float xjgz;        //н������
	float zwjt;        //ְ�����
	float jxgz;        //��Ч����
	float yfgz;        //Ӧ������
	float grsds;       //��������˰
	float sfgz;        //ʵ������

};

void main()
{	
	char ch;
	read();
	struct zggz*first;    //����ָ��ṹ���ָ���������¼������׵�ַ
	first=read();         //�������ļ��ж�ȡְ���������ݲ���ʼ��ְ�����ʽṹ�����飬��ȡ�ýṹ��������׵�ַ
	while(true)
	{
		cout<<"��ѡ��1-7��"<<endl;
		cout<<endl;
		cout<<"1.��ѯְ�����ʼ�¼"<<endl;
		cout<<"2.�޸�ְ�����ʼ�¼"<<endl;
		cout<<"3.���ְ�����ʼ�¼"<<endl;
		cout<<"4.ɾ��ְ�����ʼ�¼"<<endl;
		cout<<"5.����ְ�����ʼ�¼"<<endl;
		cout<<"6.���ְ�����ʼ�¼"<<endl;
		cout<<"�˳�ϵͳ"<<endl;
		cout<<"����ѡ���ǣ�"<<endl;
		ch=getche();

		switch(ch)
		{
			case"1":
				find(first);           //��ѯ
				break;

			case"2":
				change(first);         //�޸�
				break

			case"3":
				first=add(first);      //���
				break;

			case"4":
				first=del(first);      //ɾ��
				break;

			case"5":
				write(first);          //����
				break;

			case"6":
				list(first);           //���
				break;

			case"7":
				return;                //�˳�

			default:
				cout<<"�밴�������������ѡ��1-7��"<<endl;
			getche();
		
		}
	}

	return;

}

/**********�������ļ���gz.dat��ȡְ���������ݵ��ṹ����zggz[]��***********/

struct zggz*read()
{
	FILE*fp                                //�����ļ�ָ��
	int n=0;                               //������¼ְ����¼���ı���
	struct zggz*first,*readdat;            //��¼�׵�ַ���·����ڴ��ַ
	struct zggz*p                          //�м����
	zggz zggz1[50];                        //����ְ�����ʽṹ������
	ifstream in("gz.dat",ios::binary);     //���������ļ�������in���򿪶����������ļ�gz.dat
	if(!in)                                //����ļ���ʧ�ܣ�in����0ֵ
	{
		cout<<"ְ�����������ļ���ʧ�ܣ���Ϊ��"<<endl;
		cout<<"��������������˵�"<<endl;
		getch();
		return 0;
	}
	else                                  //�ļ��򿪳ɹ�ʱ
	{
		readdat=(struct zzgz*)malloc(sizeof(struct zggz));        //��̬��������ڴ�ռ䣬������ڴ�����׵�ַ
		while(fread(readdat,sizeof(struct zggz),1,fp)==1)
		{
			if(n==0)                      //����������ʼ��
			{
				first=readdat;
				first->front=NULL;
				first->behind=NULL;
				p=readdat;
			
			}
			else                         //˵��׷������������
			{
				p->behind=readdat;
				readdat->front=p;
				readdat->behind=NULL;
				p=readdat;
			
			}
		
		  n++;                          //ְ����������1
		  readdat=(struct zggz*)malloc(sizeof(struct zggz));
		
		}

		fclose(fp);                    //�ر��ļ�ָ��
		cout<<"ְ���������ݶ�ȡ��ϣ����У�"<<n<<"��"<<endl;
		cout<<"�����������"



	
	
	
	
	}

	}




}

void input(struct Student stu[])
{
    int i;
    printf("����������ѧ����ţ�������������Ŀ�ɼ���\n");
    for (i=0;i<3;i++)
    {
        scanf("%d %s %f %f %f",&stu[i].num, &stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
        stu[i].aver = (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
    }
}

