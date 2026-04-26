bool lemonadeChange( int *bills, int billsSize ) {
	int i = 0, q5 = 0, q10 = 0, q20 = 0, change = 0;

	for ( i = 0; i < billsSize; i++ ) {
		change = bills[i] - 5;

		if ( change == 5 ) {
			if ( q5 < 1 )
				return false;
			else
				q5 -= 1;
		} else if ( change == 15 ) {
			if ( q5 < 3 && ( q10 < 1 || q5 < 1 ) ) {
				return false;
			} else if ( q10 >= 1 && q5 >= 1 ) {
				q10 -= 1;
				q5 -= 1;
			} else if ( q5 >= 3 ) {
				q5 -= 3;
			}
		}

		if ( bills[i] == 5 )
			q5 += 1;
		else if ( bills[i] == 10 )
			q10 += 1;
		else if ( bills[i] == 20 )
			q20 += 1;
	}

	return true;
}
