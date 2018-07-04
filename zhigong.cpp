#include<stdio.h>            //������������������������ڴ�
#include<fstream>             //��������������ļ��������ڴ�                                                                                                                                                                                             j
#include<conio.h>             //getch()��getche()���������ڴ�
#include<string.h>              //����ַ������������ڴ�


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
	char  name[10];       //ְ������
	float gwgz;           //��λ����
	float xjgz;           //н������
	float zwjt;           //ְ�����
	float jxgz;           //��Ч����
	float yfgz;           //Ӧ������
	float grsds;          //��������˰
	float sfgz;           //ʵ������

};

void main()
{	
	char ch;
	struct zggz*first;    //����ָ��ṹ���ָ���������¼������׵�ַ
	first=read();         //�������ļ��ж�ȡְ���������ݲ���ʼ��ְ�����ʽṹ�����飬��ȡ�ýṹ��������׵�ַ
	while(true)
	{
		system("cls");
		printf("###��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ###\n\n");
		printf("��ѡ��1-7��:\n");
		printf("=================================================================\n");
		printf("|\t\t\t1.��ѯְ�����ʼ�¼\t\t\t|\n");
		printf("|\t\t\t2.�޸�ְ�����ʼ�¼\t\t\t|\n");
		printf("|\t\t\t3.���ְ�����ʼ�¼\t\t\t|\n");
		printf("|\t\t\t4.ɾ��ְ�����ʼ�¼\t\t\t|\n");
		printf("|\t\t\t5.����ְ�����ʼ�¼\t\t\t|\n");
		printf("|\t\t\t6.���ְ�����ʼ�¼\t\t\t|\n");
		printf("|\t\t\t7.�˳�ϵͳ\t\t\t\t|\n");
		printf("=================================================================\n\n");
		printf("����ѡ���ǣ�\n\n");
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
				printf("�밴�������������ѡ��1-7��\n");
			getch();
		
		}
	}

	return;

}

/**********�������ļ���gz.dat��ȡְ���������ݵ��ṹ����zggz[]��***********/

struct zggz*read()
{
	FILE*file;                                //�����ļ�ָ��
	int n=0;                                  //������¼ְ����¼���ı���
	struct zggz*first,*readdate;              //��¼�׵�ַ���·����ڴ��ַ
	struct zggz*p ;                           //�м����                      
    if((file=fopen("gz.dat","rb"))==NULL)     //�Զ����Ʒ�ʽ��ְ�����������ļ��������ж��Ƿ�ʧ��                             
	{
		printf("ְ�����������ļ���ʧ�ܣ���Ϊ��\n");
		printf("��������������˵�\n");
		getch();
		return 0;
	}
	else                                      //�ļ��򿪳ɹ�ʱ
	{
		readdate=(struct zggz*)malloc(sizeof(struct zggz));        //��̬��������ڴ�ռ䣬������ڴ�����׵�ַ
		while(fread(readdate,sizeof(struct zggz),1,file)==1)
		{
			if(n==0)                          //����������ʼ��
			{
				first=readdate;
				first->front=NULL;
				first->behind=NULL;
				p=readdate;
			
			}
			else                              //˵��׷������������
			{
				p->behind=readdate;
				readdate->front=p;
				readdate->behind=NULL;
				p=readdate;
			
			}
		
		  n++;                                 //ְ����������1
		  readdate=(struct zggz*)malloc(sizeof(struct zggz));
		
		}

		fclose(file);                          //�ر��ļ�ָ��
		printf("ְ���������ݶ�ȡ��ϣ����У�%d�ˣ�\n",n);
	}

		printf("��������������˵�\n");
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
		printf("û�����ݿɴ棡��������������˵�\n");
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
		printf("%d��ְ����¼�������\n");
	
	}
	else                                   //�ļ��򿪲��ɹ�ʱ
		printf("�޷���ְ�����������ļ�\n");
	getch();

}

/**********��ѯְ���������ݼ�¼�����ݹ��ţ�*************/

