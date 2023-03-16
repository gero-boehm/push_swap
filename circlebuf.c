#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
	int				*items;
	size_t			size;
	size_t			max_size;
	unsigned long	start;
}	t_stack;

int	malloc2(size_t count, int **ptr)
{
	*ptr = malloc(count);
	return (*ptr == NULL);
}

int	create_stack(t_stack *stack, size_t size)
{
	if (malloc2(size * sizeof(int), &stack->items))
		return (1);
	stack->size = 0;
	stack->max_size = size;
	stack->start = 0;
	return (0);
}

unsigned long	normalize_index(t_stack *stack, long index)
{
	return ((index + stack->start + stack->max_size) % stack->max_size);
}

int	add_item(t_stack *stack, int item)
{
	unsigned long	index;

	if (stack->size == stack->max_size)
		return (1);
	index = normalize_index(stack, stack->size++);
	stack->items[index] = item;
	return (0);
}

int	get_item_at(t_stack *stack, unsigned long index)
{
	index = normalize_index(stack, index);
	return (stack->items[index]);
}

void	set_item_at(t_stack *stack, unsigned long index, int item)
{
	index = normalize_index(stack, index);
	stack->items[index] = item;
}

void	swap(t_stack *stack)
{
	int	item1;
	int	item2;

	if (stack->size < 2)
		return ;
	item1 = get_item_at(stack, 0);
	item2 = get_item_at(stack, 1);
	set_item_at(stack, 0, item2);
	set_item_at(stack, 1, item1);
}

void	push(t_stack *stack1, t_stack *stack2)
{
	int	item;

	if (stack1->size == 0)
		return ;
	item = get_item_at(stack1, 0);
	stack1->start = normalize_index(stack1, 1);
	stack1->size--;
	set_item_at(stack2, -1, item);
	stack2->start = normalize_index(stack2, -1);
	stack2->size++;
}

void	rotate(t_stack *stack)
{
	int	item;

	if (stack->size < 2)
		return ;
	item = get_item_at(stack, 0);
	stack->start = normalize_index(stack, 1);
	set_item_at(stack, stack->size - 1, item);
}

void	rotate_reverse(t_stack *stack)
{
	int	item;

	if (stack->size < 2)
		return ;
	item = get_item_at(stack, stack->size - 1);
	stack->start = normalize_index(stack, -1);
	set_item_at(stack, 0, item);
}

void	sa(t_stack *stack)
{
	printf("sa\n");
	swap(stack);
}

void	sb(t_stack *stack)
{
	printf("sb\n");
	swap(stack);
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	printf("ss\n");
	swap(stack1);
	swap(stack2);
}

void	pb(t_stack *a, t_stack *b)
{
	printf("pb\n");
	push(a, b);
}

void	pa(t_stack *b, t_stack *a)
{
	printf("pa\n");
	push(b, a);
}

void	ra(t_stack *stack)
{
	printf("ra\n");
	rotate(stack);
}

void	rb(t_stack *stack)
{
	printf("rb\n");
	rotate(stack);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	printf("rr\n");
	rotate(stack1);
	rotate(stack2);
}

void	rra(t_stack *stack)
{
	printf("rra\n");
	rotate_reverse(stack);
}

void	rrb(t_stack *stack)
{
	printf("rrb\n");
	rotate_reverse(stack);
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	printf("rrr\n");
	rotate_reverse(stack1);
	rotate_reverse(stack2);
}

void	print_stack(t_stack *stack)
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

void	print_indices()
{
	printf("\n");
	printf("\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", i);
	printf("    ");
	for (int i = 0; i < 10; i++)
		printf("%d ", i);
	printf("\n");
}

void	print_stacks(t_stack *stack1, t_stack *stack2)
{
	print_stack(stack1);
	printf("    ");
	print_stack(stack2);
	printf("\n");
	printf("\n");
}

int	main(void)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (create_stack(&stack_a, 10))
		return (1);
	if (create_stack(&stack_b, 10))
		return (2);
	for (int i = 0; i < 10; i++)
		add_item(&stack_a, i);

	printf("\n");

	// run ops here
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// ra(&stack_a);
	// pb(&stack_a, &stack_b);
	// rb(&stack_b);
	// rb(&stack_b);
	// pb(&stack_b, &stack_a);


	print_indices();
	print_stacks(&stack_a, &stack_b);

	return (0);
}
