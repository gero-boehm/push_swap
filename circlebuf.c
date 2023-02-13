#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_circle {
	int				*items;
	size_t			size;
	size_t			max_size;
	unsigned long	start;
}	t_circle;


int	malloc2(size_t count, int **ptr)
{
	*ptr = malloc(count);
	return (*ptr == NULL);
}

int	create_buf(t_circle *buf, size_t size)
{
	if (malloc2(size, &buf->items))
		return (1);
	buf->size = 0;
	buf->max_size = size;
	buf->start = 0;
	return (0);
}

unsigned long	normalize_index(t_circle *buf, unsigned long index)
{
	return ((index + buf->start + buf->max_size) % buf->max_size);
}

int	add_item(t_circle *buf, int item)
{
	unsigned long	index;

	if (buf->size == buf->max_size)
		return (1);
	index = normalize_index(buf, buf->size++);
	buf->items[index] = item;
	return (0);
}

int	get_item_at(t_circle *buf, unsigned long index)
{
	index = normalize_index(buf, index);
	return (buf->items[index]);
}

void	set_item_at(t_circle *buf, unsigned long index, int item)
{
	index = normalize_index(buf, index);
	buf->items[index] = item;
}

void push(t_circle *buf1, t_circle *buf2)
{
	int	item;

	if (buf1->size == 0)
		return ;
	item = get_item_at(buf1, 0);
	buf1->start = normalize_index(buf1, 1);
	buf1->size--;
	set_item_at(buf2, -1, item);
	buf2->start = normalize_index(buf2, -1);
	buf2->size++;
}

void pb(t_circle *a, t_circle *b)
{
	push(a, b);
}

void pa(t_circle *b, t_circle *a)
{
	push(b, a);
}

void	ra(t_circle *buf)
{
	int	item;

	item = get_item_at(buf, 0);
	buf->start = normalize_index(buf, 1);
	set_item_at(buf, buf->size - 1, item);
}

void	rra(t_circle *buf)
{
	int	item;

	item = get_item_at(buf, buf->size - 1);
	buf->start = normalize_index(buf, buf->max_size - 1);
	set_item_at(buf, 0, item);
}

void	print_stack(t_circle *stack)
{
	if (stack->size == 0)
	{
		printf("                    ");
		return ;
	}
	for (int i = 0; i < 10; i++)
	{
		if ((i >= stack->start && i <= stack->start + stack->size - 1) || (stack->start + stack->size > 10 && i <= normalize_index(stack, stack->size - 1)))
			printf("%d ", get_item_at(stack, i - stack->start));
		else
			printf("  ");
	}
}

int	main(void)
{
	t_circle	stack_a;
	t_circle	stack_b;

	if (create_buf(&stack_a, 10))
		return (1);
	if (create_buf(&stack_b, 10))
		return (2);
	for (int i = 0; i < 10; i++)
		add_item(&stack_a, i);

	printf("\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", i);
	printf("    ");
	for (int i = 0; i < 10; i++)
		printf("%d ", i);
	printf("\n");

	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	// pb(&stack_a);
	// pb(&stack_a);
	// pb(&stack_a);
	ra(&stack_a);
	pb(&stack_a, &stack_b);
	ra(&stack_b);
	pa(&stack_b, &stack_a);

	// rra(&stack_a);
	// rra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);
	// ra(&stack_a);

	// printf("%lu - %lu | %zu\n", buf.start, normalize_index(&buf, buf.size - 1), buf.size);

	print_stack(&stack_a);
	printf("    ");
	print_stack(&stack_b);
	printf("\n");
	printf("\n");

	return (0);
}
