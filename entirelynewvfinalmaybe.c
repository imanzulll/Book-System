#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


//functions
void returnfunc(void);
void mainMenu(void);

void staffArea(void);
void customerArea(void);

void addrecord(void);
void deleterecord(void);
void searchrecord(void);
void viewrecord(void);

void custDisplayBook();
void custSearch(void);
void addtoCart(int n,int b,int i);
void displayCart(void);


void SortName();
void SortPrice();
void SortBookID();
void displaySortName(int);
void displaySortPrice(int);
void displaySortBookID(int);
void checkout();
void thankyou();
int fileOptoArray();
void auth(char []);

int getdata();
int checkid(int c);
//
//structs
struct bookInfo{ //fileop
	int id;
	char name[255];
	char author[255];
	float price;

};struct bookInfo b;

struct bookInfo2{ //array
	int id;
	char name[255];
	char author[255];
	float price;

}temp;
struct bookInfo2 book[255];

struct payment{
	float total;
};struct payment payment;

struct cart{
	int bookqty;	
	struct bookInfo2 bookk;
};struct cart cart[255];


struct customerInfo
{
    char name[255];
    char gender[15];
    char phoneNum[30];
    char address[255];
    //int age;
   // int bookTotal;
   // float total;
    struct cart crt[255];

};struct customerInfo cst;


//

//variables
FILE *fp,*ft,*dp,*dt;
int tBook;
char findrecord;
char searchcust;
int indArr=0;
int bookTypeCount;
int bookTotal;
int bookOrdered;
char password[255] = "admin404";
//


int main(){
	system("cls");
	fileOptoArray();
	mainMenu();
	return 0;
}


void mainMenu(void){
	system("cls");
	//initialization
	char choice;
	//Main Menu
	while (1){

	printf("======================================================================================\n");
	printf("                            Welcome to Online Book Shopping                           \n");
	printf("======================================================================================\n");
		printf("\n\t\t\t1) STAFF AREA");
		printf("\n\t\t\t2) CUSTOMER AREA");
		printf("\n\t\t\t3) EXIT");
		printf("\n\nEnter your choice : \t");
		scanf("%d",&choice);
		//switch cases
		switch(choice){
			//search book
			case 1: {
				system("cls");
				fflush(stdin);
				char passreq[255];
				printf("\n\n\n\t\t\tEnter password to access staff area\n\n\t\t\t\tPassword : ");
				gets(passreq);
				auth(passreq);
				//staffArea();
				break;
			}
			//Customer Area ( Search Book)
			case 2: {
                customerArea();
				break;
			}
			//checkout
			case 3: {
				printf("\n\n \t\t\t Thank You! ");
				exit(1);
			
				break;
			}

			default:{
				printf("\n\n\t\t\tPlease enter the valid choice!\n");
				printf("\t\t\t");system("pause");
				main();
				break;
				
			}
		}
	}
}

void auth(char password[255]){
	
	//check whether password input correct or not
	if(strcmp(password,"admin404")==0){
		staffArea();
	}else{
		printf("\n\n\n\t\t\t\tWrong password!\n \t\t\t");
		
		system("pause");
		mainMenu();
	}
}
void staffArea(void){
	system("cls");
	printf("======================================================================================\n");
	printf("                                      Staff Area                                      \n");
	printf("======================================================================================\n");
	printf("\n\t\t\t1) ADD BOOK RECORDS");
	printf("\n\t\t\t2) DELETE BOOK RECORDS");
	printf("\n\t\t\t3) SHOW ALL BOOK RECORDS");
	printf("\n\t\t\t4) SEARCH BOOK RECORDS");
	printf("\n\t\t\t5) BACK TO MAIN MENU");
	printf("\n\nEnter your choice : \t");
	int choose;
	scanf("%d",&choose);

	if(choose == 1){
		//addBook();
		addrecord();
	}else if(choose == 2){
	//	deletebookRecords();
		deleterecord();
	}else if(choose == 3){
        viewrecord();
	}else if(choose == 4){
		searchrecord();
	}else if(choose == 5){
		mainMenu();
	}else{
		printf("Wrong input!");
		staffArea();
	}


}

