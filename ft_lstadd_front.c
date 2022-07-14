#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}


/*
 * ft_lstadd_frontPrototypevoid ft_lstadd_front(t_list **lst, t_list *new);Turn in files-
 * Parameters
 * #1.  The address of a pointer to the first link of a list.
 * #2.  The address of a pointer to the element to beadded to the list.
 *
 * Return valu
 * eNone
 *
 * External functs.None
 * Description Adds the element ’new’ at the beginning of the list.*/