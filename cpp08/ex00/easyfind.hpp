/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:51:12 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/05 11:19:01 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "IntegerNotFoundException.hpp"

template <typename T>int& easyfind( T& cont, int to_find )
{
	typename T::iterator found = std::find( cont.begin(), cont.end(), to_find );
	if ( found == cont.end() )
		throw IntegerNotFoundException();
	return ( *found );
}
