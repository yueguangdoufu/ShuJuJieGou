#include"SqListtou.h"
/////菜单
void menu()
{
	printf("************************************************\n");
	printf("0.退出                    1.插入数字\n");
	printf("2.删除数字                3.与数据满足相等的位置\n");
	printf("4.返回第i个元素的值       5.数据长度\n");
	printf("6.清空                    7.创建链表\n");
	printf("8.销毁链表                9.判空\n");
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
		printf("请输入菜单的数字：");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				printf("欢迎下次再来！\n");
				exit(0);
			case 1:
				printf("请输入插入的位置和数据：");
				scanf("%d %d",&i,&e);
				if(ListInsert(&L,i,e)==ERROR)
					printf("输入位置有误！\n");
				else
					PutList (&L);
				break;
			case 2:
				printf("请输入删除的位置：");
				scanf("%d",&i);
				if(ListDelete(&L,i,&e1)==ERROR)
					printf("输入位置有误！\n");
				else
				{
					printf("被删掉的数字为：%d\n",e1);
					PutList(&L);
				}
				break;
			case 3:
				printf("请输入查找的数据：");
				scanf("%d",&e2);
				loc=LocateElem(&L,e2,equal);
				if(loc != 0)
					printf("数据%d在第%d个位置\n",e2,loc);
				else
					printf("数据%d不存在！\n",e2);
					PutList (&L);
				break;	
			case 4:
				printf("请输入要返回的位置：");
				scanf("%d",&e4);
				if(GetElem(&L,e4,&e3)==ERROR)
					printf("输入位置有误!\n");	
				else
					printf("第%d个位置的值为：%d\n",e4,e3);
				break;
			case 5:
				length = ListLength(&L);
				if( length!= OVERFLOW)
					printf("链表有%d个元素！\n",length);
				break;
			case 6:
				ClearList(&L);
				if(ClearList(&L) == OK)
					printf("清空成功！\n");
				else
					printf("清空不成功！\n");
				break;
			case 7:
				if(IniList(&L) == OK)
					printf("创建成功！\n");
				else
					printf("创建不成功！\n");
				break;
			case 8:
				if(DestroyList(&L) == OK)
					printf("销毁成功！\n");
				else
					printf("销毁不成功！\n");
				break;
			case 9:
				if(ListEmpty(&L) == TRUE)
					printf("链表为空！\n");
				else
					printf("链表不为空！\n");
				break;
			}
		}	
}