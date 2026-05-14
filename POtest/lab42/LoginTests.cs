using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;
//using SauceDemoAutomation.Pages;

namespace SauceDemoAutomation
{
    [TestFixture]
    public class LoginTests
    {
        private IWebDriver _driver;
        private LoginPage _loginPage;

        [SetUp] // Выполняется перед каждым тестом
        public void Setup()
        {
            _driver = new ChromeDriver();
            _driver.Manage().Window.Maximize();
            _driver.Navigate().GoToUrl("https://www.saucedemo.com/");

            // Инициализируем страницу
            _loginPage = new LoginPage(_driver);
        }

        [Test]
        public void SuccessfulLoginTest()
        {
            // Используем метод из нашего Page Object
            _loginPage.Login("standard_user", "secret_sauce");

            // Проверка (Assert) — убеждаемся, что мы вошли (URL изменился)
            Assert.That(_driver.Url, Does.Contain("inventory.html"));
        }

        [TearDown] // Выполняется после каждого теста
        public void Teardown()
        {
            _driver.Quit(); // Обязательно закрываем браузер
            _driver.Dispose();
        }
    }
}