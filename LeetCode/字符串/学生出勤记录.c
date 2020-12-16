bool checkRecord(char * s)
{
	if (s == NULL)
		return false;
	int a = 0, l = 0;
	char *ps = s;
	char *ps2 = ps;
	while (*ps!='\0')
	{
		if (*ps == 'A')
		{
			a++;
		}
		if (a == 2)
			return false;
		if (*ps == 'L'&& *ps2!='L')
		{
			ps2 = ps;
			l++;
		}
		else if (*ps == 'L'&& *ps2 == 'L')
		{
			l++;
			if (l >= 3)
				return false;
		}
		if (*ps != 'L')
		{
			ps2 = ps;
			l = 0;
		}	
		ps++;
	}
	return true;
}

// bool checkRecord(char * s)
// {
// 	int len = strlen(s);
//     int a = 0;
//     for(int i=0;i<len;++i)
//     {
//         if(s[i]=='A') a++;
//         if(a>1) return 0;
//     }

// 	for (int i = 0; i < len - 2; ++i)
// 	{
// 		if (s[i] == 'L'&&s[i + 1] == 'L'&&s[i + 2] == 'L')
// 			return false;
// 	}
// 	return true;
// }