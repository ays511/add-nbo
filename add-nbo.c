#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t num_from_file(char *file_name){
	FILE *fp = fopen(file_name,"rb");
	if(fp == NULL){
		printf("Can't open file!");
		exit(-1);
	}
	uint32_t num;
	fread(&num,1,sizeof(uint32_t),fp);
	fclose(fp);
	return ntohl(num);
}

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("syntax : add-nbo <file1> <file2>\nsample : add-nbo a.bin b.bin\n");
		return -1;
	}
	uint32_t num1 = num_from_file(argv[1]);
	uint32_t num2 = num_from_file(argv[2]);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",num1,num1,num2,num2,num1+num2,num1+num2);
	return 0;
}

