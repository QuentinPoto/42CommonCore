#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	res->content = content;
	res->next = NULL;
	return (res);
}

//Parameters #1.  The content to create the new element with.
//Return value The new element.
//
//External functs.malloc

//DescriptionAllocates (with malloc(3)) and returns a new element.
// The variable ’content’ is initializedwith the value of the parameter ’content’.
// Thevariable ’next’ is initialized to NULL