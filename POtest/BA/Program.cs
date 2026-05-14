using System;

public class BankAccount
{
    private decimal _balance;

    public BankAccount(decimal initialBalance = 0)
    {
        if (initialBalance < 0)
            throw new ArgumentException("Начальный баланс не может быть отрицательным");

        _balance = initialBalance;
    }

    public void Deposit(decimal amount)
    {
        if (amount <= 0)
            throw new ArgumentException("Сумма должна быть больше 0");

        _balance += amount;
    }

    public void Withdraw(decimal amount)
    {
        if (amount <= 0)
            throw new ArgumentException("Сумма должна быть больше 0");

        if (amount > _balance)
            throw new InvalidOperationException("Недостаточно средств");

        _balance -= amount;
    }

    public decimal GetBalance()
    {
        return _balance;
    }
}