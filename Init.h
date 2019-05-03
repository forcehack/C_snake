#include<stdio.h>
#include<time.h>
#include <windows.h>
#include<stdlib.h>
#include<conio.h>//kbhit ����kbhit����ͣ  ��getch()����
/*********�궨����**************/

#define FOOD 1
#define INIT_X 5 //�߳�����
#define INIT_Y 2
#define MIN_SPEED 100
#define MAX_SPEED 10
#define INIT_LENTH 5 //��ʼ����

/*********ö�ٶ�����******************/
enum status{
	death=0


};
/*********�ṹ�嶨����****************/
typedef struct node 
{
    /*����ڵ�*/
    int x;
    int y;
	//��������
	struct node *next;
   

}SnakeNode;

typedef struct body{

	char direct;
	int speed;
	int length;
}SnakeBody;

typedef struct Food{
	int x;
	int y;
	
}SnakeFood;



/********����������**********/
void DrawMap();
void createSnake();
void createFood();
void printSnake(int ,int );
SnakeNode *createNode(SnakeNode *head,SnakeNode *data);
void setColor(unsigned short ForeColor,unsigned short BackGroundColor);
void gameOver();
void continueGame();
/****************************/
SnakeNode *p;
//����ͷָ��
SnakeNode *HEAD;
SnakeBody *b;
SnakeFood *food;
SnakeNode *currentNode=NULL;
//���ù��λ��
void setPos(int x,int y){
	
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 0 };
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

