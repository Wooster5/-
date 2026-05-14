using NUnit.Framework;
using Moq;
using System;

[TestFixture]
public class UserRegistrationTests
{
    private Mock<IEmailService> _mockEmailService;
    private UserRegistration _registration;

    [SetUp]
    public void Setup()
    {
        _mockEmailService = new Mock<IEmailService>();
        _registration = new UserRegistration(_mockEmailService.Object);
    }

    [Test]
    public void Register_ValidEmail_SendsEmail()
    {
        // Act
        _registration.Register("test@mail.com");

        // Assert
        _mockEmailService.Verify(
            x => x.SendEmail(
                "test@mail.com",
                "Добро пожаловать",
                "Спасибо за регистрацию!"
            ),
            Times.Once
        );
    }

    [Test]
    public void Register_EmptyEmail_ThrowsException()
    {
        Assert.Throws<ArgumentException>(
            () => _registration.Register("")
        );
    }

    [Test]
    public void Register_NullEmail_ThrowsException()
    {
        Assert.Throws<ArgumentException>(
            () => _registration.Register(null)
        );
    }

    [Test]
    public void Register_EmailCalledOnce()
    {
        _registration.Register("user@test.com");

        _mockEmailService.Verify(
            x => x.SendEmail(It.IsAny<string>(),
                             It.IsAny<string>(),
                             It.IsAny<string>()),
            Times.Once
        );
    }

    [Test]
    public void Register_EmailCalledWithCorrectAddress()
    {
        _registration.Register("abc@test.com");

        _mockEmailService.Verify(
            x => x.SendEmail(
                "abc@test.com",
                It.IsAny<string>(),
                It.IsAny<string>()),
            Times.Once
        );
    }
}