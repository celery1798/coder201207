
char *mystrcpy(char *dest, const char *src);

mystrncpy()


int main()
{

char str1[32],str2[] = "hello"; 

mystrcpy(str1,str2)
strncpy(str1,str2,3);
}
