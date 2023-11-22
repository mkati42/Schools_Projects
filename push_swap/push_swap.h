/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkati <mkati@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:32:48 by mkati             #+#    #+#             */
/*   Updated: 2023/08/12 15:18:41 by mkati            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

void			check_control(int ac, char **str);
int				number_control(char *av);
void			list_creating(int ac, char **av);
long long		ft_atoi(const char *str);
void			ft_putstr(char *str);
void			ft_error(char *str);
void			ft_free_stack(t_list **clear);
void			init_stack(int ac, char **av, t_list **a);
void			ft_lst_addback(t_list **stack, t_list *new);
t_list			*ft_lstnew(int value);
t_list			*ft_lstlast(t_list *head);
t_list			*get_next_min(t_list **stack);
void			index_lst(t_list **stack);
int				sort_control(t_list **a);
void			sort_stack(t_list **a, t_list **b);
int				ft_lstsize(t_list *head);
char			**ft_split(char *s, char c);
int				count_word(const char *s, char c);
int				string_len(char const *str, char c);
void			sort_3(t_list **stack);
void			sort_4(t_list **a, t_list **b);
void			sort_5(t_list **a, t_list **b);
int				push_s(t_list **from, t_list **to);
int				push_a(t_list **a, t_list **b);
int				push_b(t_list **a, t_list **b);
int				r_reverse_s(t_list **stack);
int				r_reverse_a(t_list **a);
int				r_reverse_b(t_list **b);
int				r_reverse_ab(t_list **a, t_list **b);
int				reverse_s(t_list **stack);
int				reverse_a(t_list **a);
int				reverse_b(t_list **b);
int				swap_s(t_list **stack);
int				swap_a(t_list **a);
int				swap_b(t_list **b);
int				swap_ab(t_list **a, t_list **b);
void			bit_sort(t_list **a, t_list **b, int max_bit);
int				init_max_bit(int value);
void			radix_sort(t_list **a, t_list **b);
void			bit_control_a(t_list **a, t_list **b, int bit, int value);
void			bit_control_b(t_list **b, t_list **a, int bit, int value);
void			ft_free_2d(char **argv);
int				ft_strlen(char *str);
int				same_nbr_control(t_list **av);
void			valid_char_control(char a);
char			*ft_substr(char *s, int start, int len);
int				l_long_control(char *str);

#endif
