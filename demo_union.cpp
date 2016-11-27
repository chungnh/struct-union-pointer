#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char name[20];
	int birth;
	int sex; // 0: nu, 1: nam
	union {
		char husband[20];
		char wife[20];
	}x;
}people;

main ()
{
	people p[100];
	int n;
	printf("Nhap so luong: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("%d: \n", i + 1);
		fflush(stdin);
		printf("name: ");
		gets(p[i].name);
		printf("sex (0 = nu, 1 = nam): ");
		scanf("%d", &p[i].sex);
		if(p[i].sex){
			printf("nhap ten vk: ");
			fflush(stdin);
			gets(p[i].x.wife);
		}
		else{
			printf("nhap ten ck: ");
			fflush(stdin);
			gets(p[i].x.husband);
		}
	}
	printf("ds vua nhap: \n");
	for(int i = 0; i < n; i++){
		printf("%d: \n", i + 1);
		printf("name: %s\n", p[i].name);
		if(p[i].sex){
			printf("sex = nam\n");
			printf("wife = %s", p[i].x.wife);
		}
		else{
			printf("sex = nu\n");
			printf("husband = %s", p[i].x.husband);
		}
	}
	return 0;
}
