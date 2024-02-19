#include "deck.h"

/**
 * cmpdeck - custom func to cmp str in deck
 * @str1: 1st string
 * @str2: 2nd string
 *
 * Return: positive or negative
 */
int cmpdeck(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * calc_val - calc val
 * @card: cart
 *
 * Return: value
 */
char calc_val(deck_node_t *card)
{
	if (cmpdeck(card->card->value, "Ace") == 0)
		return (0);
	if (cmpdeck(card->card->value, "1") == 0)
		return (1);
	if (cmpdeck(card->card->value, "2") == 0)
		return (2);
	if (cmpdeck(card->card->value, "3") == 0)
		return (3);
	if (cmpdeck(card->card->value, "4") == 0)
		return (4);
	if (cmpdeck(card->card->value, "5") == 0)
		return (5);
	if (cmpdeck(card->card->value, "6") == 0)
		return (6);
	if (cmpdeck(card->card->value, "7") == 0)
		return (7);
	if (cmpdeck(card->card->value, "8") == 0)
		return (8);
	if (cmpdeck(card->card->value, "9") == 0)
		return (9);
	if (cmpdeck(card->card->value, "10") == 0)
		return (10);
	if (cmpdeck(card->card->value, "Jack") == 0)
		return (11);
	if (cmpdeck(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_deck_type - sort deck type
 * @deck: deck pointer
 */
void sort_deck_type(deck_node_t **deck)
{
	deck_node_t *pass, *posit, *tmp;

	for (pass = (*deck)->next; pass != NULL; pass = tmp)
	{
		tmp = pass->next;
		posit = pass->prev;
		while (posit != NULL && posit->card->kind > pass->card->kind)
		{
			posit->next = pass->next;
			if (pass->next != NULL)
				pass->next->prev = posit;
			pass->prev = posit->prev;
			pass->next = posit;
			if (posit->prev != NULL)
				posit->prev->next = pass;
			else
				*deck = pass;
			posit->prev = pass;
			posit = pass->prev;
		}
	}
}

/**
 * sort_deck_value - sort deck value
 * @deck: deck position
 */
void sort_deck_value(deck_node_t **deck)
{
	deck_node_t *pass, *posit, *tmp;

	for (pass = (*deck)->next; pass != NULL; pass = tmp)
	{
		tmp = pass->next;
		posit = pass->prev;
		while (posit != NULL &&
			   posit->card->kind == pass->card->kind &&
			   calc_val(posit) > calc_val(pass))
		{
			posit->next = pass->next;
			if (pass->next != NULL)
				pass->next->prev = posit;
			pass->prev = posit->prev;
			pass->next = posit;
			if (posit->prev != NULL)
				posit->prev->next = pass;
			else
				*deck = pass;
			posit->prev = pass;
			posit = pass->prev;
		}
	}
}

/**
 * sort_deck - sort deck
 * @deck: deck position
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck_type(deck);
	sort_deck_value(deck);
}
