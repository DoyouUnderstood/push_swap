#include "push_swap.h"

void	algo(Element **liste, Element **liste_b)
{
	pb(liste, liste_b);
	pb(liste, liste_b);
}

int	ft_lstsize(Element *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->suivant;
		size++;
	}
	return (size);
}

void	sort_three_elements(Element **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->valeur;
	b = (*stack_a)->suivant->valeur;
	c = (*stack_a)->suivant->suivant->valeur;
	if (a < b && b > c && a < c)
	{
		// Échanger 'b' et 'c'
		sa(stack_a, 1);
	}
	else if (a > b && b < c)
	{
		// Effectuer une rotation vers le haut pour mettre 'a' en bas
		ra(stack_a, 1);
	}
	else if (a > b && b > c)
	{
		// Échanger 'a' et 'b'
		sa(stack_a, 1);
		// Effectuer une rotation vers le bas pour mettre 'c' en haut
		rra(stack_a, 1);
	}
	else if (a > c && c < b)
	{
		// Effectuer une rotation vers le bas pour mettre 'c' en haut
		rra(stack_a, 1);
	}
	else if (a > c && b < c)
	{
		// Échanger 'a' et 'c'
		sa(stack_a, 1);
		// Effectuer une rotation vers le haut pour mettre 'a' en bas
		ra(stack_a, 1);
	}
	// Si a < b && b < c, la liste est déjà triée, donc rien à faire
}

void	sort_stack_a(Element **stack_a, Element **stack_b)
{
	int	num_to_push;

	while (*stack_b)
	{
		num_to_push = find_next_num_to_push(*stack_a, *stack_b);
		// Si num_to_push n'est pas valide, sortir de la boucle
		if (num_to_push == -6000)
		{
			break ;
		}
		// Déplacer num_to_push au sommet de stack_b
		while (*stack_b && (*stack_b)->valeur != num_to_push)
		{
			if (is_closer_to_top(*stack_b, num_to_push))
			{
				rb(stack_b);
			}
			else
			{
				rrb(stack_b);
			}
		}
		// Pousser num_to_push de stack_b à stack_a
		pa(stack_a, stack_b, 1);
		// Faire tourner stack_a jusqu'à ce que num_to_push soit à sa position correcte
		while (*stack_a && (*stack_a)->suivant
			&& (*stack_a)->valeur > (*stack_a)->suivant->valeur)
		{
			ra(stack_a, 1);
		}
	}
}

int	find_next_num_to_push(Element *stack_a, Element *stack_b)
{
	int		min_a;
	int		max_b_below_min_a;
	int		max_b;
	Element	*current;

	min_a = find_min(stack_a);
	max_b_below_min_a = -6000;
	max_b = -6000;
	current = stack_b;
	while (current)
	{
		if (current->valeur < min_a && current->valeur > max_b_below_min_a)
		{
			max_b_below_min_a = current->valeur;
		}
		if (current->valeur > max_b)
		{
			max_b = current->valeur;
		}
		current = current->suivant;
	}
	// Si tous les nombres inférieurs au minimum de stack_a ont été poussés,
	// retourner le maximum de stack_b
	if (max_b_below_min_a == -6000)
	{
		return (max_b);
	}
	return (max_b_below_min_a);
}

int	find_max(Element *stack)
{
	int		max_val;
	Element	*current;

	max_val = -6000;
	current = stack;
	while (current)
	{
		if (current->valeur > max_val)
		{
			max_val = current->valeur;
		}
		current = current->suivant;
	}
	return (max_val);
}

int	find_min(Element *stack)
{
	int		min_val;
	Element	*current;

	min_val = 6000;
	current = stack;
	while (current)
	{
		if (current->valeur < min_val)
		{
			min_val = current->valeur;
		}
		current = current->suivant;
	}
	return (min_val);
}

int	is_closer_to_top(Element *stack, int num)
{
	int		distance_from_top;
	Element	*current;

	distance_from_top = 0;
	current = stack;
	while (current && current->valeur != num)
	{
		distance_from_top++;
		current = current->suivant;
	}
	return (distance_from_top <= ft_lstsize(stack) / 2);
}

void	sort_remaining_elements(Element **stack_a)
{
	int		length;
	int		sorted;
	Element	*current;
	int		max_val;
	int		max_index;
	int		index;

	length = ft_lstsize(*stack_a);
	sorted = 0;
	while (!is_order(*stack_a))
	{
		current = *stack_a;
		max_val = current->valeur;
		max_index = 0;
		index = 0;
		// Trouver l'élément le plus grand qui n'est pas à sa place correcte
		while (current)
		{
			if (current->valeur > max_val && index != length - sorted - 1)
			{
				max_val = current->valeur;
				max_index = index;
			}
			current = current->suivant;
			index++;
		}
		// Si l'élément le plus grand est plus proche du début,
		if (max_index < index / 2)
		{
			while (max_index > 0)
			{
				ra(stack_a, 1);
				max_index--;
			}
		}
		else
		{
			// Sinon, utilisez rra pour le déplacer en haut
			while (max_index < index)
			{
				rra(stack_a, 1);
				max_index++;
			}
		}
		// Une fois que l'élément le plus grand est en haut
		ra(stack_a, 1);
		sorted++;
	}
}

void	fill_b(Element *liste, Element *liste_b)
{
	while (ft_lstsize(liste) != 3)
	{
		printf("~/-------------------------/\n");
		draw_list(liste);
		draw_list(liste_b);
		move_best_num_to_top_and_push(&liste, &liste_b);
		printf("~/-------------------------/\n");
	}
	// push_to_correct_position_in_a(&liste, &liste_b);
	printf("~/-------------------------/\n");
	draw_list(liste);
	draw_list(liste_b);
	sort_three_elements(&liste);
	printf("~/-------------------------/\n");
	draw_list(liste);
	draw_list(liste_b);
	sort_stack_a(&liste, &liste_b);
	printf("~/-------------------------/\n");
	draw_list(liste);
	// draw_list(liste_b);
	sort_remaining_elements(&liste);
	printf("~/-------------------------/\n");
	draw_list(liste);
	draw_list(liste_b);
}
int	main(int argc, char **argv)
{
	Element *liste = NULL;
	Element *liste_b = NULL;
	int len = 0;
	liste = remlistelir_liste(argc, argv, &len);
	algo(&liste, &liste_b);
	fill_b(liste, liste_b);

	while (liste != NULL)
	{
		Element *temliste = liste;
		liste = liste->suivant;
		free(temliste);
	}
	return (0);
}