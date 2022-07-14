#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*
 *
 ft_lstlastPrototypet_list *ft_lstlast(t_list *lst);

 Turn in files-

 #1.  The beginning of the list.

 Return value Last element of the list.

 External functs.None

 Description
 Returns the last element of the list

 */