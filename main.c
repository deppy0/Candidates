#include "funcs.c"

int main(void)
{
	char ch = ' ';
	candidate_l list = { 0 };
	str_short temp;
	do
	{
		printf(
			"\n\na) Add candidate info\n"
			"b) Display all candidates\n"
			"c) Display by rating\n"
			"d) Display by party\n"
			"e) Exit\n\n"
			"Pick: "
		);
		scanf(" %c", &ch);
		switch (ch)
		{
			case 'A':
			case 'a':
				getInput(&list);
				break;
			case 'B':
			case 'b':
				displayAlphabetically(list, 1);
				break;
			case 'C':
			case 'c':
				displayByRating(list, 1);
				break;
			case 'D':
			case 'd':
				printf("\n\nInput party name: ");
				scanf(" %s", temp);
				if (strcmp(temp, "!!") != 0)
					displayByParty(list, temp);
				break;
			case 'E':
			case 'e':
			default:
				break;
		}
	} while (ch != 'E' && ch != 'e');
	
    return 0;
}
