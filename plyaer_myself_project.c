#include<stdio.h>
# include<string.h>
#include <stdlib.h>

typedef struct Player{
	int Jersey_No;
	char name[50];
	int runs;
	int wickets;
	int matches;
}Player;
void addhardcoded(Player p[] , int *pcount){
	p[0].Jersey_No = 10;
	strcpy(p[0].name, "Rohit");
	p[0].runs = 10000;
	p[0].wickets = 5;
	p[0].matches = 227;
	(*pcount)++;
	
	p[1].Jersey_No = 7;
	strcpy(p[1].name, "Dhoni");
	p[1].runs = 10773;
	p[1].wickets = 0;
	p[1].matches = 350;
	(*pcount)++;
	
	p[2].Jersey_No = 18;
	strcpy(p[2].name, "Virat");
	p[2].runs = 12344;
	p[2].wickets = 4;
	p[2].matches = 262;
	(*pcount)++;
	
	p[3].Jersey_No = 15;
	strcpy(p[3].name, "Hardik");
	p[3].runs = 1500;
	p[3].wickets = 45;
	p[3].matches = 75;
	(*pcount)++;
	
	p[4].Jersey_No = 33;
	strcpy(p[4].name, "Ravindra");
	p[4].runs = 2400;
	p[4].wickets = 250;
	p[4].matches = 175;
	(*pcount)++;
	
	p[5].Jersey_No = 28;
	strcpy(p[5].name, "KL");
	p[5].runs = 2300;
	p[5].wickets = 0;
	p[5].matches = 45;
	(*pcount)++;
	
	p[6].Jersey_No = 77;
	strcpy(p[6].name, "Shreyas Iyer");
	p[6].runs = 1500;
	p[6].wickets = 0;
	p[6].matches = 50;
	(*pcount)++;
	
	p[7].Jersey_No = 9;
	strcpy(p[7].name, "Shikhar");
	p[7].runs = 6200;
	p[7].wickets = 0;
	p[7].matches = 165;
	(*pcount)++;
	
	p[8].Jersey_No = 27;
	strcpy(p[8].name, "Jasprit");
	p[8].runs = 250;
	p[8].wickets = 120;
	p[8].matches = 67;
	(*pcount)++;
	
	p[9].Jersey_No = 8;
	strcpy(p[9].name, "Bhuvneshwar");
	p[9].runs = 1000;
	p[9].wickets = 150;
	p[9].matches = 138;
	(*pcount)++;
}


void addplayer(Player p[] ,int *pcount, int *Max_player){
	int i,addp;
	char ch[5];
	Player *tempp;
	if(*pcount >= *Max_player){
		printf("\n______ ... PLAYER SYSTEM IS FULL ... ______\n");
		printf("\n DO YOU WANT TO ADD MORE PLAYERS? (YES/NO) : ");
		scanf("%s",&ch);
		int r1=strcmp(ch,"Yes");
		int r2=strcmp(ch,"YES");
		int r3=strcmp(ch,"Y");
		int r4=strcmp(ch,"y");

		if(r1==0 || r2==0 || r3==0 || r4==0){
			printf("HOW MANY PLAYER YOU WANT TO ADD : ");
			scanf("%d",&addp);
			tempp = (Player*)realloc(p , (*Max_player + addp) * sizeof(Player));
			
			if (tempp != NULL) {
			p=tempp;
			*Max_player=*Max_player+addp;
			printf("\n______PLAYER SYSTEM IS UPDATED______\n\n");
			}
		}
	else{
		printf("\n______USER DO NOT WANT TO ADD MORE PLAYERS______\n\n");
	}
	}
	if(*pcount < *Max_player){
		printf("ENTER JERSEY NUMBER OF PLAYER           : ");
		scanf("%d",&p[*pcount].Jersey_No);
		printf("ENTER NAME OF PLAYER                    : ");
		scanf("%s",&p[*pcount].name);
		printf("ENTER RUNS OF PLAYER                    : ");
		scanf("%d",&p[*pcount].runs);
		printf("ENTER WICKETS OF PLAYER                 : ");
		scanf("%d",&p[*pcount].wickets);
		printf("ENTER NUMBER OF MACHES PLAYED BY PLAYER : ");
		scanf("%d",&p[*pcount].matches);
		
		(*pcount)++;
		printf("\n______PLAYER ADDED IN SYSTEM SUCCESSFULLY______\n\n");	
	}
}

void removeplayer(Player p[] , int *pcount){
	int jersey_Num,i,j;
	int jn=0;
	if(*pcount == 0){
		printf("\n______SYSTEM IS EMPTY...NO PLAYER INFORMATION IN SYSTEM______\n");
	}
	printf("\nENTER JERSEY NUMBER OF PLAYER YOU WANT TO REMOVE FROM SYSTEM : ");
	scanf("%d",&jersey_Num);	
	
	for(i=0 ; i< *pcount ;i++){
		if(p[i].Jersey_No == jersey_Num){
			jn=1;
			for(j=i;j<*pcount-1;j++){
			p[j] = p[j+1];
			}
			(*pcount)--;
			printf("\n______PLAYER REMOVED FROM SYSTEM SUCCESSFULLY______\n\n");
		}
	}
	if(jn==0){
		printf("\n______PLAYER WITH JERSEY NUMBER %d NOT FOUND IN SYSTEM______\n",jersey_Num);
	}
}


