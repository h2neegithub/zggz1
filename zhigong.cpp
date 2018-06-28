#include<iostream>            //������������������������ڴ�
#include<fstream>             //��������������ļ��������ڴ�                                                                                                                                                                                             j
#include<conio.h>             //getch()��getche()���������ڴ�
#include<cstring>              //����ַ������������ڴ�
using namespace std;

  /*************************������������**************************/

struct zggz*read();                //�������ļ��ж�ȡְ����������
void write(struct zggz*first);     //д��ְ�����ʼ�¼
void find(struct zggz*first);      //����ְ�����ʼ�¼
void modify(struct zggz*first);    //�޸�ְ�����ʼ�¼
struct zggz*add(struct zggz*first);//����ְ�����ʼ�¼
struct zggz*del(struct zggz*first) ;//ɾ��ְ�����ʼ�¼
float grsds(float m);              //�����������˰
void list(struct zggz*first);      //���ְ�����ʼ�¼

struct zggz                        //����ְ���������ݽṹ��
{	
	struct zggz*front;
	struct zggz*behind;
	char  gonghao[10];    //ְ������
	char  name[10];   //ְ������
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
			case'1':
				find(first);           //��ѯ
				break;

			case'2':
				modify(first);         //�޸�
				break;

			case'3':
				first=add(first);      //���
				break;

			case'4':
				first=del(first);      //ɾ��
				break;

			case'5':
				write(first);          //����
				break;

			case'6':
				list(first);           //���
				break;

			case'7':
				return;                //�˳�

			default:
				cout<<"�밴�������������ѡ��1-7��"<<endl;
			getch();
		
		}
	}

	return;

}

/**********�������ļ���gz.dat��ȡְ���������ݵ��ṹ����zggz[]��***********/

struct zggz*read()
{
	FILE*file;                                //�����ļ�ָ��
	int n=0;                               //������¼ְ����¼���ı���
	struct zggz*first,*readdate;            //��¼�׵�ַ���·����ڴ��ַ
	struct zggz*p ;                         //�м����                      
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
		readdate=(struct zggz*)malloc(sizeof(struct zggz));        //��̬��������ڴ�ռ䣬������ڴ�����׵�ַ
		while(fread(readdate,sizeof(struct zggz),1,file)==1)
		{
			if(n==0)                      //����������ʼ��
			{
				first=readdate;
				first->front=NULL;
				first->behind=NULL;
				p=readdate;
			
			}
			else                          //˵��׷������������
			{
				p->behind=readdate;
				readdate->front=p;
				readdate->behind=NULL;
				p=readdate;
			
			}
		
		  n++;                             //ְ����������1
		  readdate=(struct zggz*)malloc(sizeof(struct zggz));
		
		}

		fclose(file);                        //�ر��ļ�ָ��
		cout<<"ְ���������ݶ�ȡ��ϣ����У�"<<n<<"��"<<endl;
	}

		cout<<"��������������˵�"<<endl;
		getch();
		return first;
		
}


/**********��ְ�����������ļ�д���¼*************/

void write(struct zggz*first)
{
	FILE*file;                             //����ָ���ļ�
	int n=0;                               //ͳ�ƴ����ļ�ְ������
	if(first==NULL)                        //�ڴ����޹��ʼ�¼
	{
		cout<<"û�����ݿɴ棡��������������˵�"<<endl;
		getch();
		return;
	
	}
	if((file=fopen("gz.dat","wb"))!=NULL)               //�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��
	{
	
		do
		{
			fwrite(first,sizeof(struct zggz),1,file);   //���м�¼һ��д���ļ�
			n++;
			first=first->behind;
		
		}while(first!=NULL);
		fclose(file);                      //�ر��ļ�ָ��
		cout<<n<<"��ְ����¼�������"<<endl;
	
	}
	else                                   //�ļ��򿪲��ɹ�ʱ
		cout<<"�޷���ְ�����������ļ�"<<endl;
	getch();

}

/**********��ѯְ���������ݼ�¼�����ݹ��ţ�*************/

void find(struct zggz*first)
{

	char gonghao[10];                      //����ְ�������ַ�����
	if(first==NULL)                        //˵ ���ڴ��޹��ʼ�¼
	{
		
		cout<<"��ǰ��û��ְ�����ʼ�¼����������������˵�";
		getch();
		return;

	}
	
	cout<<"������ְ�����ţ�"<<endl;        //��ʾ��Ϣ
	gets(gonghao);                         //�Ӽ��̶�ȡ�ַ���
  
	while(first!=NULL)                     //������ʼ������
	{
		if(strcmp(first->gonghao,gonghao)==0)    //�Ƚϲ��ҵ�
		{
			/*********��ʾ��ְ���������************/
			cout<<"��ְ������������£�"<<endl;
			cout<<"����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������"<<endl;
			cout<<first->gonghao<<'\t'<<first->name<<'\t'<<first->gwgz<<'\t'<<first->xjgz<<'\t'<<first->zwjt<<'\t';
			cout<<first->jxgz<<'\t'<<first->yfgz<<'\t'<<first->grsds<<'\t'<<first->sfgz<<endl;
			cout<<"��������������˵�";
			getch();
			return;

		}

		first=first->behind;
	}

	//ѭ���Զ�������ζ��δ�ҵ�
	cout<<"���������ְ����������򲻴��ڣ���������������˵�"<<endl;
	getch();
	return;

}


