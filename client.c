/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:57:31 by jaylor            #+#    #+#             */
/*   Updated: 2017/02/17 13:02:57 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>

int main()
{
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STERAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9024);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int con_stat;

	con_stat = connect(network_socket, (struct sockaddr*)&server_addres, sizeof(server_address));

	if(con_stat == -1)
		printf("errror connection");
	char ser_res[256];

	recv(network_socket, &ser_res, sizeof(ser_res), 0);
	printf("%s", ser_res);
	close(sock);	
}