void customerArea(void){
	system("cls");
	printf("======================================================================================\n");
	printf("                                   Customer Area                                      \n");
	printf("======================================================================================\n");
	printf("\n\t\t\t1) SEARCH BOOK TO BUY"); //Display available books dulu then tanya ada yang berkenan ke dok, kalau ada boleh search
	printf("\n\t\t\t2) DISPLAY CART");
	printf("\n\t\t\t3) DISPLAY ALL BOOKS");
	printf("\n\t\t\t4) CHECKOUT");
	printf("\n\t\t\t5) BACK TO MAIN MENU");
	printf("\n\nEnter your choice : \t");
	int choice;
	scanf("%d",&choice);

	if(choice == 1){
		custSearch();
	}else if(choice == 2){
		displayCart();
	}else if(choice == 3){
        custDisplayBook();
	}else if(choice == 4){
		checkout();
	}else if(choice == 5){
		mainMenu();
	}else{
		printf("Wrong input!");
		customerArea();
	}


}

void checkout(){
	system("cls");
	printf("======================================================================================\n");
	printf("                                     CheckOut                                         \n");
	printf("======================================================================================\n");
	printf("\n \t\tTotal price : RM %.2f",payment.total);
	printf("\n \t\tTotal book  :    %d\n\n\n",bookOrdered);
	printf("Proceed with checkout?(y/n) : ");char yesNo;scanf("%c",&yesNo);
	fflush(stdin);
		if(yesNo=='y' || yesNo=='Y'){
		
			printf("\n\n\nPlease insert your details.\n\n");
			printf("Customer Name                : ");scanf("%s",cst.name);
			printf("Customer Gender (Male/Female): ");scanf("%s",cst.gender);
			printf("Customer Phone Num.          : ");scanf("%s",cst.phoneNum);
			printf("Customer Address             : ");scanf("%s",cst.address);
			
			thankyou();
		}else if(yesNo == 'n' || yesNo == 'N'){
			printf("Press any key to go back to customer area. ");getch();
			customerArea();
		}else{
			printf("Yes or No only!");
			checkout();
		}
		
}

void thankyou(){
	printf("\n\n\t\t\t>>>>>Thank You for Buying With Us!<<<<<\n");
	printf("\n\n\t\t\t\t>>>See you again!!<<<\n");
	exit(1);
}
void custDisplayBook(){
	system("cls");
	bookTotal = fileOptoArray();
	int x;
	printf("======================================================================================\n");
	printf("                                   Book Records                                      \n");
	printf("======================================================================================\n");
	printf("\tBook ID\t\tBook Name\t\t\t\tBook Author\t\tPrice (RM)     \n");
   	
    for(x=0;x<bookTotal;x++)
    {
		
		printf("\n");
		printf("\t%d",book[x].id);
		printf("\t\t%-20s",book[x].name);
		printf("\t\t\t%-20s",book[x].author);
		printf("\t%-10.2f",book[x].price);

	}

	
	
	printf("\n\n\t\t\t\t\t\t\t\t\tTotal Books : %d",bookTotal);
	printf("\n\t1.	Sort By Ascending Name");
	printf("\n\t2.	Sort By Ascending Price");
	printf("\n\t3.	Sort By Ascending Book ID");
	printf("\n\t4.	Back to Customer Area");
	int pilih;printf("\n\nChoose your action : ");scanf("%d",&pilih);
	
	if(pilih == 1){
		SortName();
	}else if(pilih == 2){
		SortPrice();
	}else if(pilih == 3){
		SortBookID();
	}else if(pilih == 4){
		customerArea();
	}else{
		printf("\n\n\t\tWrong input! Please check.");
		custDisplayBook();
	}
    //getch();
    //SortName();
    
}

void SortName(){
 int i,n,j;
 n=bookTotal;
 for (i = 1; i < n; i++){
 	for (j = 0; j < n - i; j++) {
         if (strcmp(book[j].name, book[j + 1].name) > 0) {
            temp = book[j];
            book[j] = book[j + 1];
            book[j + 1] = temp;
         }
      }
 }
	displaySortName(n);
}

