#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

typedef struct Element
{
	int				valeur;
	struct Element	*suivant;
}					Element;

Element				*creerElement(void);
Element				*add_nbr(Element *list, int value);
void				draw_list(Element *list);
int					is_empty(Element *liste);
int					is_order(Element *liste);
int					is_order_descending(Element *liste);
void				algo(Element **liste, Element **liste_b);
Element				*remlistelir_liste(int argc, char **argv, int *len);
void				swap_both(Element **liste_a, Element **liste_b);
void				swap_a(Element **liste);
void				pa(Element **liste_a, Element **liste_b, int afficher);
void				ra(Element **liste_a, int afficher);
void				rra(Element **liste_a, int afficher);
void	sa(Element **liste, int afficher);
void				rb(Element **liste_b);
void				rr(Element **liste_a, Element **liste_b);
void				ft_putstr(char *str);
void				pb(Element **liste_a, Element **liste_b);
void				rrb(Element **liste_b);
void				sb(Element **liste);
char				*shortest_rotation_to_top(Element *stack_a, int num,
						int *num_rotations);
int					find_closest_lower(Element *stack_b, int num);
char				*shortest_rotation_to_top_b(Element *stack_b,
						int closest_lower, int *num_rotations);
int					best_num_to_push(Element *stack_a, Element *stack_b);
int					total_rotations_to_position(Element *stack_a,
						Element *stack_b, int num, int closest_lower);
void				move_best_num_to_top_and_push(Element **stack_a,
						Element **stack_b);
int					ft_lstsize(Element *lst);
void				sort_three_elements(Element **stack_a);
int find_min(Element *stack);
void	sort_stack_a(Element **stack_a, Element **stack_b);
int find_next_num_to_push(Element *stack_a, Element *stack_b);
int	is_closer_to_top(Element *stack_b, int num);
int find_max(Element *stack);
void sort_remaining_elements(Element **stack_a);
// void	push_to_correct_position_in_a(Element **stack_a, Element **stack_b);
#endif
