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
        j = 0;

		printf("Enter Last Name: ");
        do {
            scanf("%c", &ch);

            if (ch != '\n') {
                ptr->last[i] = ch;
                i++;
            }
        } while (i < 30 && ch != '\n');

        ptr->last[i] = '\0';

		printf("Enter First Name: ");
        do {
            scanf("%c", &ch);

            if (ch != '\n') {
                ptr->first[j] = ch;
                j++;
            }
        } while (j < 30 && ch != '\n');

        ptr->first[j] = '\0';

		printf("Enter Middle Initial: ");
        scanf("%c", &ptr->middle_initial);
}

void getDate(date_p ptr) {
	
	printf("Enter Month: ");
	scanf("%d", &ptr->month);
	printf("Enter Day: ");
	scanf("%d", &ptr->day);
	printf("Enter Year: ");
	scanf("%d", &ptr->year);
}

//TODO: FOR CHECKING
void getInput(candidate_l_p ptr) {

	int i = 0, j = 0;
	do
	{
		printf("Name of the candidate: ");
		getName(&ptr->candidates[i].name);
		printf("/nBirthday: ");
		getDate(&ptr->candidates[i].birth);

		printf("/nPosition: ");
		scanf("%s", ptr->candidates[i].position);
		printf("/nParty: ");
		scanf("%s", ptr->candidates[i].party);
		
		printf("/nBills passed: ");
		do
		{
			printf("/nBill name: ");
			scanf("%s", ptr->candidates[i].bills.bills[j].bill_name);
			printf("/nDate the bill was passed: ");
			getDate(&ptr->candidates[i].bills.bills[j].pass_date);

			j++;
		}
		while(strcmp(ptr->candidates[i].bills.bills[j].bill_name,"!!" )!=0 && j<BILL_MAX);

		printf("/nConfidence rate: ");
		scanf("%d", ptr->candidates[i].confidence);

		i++;
	}
	while(strcmp(ptr->candidates[i].name.last,"!!" )!=0 && i<CANDIDATE_MAX);
}

void displayDate(date_t date) {
	str_short date_Format;

	parse_mmddyyyy(&date, date_Format);
	printf("%s\n", date_Format);
} 

void display(candidate_t candidate){

	int j = 0;

	printf("Name of the candidate: ", candidate.name);
	printf("/nBirthday: ");
	displayDate(candidate.birth);
	printf("/nPosition: ", candidate.position);
	printf("/nParty: ", candidate.party);
	
	printf("/nBills passed: ");
	do
	{
		printf("/nBill name: ",candidate.bills.bills[j].bill_name);
		printf("/nDate the bill was passed: ");
		displayDate(candidate.bills.bills[j].pass_date);

		j++;
	}
	while(j<candidate.bills.count);

	printf("/nConfidence rate: ");
	scanf("%d", candidate.confidence);
}

void displayByParty(candidate_l list, str_short party_name)
{
	int i = 0;
	char key;
	do
	{
		if(strcmp(party_name, list.candidates[i].party)==0)
			display(list.candidates[i]);
		scanf("%c", key);
		i++;
	}
	while(i<list.count && key == '\n');
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
