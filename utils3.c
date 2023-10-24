/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:12:45 by alletond          #+#    #+#             */
/*   Updated: 2023/10/24 11:14:30 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Element	*creerElement(void)
{
	Element	*nouvelElement;

	nouvelElement = (Element *)malloc(sizeof(Element));
	if (nouvelElement != NULL)
	{
		nouvelElement->valeur = 0;
		nouvelElement->suivant = NULL;
	}
	return (nouvelElement);
}

Element	*add_nbr(Element *list, int value)
{
	Element	*nouvelElement;

	nouvelElement = creerElement();
	if (nouvelElement != NULL)
	{
		nouvelElement->valeur = value;
		nouvelElement->suivant = list;
		list = nouvelElement;
	}
	return (list);
}

void	draw_list(Element *list)
{
	while (list)
	{
		printf("%d ", list->valeur);
		list = list->suivant;
	}
	printf("\n");
}

Element	*remlistelir_liste(int argc, char **argv, int *len)
{
	Element	*liste;
	int		valeur;

	liste = NULL;
	*len = 0; // initialisez la valeur à laquelle len pointe à 0
	for (int i = 1; i < argc; i++)
	{
		valeur = atoi(argv[i]);
		liste = add_nbr(liste, valeur);
		(*len)++; // incrémentez la valeur à laquelle len pointe
	}
	return (liste);
}

int	is_empty(Element *liste)
{
	return (liste == NULL);
}
int	is_order(Element *liste)
{
	while (liste != NULL && liste->suivant != NULL)
	{
		if (liste->valeur > liste->suivant->valeur)
			return (0);
		liste = liste->suivant;
	}
	return (1);
}
int	is_order_descending(Element *liste)
{
	while (liste != NULL && liste->suivant != NULL)
	{
		if (liste->valeur < liste->suivant->valeur)
			return (0);
		liste = liste->suivant;
	}
	return (1);
}