bool isPalindrome(int x) {
	long int inv = 0, tmp = x;

	if (x < 0)
		return false;

	while (tmp > 0) {
		inv = inv * 10 + (tmp % 10);
		tmp /= 10;
	}

	if (x == inv)
		return true;

	return false;
}
