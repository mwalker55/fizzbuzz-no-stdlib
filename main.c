#define FIB_MAX 100
#include "unistd.h"

size_t strlen(char *str) {
	size_t len = 0;
	while(*(str++)){
		len+=1;
	}
	return len;
}

void intToText(int num, char* buf){
	char *ptr = buf;
	size_t size = 0;

	while(num > 0){
		*(ptr++) = num%10 + '0';
		size++;
		num/=10;
	}

	/* Original loop builds number in reverse
	   This reverses the number to its correct order */
	for(int a = 0, b = size-1; a < b; a++, b--){
		char temp = buf[a];
		buf[a] = buf[b];
		buf[b] = temp;
	}
	buf[size] = '\n';
	buf[size+1] = 0;
}

int main(void){
	char buf[64];
	int i;
	for(i = 1; i < FIB_MAX; i++){
		// else-if done instead of just ifs to reduce system call overhead
		if(i%3==0&&i%5==0){
			write(1, "FizzBuzz\n", 9);
		} else if (i%3==0){
			write(1, "Fizz\n", 5);
		} else if (i%5==0){
			write(1, "Buzz\n", 5);
		} else {
			intToText(i, buf);
			write(1, buf, strlen(buf));
		}
	}
}