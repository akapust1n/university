'use strict';

import View from "../modules/view"
import Button from "../components/button/button.js";
import Link from "../components/link/link.js";
import Post from "../components/post/post.js";

const showdown = require('showdown');
const converter = new showdown.Converter();

export default class PostView extends View {
    constructor(options = {}) {
        super(options);
        this._init();
        // this.hide();
    }

    _init() {
        let container = document.querySelector('.content_container');
        let parts = document.URL.split('/')
        let lastId = parts[parts.length - 1]
        const params = "?id=" + lastId.toString()
        let xhr = new XMLHttpRequest();
        xhr.open('GET', '/api/postById' + params, false);
        xhr.send();
        let post = JSON.parse(xhr.responseText).result[0]
        console.log(post)
        let session = window.session;
        if (!session || !session.isAuthenticated) {
            this._post = new Post({
                data: {
                    fields: [{
                        id: post.id,
                        body: converter.makeHtml(post.text),
                        title: post.title,
                        author: post.author
                    }],
                    // controls: [{
                    //     // text: 'Sing in',
                    //     // type: 'submit',
                    //     // class: 'button1'
                    // }],
                    template: 'post/post.tmpl',
                }
            });
        } else {
            this._post = new Post({
                data: {
                    fields: [{
                        id: post.id,
                        body: converter.makeHtml(post.text),
                        title: post.title,
                        author: post.author
                    }],
                    controls: [{
                        text: 'Edit',
                        type: 'submit',
                        class: 'button1',
                        id: lastId,
                    }],
                    template: 'post/post.tmpl',
                }
            });
        }
        console.log(document.URL);

        this._el = this._post._el;
        container.appendChild(this._post._el);

    }
}