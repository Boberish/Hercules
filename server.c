/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:17:49 by jaylor            #+#    #+#             */
/*   Updated: 2017/02/17 13:41:15 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>

int main()
{
	char 	ser_mes[256] = "PONG PONG";
	int		ser_sock;
		
	ser_sock = socket (AF_INET, SOCK_STREAM, 0); //assiging socket, internet, ty

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9024);
	server_address.sin_addr.s_addr = INADDR_ANY;

	bind(ser_sock, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(ser_sock, 5);
	
	int client_sock;
	client_sock = accept(ser_sock, NULL, NULL);
	send(client_sock, ser_mes, sizeof(ser_mes), 0);
	return (0);
}
