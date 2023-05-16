#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

struct items{
    char item[20];
    float price;
    int qty;

};
struct orders{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};
void generateBillHeader(char name[50], char date[30]){
    printf("\n\n");
    printf("\t Pritam Resturant");
    printf("\n\t ----------------------------");
    printf("\n Date:%s",date);
    printf("\n Invoice Name : %s",name);
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("Items\t\t");
    printf("Quantity\t");
    printf("Total\t");
    printf("\n--------------------------------------------------");
    printf("\n\n");

}

void generateBillBody(char item[30] , int qty , float price){
    printf("%s\t\t",item);
    printf("%d\t\t",qty);
    printf("%.2f\t\t",qty*price);
    printf("\n");
}

void generateBillFooter(float Total){
    printf("\n");
    float dis = 0.1*Total;
    float netTotal = Total - dis;
    float cgst = 0.09*netTotal;
    float grandTotal = netTotal+2*cgst;
    printf("--------------------------------------------------\n");
    printf("\nSubTotal :\t\t\t%.2f",Total);
    printf("\nDiscount on food is :\t\t%.2f""%",dis);
    printf("\n\t\t\t-----------------");
    printf("\nNet Total :\t\t\t%0.2f",netTotal);
    printf("\n CGST :\t\t\t\t%0.2f""%",cgst);
    printf("\n SGST :\t\t\t\t%0.2f""%",cgst);
    printf("\n-----------------------------------------");
    printf("\nGrand Total :\t\t\t%0.2f",grandTotal);
    printf("\n-----------------------------------------\n");
}


int main(){
    //variables
    int opt,n;
    float total;
    struct orders ord;
    struct orders order;
    char saveBill = 'y';
    FILE *fp;
    //Resturent dashboard
    printf("\t================= PRITAM RESTURENT =================");
    printf("\n\n");
    printf("Please select your preference.: ");
    printf("\n\t\t\t1.Generate Invoices.\n");
    printf("\t\t\t2.Show all Invoices.\n");
    printf("\t\t\t3.Search Invoices.\n");
    printf("\t\t\t4.Exit.\n");

printf("Your choice : ");
scanf("%d",&opt);
fgetc(stdin);
switch(opt){
    case 1:
    system("clear");
    printf("\nPlease Enter your name:\t");
    fgets(ord.customer,50,stdin);
    ord.customer[strlen(ord.customer)-1] = 0;
    strcpy(ord.date,__DATE__);
    printf("Please enter the number of items: ");
    scanf("%d",&n);
    ord.numOfItems = n;

    for(int i =0;i<n;i++){
        fgetc(stdin);
        printf("\n\n");
        printf("Plese enter the item %d:\t",i+1);
        fgets(ord.itm[i].item,20,stdin);
        ord.itm[i].item[strlen( ord.itm[i].item)-1] = 0;
        printf("Please enter the quantity:  ");
        scanf("%d",&ord.itm[i].qty);
        printf("Please enter the unit of price : ");
        scanf("%f",&ord.itm[i].price);
        total += ord.itm[i].qty * ord.itm[i].price;
    }

    generateBillHeader(ord.customer,ord.date);
    for(int i =0;i<ord.numOfItems;i++){
        generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
    }
    generateBillFooter(total);

printf("\n Are you want to save the bill?[y/n]\t");
scanf("%s",&saveBill);

if(saveBill == 'y'){
    fp = fopen("ResturentBill.dat","a+");
    fwrite(&ord,sizeof(struct orders),1,fp);
    if(fwrite != 0)
        printf(" \n Successfully saved\n");
    
    else
        printf("\n Error in saving ");
        fclose(fp);   
}
break;


case 2:
system("clear");
fp = fopen("ResturentBill.dat","r");
printf("\n ****** Your Previous Invoice ******\n");
while(fread(&order,sizeof(struct orders),1,fp)){
    float tot =0;
    generateBillHeader(order.customer,order.date);
    for(int i =0;i<order.numOfItems;i++){
        generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
        tot+=order.itm[i].qty * order.itm[i].price;

    }
    generateBillFooter(tot);
}
fclose(fp);
break;

}
    
    return 0;
}