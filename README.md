
**<font face="Times New Roman" size=6><center>HomeWork1</center></font>**

## <font face="Times NewRoman">Chapter 1</font>
<font face="Times NewRoman" size=3>

**1.1 Difference between Substitution Cipher and Transposition Cipher**

Cipher are both ancient and enduring cryptography methods. It is typical of Substitution Cipher to create a special alphabet and map every letter to another distinct cipher letter with the very alphabet. Transposition Cipher’s encryption works by rearranging the order of letters in plaintext with a transposition table.
When it comes to difference between Substitution Cipher and Transposition Cipher, it is obvious that:
* Substitution Cipher encrypts every letter while Transposition Cipher didn’t. Actually Transposition Cipher changes the places of words in plaintext.
* Substitution Cipher ask for a mapping alphabet and Transposition Cipher didn't.
* Frequency Analysis is available for Substitution Cipher while helping nothing with Transposition Cipher.
* Substitution Cipher is more convenient than Substitution Cipher in operation. Because there is a direct mapping alphabet while Transposition Cipher takes some mathematical operation.<br>
  
**1.2 Examples of Chiper**

Examples of Substitution Cipher: 
* Caesar Cipher
* Enigma Cipher
* Vigenère cipher
  
Examples of Transposition Cipher: 
* Rail fence Cipher
* Double Columnar Transposition Cipher

</font>

## <font face="Times NewRoman">Chapter 2</font>

<font face="Times New Roman" size=3>**2.1 Program Design**

I apply two cipher methods in my encryption: Substitution Cipher and Fences Cipher(Transposition Cipher). As Substitution Cipher is vulnerable to frequency analysis, so it's employed in number encryption while Substitution Cipher is  employed in letter encryption.
</font>

<font face="Times New Roman" size=3>2.1.1 Here is my Substitution Cipher chart for digit. There is mapping relation between every plain digit to a cipher one. And corrospongdingly it is convenient for users to decrypt the cipher in accord with the chart.</font>


<center><table>
  <tr>
    <th>Plain</th>
    <th>0</th>
	<th>1</th>
	<th>2</th>
	<th>3</th>
	<th>4</th>
	<th>5</th>
	<th>6</th>
	<th>7</th>
	<th>8</th>
	<th>9</th>
  </tr>
  <tr>
    <td>Cipher</td>
    <td>5</td>
    <td>3</td>
	<td>8</td>
	<td>1</td>
	<td>7</td>
	<td>6</td>
	<td>2</td>
	<td>0</td>
	<td>9</td>
	<td>4</td>
  </tr>
</table></center>

<center><font face="Times New Roman" size=2>Tabel 1 Encryption Chart</font></center>
<br><br>
<center><table>
  <tr>
    <th>Cipher</th>
    <th>0</th>
	<th>1</th>
	<th>2</th>
	<th>3</th>
	<th>4</th>
	<th>5</th>
	<th>6</th>
	<th>7</th>
	<th>8</th>
	<th>9</th>
  </tr>
  <tr>
    <td>Plain</td>
    <td>7</td>
    <td>3</td>
	<td>2</td>
	<td>1</td>
	<td>9</td>
	<td>0</td>
	<td>5</td>
	<td>4</td>
	<td>2</td>
	<td>8</td>
  </tr>
</table></center>

<center><font face="Times New Roman" size=2>Tabel 2 Decryption Chart</font></center>

<font face="Times New Roman" size=3>2.1.2 When it comes to Fences Cipher, I make a decision to combine it with Pinyin. Pinyin consists of initials and finals which fits with Fences Cipher and it's secret to associate with Pinying in an English-like context. Primarily partition every Pinyin into initial and final seperately, then collect 4 finals after their own initials as cipher. For instance, "XUJIACHENG" consists of "X/J/CH" and "U/IA/ENG". Consequently the cipher is "XJCHUIAENG"("XJCH/UIAENG").</font>

<font face="Times New Roman" size=3>**2.2 Program Implement**

Plaintext is deposited in string `str`. For encryption operation, the program scans every character in `str`.If the current character `*ch` is a digit, it will turn into cipher digit according to array `order1`;if it's a letter, function `getInitlen` is called  and an init takes away and follows an final. Decryption operation does it reversely.
</font>
```
void Encrypt(char *str); //Encrypt the plaintext
void Decrypt(char *str); //Decrypt the cipher
int getInitLen(char *ch);//Get length of first initial after point ch
int getFinalLen(char *ch);//Get length of first final after point ch

char *order1[10] = {"5", "3", "8", "1", "7", "6", "2", "0", "9", "4"};
//Encryption Chart

char *order4[10] = {"7", "3", "2", "1", "9", "0", "5", "4", "2", "8"};
//Decryption Chart

char *order2[23] = {"B", "C", "D", "F", "G", "H", "J", "K", "L", "M", "N", "P",
 "Q", "R", "S", "T", "W", "X", "Y", "Z", "SH", "CH", "ZH"};//Initials

char *order3[29] = {"A", "O", "E", "I", "U", "V", "AI", "AO", "OU", "IU", "IA", 
"IE","VE", "ER", "AN", "UE", "EN", "IN", "UN", "VN", "ANG", "ENG", "ING", "ONG",
"IAN","UAN","IANG","IONG","UANG"};//Finals
```
See details about function `getInitLen` (pesudo code).
```
function getInitLen(char* ch)
    tempstr = Next 2 letters from ch;//ch itself included
    if  a string in order2 matches tempstr 
        then return 2

    tempstr = Next 1 letter from ch;//ch itself
    if a string in order2 matches tempstr
        then return 1
    
    if no one matches then return 0
```
function `getFinalLen` is similar to `getInitLen`.<br>
Note: the  program is programmed by C. A C compiler is enough.

<font face="Times New Roman" size=3>**2.3 Test and Analysis**

2.2.1 Test results are as following:

![test1](C:/Users/Administrator/Desktop/p1.png)
<center><font size=2>Picture 1 Encrption Operation</font></center><br>

![test1](C:/Users/Administrator/Desktop/p2.png)
<center><font size=2>Picture 2 Decryption Operation</font></center><br>

![test2](C:/Users/Administrator/Desktop/p4.png)
<center><font size=2>Picture 3 Encryption Operation</font></center><br>

![test2](C:/Users/Administrator/Desktop/p5.png)
<center><font size=2>Picture 4 Decryption Operation</font></center><br>

2.2.2 Although the program works at most time, there are some flaws within it left to better.Different from letters in English, Pinyin have some letters binded and the program or even people may have difficulty distinguish some them at times.
For example, for initials "sh" in cipher, it's confusing to dertermine it as "s" and "h" or simple "sh". I simply take it as "sh" for convenience. For my perspective, the problem could be solved if we have the after following complex designs.
</font>

<font face="Times New Roman" size=3>**2.4 Summary and Experience**

The homework is far from an easy job. Initially I make an attempt to combine encryption with hash function. However it takes great troubles in decryption. Afterwards when I cope with initials and finals, I spare no effort how to accuratly partition them, preventing from misunderstanding "ai" as "a".
The solution proove to matching word in decreasing order of length of initials and finals. Despite that I suffer from lots of rubs, it is I that enjoy the experience of **ENCRYPTION** and **DECRYPTION** so lot. 
</font>

## <font face="Times New Roman">Appedix</font>
```
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
```