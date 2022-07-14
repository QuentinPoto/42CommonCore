#include "libft.h"

//void ft_lstclear(t_list **lst, void (*del)(void*))
//{
//	t_list	*ptr;
//	t_list	*temp;
//
//	ptr = *lst;
//	temp = *lst;
//	while (temp)
//	{
//		temp = temp->next;
//		del(ptr->content);
//	}
//}

void ft_lstclear(t_list **lst, void (*del)(void*)) {
	if (*lst)
	{
		ft_lstclear(&(*lst)->next, del);
		free(*lst);
		del(*lst);
	}
}

//Turn in files-Parameters
// #1.  The adress of a pointer to an element.
// #2.  The adress of the function used to delete the content of the element.
//
// Return valueNone
//
// External functs.free
//
// Description Deletes and frees the given element and every
// successor of that element, using the function ’del’ and free(3).
// Finally, the pointer to the list must be set to NULL