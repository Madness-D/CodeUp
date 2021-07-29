//ASCII码，大写英文字母65——90，小写97——122
#include<stdio.h>

int main() {
	char  a[100];
	gets(a);//获取字符
	for (int i = 0; i < 100; i++) {
		if (a[i] >= 65 && a[i] <= 90) {
			a[i] = 155 - a[i];
		}
		else if (a[i] >= 97 && a[i] <= 122) {
			a[i] = 219 - a[i];
		}
	}
	puts(a);
	return 0;
}