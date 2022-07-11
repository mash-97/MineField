import requests
import urllib.parse as urlparse
from urllib.parse import urlencode

url = "https://google-translate1.p.rapidapi.com/language/translate/v2"

text = "Hello World"

params = {
	'source': 'en',
	'target': 'bd',
	'q': text
}

encoded_params = urlencode(params)
print(f"encoded params: ", encoded_params)

# payload = "source=en&target=es&q=Hello%2C%20world!"
headers = {
	"content-type": "application/x-www-form-urlencoded",
	"Accept-Encoding": "application/gzip",
	"X-RapidAPI-Host": "google-translate1.p.rapidapi.com",
	"X-RapidAPI-Key": "b75d7a0c0cmsheb461c45b57458ap1f2155jsnff7dec0ce250"
}

response = requests.request("POST", url, data=encoded_params, headers=headers)

print(response.text)

