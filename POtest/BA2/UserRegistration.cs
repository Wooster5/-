public class UserRegistration
{
    private readonly IEmailService _emailService;

    public UserRegistration(IEmailService emailService)
    {
        _emailService = emailService;
    }

    public void Register(string email)
    {
        if (string.IsNullOrEmpty(email))
            throw new ArgumentException("Email не может быть пустым");

        // логика регистрации (условно)

        _emailService.SendEmail(
            email,
            "Добро пожаловать",
            "Спасибо за регистрацию!"
        );
    }
}