void displaySortName(int n){
	system("cls");
	printf("======================================================================================\n");
	printf("                                Book Records Sorted By Name                                      \n");
	printf("======================================================================================\n");
	printf("\tBook ID\t\tBook Name\t\t\t\tBook Author\t\tPrice (RM)     \n");
 	for (int i = 0; i < n; i++) {
 		
 			printf("\n");
			printf("\t%d",book[i].id);
			printf("\t\t%-20s",book[i].name);
			printf("\t\t\t%-20s",book[i].author);
			printf("\t%-10.2f",book[i].price);
      		//printf("\n%s\t%d\t%f",book[i].name,book[i].id,book[i].price);
   		}
 	//getch();
 	printf("\n\n\t\t\t\t\t\t\t\t\tTotal Books : %d",bookTotal);
	printf("\n\t1.	Sort By Ascending Name");
	printf("\n\t2.	Sort By Ascending Price");
	printf("\n\t3.	Sort By Ascending Book ID");
	printf("\n\t4.	Back to Customer Area");
	int pilih;printf("\n\nChoose your action : ");scanf("%d",&pilih);
	
	if(pilih == 1){
		SortName();
	}else if(pilih == 2){
		SortPrice();
	}else if(pilih == 3){
		SortBookID();
	}else if(pilih == 4){
		customerArea();
	}else{
		printf("\n\n\t\tWrong input! Please check.");
		custDisplayBook();
	}
	
}

void SortPrice(){
 int i,n,j;
 n=bookTotal;
 for (i = 1; i < n; i++){
 	for (j = 0; j < n - i; j++) {
         if (book[j].price > book[j + 1].price) {
            temp = book[j];
            book[j] = book[j + 1];
            book[j + 1] = temp;
         }
      }
 }
	displaySortPrice(n);
}

void displaySortPrice(int n){
	system("cls");
	printf("======================================================================================\n");
	printf("                           Book Records Sorted By Price                                    \n");
	printf("======================================================================================\n");
	printf("\tBook ID\t\tBook Name\t\t\t\tBook Author\t\tPrice (RM)     \n");
 	for (int i = 0; i < n; i++) {
 		
 			printf("\n");
			printf("\t%d",book[i].id);
			printf("\t\t%-20s",book[i].name);
			printf("\t\t\t%-20s",book[i].author);
			printf("\t%-10.2f",book[i].price);
      		//printf("\n%s\t%d\t%f",book[i].name,book[i].id,book[i].price);
   		}
 	//getch();
 	printf("\n\n\t\t\t\t\t\t\t\t\tTotal Books : %d",bookTotal);
	printf("\n\t1.	Sort By Ascending Name");
	printf("\n\t2.	Sort By Ascending Price");
	printf("\n\t3.	Sort By Ascending Book ID");
	printf("\n\t4.	Back to Customer Area");
	int pilih;printf("\n\nChoose your action : ");scanf("%d",&pilih);
	
	if(pilih == 1){
		SortName();
	}else if(pilih == 2){
		SortPrice();
	}else if(pilih == 3){
		SortBookID();
	}else if(pilih == 4){
		customerArea();
	}else{
		printf("\n\n\t\tWrong input! Please check.");
		custDisplayBook();
	}
	
}

void SortBookID(){
 int i,n,j;
 n=bookTotal;
 for (i = 1; i < n; i++){
 	for (j = 0; j < n - i; j++) {
         if (book[j].id > book[j + 1].id) {
            temp = book[j];
            book[j] = book[j + 1];
            book[j + 1] = temp;
         }
      }
 }
	displaySortBookID(n);	
}

void displaySortBookID(int n){
	system("cls");
	printf("======================================================================================\n");
	printf("                              Book Records Sorted by ID                                      \n");
	printf("======================================================================================\n");
	printf("\tBook ID\t\tBook Name\t\t\t\tBook Author\t\tPrice (RM)     \n");
 	for (int i = 0; i < n; i++) {
 		
 			printf("\n");
			printf("\t%d",book[i].id);
			printf("\t\t%-20s",book[i].name);
			printf("\t\t\t%-20s",book[i].author);
			printf("\t%-10.2f",book[i].price);
      		//printf("\n%s\t%d\t%f",book[i].name,book[i].id,book[i].price);
   		}
 	//getch()
	printf("\n\n\t\t\t\t\t\t\t\t\tTotal Books : %d",bookTotal);
	printf("\n\t1.	Sort By Ascending Name");
	printf("\n\t2.	Sort By Ascending Price");
	printf("\n\t3.	Sort By Ascending Book ID");
	printf("\n\t4.	Back to Customer Area");
	int pilih;printf("\n\nChoose your action : ");scanf("%d",&pilih);
	
	if(pilih == 1){
		SortName();
	}else if(pilih == 2){
		SortPrice();
	}else if(pilih == 3){
		SortBookID();
	}else if(pilih == 4){
		customerArea();
	}else{
		printf("\n\n\t\tWrong input! Please check.");
		custDisplayBook();
	};
		
}
void addrecord(void){
	system("cls");
	fp=fopen("records.dat","a+");
	if(getdata()==1)
	{
		fseek(fp,0,SEEK_END);
		fwrite(&b,sizeof(b),1,fp);
		fclose(fp);
		printf("\n\n");
		printf("The Record Is Successfully Saved ! !\n\n");
		printf("Add any more?(Y / N): ");
		if(getch()=='n')
	    	staffArea();
		else
	    	system("cls");
	    	addrecord();
	}
}

