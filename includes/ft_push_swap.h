/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:41:10 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/30 18:44:34 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}		t_list;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	t_list	*op;
}		t_stack;

/*--------------------Libft un peu modifiée---------------------*/
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_back_node(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
/* Cree une liste "vide"*/
t_list		*ft_create_empty_lst(void);
void		*ft_calloc(size_t count, size_t size);
char		**ft_split(char const *s, char c);
int			ft_isdigit(int c, int index);
void		ft_putstr(char *str);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *s, int c, size_t n);
int			ft_strcmp(char *s1, char *s2);

/* Permet de trouver le int le plus grand/petit dans la liste donnee*/
int			ft_bigger(t_list *lst);
int			ft_smaller(t_list *lst);

/* Affiche dans la sortie d'erreur : erreur*/
void		ft_error(void);
void		ft_clean_stack(t_stack **stack);

/*Permet de Checker si les arguments sont valables*/
int			ft_check_args(int argc, char **argv, t_stack **stack);
int			ft_check_big_args(int argc, char **argv, t_stack **stack);
int			ft_check_empty_arg(char **argv);
/* Permet de convertir les arguments pour les mettre dans la stack A*/
void		convert_args(int argc, char **argv, t_list **lst, t_stack **stack);

/* Renvoie 1 si la liste est deja triee, permet d'eviter des calcul inutiles*/
int			ft_all_sorted(t_list *lst);
int			ft_all_inv_sorted(t_list *lst);

/*-------------------------OPERATIONS----------------------------------------*/
/*Ce sont toutes les operations qui sont permises dans l'exercice push swap*/
void		ft_sa(t_stack **stack);
void		ft_ra(t_stack **stack);
void		ft_rb(t_stack **stack);
void		ft_rra(t_stack **stack);
void		ft_rrb(t_stack **stack);
void		ft_pa(t_stack **stack);
void		ft_pb(t_stack **stack);
void		ft_sb(t_stack **stack);
void		ft_ss(t_stack *stack);
void		ft_rr(t_stack *stack);
void		ft_rrr(t_stack *stack);

/*------------------------PRINT---------------------------------------------*/
/* Permet d'afficher la liste qu'on envoie dedans */
void		print_list_int(t_list **begin_list);
/* Permet d'afficher les operations contenues dans op*/
void		print_op(t_list **begin_list);

/*-----------------------------Mediane------------------------------------*/
/*Permet d'avoir la mediane en fonction de la taille de la liste*/
int			ft_get_median(t_list *lst, int size, t_stack **stack);
/*Transforme une liste en tableau (Plus pratique pour trouver mediane)*/
int			*ft_list_to_tab(t_list *lst, int size);
/*Trie à bulle classique*/
void		ft_sort_tab(int *tab, int size);

/*----------Fonctions Recursives de trie A -> B et B -> A ET TRIE------*/
void		ft_sort(t_stack *stack);
int			ft_sort_a_to_b(t_stack *stack, int size);
int			ft_sort_b_to_a(t_stack *stack, int size);
void		ft_process_a(t_stack **stack, int size_a);
/* Permet de process la liste apres avoir converti les arguments, 
On va donc choisir quel algo va etre utilise en fonction de si 
il est plus petit que 5, == 3, ==2, ==1*/
void		ft_process(t_stack **stack, int size_a);
void		ft_2numbers(t_stack *stack);
void		ft_3numbers(t_stack **stack);
void		ft_5less(t_stack **stack);
int			ft_process_b(t_stack *stack, int len_lst);
void		ft_2numbers_b(t_stack *stack);
void		ft_3numbers_b(t_stack **stack);

/* ------------------------scan de liste--------------------------------------*/
int			ft_scan_top_to_bot(t_list *lst, int median, int size,
				int direction);
int			ft_scan_bot_to_top(t_list *lst, int median, int size,
				int direction);

/*--------------------Suppr liste------------------------------------------*/

void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));

/*--------------------OPTIMISATION-----------------------------------------*/
/* Permet de supprimer les operations inutiles dans Op et transformer 2 
Operations en une quand c'est possible pour reduire le nb total d'operations*/
int			ft_optimise(t_list **lst);
int			ft_optimise_2(t_list **lst);
/*----------------------Comb-----------------------------------------------*/
/* Permet de faire des combinaisons d'operations*/
void		ft_comb_a_one(t_stack **stack);
void		ft_comb_a_two(t_stack **stack);
void		ft_comb_a_three(t_stack **stack);
void		ft_comb_a_four(t_stack **stack);
void		ft_comb_b_one(t_stack **stack);
void		ft_comb_b_two(t_stack **stack);
void		ft_comb_b_three(t_stack **stack);
void		ft_comb_b_four(t_stack **stack);

/*---------------Fonctions utiles pour ft_sort.c---------------------*/
/* Renvoie 1 si il y a un nombre qui est en dessous de la mediane
dans la liste A*/
int			is_nb_under_med_in_a(t_stack *stack, int length, int median);
/* Renvoie 1 si il y a un nombre qui est au dessus de la mediane
dans la liste B*/
int			is_nb_above_med_in_b(t_stack *stack, int length, int median);
/* Permet de replacer la liste A dans le bon sens apres avoir Rotate
et push des elements dans la liste B*/
void		ft_rotate_to_original_position_a(t_stack **stack, int rotate);
/* Permet de replacer la liste B dans le bon sens apres avoir Rotate
et push des elements dans la liste A*/
void		ft_rotate_to_original_position_b(t_stack **stack, int rotate);

int			ft_is_space(char c);
void		ft_clean_tab2d(char **strs);

/*---------------------------GNL-------------------------------------*/
char		*get_next_line(int fd);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_gnl_strjoin(char *s1, char *s2);

/*------------------------Checker---------------------------------------*/
void		ft_init(t_stack **stack, t_list **do_op);

#endif