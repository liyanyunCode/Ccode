//实现字母大小写的转换，多组输入和输出

//针对每组输入输出对应的小写字母

#include<stdio.h>
int main()
{
	int ch = 0;
	//当你在屏幕上键入一个字母时，按回车键后，回车键也会被当作字符，被geychar捕捉到，
	//putchar一次智能捕捉一个字符，则先读取输入的字符在读取回车键。
	while ((ch=getchar())!=EOF)//在屏幕上输入control+ Z就可以结束  EOF文件结束标志
	{
		putchar(ch + 32);
		printf("\n");
		//printf("%c\n",ch+32)上面两句可以用这个表示。
		getchar();//在放一个getchar，这个就会读取回车键字符，数据缓冲区就没有东西了。
	}
}