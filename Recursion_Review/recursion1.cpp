// Function called NumEven that returns the number of even digits in a positive number
Int numEven(int x) {
	If ( x  == 0) { //base case
		Return 0;
	}

	Else {
		If  (x%2 == 0) { //number is even
			Return numEven(x/10) + 1;
		}

		Return numEven (x/10); //number is odd
	}
}
