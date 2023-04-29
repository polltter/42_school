//
// Created by miguel on 28-04-2023.
//

#include "Account.hpp"
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    _displayTimestamp();
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    this->_amount = initial_deposit;
    std::cout << "index:" << this->_accountIndex \
                << ";amount:" << this->_amount \
                << ";created\n";
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex \
                << ";amount:" << _amount \
                << ";closed\n";
}

void Account::_displayTimestamp() {
    std::time_t now = time(0);
    tm *gmtm = gmtime(&now);
    std::cout << "[" << gmtm->tm_year + 1900 \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_mon \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_mday << "_" \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_hour \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_min
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_sec << "] ";
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts \
                << ";total:" << _totalAmount \
                << ";deposits:" << _totalNbDeposits \
                << ";withdrawals:" << _totalNbWithdrawals \
                << std::endl;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex \
                << ";amount:" << _amount \
                << ";deposits:" << _nbDeposits \
                << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex \
                << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex \
                << ";p_amount:" << _amount \
                << ";withdrawal:";
    if (_amount - withdrawal < 0) {
        std::cout << "refused\n";
        return (false);
    }
    else {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}