package main

import (
	"bytes"
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"strings"
)

func optionsRequest(url string, data io.Reader) (string, error, int) {
	client := &http.Client{}
	req, err := http.NewRequest(http.MethodOptions, url, data)
	if err != nil {
		// handle error
		log.Fatal(err)
	}
	response, err := client.Do(req)
	if err != nil {
		// handle error
		return string("empty"), err, -1
	}
	defer response.Body.Close()

	bodyBytes, err := ioutil.ReadAll(response.Body)
	return string(bodyBytes), err, response.StatusCode

}

func headRequest(url string, data io.Reader) (error, int) {
	client := &http.Client{}
	req, err := http.NewRequest(http.MethodOptions, url, data)
	if err != nil {
		// handle error
		log.Fatal(err)
	}
	response, err := client.Do(req)
	if err != nil {
		// handle error
		log.Fatal(err)
	}
	return err, response.StatusCode
}
func main() {
	arg := os.Args[1]
	switch arg {
	case "1.2.1":
		sites := [...]string{"http://google.com", "https://ya.ru/", "https://www.rambler.ru/", "https://www.google.ru/", "https://github.com/", "https://www.apple.com/", "https://www.linkedin.com/"}
		for _, site := range sites {
			body, _, code := optionsRequest(site, strings.NewReader("any thing"))
			//fmt.Println(response)
			fmt.Println(site)
			//fmt.Println(err)
			fmt.Println(code)
			if code == 200 {
				fmt.Println(body)
			}
		}
	case "1.2.2":
		fmt.Println("HEAD REQUESTS")
		sites2 := [...]string{"https://vk.com", "https://www.apple.com/", "http://www.msn.com"}
		for _, site := range sites2 {
			_, code := headRequest(site, strings.NewReader("any thing"))
			fmt.Println(site)
			fmt.Println(code)

		}
	case "1.2.3":
		fmt.Println("---------------")

		fmt.Println("GET and POST requests")
		resp, _ := http.Get("http://google.com")
		defer resp.Body.Close()

		fmt.Println("google get and post")
		bodyBytes, _ := ioutil.ReadAll(resp.Body)

		fmt.Println(string(bodyBytes))
		var jsonStr = []byte(`{"title":"Buy cheese and bread for breakfast."}`)
		resp, _ = http.Post("http://google.com", "application/json", bytes.NewBuffer(jsonStr))
		bodyBytes, _ = ioutil.ReadAll(resp.Body)
		fmt.Println(string(bodyBytes))

		resp, _ = http.Get("http://yandex.ru")
		fmt.Println("yandex get and post")
		bodyBytes, _ = ioutil.ReadAll(resp.Body)
		fmt.Println(string(bodyBytes))
		resp2, _ := http.Post("http://yandex.ru", "application/json", bytes.NewBuffer(jsonStr))

		bodyBytes2, _ := ioutil.ReadAll(resp2.Body)

		fmt.Println(string(bodyBytes2))
	case "1.3.2.1":
		resp, _ := http.Get("https://api.vk.com/method/users.get?fields=photo_max_orig,sex,bdate,education&access_token=4f32d36320d5c33d08b08ac2460ed3876c79185db3b35a137a1d77da3debeb8e677325eda07c5fdece386&user_ids=1")
		bodyBytes, _ := ioutil.ReadAll(resp.Body)
		fmt.Println(string(bodyBytes))
	case "1.3.2.2":
		resp, _ := http.Get("https://api.vk.com/method/wall.get?access_token=4f32d36320d5c33d08b08ac2460ed3876c79185db3b35a137a1d77da3debeb8e677325eda07c5fdece386&owner_id=-76982440&count=10")
		bodyBytes, _ := ioutil.ReadAll(resp.Body)
		fmt.Println(string(bodyBytes))
	case "1.3.2.3":

		resp, _ := http.Get("https://api.vk.com/method/wall.get?access_token=4f32d36320d5c33d08b08ac2460ed3876c79185db3b35a137a1d77da3debeb8e677325eda07c5fdece386&owner_id=-76982440&count=10")
		bodyBytes, _ := ioutil.ReadAll(resp.Body)
		fmt.Println(string(bodyBytes))

	case "1.3.2.4":

		resp, _ := http.Get("https://api.vk.com/method/database.getFaculties?access_token=4f32d36320d5c33d08b08ac2460ed3876c79185db3b35a137a1d77da3debeb8e677325eda07c5fdece386&university_id=250")
		bodyBytes, _ := ioutil.ReadAll(resp.Body)
		fmt.Println(string(bodyBytes))
	}

}
