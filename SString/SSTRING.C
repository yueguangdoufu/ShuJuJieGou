#include"stdio.h"
#include"stdlib.h"

#define OK 1
#define FALSE 0
#define TRUE 1
#define OVERFLOW 0
#define ERROR 0

#define MAXSTRLEN 255

typedef unsigned char SString[MAXSTRLEN + 1];
typedef int Status;

//´®µÄ¸³Öµ
Status StrAssign(SString *T,char chars[]){
	int i;
	int len=0;
	
	while(chars[len]){
		len++;
	}
	*T[0]=len;
	for(i = 0 ; i <= *T[0] ; i++){
		*T[i +1] = chars[i];
	}
	return OK;
}

Status StrCopy(SString *T,SString S){
	int i;
	for(i = 1;i<=S[0];i++)
	{
		*T[i] = S[i];
		*T[0] = S[0];
	}
	return OK;
}

Status StrEmpty(SString S)
{
	if(S[0] == 0){
		return OK;
	}else{
		return ERROR;
	}
}

Status StrCompare(SString S,SString T){
	int i;
	for(i = 1;i<=S[0]&&i<=T[0];++i)
	{
		if(S[i]!=T[i])
			return S[i]-T[i];
	}
	return S[0]-T[0];
}

Status StrLength(SString S){
	return S[0];
}

Status ClearString(SString S){
	S[0] = 0;
	return OK;
}

Status Concat(SString *T,SString S1,SString S2){
	int i;
	Status uncut;
	if(S1[0]+S2[0]<=MAXSTRLEN){
		for(i = 1;i<S1[0];i++){
			*T[i]=S1[i];
		}
		for(i = 1;i<=S2[0];i++){
			*T[S1[0]+i]=S2[i];
		}
		*T[0]=S1[0]+S2[0];
		uncut = TRUE;
	}else if(S1[0]<MAXSTRLEN){
		for(i = 1;i<=S1[0];i++){
			*T[i] = S1[i];
		}
		for(i = 1; i <= MAXSTRLEN - S1[0];i++){
			*T[S1[0]+i] = S2[i];
		}
		*T[0] =MAXSTRLEN;
		uncut = FALSE;
	}else{
		for(i = 1 ; i <= MAXSTRLEN;i++){
			*T[i] = S1[i];
		}	
		uncut = FALSE;
	}
	return uncut;
}

Status SubString(SString *Sub,SString S,int pos,int len) {
	int i;
	if(pos<1||pos>S[0]||len>S[0]-pos+1)
		return ERROR;
	for(i = 1; i <= len;i++){
		*Sub[i]=S[pos+i-1];
	}
	*Sub[0]=len;
	return OK;
}

Status Index(SString S,SString T,int pos){
	int i,j;
	i = pos;
	j = 1;
	while(i<S[0]&&j<=T[0]){
		if(S[i]==T[i]){
			++i;
			++j;
		}else{
			i = i-j+2;
			j = 1;
		}
	}
	if(j>T[0])
		return i - T[0];
	return 0;
} 

Status Replace(SString *S,SString T,SString V){
	int i,j;
	int flag= 1;
	for(i = 1;i<=*S[0]-T[0];i++){
		for(j = 1;j<=T[0];j++){
			if(*S[i+j]!=T[i]){
				flag = 0;
				break;
			}
			flag = 1;
		}
		if(flag = 1){
			for(j = 1;j<=T[0];j++){
				*S[i+j] =V[j];
			}
			i = i+j-1;
		}
	}
	return OK;

}

Status StrInsert(SString *S,int pos,SString T){
	int i;
	if(pos<1||pos>*S[0]+1)
		return ERROR;
	if(*S[0]+T[0]<=MAXSTRLEN){
		for(i = *S[0];i>=pos;i--){
			*S[i+T[0]]=*S[i];
		}
		for(i = pos ;i<pos+T[0];i++){
			*S[i] = T[i-pos+1];
		}
		*S[0]=*S[0]+T[0];
		return TRUE;
	}
	else{
		for(i = MAXSTRLEN;i>=pos;i++){
			*S[i] = *S[i-T[0]];
		}
		for(i = pos;i<pos+T[0];i++){
			*S[i]=T[i-pos+1];
		}
		*S[0] = MAXSTRLEN;
		return FALSE;
	}
}

Status StrDelete(SString *S,int pos,int len){
	int i;
	if(pos<1||pos>*S[0]-len+1||len<0)
		return ERROR;
	for(i = pos+len;i<=*S[0];i++){
		*S[i-len] = *S[i];
	}
	*S[0] =*S[0]- len;
	return OK;
}


Status DestroyString(SString *S){
	int i;
	char *p;
	for(i = *S[0] ;i>0;i-- ){
		p = S[i];
		free(p);
	}
	p = S[0];
	free(p);
	return OK;
}

