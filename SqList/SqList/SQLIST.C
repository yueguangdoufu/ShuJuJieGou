#include"SqListtou.h"
#include<stdio.h>
/////�˵�
void menu()
{
	printf("****************************************\n");
	printf("0.�˳�                        1.��������\n");
	printf("2.ɾ������                  3.���ֵ�λ��\n");
	printf("4.���ص�i��Ԫ�ص�ֵ           5.���ݳ���\n");
	printf("6.���\n");
	printf("****************************************\n");
}
void main()
{
	SqList L;
	ElemType e,e1,e2,e3,e4,choice,i,i1;
	IniList(&L);
	menu();
	CreateList(&L);
	while(1)
	{
		printf("������˵������֣�");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("��ӭ�´�������\n");
				break;
			case 1:
				printf("����������λ�ú����ݣ�");
				scanf("%d%d",&i,&e);
				if(ListInsert(&L,i,e)==ERROR)
				{
					printf("����λ������\n");
					exit(0);
				}
				else
					PutList (&L);
				break;
			case 2:
				printf("������ɾ����λ�ã�");
				scanf("%d",&i1);
				if(ListDelete(&L,i1,&e1)==ERROR)
				{
					printf("����λ������\n");
					exit(0);
				}
				else
				{
					printf("��ɾ��������Ϊ��%d\n",e1);
					PutList(&L);
				}
				break;
			case 3:
				printf("��������ҵ����ݣ�");
				scanf("%d",&e2);
				if(LocateElem(&L,e2,equal) != 0)
					printf("����%d�ڵ�%d��λ��\n",e2,LocateElem(&L,e2,equal));
				else
					Printf("����%d�����ڣ�\n",e2);
				PutList (&L);
				break;	
			case 4:
				printf("������Ҫ���ص�λ�ã�");
				scanf("%d",&e4);
				if(GetElem(&L,e4,&e3)==ERROR)
				{
					printf("����λ������\n��");
					exit(0);	
				}
				else
					printf("��%d��λ�õ�ֵΪ��%d\n",e4,e3);
				break;
			case 5:
				if(ListLength(&L) == OVERFLOW)
					printf("��������\n");
				else
					printf("��%d��Ԫ��\n",ListLength(&L));
				break;
			case 6:
				ClearList(&L);
				if(ClearList(&L) == OK)
					printf("��ճɹ���\n");
				else
					printf("��ղ��ɹ���\n");
				break;
			}
		}
		DestroyList(&L);
}