//
// TO DO : desenvolva um algoritmo para verificar se um numero inteiro positivo
//         e uma capicua
//         Exemplos: 12321 e uma capiacua, mas 123456 nao e
//         USE uma PILHA DE INTEIROS (STACK) e uma FILA DE INTEIROS (QUEUE)
//
// TO DO : design an algorithm to check if the digits of a positive decimal
//         integer number constitue a palindrome
//         Examples: 12321 is a palindrome, but 123456 is not
//         USE a STACK of integers and a QUEUE of integers
//

#include <stdio.h>
#include "IntegersQueue.h" // Include the header file for IntegersQueue.
#include "IntegersStack.h" // Include the header file for IntegersStack.

int main(void) {
    int n, isPalindrome = 1;
    Queue* q1 = QueueCreate(100); // Create a queue to store digits.
    Stack* s1 = StackCreate(100); // Create a stack to store digits.

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    int originalNumber = n; // Store the original number for comparison later.

    while (n > 0) {
        int digit = n % 10;
        QueueEnqueue(q1, digit); // Enqueue the digit into the queue.
        StackPush(s1, digit);    // Push the digit onto the stack.
        n /= 10;
    }

    // Compare the digits from the queue and the stack.
    while (!QueueIsEmpty(q1) && !StackIsEmpty(s1)) {
        int queueDigit = QueueDequeue(q1);
        int stackDigit = StackPop(s1);

        if (queueDigit != stackDigit) {
            isPalindrome = 0; // Not a palindrome.
            break;
        }
    }

    if (isPalindrome) {
        printf("%d is a palindrome.\n", originalNumber);
    } else {
        printf("%d is not a palindrome.\n", originalNumber);
    }

    // Clean up and destroy the data structures.
    QueueDestroy(&q1); 
    StackDestroy(&s1);

    return 0;
}

