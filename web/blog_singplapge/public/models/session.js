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
    let f = function (attrs) {
      this._auth = true;
      localStorage.userinfo = JSON.stringify(this.attributes);
    };
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
