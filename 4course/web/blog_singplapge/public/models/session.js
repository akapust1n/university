'use strict';

import Model from "./model.js";

export default class Session extends Model {

  constructor(attributes) {
    super(attributes);
  }

  url() {
    return `${this.baseUrl}/session`;
  }

  save() {
    let f = (attrs) => {
      console.log(JSON.stringify(this.attributes))
      this._auth = true;
      localStorage.userinfo = JSON.stringify(this.attributes);
      let result = JSON.stringify(this.attributes).result;
      if (result != "not such user") { //:))))
        localStorage.result = result
      }
    };
    console.log("server____", JSON.stringify(this.attributes));
    return super.save()
      .then(f.bind(this));
  }

  remove() {
    this._auth = false;
    localStorage.removeItem('userinfo');
    return super.remove().catch(() => {
      return {}
    });
  }

  get isAuthenticated() {
    return !!this._auth;
  }

}