'use strict';

import View from "../modules/view"
import Button from "../components/button/button.js";
import Link from "../components/link/link.js";
import Post from "../components/post/post.js";

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
        this._post = new Post({
            data: {
                fields: [{
                    id: lastId,
                    body: "Бе́та-тести́рование (англ. beta testing) — интенсивное использование почти готовой версии продукта (как правило, программного или аппаратного обеспечения) с целью выявления максимального числа ошибок в его работе для их последующего устранения перед окончательным выходом (релизом) продукта на рынок, к массо",
                    title: "title" + lastId,
                    author: lastId

                }],
                template: 'post/post.tmpl',
            }
        });
        console.log(document.URL);

        this._el = this._post._el;
        container.appendChild(this._post._el);

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