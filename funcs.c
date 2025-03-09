#include "defs.h"

void parse_mmddyyyy(date_p date, str_short str)
{
	char t[2] = { 0 };
	switch (date->month)
	{
		default: case 1:
			strcpy(str, "January ");
			break;
		case 2:
			strcpy(str, "February ");
			break;
		case 3:
			strcpy(str, "March ");
			break;
		case 4:
			strcpy(str, "April ");
			break;
		case 5:
			strcpy(str, "May ");
			break;
		case 6:
			strcpy(str, "June ");
			break;
		case 7:
			strcpy(str, "July ");
			break;
		case 8:
			strcpy(str, "August ");
			break;
		case 9:
			strcpy(str, "September ");
			break;
		case 10:
			strcpy(str, "October ");
			break;
		case 11:
			strcpy(str, "November ");
			break;
		case 12:
			strcpy(str, "December ");
			break;
	}
	t[0] = '0' + date->day / 10 % 10;
	strcat(str, t);
	t[0] = '0' + date->day % 10;
	strcat(str, t);
	strcat(str, ", ");
	t[0] = '0' + date->year / 1000 % 10;
	strcat(str, t);
	t[0] = '0' + date->year / 100 % 10;
	strcat(str, t);
	t[0] = '0' + date->year / 10 % 10;
	strcat(str, t);
	t[0] = '0' + date->year % 10;
	strcat(str, t);
}

void getName(name_p ptr)
{
    char ch;
    int i = 0,
        j = 0,
        t = 0;

		printf("Enter Last Name: ");
        do {
        	if (i == 0)
        		scanf(" %c", &ch);
        	else
            	scanf("%c", &ch);

            if (ch != '\n') {
                ptr->last[i] = ch;
                i++;
            }
        } while (i < 30 && ch != '\n');
		
        ptr->last[i] = '\0';
        t += strcmp(ptr->last, "!!") == 0;
		
		if (t == 0)
		{
			printf("Enter First Name: ");
	        do {
	            scanf("%c", &ch);
	
	            if (ch != '\n') {
	                ptr->first[j] = ch;
	                j++;
	            }
	        } while (j < 30 && ch != '\n');
	    }

        ptr->first[j] = '\0';
        t += strcmp(ptr->first, "!!") == 0;
		
		if (t == 0)
		{
			printf("Enter Middle Initial: ");
        	scanf("%c", &ptr->middle_initial);	
		}
}

void getDate(date_p ptr) {
	
	printf("Enter Month: ");
	scanf(" %d", &ptr->month);
	printf("Enter Day: ");
	scanf(" %d", &ptr->day);
	printf("Enter Year: ");
	scanf(" %d", &ptr->year);
}

void getInput(candidate_l_p ptr)
{
	int stop;
	candidate_p c;
	bill_p pb;
	str_long lng = { 0 };
	if (ptr->count < CANDIDATE_MAX)
	{
		c = &ptr->candidates[ptr->count];
		printf("\nName of the candidate\n\n");
		getName(&c->name);
		if (strcmp(c->name.last, "!!") != 0)
		{
			printf("\nBirthday:\n");
			getDate(&c->birth);
			printf("\n\nPosition: ");
			scanf(" %s", c->position);
			printf("\nParty: ");
			scanf(" %s", c->party);
			for (c->bills.count = 0, stop = 0; !stop && c->bills.count < BILL_MAX; c->bills.count++)
			{
				printf("\n\nEnter bill name, or type !! to cancel: ");
				scanf(" %s", lng);
				pb = &c->bills.bills[c->bills.count];
				stop = strcmp(lng, "!!") == 0;
				if (!stop)
				{
					strcpy(pb->bill_name, lng);
					printf("\nBill pass date:\n\n");
					getDate(&pb->pass_date);
				}
				else c->bills.count--;
			}
			printf("\nConfidence rate: ");
			scanf(" %lf", &c->confidence);
			ptr->count++;
		}
	}
	else
		printf("You cannot add more candidates.\n");
}

