#include"Init.h"


void main(){
	//��ʼ��
		Init();
	
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
