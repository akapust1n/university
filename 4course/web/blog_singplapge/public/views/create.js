import View from "../modules/view"
import Create from "../components/create/create"
import Session from "../models/session"
import SimpleMDE from 'simplemde';



export default class CreateView extends View {
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
                    text: 'publicate',
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


        window.session = window.session || new Session();
        this._form.on('submit', event => {
            event.preventDefault();
            const formData = this._form.getFormData();
            let session = (window.session = new Session(formData));
            session.save().then(attrs => {
                    window.userinfo = formData;
                    this.router.go('/');
                },
                attrs => {
                    window.alert("Логин или пароль не верны");
                });
        });


    }



}