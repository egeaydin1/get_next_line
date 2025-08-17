/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:03:02 by egeaydin          #+#    #+#             */
/*   Updated: 2025/08/17 20:43:16 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int main() {
    int fd = open("test1.txt", O_RDWR);
    char *line = get_next_line(fd);
    printf("1.satır %zu: '%s'\n",ft_strlen(line),line);
    line = get_next_line(fd);
    printf("2.satır %zu: '%s'\n",ft_strlen(line),line);
    line = get_next_line(fd);
    printf("3.satır %zu: '%s'\n",ft_strlen(line),line);
    free(line);
    close(fd);
}