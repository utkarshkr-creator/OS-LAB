#include<stdio.h>
int main(){
	FILE *fp;
	printf("Cpuinfo\n\n\n");
	fp=fopen("/proc/cpuinfo","r");
	char line[300];
	while(fgets(line,sizeof(line),fp)){
          printf("%s\n",line);
	}
	fclose(fp);
	printf("Meminfo\n\n\n");
       fp=fopen("/proc/meminfo","r");
        char line1[300];
     while(fgets(line,sizeof(line1),fp)) printf("%s\n",line);
    fclose(fp);	
	return 0;
}
