/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:19:37 by vcaratti          #+#    #+#             */
/*   Updated: 2025/11/24 12:42:58 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "includes.hpp"

void	handleChar( std::string& str, std::ostream& stream );
void	handleInt( std::string& str, std::ostream& stream );
void	handleFloat( std::string& str, std::ostream& stream );
void	handleDouble( std::string& str, std::ostream& stream );
void	handlePseudo( std::string& str, std::ostream& stream );
void	handleError( std::string& str, std::ostream& stream );
