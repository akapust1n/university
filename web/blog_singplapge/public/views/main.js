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
    this._main = new Main({
      data: {
        fields: [{
            id: 1,
            body: "blog1",
            title: "title1",
            author: "author1"
          },
          {
            id: 2,
            body: "blog2",
            title: "title2",
            author: "author2"
          },
          {
            id: 3,
            body: "blog3",
            title: "title3",
            author: "author3"
          }
        ],
        template: "main/main.tmpl",
      }
    });
    this._el = this._main._el;
    container.appendChild(this._main._el);

  }

  // resume(options = {}) {
  //   let session = window.session;
  //   if (!session || !session.isAuthenticated) {
  //     this.router.go('/login');
  //   }
  //   else {
  //     this.show();
  //   }
  // }
}