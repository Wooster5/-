using NUnit.Framework;
using System;

[TestFixture]
public class BankAccountTests
{
    private BankAccount _account;

    [SetUp]
    public void Setup()
    {
        _account = new BankAccount(100);
    }

    [Test]
    public void Deposit_ValidAmount_IncreasesBalance()
    {
        _account.Deposit(50);
        Assert.That(_account.GetBalance(), Is.EqualTo(150));
    }

    [Test]
    public void Deposit_NegativeAmount_ThrowsException()
    {
        Assert.Throws<ArgumentException>(() => _account.Deposit(-10));
    }

    [Test]
    public void Withdraw_ValidAmount_DecreasesBalance()
    {
        _account.Withdraw(40);
        Assert.That(_account.GetBalance(), Is.EqualTo(60));
    }

    [Test]
    public void Withdraw_TooMuch_ThrowsException()
    {
        Assert.Throws<InvalidOperationException>(() => _account.Withdraw(200));
    }

    [Test]
    public void Withdraw_NegativeAmount_ThrowsException()
    {
        Assert.Throws<ArgumentException>(() => _account.Withdraw(-5));
    }

    [Test]
    public void GetBalance_ReturnsCorrectInitialBalance()
    {
        Assert.That(_account.GetBalance(), Is.EqualTo(100));
    }

    [Test]
    public void MultipleOperations_WorkCorrectly()
    {
        _account.Deposit(50);
        _account.Withdraw(30);
        Assert.That(_account.GetBalance(), Is.EqualTo(120));
    }

    [Test]
    public void Constructor_NegativeBalance_ThrowsException()
    {
        Assert.Throws<ArgumentException>(() => new BankAccount(-100));
    }
}