#include <stdio.h>
#include <stdlib.h>

/* Applies the card counting logic to whatever the present count is

   presentCount: the present count of the game
   val: the value of the card
*/
int countingLogic(int presentCount, int val) {
	if ((val > 2) && (val < 7)) {
		presentCount++;
	} else if (val == 10) {
		presentCount--;
	}
	return presentCount;
}

int main() 
{
	char cardName[3];
	int count = 0;
	int val;
	while (cardName[0] != 'X') {
		puts("Enter the card name:");
		scanf("%2s",cardName);
		val = 0;
		switch (cardName[0]) {
			case 'K':
			case 'Q':
			case 'J':
				val = 10;
				break;
			case 'A':
				val = 11;
				break;
			case 'X':
				continue;
			default:
				val = atoi(cardName);
				if ((val < 1) || val > 10) {
					puts("I don't understand that value");
					continue;
				}

		}
		count = countingLogic(count, val);
		
		printf("Current count: %i\n", count);
	}
	return 0;
}
