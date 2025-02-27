/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:08:18 by mbrighi           #+#    #+#             */
/*   Updated: 2025/02/27 22:13:39 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


// int	main(int argc, char *argv[])
// {
// 	int id;
	
// 	id = fork();
// 	if (id == 0)
// 		printf("L'hai fatta la fota? : %d\n", id);
// 	else
// 	{
// 		wait(NULL);
// 		printf("ti prendo a legnate porcoddio: %d\n" , id);
// 	}
// 	return (0);	
// }

// int	main(int argc, char *argv[])
// {
// 	int i;
// 	int id;
	
// 	i = 3;
// 	id = fork();
// 	fork();
// 	while (id == 0 && i > 0)
// 	{
// 		printf("Secondo me sono %d\n", i);
// 		i--;
// 	}
// 	return (0);	
// }

// int	main(int argc, char *argv[])
// {
// 	int id;

// 	id = fork();
// 	if (id != 0)
// 	{
// 		fork();
// 	}
// 	printf("L'hai fatta la fota? : %d\n", id);
// 	if (id != 0)
// 		printf("ti prendo a legnate porcoddio: %d\n" , id);
// 	return (0);	
// }


// int	main(int argc, char *argv[])
// {
// 	int	id;
// 	int	n;
// 	int	i;

// 	id = fork();
// 	if (id == 0)
// 		n = 1;
// 	else
// 		n = 6;
// 	i = n;
// 	while (i < n + 5)
// 	{
// 		printf("%d ", i);
// 		fflush(stdout);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }

// int	main(int argc, char *argv[])
// {
// 	int	id;
// 	int	n;
// 	int	i;
// 	int status;

// 	id = fork();

// 	if (id != 0)
// 		n = 1;
// 	else
// 		n = 6;
// 	if (id == 0)
// 		wait(&status);
// 	i = n;
// 	while (i < n + 5)
// 	{
// 		printf("%d ", i);
// 		i++;
// 		fflush(stdout);
// 	}
// 	// for (i = n; i< n + 5; i++)
// 	// {
// 	//  	printf("%d", i);
// 	// 	fflush(stdout);
// 	// }
// 	if (id == 0)
// 		printf("\n");
// 	return (0);
// }

// int	main(int argc, char *argv[])
// {
// 	int id;
	
// 	id = fork();
// 	if (id == 0)
// 		sleep(1);
// 	printf("Current ID : %d, parent ID %d, %d\n", getpid(), getppid(), id);
// 	int res = wait (NULL);
// 	if (res == -1)
// 		printf("No child to wait with candies\n");
// 	else
// 		printf("%d finished execution\n", res);
// 	return (0);
// }

// int	main(int argc, char *argv[])
// {
// 	int id1;
// 	int id2;
	
// 	id1 = fork();
// 	id2 = fork();
// 	if (id1 == 0)
// 		{
// 			if (id2 == 0)
// 				printf("We are process y\n");
// 			else
// 				printf("We are process x\n");
// 		}
// 		else
// 		{
// 			if (id2 == 0)
// 				printf("We are process z\n");
// 			else
// 				printf("We are the parent process\n");
// 		}
// 	while (wait(NULL) != -1 || errno != ECHILD)
// 		printf("Waited for a child to finish\n");
// 	return (0);
// }

// int	main(int argc, char *argv[])
// {
// 	int fd[2];
// 	//fd[0] - read
// 	//fd[1] - write
// 	int id;
// 	int x;
// 	int y;

// 	if(pipe(fd) == -1)
// 	{
// 		printf("An error occurred with opening the pipe\n");
// 		return (1);
// 	}
// 	id = fork();
// 	if (id == -1) {
// 		printf("An error occurred with the fork\n");
// 		return 4;
// 	}
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		printf("Input a number: ");
// 		scanf("%d", &x);
// 		if (write(fd[1], &x, sizeof(int)) == -1) {
// 			printf("An error occurred with writing the pipe\n");
// 			return 2;
// 		}
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		if(read(fd[0], &y, sizeof(int))== -1) {
// 			printf("An error occurred with reading from the pipe\n");
// 			return 3;
// 		}
// 		y = y * 3;
// 		close(fd[0]);
// 		printf("Got from child process %d\n", y);
// 	}

// 	return (0);
// }

int	main(int argc, char *argv[])
{
	int arr[] = {1, 2, 3, 4, 1, 2};
	int fd[2];
	int	id;
	int	start;
	int	end;
	int arrSize;

	arrSize = sizeof(arr) / sizeof(int);
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		start = 0;
		end = start + arrSize / 2 ;
	}
	else
	{
		start = arrSize /2;
		end = arrSize;
	}
	
	return (0);
}