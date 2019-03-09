#include <stdio.h>
#include <math.h>
#include <string.h>
void Encrypt(char *str);
void Decrypt(char *str);
int getInitLen(char *ch);
int getFinalLen(char *ch);
char *order1[10] = {"5", "3", "8", "1", "7", "6", "2", "0", "9", "4"};//Encryption Chart
char *order2[23] = {"B", "C", "D", "F", "G", "H", "J", "K", "L", "M", "N", "P", "Q", "R", "S", "T", "W", "X", "Y", "Z", "SH", "CH", "ZH"};//Initials
char *order3[29] = {"A", "O", "E", "I", "U", "V", "AI", "AO", "OU", "IU", "IA", "IE", "VE", "ER", "AN",
 "UE", "EN", "IN", "UN", "VN", "ANG", "ENG", "ING", "ONG","IAN","UAN","IANG","IONG","UANG"};//Finals
char *order4[10] = {"7", "3", "2", "1", "9", "0", "5", "4", "2", "8"};//Decryption Chart
int main()
{
	char str[255];
	char ch,*ptrch;
	printf("Do you want to Encrypt or Decrypt(E/D):");
	ch = getchar();
	getchar();
	if (ch == 'E')
	{
		gets(str);
		ptrch = str;
		while (*ptrch){
			if ('a'<=*ptrch&&*ptrch<='z') *ptrch = *ptrch-'a'+'A';
			ptrch++; 
			} 	
		Encrypt(str);
	}
	else if (ch == 'D')
	{
		gets(str);
		Decrypt(str);
	}
}
void Encrypt(char *str)
{
	char *ch;
	char init[255], final[255], ans[255];
	int isIi, cnt1, cnt2, num, i, len, cnt, j, k;

	ch = str;
	cnt = cnt1 = cnt2 = 0;
	while (*ch)
	{
		if ('0' <= *ch && *ch <= '9')
		{
			num = *ch - '0';
			*ch = order1[num][0];
			ans[cnt] = *ch;
			cnt++;
		}
		else if ('A' <= *ch && *ch <= 'Z')
		{
			len = getInitLen(ch);
			for (i = 0; i < len; i++)
			{
				init[cnt1] = *ch;
				cnt1++;
				ch++;
			}
			if (len)
			{
				init[cnt1] = '/';
				cnt1++;
			}

			len = getFinalLen(ch);
			for (i = 0; i < len; i++)
			{
				final[cnt2] = *ch;
				cnt2++;
				ch++;
			}
			if (len)
			{
				final[cnt2] = '/';
				cnt2++;
			}
			continue;
		}
		ch++;
	}
	init[cnt1] = final[cnt2] = '\0';

	i = j = 0;
	while (init[i])
	{
		k = 0;
		while (k < 4 && init[i])
		{
			if (init[i] == '/')
			{
				k++;
				i++;
			}
			else
			{
				ans[cnt] = init[i];
				i++;
				cnt++;
			}
		}
		k = 0;
		while (k < 4 && final[j])
		{
			if (final[j] == '/')
			{
				k++;
				j++;
			}
			else
			{
				ans[cnt] = final[j];
				j++;
				cnt++;
			}
		}
	}
	ans[cnt] = '\0';
	printf("Cipher Text:");
	puts(ans);
}
void Decrypt(char *str)
{
	char *ch;
	char init[255], final[255], ans[255];
	int i, j, k, cnt1, cnt2, len, cnt;

	ch = str;
	cnt = cnt1 = cnt2 = 0;
	while (*ch)
	{
		if ('A' <= *ch && *ch <= 'Z')
		{

			k = 0;
			while (k < 4 && *ch)
			{
				len = getInitLen(ch);
				k++;
				for (i = 0; i < len; i++)
				{
					init[cnt1] = *ch;
					ch++;
					cnt1++;
				}
				if (len)
				{
					init[cnt1] = '/';
					cnt1++;
				}
			}

			k = 0;
			while (k < 4 && *ch)
			{
				len = getFinalLen(ch);
				k++;
				for (i = 0; i < len; i++)
				{
					final[cnt2] = *ch;
					ch++;
					cnt2++;
				}
				if (len)
				{
					final[cnt2] = '/';
					cnt2++;
				}
			}
		}
		else if ('0' <= *ch&&*ch <= '9')
		{
			ans[cnt] = order4[*ch-'0'][0];
			cnt++;
			ch++;
		}
	}
	init[cnt1] = final[cnt2] = '\0';
	i = j = 0;
	while (init[i])
	{
		while (init[i] && init[i] != '/')
		{
			ans[cnt] = init[i];
			i++;
			cnt++;
		}
		if (init[i])
			i++;
		while (final[j] && final[j] != '/')
		{
			ans[cnt] = final[j];
			j++;
			cnt++;
		}
		if (final[j])
			j++;
	}
	ans[cnt] = '\0';
	printf("Plain Text:");puts(ans);
}
int getInitLen(char *ch)
{
	int i;
	char str1[2], str2[3];

	strncpy(str1, ch, 1);
	strncpy(str2, ch, 2);
	str1[1] = str2[2] = '\0';

	for (i = 20; i < 23; i++)
		if (!strcmp(order2[i], str2))
			return 2;
	for (i = 0; i < 20; i++)
		if (!strcmp(order2[i], str1))
			return 1;
	return 0;
}
int getFinalLen(char *ch)
{
	int i;
	char str[5];
	
	strncpy(str, ch, 4);str[4] = '\0';
	for (i = 25; i < 28; i++)
		if (!strcmp(order3[i], str))
			return 4;
	
	strncpy(str, ch, 3);str[3] = '\0';
	for (i = 20; i < 25; i++)
		if (!strcmp(order3[i], str))
			return 3;
			
	strncpy(str, ch, 2);str[2] = '\0';
	for (i = 6; i < 20; i++)
		if (!strcmp(order3[i], str))
			return 2;
			
	strncpy(str, ch, 1);str[1] = '\0';		
	for (i = 0; i < 6; i++)
		if (!strcmp(order3[i], str))
			return 1;
			
	return 0;
}
