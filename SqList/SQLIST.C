#include"SqListtou.h"
/////�˵�
void menu()
{
	printf("************************************************\n");
	printf("0.�˳�                    1.��������\n");
	printf("2.ɾ������                3.������������ȵ�λ��\n");
	printf("4.���ص�i��Ԫ�ص�ֵ       5.���ݳ���\n");
	printf("6.���                    7.��������\n");
	printf("8.��������                9.�п�\n");
	printf("************************************************\n");
}
void main()
{
	SqList L;
	ElemType e,e1,e2;
	ElemType e3,e4,choice;
	ElemType i,loc,length;
	L.elem=0;
	menu();
	while(1)
	{
		printf("������˵������֣�");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("��ӭ�´�������\n");
				exit(0);
			case 1:
				printf("����������λ�ú����ݣ�");
				scanf("%d %d",&i,&e);
				if(ListInsert(&L,i,e)==ERROR)
					printf("����λ������\n");
				else
					PutList (&L);
				break;
			case 2:
				printf("������ɾ����λ�ã�");
				scanf("%d",&i);
				if(ListDelete(&L,i,&e1)==ERROR)
					printf("����λ������\n");
				else
				{
					printf("��ɾ��������Ϊ��%d\n",e1);
					PutList(&L);
				}
				break;
			case 3:
				printf("��������ҵ����ݣ�");
				scanf("%d",&e2);
				loc=LocateElem(&L,e2,equal);
				if(loc != 0)
					printf("����%d�ڵ�%d��λ��\n",e2,loc);
				else
					printf("����%d�����ڣ�\n",e2);
					PutList (&L);
				break;	
			case 4:
				printf("������Ҫ���ص�λ�ã�");
				scanf("%d",&e4);
				if(GetElem(&L,e4,&e3)==ERROR)
					printf("����λ������!\n");	
				else
					printf("��%d��λ�õ�ֵΪ��%d\n",e4,e3);
				break;
			case 5:
				length = ListLength(&L);
				if( length!= OVERFLOW)
					printf("������%d��Ԫ�أ�\n",length);
				break;
			case 6:
				ClearList(&L);
				if(ClearList(&L) == OK)
					printf("��ճɹ���\n");
				else
					printf("��ղ��ɹ���\n");
				break;
			case 7:
				if(IniList(&L) == OK)
					printf("�����ɹ���\n");
				else
					printf("�������ɹ���\n");
				break;
			case 8:
				if(DestroyList(&L) == OK)
					printf("���ٳɹ���\n");
				else
					printf("���ٲ��ɹ���\n");
				break;
			case 9:
				if(ListEmpty(&L) == TRUE)
					printf("����Ϊ�գ�\n");
				else
					printf("������Ϊ�գ�\n");
				break;
			}
		}	
}