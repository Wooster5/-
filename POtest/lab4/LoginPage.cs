using OpenQA.Selenium;

namespace SauceDemoAutomation
{
    public class LoginPage
    {
        private readonly IWebDriver _driver;

        // Описываем элементы страницы через локаторы
        private IWebElement UsernameField => _driver.FindElement(By.Id("user-name"));
        private IWebElement PasswordField => _driver.FindElement(By.Id("password"));
        private IWebElement LoginButton => _driver.FindElement(By.Id("login-button"));

        public LoginPage(IWebDriver driver)
        {
            _driver = driver;
        }

        // Описываем действия на странице (методы)
        public void Login(string user, string pass)
        {
            UsernameField.SendKeys(user);
            PasswordField.SendKeys(pass);
            LoginButton.Click();
        }
    }
}