void displayDate(date_t date) {
	str_short date_Format;

	parse_mmddyyyy(&date, date_Format);
	printf("%s\n", date_Format);
} 

void display(candidate_t candidate){

	int j = 0;

	printf("\nName of the candidate: %s %s %c", candidate.name.last, candidate.name.first, candidate.name.middle_initial);
	printf("\nBirthday: ");
	displayDate(candidate.birth);
	printf("\nPosition: %s", candidate.position);
	printf("\nParty: %s", candidate.party);
	
	printf("\nBills passed: ");
	do
	{
		printf("\nBill name: %s",candidate.bills.bills[j].bill_name);
		printf("\nDate the bill was passed: ");
		displayDate(candidate.bills.bills[j].pass_date);

		j++;
	}
	while(j<candidate.bills.count);

	printf("\nConfidence rate: %.2lf\n", candidate.confidence);
}

void displayByRating(candidate_l list, int boolHighestOnTop)
{
	int i;
	char key = ' ';
	sortByRating(&list, boolHighestOnTop);
	printf("\n===== START OF LIST =====\n");
	for (i = 0; i < list.count && key != 'Q' && key != 'q'; i++)
	{
		display(list.candidates[i]);
		printf("\nEnter any key to continue, or enter Q to quit: ");
		scanf(" %c", &key);
	}
	printf("\n===== END OF LIST =====\n");
}

void displayAlphabetically(candidate_l list, int boolSortAtoZ)
{
	int i;
	char key = ' ';
	sortAlphabetical(&list, boolSortAtoZ);
	printf("\n===== START OF LIST =====\n");
	for (i = 0; i < list.count && key != 'Q' && key != 'q'; i++)
	{
		display(list.candidates[i]);
		printf("\nEnter any key to continue, or enter Q to quit: ");
		scanf(" %c", &key);
	}
	printf("\n===== END OF LIST =====\n");
}

void displayByParty(candidate_l list, str_short party_name)
{
	int i = 0;
	char key = ' ';
	printf("\n===== START OF LIST =====\n");
	do
	{
		if (strcmp(party_name, list.candidates[i].party) == 0)
		{
			display(list.candidates[i]);
			printf("\nEnter any key to continue, or enter Q to quit: ");
			scanf(" %c", &key);
		}
		i++;
	}
	while(i<list.count && key != 'Q' && key != 'q');
	printf("\n===== END OF LIST =====\n");
}

void swap(candidate_p ptrcand1, candidate_p ptrcand2)
{
	candidate_t temp = *ptrcand1;
	*ptrcand1 = *ptrcand2;
	*ptrcand2 = temp;	
}

void sortByRating(candidate_l_p list, int boolHighestOnTop)
{
	int i, j, mx;
	for (i = 0; i < list->count - 1; i++)
	{
		mx = i;
		for (j = i + 1; j < list->count; j++)
			if (boolHighestOnTop)
				if (list->candidates[j].confidence > list->candidates[mx].confidence)
					mx = j;
				else;
			else
				if (list->candidates[j].confidence < list->candidates[mx].confidence)
					mx = j;
				else;
		swap(&list->candidates[i], &list->candidates[mx]);
	}
}

void sortAlphabetical(candidate_l_p list, int boolSortAtoZ)
{
	int i, j, m;
	for (i = 0; i < list->count - 1; i++)
	{
		m = i;
		for (j = i + 1; j < list->count; j++)
			if (!boolSortAtoZ)
				if (strcmp(list->candidates[m].name.last, list->candidates[j].name.last) < 0)
					m = j;
				else;
			else
				if (strcmp(list->candidates[m].name.last, list->candidates[j].name.last) > 0)
					m = j;
				else;
		swap(&list->candidates[i], &list->candidates[m]);
	}
}
