'use strict';


export default class User {

	constructor(attributes = {}) {}

	url() {
		return `${this.baseUrl}/user/`;
	}

	get defaults() {
		return {
			name: 'Default name',
			password: 'password'
		}
	}


	remove() {
		super.remove().then(attrs => {
			return attrs
		})
	}

}