void searchplayer(Player p[],int *pcount){
	int i,ch,jersey_no,r;
	char name_p[100];

	printf("\nENTER YOUR CHOICE 1 OR 2 ON WHICH YOU WANT TO SEARCH A PLAYER IN SYSTEM\n1.JERSEY NUMBER OF PLAYER\n2.NAME OF PLAYER");
	printf("\n______ENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	int f=0;
	if(ch == 1){
		printf("\nENTER JERSEY NUMBER OF PLAYER TO BE SEARCHED : ");
		scanf("%d",&jersey_no);
		for(i=0;i<*pcount;i++){
			if(p[i].Jersey_No==jersey_no){
			f++;
			break;
			}
		}
		if(f==1){
			printf("\n______PLAYER WITH JERSEY NUMBER %d IS FOUND______\n",jersey_no);
			printf("\nJERSEY NUMBER : %d\nNAME          : %s\nRUNS          : %d\nWICKETS       : %d\nMATCHES       : %d \n\n",p[i].Jersey_No,p[i].name,p[i].runs,p[i].wickets,p[i].matches);
		}
		else{
				printf("\n______PLAYER WITH JERSEY NUMBER %d IS NOT FOUND IN SYSTEM______\n\n",jersey_no);
		}
	}
	
	else if(ch == 2){
		printf("\nENTER NAME OF PLAYER TO BE SEARCHED : ");
		scanf("%s",&name_p);
		int fn=0;
		for(i=0;i<*pcount; i++){
			if(strcasecmp(p[i].name,name_p)==0){
				fn=1;
				break;
			}
		}
		if(fn==1){
			printf("\n______PLAYER WITH NAME %s IS FOUND______\n",name_p);
			printf("\nNAME          : %s\nJERSEY NUMBER : %d\nRUNS          : %d\nWICKETS       : %d\nMATCHES       : %d \n\n",p[i].name,p[i].Jersey_No,p[i].runs,p[i].wickets,p[i].matches);

			}
		else{
			printf("\n______PLAYER WITH NAME %s IS NOT FOUND IN SYSTEM______\n\n",name_p);
		}
 	}
}

void updateplayer(Player p[] ,int pcount){
	int jersey_no,i,f=0;
		printf("\nENTER JERSEY NUMBER OF PLAYER TO BE UPDATED : ");
		scanf("%d",&jersey_no);
		for(i=0;i<pcount;i++){
			if(p[i].Jersey_No==jersey_no){
				f=1;
				break;
			}
		}
		if(f==1){
			printf("\n______PLAYER WITH JERSEY NUMBER %d IS FOUND______\n\n",jersey_no);
			printf("ENTER NEW RUNS OF PLAYER         : ");
			scanf("%d",&p[i].runs);
			printf("ENTER NEW WICKETS OF PLAYER      : ");
			scanf("%d",&p[i].wickets);
			printf("ENTER NEW MATCHES OF PLAYER      : "); 
			scanf("%d",&p[i].matches);
			printf("\n______PLAYER WITH JERSEY NUMBER %d IS UPDATED SUCCESSFULLY IN A SYSTEM______\n\n",jersey_no);
		}
		if(f==0){
			printf("\n______PLAYER WITH JERSEY NUMBER %d IS NOT FOUND IN SYSTEM______\n\n",jersey_no);
		}
}


void displaysortedplayer(Player p [], int pcount){
	int i,j,ch;
	Player temp;
	//For runs
	printf("\nENTER YOUR CHOICE 1 OR 2 ON WHICH YOU WANT TO SORT A PLAYER IN SYSTEM\n1.ON BASIS OF RUNS\n2.ON BASIS OF WICKETS");
	printf("\n______ENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	if(ch == 1){
	printf("\nENTER YOUR CHOICE 1 OR 2 ON WHICH YOU WANT TO SORT MAXIMUM/MINIMUM RUNS OF A PLAYER IN SYSTEM\n1.MAXIMUM RUNS\n2.MINIMUM RUNS");
	printf("\n______ENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	if(ch == 1){
		for(i=0;i<pcount-1;i++){
			for(j=0;j<pcount-i-1;j++){
				if(p[j].runs<p[j+1].runs){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}
			}
		}
	printf("\n______SORTED PLAYERS LIST BASED ON MAXIMUM RUNS______\n\n");
	for(i=0;i<pcount;i++){
		printf("\nINFORMATION OF PLAYER : %d\n",i+1);
		printf("RUNS          : %d\nWICKETS       : %d\nMATCHES       : %d\nNAME          : %s\nJERSEY NUMBER : %d\n \n\n",p[i].runs,p[i].wickets,p[i].matches,p[i].name,p[i].Jersey_No);
		}
	}
	if(ch == 2){
		for(i=0;i<pcount-1;i++){
			for(j=0;j<pcount-i-1;j++){
				if(p[j].runs>p[j+1].runs){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}
			}
		}
	printf("\n______SORTED PLAYERS LIST BASED ON MINIMUM RUNS______\n\n");
	for(i=0;i<pcount;i++){
		printf("\nINFORMATION OF PLAYER : %d\n",i+1);
		printf("RUNS          : %d\nWICKETS       : %d\nMATCHES       : %d\nNAME          : %s\nJERSEY NUMBER : %d\n \n\n",p[i].runs,p[i].wickets,p[i].matches,p[i].name,p[i].Jersey_No);
		}
	}
  }
  
  
  //for wickets
  	else if(ch == 2){
	printf("\nENTER YOUR CHOICE 1 OR 2 ON WHICH YOU WANT TO SORT MAXIMUM/MINIMUM WICKETS OF A PLAYER IN SYSTEM\n1.MAXIMUM WICKETS\n2.MINIMUM WICKETS");
	printf("\n______ENTER YOUR CHOICE : ");
	scanf("%d",&ch);
	if(ch == 1){
		for(i=0;i<pcount-1;i++){
			for(j=0;j<pcount-i-1;j++){
				if(p[j].wickets<p[j+1].wickets){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}
			}
		}
	printf("\n______SORTED PLAYERS LIST BASED ON MAXIMUM WICKETS______\n\n");
	for(i=0;i<pcount;i++){
		printf("\nINFORMATION OF PLAYER : %d\n",i+1);
		printf("WICKETS       : %d\nRUNS          : %d\nMATCHES       : %d\nNAME          : %s\nJERSEY NUMBER : %d\n \n\n",p[i].wickets,p[i].runs,p[i].matches,p[i].name,p[i].Jersey_No);
		}
	}
	if(ch == 2){
		for(i=0;i<pcount-1;i++){
			for(j=0;j<pcount-i-1;j++){
				if(p[j].wickets>p[j+1].wickets){
					temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}
			}
		}
	printf("\n______SORTED PLAYERS LIST BASED ON MINIMUM WICKETS______\n\n");
	for(i=0;i<pcount;i++){
		printf("\nINFORMATION OF PLAYER : %d\n",i+1);
		printf("WICKETS       : %d\nRUNS          : %d\nMATCHES       : %d\nNAME          : %s\nJERSEY NUMBER : %d\n \n\n",p[i].wickets,p[i].runs,p[i].matches,p[i].name,p[i].Jersey_No);
		}
	}
  }
}

void displayallplayers(Player p[] ,int pcount){
	if(pcount==0){
		printf("\n\n______NO PLAYER IN SYSTEM______\n");
	}
	int i;
	for(i=0;i< pcount; i++){
		printf("\nINFORMATION OF PLAYER : %d\n",i+1);
		printf("NAME          : %s\nJERSEY NUMBER : %d\nRUNS          : %d\nWICKETS       : %d\nMATCHES       : %d \n\n",p[i].name,p[i].Jersey_No,p[i].runs,p[i].wickets,p[i].matches);
	}
}


void main(){
	int Max_player;
	printf("HOW MANY PLAYERS YOU WANT TO ADD : ");
	scanf("%d",&Max_player);
	Player* p = (Player*)malloc(sizeof(Player) * Max_player);	
	int pcount=0;
	int choice;
	addhardcoded(p , &pcount);
	do{
		printf("__________PLAYER MANAGEMENT SYSTEM__________\n");
		printf("\n1.ADD PLAYER ...");
		printf("\n2.REMOVE PLAYER ...");
		printf("\n3.SEARCH PLAYER ...");
		printf("\n4.UPDATE PLAYER ...");
		printf("\n5.DISPLAY SORTED PLAYERS ...");
		printf("\n6.DISPLAY PLAYERS ...");
		printf("\n7.EXIT FROM SYSTEM ...");
		printf("\nENTER YOUR CHOICE : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				addplayer(p , &pcount,&Max_player);
				break;
			case 2:
				removeplayer(p , &pcount);
				break;
			case 3:
				searchplayer(p , &pcount);
				break;
			case 4:
				updateplayer(p , pcount);
				break;
			case 5:
				displaysortedplayer(p , pcount);
				break;
			case 6:
				displayallplayers(p , pcount);
				break;
			case 7:
				printf(".....EXITED FROM SYSTEM.....\n");
                break;
            default:
            	printf("INVALID CHOICE...PLEASE ENTER VALID CHOICE FROM 1 TO 7...");
            	break;
		}
	}while(choice!=7);
}