void find(struct zggz*first)
{

	char gonghao[10];                      //����ְ�������ַ�����
	if(first==NULL)                        //˵���ڴ��޹��ʼ�¼
	{
		
		printf("��ǰ��û��ְ�����ʼ�¼����������������˵�");
		getch();
		return;

	}
	
	printf("������ְ�����ţ�\n");        //��ʾ��Ϣ
	gets(gonghao);                         //�Ӽ��̶�ȡ�ַ���
  
	while(first!=NULL)                     //������ʼ������
	{
		if(strcmp(first->gonghao,gonghao)==0)    //�Ƚϲ��ҵ�
		{
			/*********��ʾ��ְ���������************/
			printf("��ְ������������£�\n");
			printf("======================================================================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s%","����","����","��λ����","н������","ְ�����");
			printf("%-9s%-9s%8s%9s%\n","��Ч����","Ӧ������","��������˰","ʵ������");
			printf("%-6s%-6s%8.2f%",first->gonghao,first->name,first->gwgz);
			printf("%9.2f%9.2f%",first->xjgz,first->zwjt);
			printf("%9.2f%9.2f%",first->jxgz,first->yfgz);
			printf("%9.2f%9.2f%\n",first->grsds,first->sfgz);
			printf("��������������˵�");
			getch();
			return;

		}

		first=first->behind;
	}

	//ѭ���Զ�������ζ��δ�ҵ�
	printf("���������ְ����������򲻴��ڣ���������������˵�\n");
	getch();
	return;

}


/************���ְ�����ʼ�¼*************/

void list(struct zggz*first)
{
	system("cls");                       //��������
	printf("ȫ��ְ������������£�\n");
	printf("==============================================\n\n");
	if(first!=NULL)                      //˵���ڴ����������
	{
		do
		{
			printf("%-6s%-6s%-9s%-9s%-9s%","����","����","��λ����","н������","ְ�����");
			printf("%-9s%-9s%8s%9s%\n","��Ч����","Ӧ������","��������˰","ʵ������");
			printf("%-6s%-6s%8.2f%",first->gonghao,first->name,first->gwgz);
			printf("%9.2f%9.2f%",first->xjgz,first->zwjt);
			printf("%9.2f%9.2f%",first->jxgz,first->yfgz);
			printf("%9.2f%9.2f%\n",first->grsds,first->sfgz);

			first=first->behind;         //����firstָ����������һ��ṹ����
		
		}while(first!=NULL);             //��Ϊ��˵���ṹ���ݴ���
	
	}

	printf("��������������˵�\n");
	getch();
	return;

}

/************�޸�ְ���������ݼ�¼*************/

