int fact(int n) {
	int r = 0;
	while (n > 3) {
		r = r * n;
		n = n - 1;
	}
	return r;
}
