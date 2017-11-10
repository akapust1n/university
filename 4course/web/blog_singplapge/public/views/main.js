'use strict';

import View from "../modules/view"
import Main from "../components/main/main.js"
import Button from "../components/button/button.js";
import Link from "../components/link/link.js";

export default class MainView extends View {
  constructor(options = {}) {
    super(options);
    this._init();
    // this.hide();
  }

  _init() {
    let container = document.querySelector('.content_container');
    const params = "?num=10&offset=0"
    let xhr = new XMLHttpRequest();
    xhr.open('GET', '/api/posts' + params, false);
    xhr.send();
    let posts = []
    let jsonPosts = JSON.parse(xhr.responseText).result
    console.log(jsonPosts)
    jsonPosts.forEach((post, i, arr) => {
      posts.push({
        id: post.id,
        body: post.text,
        title: post.title,
        author: post.author
      })
    }, this);
    this._main = new Main({
      data: {
        fields: posts,
        template: "main/main.tmpl",
      }
    });
    this._el = this._main._el;
    container.appendChild(this._main._el);

  }

}