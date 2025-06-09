
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd1[2], fd2[2];
    pid_t pid;

    pipe(fd1); // for sending data to child
    pipe(fd2); // for receiving result from child

    pid = fork();

    if (pid > 0) {  // Parent process
        close(fd1[0]);
        close(fd2[1]);

        int radius = 5, base = 10, height = 8, length = 6, breadth = 4, side = 3;
        int data[5] = {radius, base, height, length, side};
        write(fd1[1], data, sizeof(data)); // Send input to child

        float results[4];
        read(fd2[0], results, sizeof(results)); // Get result from child

        printf("Area of Circle: %.2f\n", results[0]);
        printf("Area of Triangle: %.2f\n", results[1]);
        printf("Area of Rectangle: %.2f\n", results[2]);
        printf("Area of Square: %.2f\n", results[3]);
    }
    else if (pid == 0) { // Child process
        close(fd1[1]);
        close(fd2[0]);

        int data[5];
        read(fd1[0], data, sizeof(data)); // Read input

        float circle = 3.14 * data[0] * data[0];
        float triangle = 0.5 * data[1] * data[2];
		float rectangle = data[3] * data[4];
        float square = data[4] * data[4];

        float results[4] = {circle, triangle, rectangle, square};
        write(fd2[1], results, sizeof(results)); // Send results back
    }

    return 0;
}