int getdata()
{
	printf("======================================================================================\n");
	printf("                                Add Book Records                                   \n");
	printf("======================================================================================\n");
	printf("\n        Book ID :\t");
	scanf("%d",&tBook);
	if(checkid(tBook)==0)
	{
		printf("\n\n");
		printf("\a                         Record Already Exists !!!\a");
		returnfunc();
		//getch();
		//staffArea();
		return 0;
	}
	b.id=tBook;
	printf("        Book Name :\t");
	scanf(" %[^\n]",&b.name);
	printf("        Book Author :\t");
	scanf(" %[^\n]",&b.author);
	printf("        Book Price :\t");
	scanf("%f",&b.price);

	return 1;
}

int checkid(int c)  //check whether the record is exist in list or not
{
	rewind(fp);
	while(fread(&b,sizeof(b),1,fp)==1){

	}

	if(b.id == tBook){
			return 0;
	}else{
			return 1;
	}
}

void viewrecord(void){
	system("cls");
    printf("======================================================================================\n");
	printf("                                      Book Records                                      \n");
	printf("======================================================================================\n");
	printf("\tBook ID\t\tBook Name\t\t\t\tBook Author\t\tPrice (RM)     \n");
    fp=fopen("records.dat","r");
    while(fread(&b,sizeof(b),1,fp)==1)
    {

		printf("\n");
		printf("\t%d",b.id);
		printf("\t\t%-20s",b.name);
		printf("\t\t\t%-20s",b.author);
		printf("\t%-10.2f",b.price);

	}

	
	bookTotal = fileOptoArray();
	printf("\n\n\t\t\t\t\t\t\t\t\tTotal Books : %d",bookTotal);
    fclose(fp);
    returnfunc();
}



void returnfunc(void)
{
    {
		printf("\n\n\n\n Press ENTER to return to main menu");
    }
    b:
    if(getch()==13) //allow only use of enter
    staffArea();
    else
    goto b;
}


void deleterecord(void){
	system("cls");
    int d;
    findrecord = 'x';
    char another='y';
    while(another=='y')  //infinite loop
    {
	system("cls");
	printf("======================================================================================\n");
	printf("                               Delete Book Records                                   \n");
	printf("======================================================================================\n");
	printf(" \n               Enter book ID to delete : ");
	scanf(" %d",&d);
	fp=fopen("records.dat","r+");
	rewind(fp);
	while(fread(&b,sizeof(b),1,fp)==1)
	{
	    if(b.id==d)
	    {
			printf("\n\n");
			printf("               .....................Book record is available....................\n\n");
			printf("               Book ID     :  %d\n",b.id);
			printf("               Book Name   :  %s\n",b.name);
			printf("               Book Author :  %s\n",b.author);
			printf("               Book Price  :  RM%.2f\n",b.price);
			findrecord='t';
	    }
	}
	if(findrecord!='t')
	{
		printf("\n\n");
	    printf("                   .........................No record is found..........................\n\n");
	   	returnfunc();
	    //if(getch())
	    //staffArea();
	}
	if(findrecord=='t' )
	{
	    printf("\nDo You Want To Delete The Record ? (Y/N) ");
	    if(getch()=='y')
	    {
			ft=fopen("tempData.dat","w+");  //temporary file for delete
			rewind(fp);
			while(fread(&b,sizeof(b),1,fp)==1)
			{
		    	if(b.id!=d)
		    	{
					fseek(ft,0,SEEK_CUR);
					fwrite(&b,sizeof(b),1,ft); //write all in tempory file except that
		    	}                              //we want to delete
			}
			fclose(ft);
			fclose(fp);
			fp = fopen("records.dat","w");
			ft = fopen("tempData.dat","r");
			while(fread(&b,sizeof(b),1,ft)){ //read temp data
				fwrite(&b,sizeof(b),1,fp); //write temp contents into records
			}
			printf("\n\n\n                .........................Record successfully deleted..........................\n");
			printf("\n                                         Press any Key to Continue");
			fclose(ft);
			fclose(fp);

			/**fp=fopen("records.dat","r");    //we want to delete
			if(findrecord=='t')
			{
		    	printf("        THE RECORD IS SUCCESSFULLY DELETED.\n\n");
		    	printf("        Delete Another Record ? (Y/N) : ");
			}**/

		}
		else
		staffArea();
		fflush(stdin);
		another=getch();
	}
	fclose(ft);
	fclose(fp);
}
staffArea();
}

