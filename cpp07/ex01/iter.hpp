/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:19:01 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/03 10:52:47 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>

template <typename T> void printobj( T& obj )
{
	std::cout << obj << std::endl;
}

template <typename T> void iter( T* arr, const size_t len, void (*fn)(T&))
{
	for ( size_t i = 0; i < len; i++ )
	{
		fn(*arr);
		arr++;
	}
}

template <typename T> void iter( T* arr, const size_t len, void (*fn)(const T&))
{
	for ( size_t i = 0; i < len; i++ )
	{
		fn(*arr);
		arr++;
	}
}
