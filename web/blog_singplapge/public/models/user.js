'use strict';

import Model from "./model.js";

export default class User extends Model {

	constructor(attributes) {
		super(attributes);
	}

	url() {
		return `${this.baseUrl}/user/`;
	}

	get defaults() {
		return {
			name: 'Default name',
			email: 'anon@mail.ru',
      password: 'password'
    }
	}

  remove() {
    super.remove().then(attrs => {return attrs})
  }

}
