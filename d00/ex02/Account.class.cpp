// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Account.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 10:59:40 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 10:59:42 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Account.class.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
    return _totalAmount;
}

int	Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" 
    << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    _nbAccounts += 1;
    this->_amount = initial_deposit;
    _totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:"
    << this->checkAmount() << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:"
    << this->checkAmount() << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    this->_nbDeposits += 1;
    _totalNbDeposits += 1;
    this->_amount += deposit;
    _totalAmount += deposit;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:"
    << this->checkAmount() - deposit << ";deposit:" << deposit << ";amount:"
    << this->checkAmount() << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawals)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:"
    << this->checkAmount() << ";withdrawal:";

    if (withdrawals > this->checkAmount())
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    this->_nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    this->_amount -= withdrawals;
    _totalAmount -= withdrawals;

    std::cout << withdrawals << ";amount:"
    << this->checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" 
    << this->checkAmount() << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t curr_time;
    curr_time = time(NULL);

    tm *tm_local = localtime(&curr_time);
    std::cout << '[' << tm_local->tm_year + 1900 << std::setfill('0') << std::setw(2) << tm_local->tm_mon
    << std::setw(2) << tm_local->tm_mday << '_' << std::setw(2) << tm_local->tm_hour << std::setw(2) << tm_local->tm_min
    << std::setw(2) << tm_local->tm_sec << "] ";
}