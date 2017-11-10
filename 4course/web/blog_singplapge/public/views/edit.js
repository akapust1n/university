import View from "../modules/view"
import Create from "../components/create/create"
import Session from "../models/session"
import SimpleMDE from 'simplemde';


//mongoose.connect('mongodb://localhost/web')
// const async = require('async');



export default class EditView extends View {
    constructor(options = {}) {
        super(options);
        this._init();
        this.hide();
    }

    _init() {
        let container = document.querySelector('.content_container');
        this._form = new Create({
            data: {
                fields: [],
                template: 'create/create.tmpl',
                controls: [{
                    text: 'edit',
                    type: 'submit',
                    class: 'button1'
                }],

            }
        });
        this._el = this._form._el;
        container.appendChild(this._el);
        let editor = document.querySelector('.editor');

        let simplemde = new SimpleMDE({
            element: document.getElementById("editor")
        });
        let parts = document.URL.split('/')
        let lastId = parts[parts.length - 1]
        const params = "?id=" + lastId.toString()
        let xhr = new XMLHttpRequest();
        xhr.open('GET', '/api/postById' + params, false);
        xhr.send();
        let post = JSON.parse(xhr.responseText).result[0]
        simplemde.value(post.text)
        document.getElementById('title').value = post.title

        let publicate = document.querySelector('.button1');
        publicate.onclick = (() => {
            console.log('submit1');
            let session = window.session;
            console.log(session)
            if (session != undefined) {
                console.log('submot');
                if (!!session.isAuthenticated) {
                    console.log(simplemde.value());
                    const data = {
                        text: simplemde.value(),
                        author: session.username,
                        title: document.getElementById('title').value,
                        id: post.id
                    }
                    let xhr = new XMLHttpRequest();
                    xhr.open('POST', "/api/edit", false);
                    xhr.setRequestHeader('Content-Type', 'application/json; charset=UTF-8');



                    xhr.send(JSON.stringify(data));
                    this.router.go('/');
                } else {
                    window.alert("войдите в своей аккаунт");
                }
            } else {
                window.alert("войдите в своей аккаунт");

            }
        });


    }




}