void modify(struct zggz*first)
{
	char gonghao[10];                   //����ְ�������ַ�����
	if(first==NULL)                     //˵���ڴ��޹��ʼ�¼
	{
		printf("��ǰû��ְ�����ʼ�¼����������������˵�\n");
		getch();
		return;
	}

	printf("������ְ�����ţ�\n");      //��ʾ��Ϣ
	gets(gonghao);                       //�Ӽ��̶�ȡ�ַ���
	while(first!=NULL)                   //������ʼ������
	{
			if(strcmp(first->gonghao,gonghao)==0)    //�Ƚϲ��ҵ�
		{
			/*********��ʾ��ְ���������************/
			printf("��ְ������������£�\n");
			printf("================================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s%","����","����","��λ����","н������","ְ�����");
			printf("%-9s%-9s%8s%9s%\n","��Ч����","Ӧ������","��������˰","ʵ������");
			printf("%-6s%-6s%8.2f%",first->gonghao,first->name,first->gwgz);
			printf("%9.2f%9.2f%",first->xjgz,first->zwjt);
			printf("%9.2f%9.2f%",first->jxgz,first->yfgz);
			printf("%9.2f%9.2f%\n",first->grsds,first->sfgz);
			/**********���ո�ְԱ�µĹ�������***********/
			printf("�������ְԱ�µĸ�λ���ʣ�");
			scanf("%f",&first->gwgz);
			printf("�������ְԱ�µ�н�����ʣ�");
			scanf("%f",&first->xjgz);
			printf("�������ְԱ�µļ�Ч���ʣ�");
			scanf("%f",&first->jxgz);

			/*********����Ӧ�����ʣ���������˰��ʵ������***********/
			first->yfgz=(first->gwgz)+(first->xjgz)+(first->zwjt)+(first->jxgz);
			first->grsds=grsds(first->yfgz);
			first->sfgz=(first->yfgz)-(first->grsds);

			/**********��ʾ������***********/
			printf("��ְ����Ӧ������Ϊ��%f",first->yfgz);
			printf("\n");
			printf("��ְ���ĸ�������˰Ϊ��%f",first->grsds);
			printf("\n");
			printf("��ְ����ʵ������Ϊ��%f",first->sfgz);
			printf("\n");
			printf("��ְ�����������޸ĳɹ�����������������˵�\n\n");
			getch();
			return;
			
		}
		first=first->behind;
	}

	//ѭ���Զ�������ζ��δ�ҵ�
	printf("���������ְ����������򲻴��ڣ���������������˵�\n");
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
		printf("������ְ�����ţ�");
		fflush(stdin);                 //������̻�����
		gets(adddate->gonghao);
		printf("������ְ��������");      
		fflush(stdin);                 //������̻����� 
		gets(adddate->name);
		printf("�������ְ���µĸ�λ���ʣ�");
		scanf("%f",&adddate->gwgz);
		printf("�������ְ���µ�н�����ʣ�");
		scanf("%f",&adddate->xjgz);
		printf("�������ְ���µ�ְ�������");
		scanf("%f",&adddate->zwjt);
		printf("�������ְ���µļ�Ч���ʣ�");
		scanf("%f",&adddate->jxgz);

	 /*********����Ӧ�����ʣ���������˰��ʵ������***********/
		adddate->yfgz=(adddate->gwgz)+(adddate->xjgz)+(adddate->zwjt)+(adddate->jxgz);
		adddate->grsds=grsds(adddate->yfgz);
		adddate->sfgz=(adddate->yfgz)-(adddate->grsds);

	 /**********������ϼ�����***********/
		printf("��ְ����Ӧ������Ϊ��%f",adddate->yfgz);
		printf("\n");
		printf("��ְ���ĸ�������˰Ϊ��%f",adddate->grsds);
		printf("\n");
		printf("��ְ����ʵ������Ϊ��%f",adddate->sfgz);
		printf("\n");
		printf("��������������˵�\n\n");
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
		printf("��ǰ��û��ְ�����ʼ�¼���޷�ִ��ɾ����\n");
		printf("��������������˵�\n");
		getch();
		return first;
	
	}
	printf("�������ɾ��ְ�����ţ�");
	gets(gonghao);
	while(p!=NULL)                    //������ʼ�����в���
	{
		if(strcmp(first->gonghao,gonghao)==0)      //�Ƚϲ��ҵ�
		{
			/*********��ʾ��ְ���������************/
			printf("��ְ������������£�\n");
			printf("================================\n\n");
			printf("%-6s%-6s%-9s%-9s%-9s%","����","����","��λ����","н������","ְ�����");
			printf("%-9s%-9s%8s%9s%\n","��Ч����","Ӧ������","��������˰","ʵ������");
			printf("%-6s%-6s%8.2f%",p->gonghao,p->name,p->gwgz);
			printf("%9.2f%9.2f%",p->xjgz,p->zwjt);
			printf("%9.2f%9.2f%",p->jxgz,p->yfgz);
			printf("%9.2f%9.2f%\n",p->grsds,p->sfgz);
			printf("��ȷ��Ҫɾ��%s��ְ��������Ϣ��",p->gonghao);
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
				printf("��ְ����¼�ɹ���ɾ������������������˵�\n");
				getch();
				return first;                      //���ع���������ʼ��ַ

			}
			else                //δȷ��ɾ����¼
			{
			
			printf("��ѡ���˲�ɾ����ְ����¼����������������˵�\n");
			getch();
			return first;
			
			}

			p=p->behind ;           //ָ����һ��ṹ����

		}

	if(d=='n'||d=='N')             //��ֵ��ӳδɾ������¼��״̬
	{
		printf("����λ�޴˹��ţ���������������˵�\n");
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
