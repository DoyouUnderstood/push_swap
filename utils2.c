/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:50:05 by alletond          #+#    #+#             */
/*   Updated: 2023/10/24 11:17:31 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_best_num_to_top_and_push(Element **stack_a, Element **stack_b)
{
	int		best_num;
	int		num_rotations;
	char	*rotation_direction;
	int		closest_lower;

	best_num = best_num_to_push(*stack_a, *stack_b);
	// Mettre le meilleur nombre au sommet de stack_a
	rotation_direction = shortest_rotation_to_top(*stack_a, best_num,
			&num_rotations);
	while (num_rotations > 0)
	{
		if (strcmp(rotation_direction, "ra") == 0)
			ra(stack_a, 1); // Fonction pour effectuer la rotation "ra"
		else
			rra(stack_a, 1); // Fonction pour effectuer la rotation "rra"
		num_rotations--;
	}
	// Pousser le meilleur nombre de stack_a à stack_b
	// Trouver la position correcte dans stack_b et effectuer les rotations nécessaires
	closest_lower = find_closest_lower(*stack_b, best_num);
	rotation_direction = shortest_rotation_to_top_b(*stack_b, closest_lower,
			&num_rotations);
	while (num_rotations > 0)
	{
		if (strcmp(rotation_direction, "rb") == 0)
			rb(stack_b); // Fonction pour effectuer la rotation "rb"
		else
        {
			rrb(stack_b); // Fonction pour effectuer la rotation "rrb"
        }
		num_rotations--;
	}
	pb(stack_a, stack_b); // Fonction pour effectuer l'opération "pa"
}
