#pragma once

#include <stdio.h>


struct NODE
{
	int data;
	struct NODE *next;
};


struct NODE* BuildOneTwoThree()
{
	struct NODE* head = NULL;
	struct NODE* second = NULL;
	struct NODE* third = NULL;

	head = malloc(sizeof(struct NODE));
	second = malloc(sizeof(struct NODE));
	third = malloc(sizeof(struct NODE));

}

