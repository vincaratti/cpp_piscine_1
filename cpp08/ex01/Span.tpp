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

template <typename T> void	Span::insertRange( typename T::const_iterator start, typename T::const_iterator end )
{
	if ( this->data.size() + std::distance( start, end ) > max_size )
		throw SizeLimitExceededException();
	data.insert(this->data.end(), start, end);
	std::sort( this->data.begin(), this->data.end() );
}
