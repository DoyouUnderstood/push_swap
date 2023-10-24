/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:53:55 by alletond          #+#    #+#             */
/*   Updated: 2023/10/24 11:17:24 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_num_to_push(Element *stack_a, Element *stack_b)
{
	Element	*current_a;
	int		ops;
	int		closest_lower;

	int min_ops = 600; // Initialiser avec une grande valeur
	int num_to_push = -1; 
		// Initialiser avec une valeur non valide pour détecter les erreurs
	current_a = stack_a;
	while (current_a)
	{
		closest_lower = find_closest_lower(stack_b, current_a->valeur);
		ops = total_rotations_to_position(stack_a, stack_b, current_a->valeur,
				closest_lower);
		if (ops < min_ops)
		{
			min_ops = ops;
			num_to_push = current_a->valeur;
		}
		current_a = current_a->suivant;
	}
	return (num_to_push);
}

int	total_rotations_to_position(Element *stack_a, Element *stack_b, int num,
		int closest_lower)
{
	int	total_rotations;

	int num_rotations_a, num_rotations_b;
	char *rotation_a, *rotation_b;
	// Obtenir la rotation la plus courte pour num dans stack_a
	rotation_a = shortest_rotation_to_top(stack_a, num, &num_rotations_a);
	// Obtenir la rotation la plus courte pour closest_lower dans stack_b
	rotation_b = shortest_rotation_to_top_b(stack_b, closest_lower,
			&num_rotations_b);
	// Si les deux rotations vont dans le même sens, utiliser rr ou rrr
	if ((strcmp(rotation_a, "ra") == 0 && strcmp(rotation_b, "rb") == 0)
		|| (strcmp(rotation_a, "rra") == 0 && strcmp(rotation_b, "rrb") == 0))
	{
		total_rotations = (num_rotations_a > num_rotations_b) ? num_rotations_a : num_rotations_b;
	}
	else
	{
		total_rotations = num_rotations_a + num_rotations_b;
	}
	return (total_rotations + 1); // +1 pour l'opération push
}

char	*shortest_rotation_to_top(Element *stack_a, int num, int *num_rotations)
{
	int		rotations_top;
	int		rotations_bottom;
	Element	*current;
	int		length;

	rotations_top = 0;
	rotations_bottom = 0;
	current = stack_a;
	length = 0;
	// Calculer les rotations vers le haut (ra)
	while (current)
	{
		if (current->valeur == num)
		{
			break ;
		}
		rotations_top++;
		current = current->suivant;
	}
	// Calculer la longueur totale de la pile
	current = stack_a;
	while (current)
	{
		length++;
		current = current->suivant;
	}
	rotations_bottom = length - rotations_top;
	// Déterminer le chemin le plus court et renvoyer "ra" ou "rra"
	// tout en définissant le nombre de rotations via le pointeur
	if (rotations_top < rotations_bottom)
	{
		*num_rotations = rotations_top;
		return ("ra");
	}
	else
	{
		*num_rotations = rotations_bottom;
		return ("rra");
	}
}

// Fonction pour trouver le nombre le plus proche et inférieur à 'num' dans 'stack_b'
int	find_closest_lower(Element *stack_b, int num)
{
	Element	*current;

	int closest_lower = -300;
		// Initialiser avec la valeur la plus basse possible
	current = stack_b;
	while (current)
	{
		if (current->valeur < num && current->valeur > closest_lower)
		{
			closest_lower = current->valeur;
		}
		current = current->suivant;
	}
	return (closest_lower);
}

// Fonction pour déterminer le sens de rotation et le nombre de coups nécessaires
char	*shortest_rotation_to_top_b(Element *stack_b, int closest_lower,
		int *num_rotations)
{
	int		rotations_top;
	int		rotations_bottom;
	Element	*current;
	int		length;

	rotations_top = 0;
	rotations_bottom = 0;
	current = stack_b;
	length = 0;
	// Calculer les rotations vers le haut (rb)
	while (current)
	{
		if (current->valeur == closest_lower)
		{
			break ;
		}
		rotations_top++;
		current = current->suivant;
	}
	// Calculer la longueur totale de la pile
	current = stack_b;
	while (current)
	{
		length++;
		current = current->suivant;
	}
	rotations_bottom = length - rotations_top;
	// Déterminer le chemin le plus court et renvoyer "rb" ou "rrb"
	if (rotations_top < rotations_bottom)
	{
		*num_rotations = rotations_top;
		return ("rb");
	}
	else
	{
		*num_rotations = rotations_bottom;
		return ("rrb");
	}
}
