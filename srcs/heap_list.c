# include "../headers/fdf.h"

void	clearheap(t_heap **node)
{
	t_heap	*tmp;

	if (!node || !*node)
		return ;
	tmp = *node;
	while (node && *node)
	{
		free(tmp->ptr);
        // printf("pointer \033[36m%p\033[0m was freed\n", tmp->ptr);
		tmp->ptr = NULL;
		tmp = tmp->next;
		free(*node);
		*node = tmp;
	}
}

void	heap_addback(t_heap **lst, t_heap *new)
{
	t_heap	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_heap	*heap_new(void *content)
{
	t_heap	*head;

	head = (t_heap *)malloc(sizeof(t_heap));
	if (!head)
		return (NULL);
	head->ptr = content;
	head->next = NULL;
	return (head);
}
