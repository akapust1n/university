'use strict';


export default class Session {

  constructor(attributes = {}) {
    this.auth = false;
  }

  url() {
    return 'http://localhost:3000/api/session';
  }

  save(attrs) {
    return new Promise((resolve, reject) => {
      console.log("hello");
      console.log("hello2");
      let result = this.send('POST', attrs);

      console.log("result", result)

      localStorage.userinfo = JSON.stringify(attrs);
      if (result != "no such user") { //:))))
        localStorage.result = result
        this._auth = true;
        resolve()
      } else {
        console.log("hello3");

        reject()
      };
      console.log("server____", JSON.stringify(attrs));

    });

  }

  remove() {
    this._auth = false;
    localStorage.removeItem('userinfo');
  }
  send(method, data) {
    console.log("url")
    const url = this.url()

    let xhr = new XMLHttpRequest();
    xhr.open(method, url, false);
    xhr.setRequestHeader('Content-type', 'application/json');

    xhr.send(JSON.stringify(data));;
    console.log(xhr.responseText)
    const result = JSON.parse(xhr.responseText).result
    return result
  }
  get isAuthenticated() {
    return !!this._auth;
  }

}