void custSearch(void) //cust search by file operation
{
    system("cls");
    bookTotal = fileOptoArray();
	int search=0;char choice;int inc;
	printf("======================================================================================\n");
	printf("                                   Search For Available Books                         \n");
	printf("======================================================================================\n");
	printf("\n                  1. Search By ID\n");
    printf("                  2. Search By Name\n");
    printf("                  3. Search By Author\n");
    printf("                  4. Return To Customer Area\n\n");
    printf("                  Enter Your Choice :\t ");scanf(" %c",&choice);
    //fp=fopen("records.dat","r"); //open file for reading purpose
    //rewind(fp);   //move pointer at the begining of file
    switch(choice)
    {
	  case '1':
		{
	    	system("cls");
			printf("======================================================================================\n");
			printf("                                Search Books by ID                                    \n");
			printf("======================================================================================\n");
	    	printf("                Enter The Book ID : ");
	    	scanf(" %d",&search);
	    	printf("\n\n");
	    	int i;int searchV=0;
			//printf("Searching........");
	    	for(i=0;i<255;i++){
	    		if(book[i].id == search){
	    			searchV = 1;
	    			printf("		The Record is available.\n\n\n");
					printf("		ID   : \t%d\n",book[i].id);
					printf("		Name :\t%s\n",book[i].name);
					printf("		Author:\t%s\n",book[i].author);
					printf("		Price:\tRM%.2f\n",book[i].price);
					
					printf("\n	Add to cart?(y/n)  ");
						if(getch()=='y'){
							
							bookTypeCount++;
							int qty;
							printf("\n	How many?  ");scanf("%d",&qty);
							bookOrdered = bookOrdered + qty;
							addtoCart(inc,qty,i);
							//inc++;
							
							custSearch();
						}else{
							custSearch();
						}
					break;
					
				}else{
					searchV =0;
				}	inc++;
			
			}
			if(searchV == 0){
				printf("\nNo Book found with that ID. Please check your search.\n");getch();
				
				custSearch();
			}
	    	
	    	
	    break;
	}
	case '2':
	{
	    char title[255];
	    system("cls");
			printf("======================================================================================\n");
			printf("                                Search Books by Title                                   \n");
			printf("======================================================================================\n");
	    	printf("               Enter Book Title : ");
	   	fflush(stdin);
	    scanf(" %[^\n]",title);
	    int search=0;
	  	int i;
			//printf("Searching........");
	    	for(i=0;i<255;i++){
	    		if(strcmp(book[i].name, title)==0){
	    			search = 1;
	    			printf("		The Record is available.\n\n\n");
					printf("		ID   : \t%d\n",book[i].id);
					printf("		Name :\t%s\n",book[i].name);
					printf("		Author:\t%s\n",book[i].author);
					printf("		Price:\tRM%.2f\n",book[i].price);
					
					printf("	Add to cart?(y/n)  \n");
						if(getch()=='y'){
							bookTypeCount++;
							int qty;
							printf("	How many?  ");scanf("%d",&qty);
							bookOrdered = bookOrdered + qty;
							addtoCart(inc,qty,i);
							//inc++;
							custSearch();
						}else{
							custSearch();
						}
					
					
					}else{
						search = 0;
					}	inc++;
				
				
			}
			if(search == 0){
				printf("\nNo Book found with that title. Please check your search.\n");getch();
				custSearch();
			}
		
		break;
	}
	case '3':
    {
        char author[255];
	    system("cls");
			printf("======================================================================================\n");
			printf("                                Search Books by Author                                \n");
			printf("======================================================================================\n");
	   		printf("               Enter Book Author : ");
	   	fflush(stdin);
	    scanf(" %[^\n]",author);
	    int search=0;
	  	int i;
			//printf("Searching........");
	    	for(i=0;i<255;i++){
	    		if(strcmp(book[i].author, author)==0){
	    			search = 1;
	    			printf("		The Record is available.\n\n\n");
					printf("		ID   : \t%d\n",book[i].id);
					printf("		Name :\t%s\n",book[i].name);
					printf("		Author:\t%s\n",book[i].author);
					printf("		Price:\tRM%.2f\n",book[i].price);
					
					printf("	Add to cart?(y/n)  \n");
						if(getch()=='y'){
							bookTypeCount++;
							int qty;
							printf("	How many?  ");scanf("%d",&qty);
							bookOrdered = bookOrdered + qty;
							addtoCart(inc,qty,i);
							//inc++;
							custSearch();
						}else{
							custSearch();
						}
					
					
					}else{
						search = 0;
					}	inc++;
				
				
			}
			if(search == 0){
				printf("\nNo Book found with that author. Please check your search.\n");getch();
				custSearch();
			}
		
		break;
    }
    case '4':
    {
        customerArea();
    }
	default :
	getch();
	custSearch();
    }

    //fclose(fp);

}
void addtoCart(int n,int b,int i)
{
	bookTotal = fileOptoArray();
	cart[n].bookk.id = book[i].id;
	
	//cart[n].bookk.name[255] = book[i].name[255];
	//cart[n].bookk.author[255] = book[i].author[255];
	
	strcpy(cart[n].bookk.name,book[i].name);
	strcpy(cart[n].bookk.author,book[i].author);
	
	cart[n].bookk.price = book[i].price;
	
	payment.total =(payment.total + (book[i].price * b));
	
	cart[n].bookqty = cart[n].bookqty + b;
	
		printf("\n\n\t\tPress any key to go back to customer area.\n");
		getch();
		customerArea();
	//printf("book id : %d",cart[n].bookk.id);
	//printf("n is %d",n);getch();
	
}