/************���ְ�����ʼ�¼*************/

void list(struct zggz*first)
{
	system("cls");                       //��������
	cout<<"ȫ��ְ������������£�"<<endl;
	cout<<endl;
	if(first!=NULL)                      //˵���ڴ����������
	{
		do
		{
			cout<<"����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������"<<endl;
			cout<<first->gonghao<<'\t'<<first->name<<'\t'<<first->gwgz<<'\t'<<first->xjgz<<'\t'<<first->zwjt<<'\t';
			cout<<first->jxgz<<'\t'<<first->yfgz<<'\t'<<first->grsds<<'\t'<<first->sfgz<<endl;
			first=first->behind;         //����firstָ����������һ��ṹ����
		
		}while(first!=NULL);             //��Ϊ��˵���ṹ���ݴ���
	
	}

	cout<<"��������������˵�"<<endl;
	getch();
	return;

}

/************�޸�ְ���������ݼ�¼*************/

void modify(struct zggz*first)
{
	char gonghao[10];                   //����ְ�������ַ�����
	if(first==NULL)                     //˵���ڴ��޹��ʼ�¼
	{
		cout<<"��ǰû��ְ�����ʼ�¼����������������˵�"<<endl;
		getch();
		return;
	}

	cout<<"������ְ�����ţ�"<<endl;      //��ʾ��Ϣ
	gets(gonghao);                       //�Ӽ��̶�ȡ�ַ���
	while(first!=NULL)                   //������ʼ������
	{
			if(strcmp(first->gonghao,gonghao)==0)    //�Ƚϲ��ҵ�
		{
			/*********��ʾ��ְ���������************/
			cout<<"��ְ������������£�"<<endl;
			cout<<"����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������"<<endl;
			cout<<first->gonghao<<'\t'<<first->name<<'\t'<<first->gwgz<<'\t'<<first->xjgz<<'\t'<<first->zwjt<<'\t';
			cout<<first->jxgz<<'\t'<<first->yfgz<<'\t'<<first->grsds<<'\t'<<first->sfgz<<endl;

			/**********���ո�ְԱ�µĹ�������***********/
			cout<<"�������ְԱ�µĸ�λ���ʣ�";
			cin>>first->gwgz;
			cout<<"�������ְԱ�µ�н�����ʣ�";
			cin>>first->xjgz;
			cout<<"�������ְԱ�µļ�Ч���ʣ�";
			cin>>first->jxgz;

			/*********����Ӧ�����ʣ���������˰��ʵ������***********/
			first->yfgz=(first->gwgz)+(first->xjgz)+(first->zwjt)+(first->jxgz);
			first->grsds=grsds(first->yfgz);
			first->sfgz=(first->yfgz)-(first->grsds);

			/**********��ʾ������***********/
			cout<<"��ְ����Ӧ������Ϊ��"<<first->yfgz<<endl;
			cout<<"��ְ���ĸ�������˰Ϊ��"<<first->grsds<<endl;
			cout<<"��ְ����ʵ������Ϊ��"<<first->sfgz<<endl;
			cout<<"��ְ�����������޸ĳɹ�����������������˵�"<<endl;
			getch();
			return;
			
		}
		first=first->behind;
	}

	//ѭ���Զ�������ζ��δ�ҵ�
	cout<<"���������ְ����������򲻴��ڣ���������������˵�"<<endl;
	getch();
	return;

}

/**********��ְ�����������ļ����Ӽ�¼***********/

struct zggz*add(struct zggz*first)
{
	struct zggz*adddate;              //��¼�׵�ַ���·����ڴ��ַ
	struct zggz*p;                    //�м����
	adddate=(struct zggz*)malloc(sizeof(struct zggz));       //���붯̬�ڴ�ռ䣬������׵�ַ
	if(first==NULL)                   //˵����Ҫ����������������
	{
		first=adddate;
		first->front=NULL;
		first->behind=NULL;
		
	}
	else                              //˵����Ҫ�ҵ��������λ��
	{
		p=first;
		while(p->behind!=NULL)
		{
			p=p->behind ;
		}
	//��������׷����ָ��ָ���ϵ
		p->behind=adddate;
		adddate->front=p;
		adddate->behind=NULL;
	}
	//�����Ǵ�����һ������׷�ӹ��ʼ�¼����ֻ��adddate�������
		cout<<"������ְ�����ţ�";
		fflush(stdin);                 //������̻�����
		gets(adddate->gonghao);
		cout<<"������ְ��������";      
		fflush(stdin);                 //������̻����� 
		gets(adddate->name);
		cout<<"�������ְ���µĸ�λ���ʣ�";
		cin>>adddate->gwgz;
		cout<<"�������ְ���µ�н�����ʣ�";
		cin>>adddate->xjgz;
		cout<<"�������ְ���µ�ְ�������";
		cin>>adddate->zwjt;
		cout<<"�������ְ���µļ�Ч���ʣ�";
		cin>>adddate->jxgz;

