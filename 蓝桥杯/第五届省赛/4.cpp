#include <bits/stdc++.h>
//计算个位 
int ge_wei(int a)
{
	if(a % 2 == 0)
		return (a * 2) % 10;
	else
		return (a * 2 + 5) % 10;	
}

//计算进位 
int jin_wei(char* p)
{
	char* level[] = {
		"142857",
		"285714",
		"428571",
		"571428",
		"714285",
		"857142"
	};
	
	char buf[7];
	buf[6] = '\0';
	strncpy(buf,p,6);
	
	int i;
	for(i=5; i>=0; i--){
		int r = strcmp(level[i], buf);
		if(r<0) return i+1;
		while(r==0){
			p += 6;
			strncpy(buf,p,6);
			r = strcmp(level[i], buf);
			if(r<0) return i+1;
			if(r>0) return i;  //填空
		}
	}
	
	return 0;
}

//多位数乘以7
void f(char* s) 
{
	int head = jin_wei(s);
	if(head > 0) printf("%d", head);
	
	char* p = s;
	while(*p){
		int a = (*p-'0');
		int x = (ge_wei(a) + jin_wei(p+1)) % 10;
		printf("%d",x);
		p++;
	}
	
	printf("\n");
}

int main()
{
	f("428571428571");
	f("34553834937543");		
	return 0;
}

/*
answer:  if(r>0) i;
author: xcatf
*/