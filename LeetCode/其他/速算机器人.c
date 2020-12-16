int calculate(char* s){
	int x = 1, y = 0;

	while ((*s) != '\0')
	{
		if (*s == 'A')
			x = 2 * x + y;
		if (*s == 'B')
			y = 2 * y + x;
		s++;
	}
	return x + y;

}