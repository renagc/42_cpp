/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-c <rgomes-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:34:10 by rgomes-c          #+#    #+#             */
/*   Updated: 2023/10/20 19:52:43 by rgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(1), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	_nbAccounts--;
    _totalAmount -= this->_amount;
}

//static
int	Account::getNbAccounts( void )
{
	return (1);
}

int	Account::getTotalAmount( void )
{
	return (1);
}

int	Account::getNbDeposits( void )
{
	return (1);
}

int	Account::getNbWithdrawals( void )
{
	return (1);
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "accounts: " << getNbAccounts() << ";";
	std::cout << "total: " << getTotalAmount() << ";";
	std::cout << "deposits: " << getNbDeposits() << ";";
	std::cout << "withdrawals: " << getNbWithdrawals() << std::endl;
}

//other
void	Account::makeDeposit( int deposit )
{
	std::cout << deposit << std::endl;
	return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	std::cout << withdrawal << std::endl;
	return (1);
}

int		Account::checkAmount( void ) const
{
	return (99);
}

void	Account::displayStatus( void ) const
{
	std::cout << "accounts: " << getNbAccounts() << ";";
	std::cout << "total: " << getTotalAmount() << ";";
	std::cout << "deposits: " << getNbDeposits() << ";";
	std::cout << "withdrawals: " << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp( void )
{
	;
}
