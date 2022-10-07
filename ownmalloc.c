#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int *head=NULL;
int count=1;
int total_allocated=0;

int *allocate_memory(int *current_address,int bytes)
{
    // printf("\nAllocation - %d\n",count);
    count++;
    total_allocated+=bytes;
    int *temp=NULL;
    // printf("Current address: %p\n",current_address);
    // printf("Head is at: %p\n",head); 

    temp=(int*)sbrk(bytes);
    // printf("Printing temp: %p\n",temp);

    // if(  temp  ==  (int*)-1)
    //     printf("\n\n\n\nSbreak allocation error\n\n\n\n");

    // printf("Address range:%p to %p available\n",current_address,temp);
    // printf("Allocated:   %ld bytes\n",temp - current_address);
    return temp;
}

int main(int argc, char *argv[])
{

   int *current_address=NULL;   
   int number_to_allocate;
   current_address=(int*)sbrk(0);
   printf("\nSBRk:%p\n",(int*)sbrk(0));

   head=current_address;  
  //printf("Allocation starts at: %p\n",head);

   number_to_allocate=256;
   current_address=allocate_memory(current_address,number_to_allocate);
   printf("\nSBRk:%p\n",(int*)sbrk(0));

   number_to_allocate=256;
   current_address=allocate_memory(current_address,number_to_allocate);
   printf("\nSBRk:%p\n",(int*)sbrk(0));
   number_to_allocate=256;
   current_address=allocate_memory(current_address,number_to_allocate);
   printf("\nSBRk:%p\n",(int*)sbrk(0));
   number_to_allocate=256;
   current_address=allocate_memory(current_address,number_to_allocate);
   
   printf("\nAllocated total: %d bytes\n",total_allocated);
   printf("Total available range: %p to %p\n",head,current_address);
   int i;
   for(i=0;i<total_allocated;i++)
   {
    *(head+i)=i;
    
    //if((i==0)||(i==1)||(i==total_allocated-1))
    if((i==1)||(i==2))//||(i==total_allocated-1))
    printf("Address: %p, value= %d\n",(head+i),*(head+i));
   }

    //Read data from allcoated locations
    int read,j;
    for(j=0;j<total_allocated;j++)
    {
        read=*(head+j);        
    }
    printf("\nData read from allocated locations\n");
    printf("Trying to access last location *(head+j-1):  %d \n",*(head+j-1));
    printf("Trying to access jth location  *(head+j):  %d \n",*(head+j));
    printf("Trying to access next location  *(head+j+1):  %d \n",*(head+j+1));

   printf("The differnece: %ld\n",current_address-(head+i));
   
}