//求第n个斐波那契数 循环方式
int fibCycle(int n) {
	if (n < 1) return 0;
	int a = 1, b = 1, c = 1;
	while (n > 2) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}