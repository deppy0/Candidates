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

        do {
            scanf("%c", &ch);

            if (ch != '\n') {
                ptr->last[i] = ch;
                i++;
            }
        } while (i < 20 && ch != '\n');

        ptr->last[i] = '\0';

        do {
            scanf("%c", &ch);

            if (ch != '\n') {
                ptr->first[j] = ch;
                j++;
            }
        } while (j < 20 && ch != '\n');

        ptr->first[j] = '\0';

        scanf("%c", ptr->middle_initial);
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
