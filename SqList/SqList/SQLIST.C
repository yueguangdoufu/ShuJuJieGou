#include"SqListtou.h"
#include<stdio.h>
/////菜单
void menu()
{
	printf("****************************************\n");
	printf("0.退出                        1.插入数字\n");
	printf("2.删除数字                  3.数字的位置\n");
	printf("4.返回第i个元素的值           5.数据长度\n");
	printf("6.清空\n");
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
		printf("请输入菜单的数字：");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("欢迎下次再来！\n");
				break;
			case 1:
				printf("请输入插入的位置和数据：");
				scanf("%d%d",&i,&e);
				if(ListInsert(&L,i,e)==ERROR)
				{
					printf("输入位置有误！\n");
					exit(0);
				}
				else
					PutList (&L);
				break;
			case 2:
				printf("请输入删除的位置：");
				scanf("%d",&i1);
				if(ListDelete(&L,i1,&e1)==ERROR)
				{
					printf("输入位置有误！\n");
					exit(0);
				}
				else
				{
					printf("被删掉的数字为：%d\n",e1);
					PutList(&L);
				}
				break;
			case 3:
				printf("请输入查找的数据：");
				scanf("%d",&e2);
				if(LocateElem(&L,e2,equal) != 0)
					printf("数据%d在第%d个位置\n",e2,LocateElem(&L,e2,equal));
				else
					Printf("数据%d不存在！\n",e2);
				PutList (&L);
				break;	
			case 4:
				printf("请输入要返回的位置：");
				scanf("%d",&e4);
				if(GetElem(&L,e4,&e3)==ERROR)
				{
					printf("输入位置有误\n！");
					exit(0);	
				}
				else
					printf("第%d个位置的值为：%d\n",e4,e3);
				break;
			case 5:
				if(ListLength(&L) == OVERFLOW)
					printf("数据有误！\n");
				else
					printf("有%d个元素\n",ListLength(&L));
				break;
			case 6:
				ClearList(&L);
				if(ClearList(&L) == OK)
					printf("清空成功！\n");
				else
					printf("清空不成功！\n");
				break;
			}
		}
		DestroyList(&L);
}