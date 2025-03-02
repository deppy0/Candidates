#include "defs.h"

void swap(candidate_p ptrcand1, candidate_p ptrcand2)
{
	candidate_t temp = *ptrcand1;
	*ptrcand1 = *ptrcand2;
	*ptrcand2 = temp;	
}

void sortByRating(candidate_l_p list, int boolIncreasing)
{
	int i, j, mx;
	for (i = 0; i < list->count - 1; i++)
	{
		mx = i;
		for (j = i + 1; j < list->count; j++)
			if (boolIncreasing)
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
				if (strcmp(list->candidates[m].name.last, list->candidates[j].name.last) > 0)
					m = j;
				else;
			else
				if (strcmp(list->candidates[m].name.last, list->candidates[j].name.last) < 0)
					m = j;
				else;
		swap(&list->candidates[i], &list->candidates[m]);
	}
}