//��ʼ������
void Init(){
	char ch;

	system("cls");
	setPos(40, 10);
    printf("******************************");
    setPos(40, 12);
    printf("   ��ӭ����̰������Ϸ��");
    setPos(40, 14);
    printf("******************************");

    setPos(40, 18);
    system("pause");
	//�����Ļ
    system("cls");


	setPos(70, 5);
    printf("��ѡ��<1��ʼ 2�˳�>��");
	setPos(70, 7);
    printf("ʹ�á� �� �� �����Ʒ���");
	setPos(70, 9);
    printf("4���٣�5����\n");
	setPos(70,11);
    printf("���ո���ͣ/������ESC�˳�");
	setPos(70, 13);
    printf("��ǰ�ٶ�:");
	setPos(70, 15);
    printf("�÷֣�");
	setPos(92, 5);

//�жϼ�������

wait:
if(kbhit()){
	if((ch=getchar())=='1'){
			createSnake();
	}
	if((ch=getchar())=='2'){
		
			setPos(25,13);
			setColor(4,2);
			puts("Game over!");
			setPos(0,28);
			exit(0);
		}

}
else goto wait;


}
//����ͼ
void DrawMap(){

setColor(7,2);
	setPos(70, 5);
    printf("��ѡ��<1��ʼ 2�˳�>��");
	setPos(70, 7);
    printf("ʹ�á� �� �� �����Ʒ���");
	setPos(70, 9);
    printf("4���٣�5����\n");
	setPos(70,11);
    printf("���ո���ͣ/������ESC�˳�"); 
	setPos(70, 13);
    printf("��ǰ�ٶ�:%ld",10000/b->speed);
	setPos(70, 15);
    printf("�÷֣�%ld",b->length-1);
	setPos(92, 5);

		setPos(0,0);
		
		//��Ϊ30 ��Ϊ27  Ҳ������ѭ���ķ�������
	printf("������������������������������������������������������������\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("������������������������������������������������������������\n");
	

	

}
//��ʼ����
void createSnake(){

	int x,y;
	//���ò��� �������λ��
	srand((int)time(0));
	


	//����current
	
	p=(SnakeNode *)malloc(sizeof(SnakeNode));
	b=(SnakeBody *)malloc(sizeof(SnakeBody));
	HEAD=(SnakeNode *)malloc(sizeof(SnakeNode));
	currentNode=(SnakeNode *)malloc(sizeof(SnakeNode));//��̬�����С������ָ����ڴ��ָ��

	x=INIT_X*rand()%28+2;
	y=INIT_Y*rand()%25+2;
	x=(x%2==0)?(x):(x+1);
	y=(y%2==0)?(y):(y+1);

	p->x=x;
	p->y=y;
	b->direct=77;
	b->speed=MIN_SPEED;
	b->length=1;
	p->next=NULL;
	
	

	
	//����ʳ��
createFood();
}

//�ж���û�з��������
void directSelect(){
	char ch;
		if(kbhit()){
		ch = getch();
	
		switch(ch){
			//�ж���������
	
							case 72:b->direct=72  ;break;
							case 80:b->direct=80  ;break;
							case 75:b->direct=75  ;break;
							case 77:b->direct=77  ;break;
							case 52:(b->speed>MAX_SPEED)?b->speed-=1:b->speed ;break;
							case 53:(b->speed<MIN_SPEED)?b->speed+=1:b->speed ;break;
							case 27:exit(0);
							case 32:{
								
								setPos(23,13);
								setColor(4,2);
								printf("���ո������Ϸ!\n");
								setPos(0,28);
								system("pause");
								
								break;
									}
		
		}
	
	}

}

//�ߵ��ƶ�
void moveSnake(){
	int x=0,y=0;

	setPos(food->x,food->y);
	setColor(6,2);
	printf("%c",FOOD);

	
	//�ж���û�м������룬��Ȼ�������ʱ����
	directSelect();
	
		switch(b->direct){
		
							case 72:y=-1 ;break;
							case 80:y=1 ;break;
							case 75:x=-2 ;break;
							case 77:x=2 ;break;
						}



		if(p->x>=57||p->y>=25||p->x<=0||p->y<=0){
			
			setPos(25,13);
			setColor(4,2);
			printf("Game Over!!\n");
		
			gameOver();
		}
		else{
			
			currentNode=createNode(currentNode,p);
		
			p->x=p->x+x;
			p->y=p->y+y;
			if(p->x==food->x&&p->y==food->y){
			
			
					b->length++;
					b->speed-=1;
				
					createFood();
				
			}
			//��x��y�����ȡ��һ�ε�λ��
			printSnake(x,y);
			
			
			//VC�д�дS  ��׼C��s
			Sleep(b->speed); 
		
		}


	
}
//����ʳ��
void createFood(){
	int x,y;

	food=(SnakeFood *)malloc(sizeof(SnakeFood));
		

again:
	srand((int)time(0));
	memset(food, 0, sizeof(SnakeNode));
	x=INIT_X*rand()%25+2;
	y=INIT_Y*rand()%24+2;
	x=(x%2==0)?(x):(x+1);
	y=(y%2==0)?(y):(y+1);



	if(x==p->x&&y==p->y){
		goto again;
	}
	else{
	
		food->x=x;
		food->y=y;
	}
	
	

	
}

//��������ӡ��
void printSnake(int x,int y){
SnakeNode *Node;
int i;

Node=currentNode;


for(i=0;i<b->length&&Node!=NULL;i++){
	if(Node->x==p->x&&Node->y==p->y){
			setPos(25,13);
			setColor(4,2);
			printf("Game Over!!\n");
			
			gameOver();
	
	}
	setPos(Node->x,Node->y);
	setColor(4,2);
	printf("��");
	Node=Node->next;

}
		


//free(Node->next);
}

//��������

SnakeNode *createNode(SnakeNode *head,SnakeNode *data){
		SnakeNode *node;

	node=(SnakeNode *)malloc(sizeof(SnakeNode));

	  // ��ԭʼͷ������ӵ��˽����棬�������ݽ�������
		node->next = head;
		node->x = data->x;
		node->y=data->y;
		head = node;
 
	return head;

}

//������ɫ ��һ������Ϊ������ɫ �ڶ���Ϊ������ɫ
void setColor(unsigned short ForeColor,unsigned short BackGroundColor)

{

HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��ǰ���ھ��

SetConsoleTextAttribute(handle,ForeColor+BackGroundColor*0x10);//������ɫ

} 

//��Ϸ����/�ж��Ƿ���������˳�
void gameOver(){
	char ch;
//��ʱ1s�������Ļ
	setColor(4,7);
	Sleep(500);
	system("cls");

    setPos(40, 12);
    printf("        ������Ϸ[�ո�]        ");
	setPos(40, 14);
	printf("                              ");
	setPos(40, 16);
	printf("        �˳���Ϸ[ESC]         ");
	setPos(40, 20);

wait:
	if((kbhit())>0){
		switch((ch=getch())){
		
		case 32:continueGame();
		case 27:exit(0);break;
		
		}
	
	
	}
	else goto wait;
}   

void continueGame(){

	
	createSnake();
	while(1){
	
			//����ͼ
			DrawMap();
			//�ж���û�з��������
			directSelect();
			//�ߵ��ƶ�
			moveSnake();
			//�����Ļ
			system("cls");
	}


}

