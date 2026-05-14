using Reqnroll; // Это делает класс понятным для Reqnroll
using NUnit.Framework;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;

namespace SauceDemoAutomation.StepDefinitions
{
    [Binding] // ГЛАВНЫЙ АТРИБУТ: без него текст из .feature не свяжется с этим кодом
    public class LoginSteps
    {
        private IWebDriver _driver;

        [Given(@"пользователь открыл страницу входа")]
        public void GivenOpenPage()
        {
            // Создаем настройки для Chrome
            ChromeOptions options = new ChromeOptions();
            // Добавляем режим "без головы" (без окна)
            options.AddArgument("--headless");
            // Дополнительные аргументы для стабильности на серверах Linux
            options.AddArgument("--no-sandbox");
            options.AddArgument("--disable-dev-shm-usage");
            //Передаем эти настройки в драйвер
           _driver = new ChromeDriver(options);

            //_driver = new ChromeDriver();


            _driver.Manage().Window.Maximize();
            _driver.Navigate().GoToUrl("https://www.saucedemo.com/");
        }

        [When(@"пользователь вводит логин ""(.*)"" и пароль ""(.*)""")]
        public void WhenInputCredentials(string user, string pass)
        {
            _driver.FindElement(By.Id("user-name")).SendKeys(user);
            _driver.FindElement(By.Id("password")).SendKeys(pass);
        }

        [When(@"нажимает кнопку входа")]
        public void WhenClickLogin()
        {
            _driver.FindElement(By.Id("login-button")).Click();
        }

        [Then(@"он должен быть перенаправлен на страницу товаров")]
        public void ThenCheckUrl()
        {
            Assert.That(_driver.Url, Does.Contain("inventory.html"));
            _driver.Quit();
        }
    }
}