#include<stdio.h>
int main(){
  //Banker's Algorithm
  printf("Enter No. of Process: \n");
  int n,m;  //n=no of process, m=no of resources
  scanf("%d",&n);
  printf("Enter No. of Resources: \n");
  scanf("%d",&m);
  // printf("%d  %d",n,m);
  int Allocation[n][m]; // Allocation[i][j]=k means process pi is 
  // currently allocated 'k' instances of resources types Rj
  int max[n][m];    // max[i][j]=k means proces pi may request max 
  // k instances of resources types Rj.
  int Need[n][m];    // Need[i][j]=Max[i][j]-Allocation[i][j];
  // k means process Pi currently need 'k' instances of resources
  // types Rj. 
  printf("Enter Allocation of Resources per Process: \n");
  int i=0,j=0;
  for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&Allocation[i][j]);
  printf("Allocation Matrix:\n");
  for(i=0;i<n;i++){for(j=0;j<m;j++)printf("%d ",Allocation[i][j]);printf("\n");}
  printf("Enter Max allocation of Resources per Process: \n");
  for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&max[i][j]);
    printf("Max Matrix:\n");
  for(i=0;i<n;i++){for(j=0;j<m;j++)printf("%d ",max[i][j]);printf("\n");}
  for(i=0;i<n;i++)for(j=0;j<m;j++)Need[i][j]=max[i][j]-Allocation[i][j];
    printf("Need Matrix:\n");
  for(i=0;i<n;i++){for(j=0;j<m;j++)printf("%d ",Need[i][j]);printf("\n");}
  int Avil[m];
  printf("Enter Available Instances Resources: \n");
  for(i=0;i<m;i++)
  scanf("%d",&Avil[i]);
  int vis[n];
  for(int i=0;i<n;i++)vis[i]=0;
  int ans[n];   
  int k=0,idx=0;
  printf("Intial Available Resources:");
  for(k=0;k<m;k++)printf("%d ",Avil[k]);
  printf("\n");
  for(k=0;k<n;k++){
      for(i=0;i<n;i++){
         if(!vis[i]){
               int Milgya=1;
               for(j=0;j<m;j++){
                   if(Need[i][j]>Avil[j])
                   {
                    Milgya=0;
                    break;
                   }
               }
               if(Milgya){
                 ans[idx++]=i;  
                 int v=0; 
                 for(v=0;v<m;v++)
                  Avil[v]+=Allocation[i][v];
                 // for(v=0;v<m;v++)printf("%d ",Avil[v]);
                 //  printf("\n");
                 vis[i]=1;
               }
               else continue;
         }
         else continue;
      }
  }
  int Safe_state=1;
  for(i=0;i<n;i++){
    if(!vis[i]){Safe_state=0;break;}
  }
  if(!Safe_state){
    printf("NOT IN SAFE STATE\n");
  }
  else{
      printf("SAFE SEQUENCE: ");
      for(j=0;j<n;j++){
        printf("P%d ",ans[j]);
      }
      printf("\n");
  }
printf("Enter Request: \n");
  int Req[m];
  for(i=0;i<m;i++)scanf("%d",&Req[i]);
  int fufu=1;
  for(i=0;i<m;i++){
    if(work[i]<Req[i])
    {
      fufu=0;
      break;
    }
  }
  if(fufu && Safe_state){
    printf("Request Granted\n");
  }
  else printf("No\n");




return 0;
}
