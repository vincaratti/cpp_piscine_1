/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:27:45 by vcaratti          #+#    #+#             */
/*   Updated: 2025/12/05 12:28:02 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename T> void	Span::insertRange( T::iterator start, T::iterator end )
{
	if ( std::distance( start, end ) + this->data.size() > this->max_size )
		throw SizeLimitExceededException();
	while ( start != end )
		this->data.push_back( *start++ );
	this->data.push_back( start ); //??
}
