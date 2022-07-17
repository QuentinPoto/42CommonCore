#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = ft_lstlast(*lst);
	if (ptr == NULL)
	{
		*lst = new;
		return ;
	}
	ptr->next = new;
}

/*
 *
 #1.  The address of a pointer to the first link ofa list.
 #2.  The address of a pointer to the element to be added to the list.

 Return valueNone

 External functs.None

 Description
 Adds the element ’new’ at the end of the list.
 */