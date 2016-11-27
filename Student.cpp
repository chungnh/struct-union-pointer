#include<stdio.h>
#include<stdlib.h>
struct student{
	int id;
	char name[20];
	float math;
	float chem;
	float phys;
	void nhap(int id, char name[], float math, float phys, float chem);
	void xuat();
};

void student::nhap(int id1, char name1[], float math1, float phys1, float chem1){
	id = id1;
	name[20] = name1[20];
	math = math1;
	phys = phys1;
	chem = chem1;
}

void nhap(int n2, int n, struct student *st){
	for(int i = n2; i < n; i++){
		printf("Nhap thong tin cua sv thu %d\n", i+1);
		printf("id: ");
		scanf("%d", &st[i].id);
		printf("name: ");
		fflush(stdin);
		gets(st[i].name);
		printf("math: ");
		scanf("%f", &st[i].math);
		printf("phys: ");
		scanf("%f", &st[i].phys);
		printf("chem: ");
		scanf("%f", &st[i].chem);
	}
}

bool checkID(int id, int n, struct student *st){
	for(int i = 0; i < n; i++){
		if(st[i].id == id){
			return 1;
		}
	}
	return 0;
}

void writeFile(int id, char name[], float math, float phys, float chem){//in ra file
	FILE *f;
	f = fopen("output.txt", "a");
	fprintf(f, "%d\t%s\t%.2f\t%.2f\t%.2f\n", id, name, math, phys, chem);
	fclose(f);
}

void readFile(){
	struct student *tem = (struct student*) malloc(1000*sizeof(struct student));
	FILE *f;
	f = fopen("output.txt", "r");
	int id;
	char name[20];
	float math, chem, phys;
	char line[50];
	while(!feof(f)){
		char buff[50];
		fscanf(f, "%s", buff);
		printf("%s\n", buff);
	}
}

void sort(int n,struct student *st){
	struct student tem;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(st[i].id > st[j].id){
				tem = st[i];
				st[i] = st[j];
				st[j] = tem;
			}
		}
	}
}

void edit(int n, struct student *st){
	printf("Enter ID: ");
	int id;
	scanf("%d", &id);
	int k = 0;
	for(int i = 0; i < n; i++){
		if(st[i].id == id){
			k = 1;
			printf("Enter new infor: \n");
			printf("name: ");
			fflush(stdin);
			gets(st[i].name);
			printf("math: ");
			scanf("%f", &st[i].math);
			printf("phys: ");
			scanf("%f", &st[i].phys);
			printf("chem: ");
			scanf("%f", &st[i].chem);
		}
	}
	if(k == 0){
		printf("Not found\n");
	}
}

void del1(int i, int &n, struct student *st){
	for(int j = i; j < n; j++){
		st[j] = st[j + 1];				
	}
}

void del(int &n, struct student *st){
	printf("Enter ID: ");
	int id;
	scanf("%d", &id);
	int k = 0;
	int f;
	for(int i = 0; i < n; i++){
		if(st[i].id == id){
			k = 1;			
			n--;
			del1(i, n, st);
		}
	}
	if(k == 0){
		printf("Not found\n");
	}
}

main(){
	int n;
	printf("Nhap so sv: ");
	scanf("%d", &n);
	struct student *st = (struct student*) malloc(n*sizeof(struct student));	
	nhap(0, n, st);
	int k;
	while(1){
		printf("Moi chon chuc nang: \n");
		printf("0. Nhap\n");
		printf("1. Sort by ID\n");
		printf("2. Edit\n");
		printf("3. Delete\n");
		scanf("%d", &k);
		struct student *temp = (struct student*) malloc(n*sizeof(struct student));//tao 1 ban sao cua st[]
		for(int i = 0; i < n; i++){
					temp[i] = st[i];
				}
		switch(k){
			case 0:									
				printf("nhap so sv: ");
				int n2;
				scanf("%d", &n2);
				n += n2;
				st = (struct student*) realloc(st, n*sizeof(struct student));
				for(int i = 0; i < n - n2; i++){
					st[i] = temp[i];
				}
				nhap(n - n2, n, st);
				break;
			case 1:
				sort(n, st);
				break;
			case 2:
				edit(n, st);
				break;
			case 3:
				del(n, st);
				break;
		}
		for(int i = 0; i < n; i++){
		printf("ID: %d\n", st[i].id);
		printf("NAME: %s\n", st[i].name);
		printf("MATH: %f\n", st[i].math);
		printf("PHYS: %f\n", st[i].phys);
		printf("CHEM: %f\n", st[i].chem);
	}
	}
//	for(int i = 0; i < n; i++){
//		writeFile(st[i].id, st[i].name, st[i].math, st[i].phys,st[i].chem);
//	}
	//readFile();
}
