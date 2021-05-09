# 1NT18IS131_sahanap_nplab
CRC IMPLEMENTATION 
#include<stdio.h>
#include<string.h>
int main(){
  int i,j,keylen,msglen,flag=0;
  char input[100],key[30],temp[30],qout[100],rem[30],keyl[10];
  printf("enter data(sender side):");
  scanf("%s",input);
  printf("enter key:");
  scanf("%s",key);
  keylen=strlen(key);
  msglen=strlen(input);
  strcpy(keyl,key);
  for(i=0;i<keylen-1;i++)
  {
    input[msglen+i]='0';
  }
  for(i=0;i<keylen;i++)
   temp[i]=input[i];
  for(i=0;i<msglen;i++){
     qout[i]=temp[0];
     if(qout[i]=='0')
      for(j=0;j<keylen;j++)
      key[j]='0';else
      for(j=0;j<keylen;j++)
       key[j]=keyl[j];

      for(j=keylen-1;j>0;j--){
        if(temp[j]==key[j])
        rem[j-1]='0';else
        rem[j-1]='1';
       }
       rem[keylen-1]=input[i+keylen];
       strcpy(temp,rem);
    }
    strcpy(rem,temp);
    printf("\n Quotient is:");
    for(i=0;i<msglen;i++)
      printf("%c",qout[i]);
    printf("\n reminder is:");
    for(i=0;i<keylen-1;i++)
    printf("%c",rem[i]);
    printf("the final data is:");
    for(i=0;i<msglen;i++)
      printf("%c",input[i]);
    for(i=0;i<keylen-1;i++)
      printf("%c",rem[i]);
     printf("\n");
    char temp1[20];
    printf("enter received data:");
    scanf("%s",temp1);
  
   printf("\n Message is:");
    for(i=0;i<msglen;i++)
      printf("%c",qout[i]);
    
    printf("\n polynomial is:");
    for(i=0;i<msglen;i++)
      printf("%c",qout[i]);
    printf("\n crc is:");
    for(i=0;i<keylen-1;i++)
      printf("%c",rem[i]);

    flag=0;
    for(i=0;i<keylen-1;i++)
    {
      if(rem[i]=='1')
        flag=1;
   
      else
        flag=0;
    }

    if(flag==0)
       printf("\n no error");
    else
       printf("\n error is detected");

    return 0;
   

    }