	 /*********����Ӧ�����ʣ���������˰��ʵ������***********/
		first->yfgz=(first->gwgz)+(first->xjgz)+(first->zwjt)+(first->jxgz);
		first->grsds=grsds(first->yfgz);
		first->sfgz=(first->yfgz)-(first->grsds);

	 /**********������ϼ�����***********/
		cout<<"��ְ����Ӧ������Ϊ��"<<first->yfgz<<endl;
		cout<<"��ְ���ĸ�������˰Ϊ��"<<first->grsds<<endl;
		cout<<"��ְ����ʵ������Ϊ��"<<first->sfgz<<endl;
		cout<<"��������������˵�"<<endl;
		getch();
		return first;                //���������׵�ַ

}

/**********��ְ�����������ļ�ɾ����¼***********/

struct zggz*del(struct zggz*first)
{
	char gonghao[10];                 //����ְ�������ַ�����
	char d='N';                       //����ȷ��ɾ���ַ���y/n
	struct zggz*p;                    //�м����
	p=first;
	if(p==NULL)                       //˵���ڴ��޹��ʼ�¼
	{
		cout<<"��ǰ��û��ְ�����ʼ�¼���޷�ִ��ɾ����"<<endl;
		cout<<"��������������˵�"<<endl;
		getch();
		return first;
	
	}
	cout<<"�������ɾ��ְ�����ţ�";
	gets(gonghao);
	while(p!=NULL)                    //������ʼ�����в���
	{
		if(strcmp(first->gonghao,gonghao)==0)      //�Ƚϲ��ҵ�
		{
			/*********��ʾ��ְ���������************/
			cout<<"��ְ������������£�"<<endl;
			cout<<"����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������"<<endl;
			cout<<first->gonghao<<'\t'<<first->name<<'\t'<<first->gwgz<<'\t'<<first->xjgz<<'\t'<<first->zwjt<<'\t';
			cout<<first->jxgz<<'\t'<<first->yfgz<<'\t'<<first->grsds<<'\t'<<first->sfgz<<endl;
			cout<<"��ȷ��Ҫɾ����ְ��������Ϣ��"<<endl;
			d=getch();
			if(d=='y'||d=='Y')                     //ȷ��ɾ��
			{
				//���´���ʵ���ؽ������ϵ
				if(p->front==NULL&&p->behind==NULL)   //��ֻ��һ����¼ʱ
				{
					first=NULL;
				
				}
				else if(p->front==NULL)            //ɾ�����ǵ�һ����¼
				{
					first=p->behind;
					first->front=NULL;
				
				}
				else if(p->behind==NULL)           //ɾ���������һ����¼
				{
					(p->front)->behind=NULL;
				}
				else                               //ɾ���ǵ�һ����¼
				{
					(p->front)->behind=p->behind;
					(p->behind)->front=p->front;
				
				}
				free(p);                           //�ͷű�ɾ��������ռ�ڴ�
				cout<<"��ְ����¼�ɹ���ɾ������������������˵�"<<endl;
				getch();
				return first;                      //���ع���������ʼ��ַ

			}
			else                //δȷ��ɾ����¼
			{
			
			cout<<"��ѡ���˲�ɾ����ְ����¼����������������˵�"<<endl;
			getch();
			return first;
			
			}

			p=p->behind ;           //ָ����һ��ṹ����

		}

	if(d=='n'||d=='N')             //��ֵ��ӳδɾ������¼��״̬
	{
		cout<<"����λ�޴˹��ţ���������������˵�"<<endl;
		getch();
		return first;
	
	}
}

}

/*********�����������˰*************/
float grsds(float m)
{
	float x;                  //����Ӧ��˰���ö�
	float y=0;                //����Ӧ��˰��
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
									  //����100000Ԫ�Ĳ���45%			                       
					x=100000;
		case 8:y+=(x-80000)*0.40;
									  //����80000Ԫ��100000�Ĳ���40%
					x=80000; 
		case 7:y+=(x-60000)*0.35;
									  //����60000Ԫ��80000�Ĳ���35%
					x=60000;
		case 6:y+=(x-40000)*0.30;
									  //����40000Ԫ��60000�Ĳ���30%
					x=40000; 			     
		case 5:y+=(x-20000)*0.25; 
									  //����20000Ԫ��40000�Ĳ���25%
					x=20000;
		case 4:y+=(x-5000)*0.20;
									  //����5000Ԫ��20000�Ĳ���20%
					x=5000;
		case 3:y+=(x-2000)*0.15;
									  //����2000Ԫ��5000�Ĳ���15%
					x=2000;
		case 2:y+=(x-500)*0.10;
									  //����500Ԫ��2000�Ĳ���10%
					x=500;
		case 1:y+=x*0.05;                     
									 //������500Ԫ��5%
		}

	return y;
}
