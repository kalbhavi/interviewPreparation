int ReverseInteger(int inputNum){
	int negFlag = 1, temp = 0;
	int reversedNum = 0, max = 2147483647;
	if (inputNum < 0){
		negFlag = -1;
		inputNum = -inputNum;
	}
	for (; (inputNum > 0); inputNum = inputNum/10){
		temp = inputNum % 10;
        reversedNum = (reversedNum * 10) + temp; //reverse the number
	}
	if (reversedNum > max) //check if the number overflows
		return 0;
	else
		return (int)reversedNum * negFlag;
}