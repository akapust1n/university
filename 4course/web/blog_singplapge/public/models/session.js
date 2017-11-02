'use strict';

import Model from "./model.js";

export default class Session extends Model {

  constructor(attributes = {}) {
    this.auth = false;
  }

  url() {
    return `https://localhost:3000/api/session`;
  }

  save(attrs) {

    console.log("hey save", JSON.stringify(this.attributes).result)
    this._auth = true;
    localStorage.userinfo = JSON.stringify(this.attributes);
    let result = JSON.stringify(this.attributes).result;
    if (result != "not such user") { //:))))
      localStorage.result = result

    };
    console.log("server____", JSON.stringify(this.attributes));
  }
  remove() {
    this._auth = false;
    localStorage.removeItem('userinfo');
  }

  get isAuthenticated() {
    return !!this._auth;
  }

}