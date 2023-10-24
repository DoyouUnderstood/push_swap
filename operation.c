#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	sa(Element **liste, int afficher)
{
	int	temp;

	if (*liste != NULL && (*liste)->suivant != NULL)
	{
		temp = (*liste)->valeur;
		(*liste)->valeur = (*liste)->suivant->valeur;
		(*liste)->suivant->valeur = temp;
	}
	if (afficher)
		ft_putstr("sa\n");
}
void	sb(Element **liste)
{
	sa(liste, 0);
	ft_putstr("sb\n");
}
void	ss(Element **liste_a, Element **liste_b)
{
	sa(liste_a, 0);
	sa(liste_b, 0);
	ft_putstr("ss\n");
}

void	pa(Element **liste_a, Element **liste_b, int afficher)
{
	Element	*tmp;
	int		values;
	Element	*tempB;

	if (*liste_b != NULL)
	{
		tmp = creerElement();
		values = (*liste_b)->valeur;
		tmp->valeur = values;
		tmp->suivant = *liste_a;
		*liste_a = tmp;
		tempB = *liste_b;
		*liste_b = (*liste_b)->suivant;
		free(tempB);
	}
	if (afficher)
		ft_putstr("pa\n");
}
void	pb(Element **liste_a, Element **liste_b)
{
	Element	*tmp;
	Element	*tempA;

	if (*liste_a != NULL)
	{
		tmp = creerElement();
		tmp->valeur = (*liste_a)->valeur;
		tmp->suivant = *liste_b;
		*liste_b = tmp;
		tempA = *liste_a;
		*liste_a = (*liste_a)->suivant;
		free(tempA);
	}
	ft_putstr("pb\n");
}

void	ra(Element **liste_a, int afficher)
{
	Element	*premierElement;
	Element	*dernierElement;

	if (*liste_a != NULL && (*liste_a)->suivant != NULL)
	{
		premierElement = *liste_a;
		*liste_a = (*liste_a)->suivant;
		premierElement->suivant = NULL;
		dernierElement = *liste_a;
		while (dernierElement->suivant != NULL)
		{
			dernierElement = dernierElement->suivant;
		}
		dernierElement->suivant = premierElement;
	}
	if (afficher)
		ft_putstr("ra\n");
}
void	rb(Element **liste_b)
{
	ra(liste_b, 0);
	ft_putstr("rb\n");
}
void	rr(Element **liste_a, Element **liste_b)
{
	ra(liste_a, 0);
	ra(liste_b, 0);
	ft_putstr("rr\n");
}

void	rra(Element **liste_a, int afficher)
{
	Element	*precedent;
	Element	*courant;

	if (*liste_a != NULL && (*liste_a)->suivant != NULL)
	{
		precedent = NULL;
		courant = *liste_a;
		while (courant->suivant != NULL)
		{
			precedent = courant;
			courant = courant->suivant;
		}
		if (precedent != NULL)
		{
			precedent->suivant = NULL;
			courant->suivant = *liste_a;
			*liste_a = courant;
		}
	}
	if (afficher)
		ft_putstr("rra\n");
}
void	rrb(Element **liste_b)
{
	rra(liste_b, 0);
	ft_putstr("rrb\n");
}
void	rrr(Element **liste_a, Element **liste_b)
{
	rra(liste_a, 0); // Effectuer un reverse rotate sur la liste_a
	rra(liste_b, 0); // Effectuer un reverse rotate sur la liste_b
	ft_putstr("rrr\n");
}