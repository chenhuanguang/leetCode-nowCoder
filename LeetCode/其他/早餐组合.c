#define N 1000000007

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int breakfastNumber(int* staple, int stapleSize, int* drinks, int drinksSize, int x) {

	qsort(staple, stapleSize, sizeof(int), cmp);
	qsort(drinks, drinksSize, sizeof(int), cmp);

	long count = 0;
	int stapleIndex = 0;
	int drinksIndex = drinksSize - 1;
	while (stapleIndex < stapleSize && drinksIndex >= 0) {
		if (staple[stapleIndex] + drinks[drinksIndex] <= x) {
			count += drinksIndex + 1;
			stapleIndex++;
		}
		else {
			drinksIndex--;
		}
	}
	return count%N;
}