void displayCart(void) 
{
	//fflush(stdin);fflush(stdout);
	bookTotal = fileOptoArray();
	system("cls");
	int i;
	printf("==================================================================================================\n");
	printf("                                     Your Cart                                  \n");
	printf("==================================================================================================\n");
	printf("Book ID\t\tBook Name\t\t\tBook Author\t\tPrice (RM)\t Quantity     \n");
	int l;int check = NULL;
	
	for(i=0;i<255;i++){
//bookTypeCount	
				if(cart[i].bookk.id == 0){
					//printf("\nnull");
				
				}else{
					printf("\n");
					printf("%d",cart[i].bookk.id);
					printf("\t\t%-20s",cart[i].bookk.name);
					printf("\t\t%-20s",cart[i].bookk.author);
					printf("\t%-10.2f",cart[i].bookk.price);
					printf("\t%5d",cart[i].bookqty);

				}

				}

				
		
	
	printf("\n==================================================================================================\n");	
	printf("\n\t\t\t\t\t\t\t\tTotal price : RM %.2f",payment.total);
	printf("\n==================================================================================================\n");
	//system("cls");
	printf("\n\n\t\tPress any key to go back to customer area.");
	getch();
	customerArea();
	system("cls");
}


void searchrecord(void){
	system("cls");
	findrecord = 'x';
	int search;char choice;
	printf("======================================================================================\n");
	printf("                                    Search Books                                    \n");
	printf("======================================================================================\n");
	printf("                  1. Search By ID\n");
    printf("                  2. Search By Name\n");
    printf("                  3. Search By Author\n");
    printf("                  4. Back to Staff Area\n\n");
    printf("                  Enter Your Choice :\t ");scanf(" %c",&choice);
    fp=fopen("records.dat","r"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(choice)
    {
	  case '1':
		{
	    	system("cls");
			printf("======================================================================================\n");
			printf("                                Search Books by ID                                    \n");
			printf("======================================================================================\n");
	    	printf("                Enter The Book ID : ");
	    	fflush(stdin);
	    	scanf(" %d",&search);
	    	printf("\n\n");
			//printf("Searching........");
	    	while(fread(&b,sizeof(b),1,fp)==1)
	    	{
				if(b.id==search)
				{
		    		printf("\n\n");
					printf("		The Record is available\n\n");
					printf("\n");
					printf("		ID   : \t%d\n",b.id);
					printf("		Name :\t%s\n",b.name);
					printf("		Author:\t%s\n",b.author);
					printf("		Price:\tRM%.2f\n",b.price);
				    findrecord='t';
				}

	    }
	    if(findrecord!='t')  //checks whether conditiion enters inside loop or not
	    {
	    	printf("\aNo Record Found\a\n\n");
	    }
	    printf("\nTry Another Search ? (y/n)");
	    if(getch()=='y')
	    searchrecord();
	    else
	    staffArea();
	    break;
	}
	case '2':
	{
	    char name[255];
	    system("cls");
		printf("======================================================================================\n");
		printf("                                Search Books by Name                                 \n");
		printf("======================================================================================\n");
	    printf("               Enter Book Name : ");
	    fflush(stdin);
	    scanf(" %[^\n]",name);
	    int search=0;
	    while(fread(&b,sizeof(b),1,fp)==1)
	    {
		if(strcmp(b.name,(name))==0) //checks whether a.name is equal to s or not
		{
		    printf("\n		The Record is available.\n\n\n");
			printf("		ID   : \t%d\n",b.id);
			printf("		Name :\t%s\n",b.name);
			printf("		Author:\t%s\n",b.author);
			printf("		Price:\tRM%.2f\n",b.price);
		    search++;
		}

	    }
	    if(search==0)
	    {
	    	printf("\n\aNo Record Found\a");
	    }
	    printf("\nTry Another Search ? (Y/N)");
	    if(getch()=='y')
	    searchrecord();
	    else
	    staffArea();
	    break;
	}
	case '3':
	{
	    char author[255];
	    system("cls");
		printf("======================================================================================\n");
		printf("                                Search Books by Author                                 \n");
		printf("======================================================================================\n");
	    printf("               Enter Book Author : ");
	    fflush(stdin);
	    scanf(" %[^\n]",author);
	    int search=0;
	    while(fread(&b,sizeof(b),1,fp)==1)
	    {
		if(strcmp(b.author,(author))==0) //checks whether a.name is equal to s or not
		{
		    printf("\n		The Record is available.\n\n\n");
			printf("		ID   : \t%d\n",b.id);
			printf("		Name :\t%s\n",b.name);
			printf("		Author:\t%s\n",b.author);
			printf("		Price:\tRM%.2f\n",b.price);
		    search++;
		}

	    }
	    if(search==0)
	    {
	    	printf("\n\aNo Record Found\a");
	    }
	    printf("\nTry Another Search ? (Y/N)");
	    if(getch()=='y')
	    searchrecord();
	    else
	    staffArea();
	    break;
	}
	case '4' :
	{
		staffArea();
	}
	default :
	getch();
	searchrecord();
    }
    fclose(fp);

}

int fileOptoArray(){
	//count book
	FILE *file;
	int count = 0;
	int i = 0;
	file = fopen("records.dat","r");
	while(fread(&b,sizeof(b),1,file)==1){
		count++;
	}
	fclose(file);
	//end count
	
	//printf("\nTotal book : %d\n",count);
	
	//struct bookInfo2 book[count]; //all infor will be here
	
	//move file into array
	file = fopen("records.dat","r+");
	
	while(fread(&b,sizeof(b),1,file)==1){
		book[i].id = b.id;
		//book[i].author = b.author;
		strcpy(book[i].author,b.author);
		//book[i].name = b.name;
		strcpy(book[i].name,b.name);
		book[i].price = b.price;
		i++;
	}
	//printf("\ntotal book : %d\n",count);
	//end
	fclose(file);
	//display

	/**
	for(int i=0;i<count;i++){
		printf("%d\n",book[i].id);
		printf("%s\n",book[i].name);
		printf("%s\n",book[i].author);
		printf("%f\n",book[i].price);
		
	}**/
	return count;
}










