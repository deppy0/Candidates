#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#define STRING_SHORT	20 + 1
#define STRING_LONG 	50 + 1
#define CANDIDATE_MAX	20
#define BILL_MAX		10

typedef char str_short[STRING_SHORT];
typedef char str_long[STRING_LONG];
typedef struct
{
	int month, day, year;
} date_t, *date_p;
typedef struct
{
	str_short last, first, mid;
} name_t, *name_p;
typedef struct
{
	str_long	bill_name;
	date_t		pass_date;
} bill_t, *bill_p;
typedef struct
{
	bill_t		bills[BILL_MAX];
	int			count;
} bill_l, *bill_l_p;
typedef struct
{
	name_t		name;
	date_t		birth;
	str_short	position, party;
	bill_l		bills;
	double		confidence;
} candidate_t, *candidate_p;
typedef struct
{
	candidate_t		candidates[CANDIDATE_MAX];
	int				count;
} candidate_l, *candidate_l_p;

void getName(name_ptr ptr);
void getDate(date_ptr ptr);
void getInput(candidate_l_p list);
void displayDate(date_t date);
void display(candidate_t candidate);
void displayByParty(candidate_l list);
void swap(candidate_p ptrcand1, candidate_p ptrcand2);
void sortByRating(candidate_l_p list, int boolIncreasing);
void sortAlphabetical(candidate_l_p list, int boolSortAtoZ);