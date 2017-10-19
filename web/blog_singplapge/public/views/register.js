import View from "../modules/view"
import Form from "../components/form/form.js"
import User from "../models/user"
import Session from "../models/session"

export default class RegisterView extends View {
  constructor(options = {}) {
    super(options);
    this._init();
    this.hide();
  }

  _init() {
    let container = document.querySelector('.content_container');
    this._form = new Form({
      data: {
        fields: [{
            name: 'email',
            type: 'email',
            placeholder: 'Email'
          },
          {
            name: 'login',
            type: 'text',
            placeholder: 'Username'
          },
          {
            name: 'password',
            type: 'password',
            placeholder: 'Password'
          }
        ],
        template: 'form/form.tmpl',
        controls: [{
          text: 'Sign up',
          type: 'submit',
          class: 'register__submit btn-success btn-md'

        }]
      }
    });
    this._el = this._form._el;
    container.appendChild(this._el);
    this._form.on('submit', event => {
      event.preventDefault();
      const formData = this._form.getFormData();
      let user = new User(formData);
      user.save().then(attrs => {
          //сразу логиним
          let session = (window.session = new Session({
            login: formData['login'],
            password: formData['password']
          }));
          session.save().then(attrs => {
              window.userinfo = formData;
              this.router.go('/play');
            },
            attrs => {
              window.alert("Логин или пароль не верны");
            });

          window.userinfo = formData;
          this.router.go('/play');
        },
        () => {
          window.alert("Такой пользователь уже существует");
        });

    });
  }

  resume(options = {}) {
    this.show();
  }
}