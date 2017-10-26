'use strict';

import Router from "./modules/router.js"
import MainView from "./views/main.js"
import LoginView from "./views/login.js"
import PostView from "./views/post.js"
import CreateView from "./views/create.js"
import Session from "./models/session"


window.onload = () => {
  let routerConfig = () => {
    (new Router)
    .addRoute('/login', LoginView)
      .addRoute('/post', PostView)
      .addRoute('/create', CreateView)
      .addRoute('/', MainView)
      .start();
  }

  if (!!localStorage.userinfo) {
    window.session = new Session(JSON.parse(localStorage.userinfo));
    window.session.save().then(routerConfig);
  } else {
    window.session = new Session();
    routerConfig();
  }
}