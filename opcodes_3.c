#include "monty.h"
/**
 * _mod - computes the rest of the division of the top two elements of the stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
    int modulo;

    if(*stack == NULL || (*stack)->next == NULL)
        error_handler(ERROR_MOD);
    if ((*stack)->n == 0)
        error_handler(ERROR_DIV_ZERO);
    modulo = (*stack)->next->n / (*stack)->n;
    _pop(stack, line_number);
    (*stack)->n = modulo;
}
/**
 * _pchar - prints the char type of the head node integer
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (!stack || !*stack)
        error_handler(ERROR_STACK_EMPTY);
    if ((*stack)->n < 0 || (*stack)-> > 127)
        error_handler(ERROR_PCHAR_RANGE);
    printf("%c\n", (*stack)->n);
}
/**
 * _pstr - prints the char type of the head node integer
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *copy;
    (void)line_number;

    for (copy = *stack; copy; copy = copy->next)
    {
        if (copy->n < 1 || copy->n > 127)
            break;
        printf("%c", copy->n);
    }
    putchar('\n');
}
