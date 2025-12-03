/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:08:54 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/03 10:52:59 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> T min( T a, T b )
{
	return (( a <= b) ? a : b );
}

template <typename T> T max( T a, T b )
{
	return (( a >= b) ? a : b );
}

template <typename T> void swap( T& a, T& b )
{
	T tmp = a;
	a = b;
	b = tmp;
}
