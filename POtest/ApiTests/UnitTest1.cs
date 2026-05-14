using NUnit.Framework; // Только этот using для тестов
using RestSharp;
using System.Net;
using System.Threading.Tasks;

namespace MyLabTests
{
    [TestFixture]
    public class ApiLabSection3
    {
        [TearDown]
        public void Cleanup()
        {
            // Проверяем, что клиент существует, и освобождаем ресурсы
            _client?.Dispose();
        }
        private RestClient _client;

        [SetUp]
        public void Init()
        {
            _client = new RestClient("https://jsonplaceholder.typicode.com");
        }

        [Test]
        // Используем полное имя атрибута, чтобы не было конфликта с System.ComponentModel
        [NUnit.Framework.Description("Проверка получения списка пользователей")]
        public async Task CheckUsers_ShouldReturn200()
        {
            var request = new RestRequest("/users", Method.Get);
            var response = await _client.ExecuteAsync(request);

            Assert.That(response.StatusCode, Is.EqualTo(HttpStatusCode.OK));
        }

        [Test]
        public async Task CheckSpecificUser_ShouldHaveName() //Проверяет «позитивный сценарий» — что сервер вообще работает и отдает данные.
        {
            var request = new RestRequest("/users/1", Method.Get);
            var response = await _client.ExecuteAsync(request);

            Assert.That(response.Content, Does.Contain("Leanne Graham"));
        }
        [Test]
        [NUnit.Framework.Description("3. Создание поста (POST)")]
        public async Task CreatePost_ShouldReturn201()//Проверяет не только доступность, но и корректность данных внутри ответа.
        {
            var request = new RestRequest("/posts", Method.Post);
            request.AddJsonBody(new { title = "foo", body = "bar", userId = 1 });
            var response = await _client.ExecuteAsync(request);
            Assert.That(response.StatusCode, Is.EqualTo(HttpStatusCode.Created));
        }

        [Test]
        [NUnit.Framework.Description("4. Обновление поста (PUT)")]
        public async Task UpdatePost_ShouldReturnOk()//Имитирует добавление новой записи на сервер.
        {
            var request = new RestRequest("/posts/1", Method.Put);
            request.AddJsonBody(new { id = 1, title = "new title" });
            var response = await _client.ExecuteAsync(request);
            Assert.That(response.StatusCode, Is.EqualTo(HttpStatusCode.OK));
        }

        [Test]
        [NUnit.Framework.Description("5. Удаление поста (DELETE)")]
        public async Task DeletePost_ShouldReturnOk()//Проверяют возможность модификации и удаления данных.
        {
            var request = new RestRequest("/posts/1", Method.Delete);
            var response = await _client.ExecuteAsync(request);
            Assert.That(response.StatusCode, Is.EqualTo(HttpStatusCode.OK));
        }

        [Test]
        [NUnit.Framework.Description("6. Негативный тест: несуществующий пост")]
        public async Task GetInvalidPost_ShouldReturn404()//проверить, как система ведет себя при ошибках.
        {
            var request = new RestRequest("/posts/9999", Method.Get);
            var response = await _client.ExecuteAsync(request);
            Assert.That(response.StatusCode, Is.EqualTo(HttpStatusCode.NotFound));
        }
    }
}