#include<stdio.h>
#include"Init.h"
#include <windows.h>
#include<stdlib.h>





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